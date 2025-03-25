/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "measures.h"
#include "mikroe_accel_4_click.h"
#include "Driver_I2C.h"
#include "fsl_lpi2c_cmsis.h"
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_mrt.h"
#include "fsl_p3t1755.h"
#include "fsl_lpadc.h"
#include "fsl_vref.h"
#include "fsl_irtc.h"
#include "motor_control.h"
#include "fsl_lptmr.h"

// I2C CMSIS driver ------------------------------------------------------
static ARM_DRIVER_I2C *g_I2Cdrv = &Driver_I2C3;
static bool 	g_i2c_transfer_done = false;
static int32_t 	g_transfer_status = ARM_I2C_EVENT_TRANSFER_DONE;
// -----------------------------------------------------------------------

// Measure values --------------------------------------------------------
static uint32_t						g_max_count					= 0;

static measure_updates_t 			g_measure_updates 			= {0};
static measures_accel_t 			g_measure_accel 			= {0};
static measures_performance_core1_t g_measure_performance_core1 = {0};
static measures_performance_core2_t g_measure_performance_core2 = {0};
static float32_t 					g_measure_electrode 		= 0;
static float32_t					g_measure_mcu_temperature 	= 0;
static float32_t					g_measure_brd_temperature 	= 0;
static measures_time_t				g_measure_time				= {0};
static measures_date_t				g_measure_date				= {0};
static int32_t						g_measure_rpm				= 0;

static uint32_t						g_measure_performance_start_idle_c1 				= 0;
static uint32_t						g_measure_performance_start_ethernet_c1 			= 0;
static uint32_t						g_measure_performance_start_lvgl_c1 				= 0;
static uint32_t						g_measure_performance_start_sensors_c1 				= 0;
static uint32_t						g_measure_performance_start_idle_c2 				= 0;
static uint32_t						g_measure_performance_start_motor_control_c2 		= 0;
static uint32_t						g_measure_performance_start_motor_control_int_c2 	= 0;

static uint32_t						g_measure_performance_end_idle_c1 				= 0;
static uint32_t						g_measure_performance_end_ethernet_c1 			= 0;
static uint32_t						g_measure_performance_end_lvgl_c1 				= 0;
static uint32_t						g_measure_performance_end_sensors_c1 			= 0;
static uint32_t						g_measure_performance_end_idle_c2 				= 0;
static uint32_t						g_measure_performance_end_motor_control_c2 		= 0;
static uint32_t						g_measure_performance_end_motor_control_int_c2 	= 0;

static uint32_t						g_measure_performance_idle_c1 				= 0;
static uint32_t						g_measure_performance_ethernet_c1 			= 0;
static uint32_t						g_measure_performance_lvgl_c1 				= 0;
static uint32_t						g_measure_performance_sensors_c1 			= 0;
static uint32_t						g_measure_performance_idle_c2 				= 0;
static uint32_t						g_measure_performance_motor_control_c2 		= 0;
static uint32_t						g_measure_performance_motor_control_int_c2 	= 0;
// -----------------------------------------------------------------------

void I2C3_SignalEvent_t(uint32_t event)
{
    if (event != ARM_I2C_EVENT_TRANSFER_DONE)
    {
    	g_transfer_status = event;
    }
    g_i2c_transfer_done = true;
}

int32_t wait_transfer()
{
	while (!g_i2c_transfer_done)
	{
		// Idle or wait in FreeRtos
	}
    if (g_transfer_status == ARM_I2C_EVENT_TRANSFER_INCOMPLETE)
    {
    	g_I2Cdrv->Control(ARM_I2C_ABORT_TRANSFER, 0);
    }
    if (g_transfer_status != ARM_I2C_EVENT_TRANSFER_DONE)
    {
        return ARM_DRIVER_ERROR;
    }
    return ARM_I2C_EVENT_TRANSFER_DONE;
}

void mem_cpy(uint8_t *source, uint8_t *dest, uint16_t len)
{
	uint32_t index;
	for(index = 0; index < len; index ++)
	{
		dest[index] = source[index];
	}
}

accel4click_status_t i2c_transfer(uint8_t address, uint8_t subaddress, uint8_t *buff, uint8_t len, accel4click_i2c_option_t option)
{
	uint8_t aux_buff[10];
	int32_t status;

	if(option == k_accel_read)
	{
		g_i2c_transfer_done = false;
		g_transfer_status = ARM_I2C_EVENT_TRANSFER_DONE;
		g_I2Cdrv->MasterTransmit(address, &subaddress, 1, true);
		status = wait_transfer();
		if(ARM_I2C_EVENT_TRANSFER_DONE == status)
		{
			g_i2c_transfer_done = false;
			g_transfer_status = ARM_I2C_EVENT_TRANSFER_DONE;
			g_I2Cdrv->MasterReceive(address, buff, len, false);
			status = wait_transfer();
		}
	}
	else
	{
		aux_buff[0] = subaddress;
		mem_cpy(buff, aux_buff+1, len);
		g_i2c_transfer_done = false;
		g_transfer_status = ARM_I2C_EVENT_TRANSFER_DONE;
		g_I2Cdrv->MasterTransmit(address, aux_buff, len+1, false);
		status = wait_transfer();
	}

	if(status == 1) status = 0;
	return status;
}

void ADC0_IRQHandler(void)
{
    lpadc_conv_result_t convResultStruct;
    uint16_t Vbe1            = 0U;
    uint16_t Vbe8            = 0U;
    uint32_t convResultShift = 3U;
    float32_t parameterSlope     = FSL_FEATURE_LPADC_TEMP_PARAMETER_A;
    float32_t parameterOffset    = FSL_FEATURE_LPADC_TEMP_PARAMETER_B;
    float32_t parameterAlpha     = FSL_FEATURE_LPADC_TEMP_PARAMETER_ALPHA;
    float32_t temperature        = -273.15f; /* Absolute zero degree as the incorrect return value. */

	/* Read the 2 temperature sensor result. */
	if (true == LPADC_GetConvResult(ADC0, &convResultStruct, 0))
	{
		if(1 == convResultStruct.commandIdSource)
		{
			Vbe1 = convResultStruct.convValue >> convResultShift;
			if (true == LPADC_GetConvResult(ADC0, &convResultStruct, 0))
			{
				Vbe8 = convResultStruct.convValue >> convResultShift;
				/* Final temperature = A*[alpha*(Vbe8-Vbe1)/(Vbe8 + alpha*(Vbe8-Vbe1))] - B. */
				temperature = parameterSlope * (parameterAlpha * ((float)Vbe8 - (float)Vbe1) /
												((float)Vbe8 + parameterAlpha * ((float)Vbe8 - (float)Vbe1))) -
							  parameterOffset;
			}
			if(g_measure_mcu_temperature != temperature)
			{
				g_measure_mcu_temperature = temperature;
				g_measure_updates.mcu_temperature_update = true;
			}
		}
	}
}

void LPTMR0_IRQHandler(void)
{
	static uint32_t previus_perf_idle_c1 = 0;
	static uint32_t previus_perf_idle_c2 = 0;
	uint32_t acumulator_core1;
	uint32_t acumulator_core2;

	g_measure_performance_motor_control_c2 += g_measure_performance_motor_control_int_c2;

	acumulator_core1 = g_measure_performance_idle_c1 + g_measure_performance_ethernet_c1 + g_measure_performance_lvgl_c1 + g_measure_performance_motor_control_c2 + g_measure_performance_sensors_c1;
	//acumulator_core2 = g_measure_performance_idle_c2 + g_measure_performance_motor_control_c2;
	acumulator_core2 = 0;

	if(previus_perf_idle_c1 != g_measure_performance_idle_c1)
	{
		previus_perf_idle_c1 = g_measure_performance_idle_c1;
		g_measure_updates.performance_core1_update = true;
	}

	if(previus_perf_idle_c2 != g_measure_performance_idle_c2)
	{
		previus_perf_idle_c2 = g_measure_performance_idle_c2;
		g_measure_updates.performance_core2_update = true;
	}

	if(acumulator_core1)
	{
		g_measure_performance_core1.measures_ethernet_perf_core1 		= (uint8_t)((float32_t)g_measure_performance_ethernet_c1/(float32_t)acumulator_core1*100.0);
		g_measure_performance_core1.measures_lvgl_perf_core1 			= (uint8_t)((float32_t)g_measure_performance_lvgl_c1/(float32_t)acumulator_core1*100.0);
		g_measure_performance_core1.measures_sensors_perf_core1_t 		= (uint8_t)((float32_t)g_measure_performance_sensors_c1/(float32_t)acumulator_core1*100.0);
		g_measure_performance_core1.measures_motor_perf_core1_t 		= (uint8_t)((float32_t)g_measure_performance_motor_control_c2/(float32_t)acumulator_core1*100.0);
		g_measure_performance_core1.measures_idle_perf_core1 			= 100 - g_measure_performance_core1.measures_ethernet_perf_core1 - g_measure_performance_core1.measures_lvgl_perf_core1 - g_measure_performance_core1.measures_sensors_perf_core1_t - g_measure_performance_core1.measures_motor_perf_core1_t;
	}

	if(acumulator_core2)
	{
		g_measure_performance_core2.measures_motorControl_perf_core2 	= (uint8_t)((float32_t)g_measure_performance_motor_control_c2/(float32_t)acumulator_core2*100.0);
		g_measure_performance_core2.measures_idle_perf_core2 			= 100 - g_measure_performance_core2.measures_motorControl_perf_core2;
	}
	else
	{
		g_measure_performance_core2.measures_idle_perf_core2 			= 100;
		g_measure_performance_core2.measures_motorControl_perf_core2 	= 0;
	}
	g_measure_performance_idle_c1 = 0;
	g_measure_performance_ethernet_c1 = 0;
	g_measure_performance_lvgl_c1 = 0;
	g_measure_performance_sensors_c1 = 0;
	g_measure_performance_idle_c2 = 0;
	g_measure_performance_motor_control_c2 = 0;
	g_measure_performance_motor_control_int_c2 = 0;

	g_measure_performance_start_idle_c1 = 0;
	g_measure_performance_start_ethernet_c1 = 0;
	g_measure_performance_start_lvgl_c1 = 0;
	g_measure_performance_start_sensors_c1 = 0;
	g_measure_performance_start_idle_c2 = 0;
	g_measure_performance_start_motor_control_c2 = 0;
	g_measure_performance_start_motor_control_int_c2 = 0;
    LPTMR_ClearStatusFlags(LPTMR0, kLPTMR_TimerCompareFlag);
}

void init_RTC(void)
{
	 irtc_datetime_t datetime;

	 datetime.day     = 24;
	 datetime.month   = 7;
	 datetime.year    = 2024u;
	 datetime.hour    = 14;
	 datetime.minute  = 49;
	 datetime.second  = 00;
	 datetime.weekDay = 4;

	 CLOCK_SetupClk16KClocking(kCLOCK_Clk16KToVbat | kCLOCK_Clk16KToMain);

	 irtc_config_t irtcConfig;
	 IRTC_GetDefaultConfig(&irtcConfig);
	 IRTC_Init(RTC, &irtcConfig);
	 IRTC_SetDatetime(RTC, &datetime);
}

void init_ADCTemperature(void)
{
	static lpadc_conv_command_config_t LpadcCommandConfigStruct; /* Structure to configure conversion command. */
    lpadc_config_t lpadcConfigStruct;
    lpadc_conv_trigger_config_t lpadcTriggerConfigStruct;
    vref_config_t vrefConfig;
	// Enable ADC clock --------------------------
    CLOCK_SetClkDiv(kCLOCK_DivAdc0Clk, 1u);
    CLOCK_AttachClk(kFRO_HF_to_ADC0);
    // -------------------------------------------
    // Enable Vref -------------------------------
//    SPC0->ACTIVE_CFG1 |= 0x1;
//    VREF_GetDefaultConfig(&vrefConfig);
//    // Initialize the VREF mode.
//    VREF_Init(VREF0, &vrefConfig);
//    // Get a 1.8V reference voltage.
//    VREF_SetTrim21Val(VREF0, 8U);
    // -------------------------------------------

    /* Init ADC peripheral. */
    LPADC_GetDefaultConfig(&lpadcConfigStruct);
    lpadcConfigStruct.enableAnalogPreliminary = true;
    lpadcConfigStruct.powerLevelMode          = kLPADC_PowerLevelAlt4;
    lpadcConfigStruct.referenceVoltageSource = kLPADC_ReferenceVoltageAlt2;
    lpadcConfigStruct.conversionAverageMode = kLPADC_ConversionAverage128;
    lpadcConfigStruct.FIFO0Watermark = FSL_FEATURE_LPADC_TEMP_SENS_BUFFER_SIZE - 1U;
    LPADC_Init(ADC0, &lpadcConfigStruct);
    LPADC_DoResetFIFO0(ADC0);

    /* Do ADC calibration. */
    LPADC_SetOffsetValue(ADC0, 0x10u, 0x10u);
    LPADC_DoAutoCalibration(ADC0);

    /* Set conversion CMD configuration for temperature sensor. */
    LPADC_GetDefaultConvCommandConfig((lpadc_conv_command_config_t *) &LpadcCommandConfigStruct);
    LpadcCommandConfigStruct.channelNumber       = DEMO_LPADC_TEMP_SENS_CHANNEL;
    LpadcCommandConfigStruct.sampleChannelMode   = DEMO_LPADC_SAMPLE_TEMP_CHANNEL_MODE;
    LpadcCommandConfigStruct.sampleTimeMode      = kLPADC_SampleTimeADCK131;
    LpadcCommandConfigStruct.hardwareAverageMode = kLPADC_HardwareAverageCount128;
    LpadcCommandConfigStruct.loopCount = FSL_FEATURE_LPADC_TEMP_SENS_BUFFER_SIZE - 1U;
    LpadcCommandConfigStruct.conversionResolutionMode = kLPADC_ConversionResolutionHigh;
    LPADC_SetConvCommandConfig(ADC0, 1u, (lpadc_conv_command_config_t *) &LpadcCommandConfigStruct);

    /* Set trigger configuration. */
    LPADC_GetDefaultConvTriggerConfig(&lpadcTriggerConfigStruct);
    //LPADC_GetDefaultConvTriggerConfig(&lpadcTriggerConfigStruct2);
    lpadcTriggerConfigStruct.targetCommandId = 1u;
    //lpadcTriggerConfigStruct2.targetCommandId = DEMO_LPADC_USER_CMDID2;
    LPADC_SetConvTriggerConfig(ADC0, 0U, &lpadcTriggerConfigStruct); /* Configurate the trigger0. */

	LPADC_EnableInterrupts(ADC0, kLPADC_FIFO0WatermarkInterruptEnable);
    EnableIRQ(ADC0_IRQn);

    /* Eliminate the first two inaccurate results. */
    LPADC_DoSoftwareTrigger(ADC0, 1u); /* 1U is trigger0 mask. */
}

void measures_init()
{
	uint32_t lptmr_clock;
    lptmr_config_t lptmrConfig;
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);
	CLOCK_SetClkDiv(kCLOCK_DivI3c1FClk, 6U);
	CLOCK_AttachClk(kPLL0_to_I3C1FCLK);

	init_ADCTemperature();
	init_RTC();

	lptmr_clock = CLOCK_GetFreq(kCLOCK_Fro12M);
	g_max_count = MSEC_TO_COUNT(PERFORMANCE_TIMER_PERIOD_MS, lptmr_clock);
    P3T1755_InitTemperature();


    LPTMR_GetDefaultConfig(&lptmrConfig);
    lptmrConfig.prescalerClockSource = kLPTMR_PrescalerClock_0;
    lptmrConfig.enableFreeRunning = false;
    LPTMR_Init(LPTMR0, &lptmrConfig);
    LPTMR_SetTimerPeriod(LPTMR0, g_max_count);
    LPTMR_EnableInterrupts(LPTMR0, kLPTMR_TimerInterruptEnable);
    EnableIRQ(LPTMR0_IRQn);
    LPTMR_StartTimer(LPTMR0);
}

measure_updates_t measures_get_updates(void)
{
	measure_updates_t retval = g_measure_updates;
	g_measure_updates.accel_update = false;
	g_measure_updates.brd_temperature_update = false;
	g_measure_updates.date_update = false;
	g_measure_updates.mcu_temperature_update = false;
	g_measure_updates.performance_core1_update = false;
	g_measure_updates.performance_core2_update = false;
	g_measure_updates.rpm_update = false;
	g_measure_updates.time_update = false;
	g_measure_updates.touch_update = false;
	return retval;
}

measures_accel_t measures_get_accel_values(void)
{
	return g_measure_accel;
}

measures_performance_core1_t measures_get_performance_core1(void)
{
	return g_measure_performance_core1;
}

measures_performance_core2_t measures_get_performance_core2(void)
{
	return g_measure_performance_core2;
}

float32_t measures_get_electrode(void) // 0-3.3
{
	return g_measure_electrode;
}

float32_t measures_get_mcu_temperature(void)
{
	return g_measure_mcu_temperature;
}

float32_t measures_get_brd_temperature(void)
{
	return g_measure_brd_temperature;
}

measures_time_t measures_get_time(void)
{
	return g_measure_time;
}

measures_date_t measures_get_date(void)
{
	return g_measure_date;
}

int32_t	measures_get_rpm(void)
{
	return g_measure_rpm;
}

void measures_set_time(measures_time_t time)
{
	 static irtc_datetime_t datetime;

	 irtc_config_t irtcConfig;

	 IRTC_GetDatetime(RTC, &datetime);
	 if(time.hours == 12 && time.meridian == k_measures_screen_am)
	 {
		 datetime.hour = 0;
	 }
	 else if(time.hours == 12)
	 {
		 datetime.hour = 12;
	 }
	 else
	 {
		 datetime.hour =  (time.meridian == k_measures_screen_am)? time.hours:time.hours+12;
	 }
	 datetime.minute  = time.minutes;
	 datetime.second  = 0;
	 IRTC_Deinit(RTC);
	 IRTC_GetDefaultConfig(&irtcConfig);
	 IRTC_Init(RTC, &irtcConfig);
	 IRTC_SetDatetime(RTC, &datetime);
}

// Task in --------------------------------
void measures_idle_core1_task_in(void)
{
	g_measure_performance_start_idle_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

void measures_ethernet_task_in(void)
{
	g_measure_performance_start_ethernet_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

void measures_lvgl_task_in(void)
{
	g_measure_performance_start_lvgl_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

void measures_sensor_task_in(void)
{
	g_measure_performance_start_sensors_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

void measures_idle_core2_task_in(void)
{
	g_measure_performance_start_idle_c2 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

void measures_motor_control_task_in(void)
{
	g_measure_performance_start_motor_control_c2 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

void measures_motor_control_int_in(void)
{
	g_measure_performance_start_motor_control_int_c2 = LPTMR_GetCurrentTimerCount(LPTMR0);
}

// Task out -----------------------------
void measures_idle_core1_task_out(void)
{
	if(g_measure_performance_start_idle_c1)
	{
		g_measure_performance_end_idle_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
		g_measure_performance_idle_c1 += (g_measure_performance_end_idle_c1 - g_measure_performance_start_idle_c1);
	}
}

void measures_ethernet_task_out(void)
{
	if(g_measure_performance_start_ethernet_c1)
	{
		g_measure_performance_end_ethernet_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
		g_measure_performance_ethernet_c1 += (g_measure_performance_end_ethernet_c1 - g_measure_performance_start_ethernet_c1);
	}
}

void measures_lvgl_task_out(void)
{
	if(g_measure_performance_start_lvgl_c1)
	{
		g_measure_performance_end_lvgl_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
		g_measure_performance_lvgl_c1 += (g_measure_performance_end_lvgl_c1 - g_measure_performance_start_lvgl_c1);
	}
}

void measures_sensor_task_out(void)
{
	if(g_measure_performance_start_sensors_c1)
	{
		g_measure_performance_end_sensors_c1 = LPTMR_GetCurrentTimerCount(LPTMR0);
		g_measure_performance_sensors_c1 += (g_measure_performance_end_sensors_c1 - g_measure_performance_start_sensors_c1);
	}
}

void measures_idle_core2_task_out(void)
{
	if(g_measure_performance_start_idle_c2)
	{
		g_measure_performance_end_idle_c2 = LPTMR_GetCurrentTimerCount(LPTMR0);
		g_measure_performance_idle_c2 += (g_measure_performance_end_idle_c2 - g_measure_performance_start_idle_c2);
	}
}

void measures_motor_control_task_out(void)
{
	if(g_measure_performance_start_motor_control_c2)
	{
		g_measure_performance_end_motor_control_c2 = LPTMR_GetCurrentTimerCount(LPTMR0);
		g_measure_performance_motor_control_c2 += (g_measure_performance_end_motor_control_c2 - g_measure_performance_start_motor_control_c2);
	}
}

void measures_motor_control_int_out(void)
{
	if(g_measure_performance_start_motor_control_int_c2)
	{
		g_measure_performance_end_motor_control_int_c2 = LPTMR_GetCurrentTimerCount(LPTMR0);
		if(g_measure_performance_start_motor_control_int_c2 > g_measure_performance_end_motor_control_int_c2)
		{
			g_measure_performance_motor_control_int_c2 += (g_max_count + g_measure_performance_end_motor_control_int_c2 - g_measure_performance_start_motor_control_int_c2);
		}
		else
		{
			g_measure_performance_motor_control_int_c2 += (g_measure_performance_end_motor_control_int_c2 - g_measure_performance_start_motor_control_int_c2);
		}
	}
}

void measure_accel_update(void)
{
	float32_t x_accel;
	float32_t y_accel;
	float32_t z_accel;

	if(!Accel4Click_isReady())
	{
		g_measure_updates.accel_update = true;
		Accel4Click_init();
	}
	else
	{
		Accel4Click_get_x_acceleration(&x_accel);
		Accel4Click_get_y_acceleration(&y_accel);
		Accel4Click_get_z_acceleration(&z_accel);
		if(g_measure_accel.accelX != x_accel)
		{
			g_measure_accel.accelX = x_accel;
			g_measure_updates.accel_update = true;
		}
		if(g_measure_accel.accelY != y_accel)
		{
			g_measure_accel.accelY = y_accel;
			g_measure_updates.accel_update = true;
		}
		if(g_measure_accel.accelZ != z_accel)
		{
			g_measure_accel.accelZ = z_accel;
			g_measure_updates.accel_update = true;
		}
	}
}

void measure_update_electrode()
{

}

void measure_update_mcu_temperature()
{
    LPADC_DoSoftwareTrigger(ADC0, 1u); /* 1U is trigger0 mask. */
}

void measure_update_brd_temperature()
{
	float32_t temperature = (float32_t)P3T1755_get_temperature();
	if(temperature != g_measure_brd_temperature)
	{
		g_measure_brd_temperature = temperature;
		g_measure_updates.brd_temperature_update = true;
	}
}

void measure_update_rpm()
{
	float32_t rpm;
	rpm = motor_control_get_speed();
	g_measure_updates.rpm_update = true;
	g_measure_rpm = (int32_t)rpm;
}

void measure_update_time()
{
	static uint8_t previus_seconds = 0;
	irtc_datetime_t datetime;

	IRTC_GetDatetime(RTC, &datetime);
	if(previus_seconds != datetime.second)
	{
		if(datetime.hour > 11)
		{
			g_measure_time.meridian = k_measures_screen_pm;
			if(datetime.hour == 12)
			{
				g_measure_time.hours = 12;
			}
			else
			{
				g_measure_time.hours = datetime.hour - 12;
			}
		}
		else
		{
			g_measure_time.meridian = k_measures_screen_am;
			if(datetime.hour == 0)
			{
				g_measure_time.hours = 12;
			}
			else
			{
				g_measure_time.hours = datetime.hour;
			}
		}
		g_measure_time.minutes = datetime.minute;
		g_measure_time.seconds = datetime.second;
		g_measure_date.day = datetime.day;
		g_measure_date.month = datetime.month;
		g_measure_date.year = datetime.year;
		g_measure_updates.date_update = true;
		g_measure_updates.time_update = true;
	}
}

uint8_t measuresAccelIsReady()
{
	return Accel4Click_isReady();
}

void measures_task(void *args)
{
	accel4click_sys_mode_val_t sys_mode;

	vTaskSetApplicationTaskTag( NULL, ( void * ) 2);/*Task Tag*/

	g_I2Cdrv->Initialize(I2C3_SignalEvent_t);
	g_I2Cdrv->PowerControl(ARM_POWER_FULL);
	g_I2Cdrv->Control(ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_FAST);
	// ------------------------------------------------
	set_transfer_function(i2c_transfer);
	Accel4Click_init();
	Accel4Click_get_system_status_reg(&sys_mode);
	while(1)
	{
		measure_accel_update();
		measure_update_electrode();
		measure_update_mcu_temperature();
		measure_update_brd_temperature();
		measure_update_rpm();
		measure_update_time();
		vTaskDelay(30);
	}
}
