/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mikroe_accel_4_click.h"

#define ADDRESS		0x18

// READ DATA --------------------------------------
#define INT_STATUS 	0X00
#define TEMP_OUT 	0X01
#define VECM_LSB 	0X02
#define VECM_MSB 	0X03
#define OUT_X_LSB 	0X04
#define OUT_X_MSB 	0X05
#define OUT_Y_LSB 	0X06
#define OUT_Y_MSB 	0X07
#define OUT_Z_LSB	0X08
#define OUT_Z_MSB 	0X09

// OUTPUT BUFFER CONFIG AND STATUS ----------------
#define BUFF_STATUS 0X0B
#define BUFF_X_LSB 0X0C
#define BUFF_X_MSB 0X0D
#define BUFF_Y_LSB 0X0E
#define BUFF_Y_MSB 0X0F
#define BUFF_Z_LSB 0X10
#define BUFF_Z_MSB 0X11

// DEVICE IDENTIFICATION --------------------------
#define PROD_REV 0X12
#define WHO_AM_I 0X13

// SYSTEM STATUS REGISTER -------------------------
#define SYS_MODE 0X14

// DEVICE CONFIG ----------------------------------
#define SENS_CONFIG1 0X15
#define SENS_CONFIG2 0X16
#define SENS_CONFIG3 0X17
#define SENS_CONFIG4 0X18
#define SENS_CONFIG5 0X19
#define WAKE_IDLE_LSB 0X1A
#define WAKE_IDLE_MSB 0X1B
#define SLEEP_IDLE_LSB 0X1C
#define SLEEP_IDLE_MSB 0X1D
#define ASLP_COUNT_LSB 0X1E
#define ASLP_COUNT_MSB 0X1F
#define INT_EN 0X20
#define INT_PIN_SEL 0X21

// ZERO -G OFFSET COMPENSATION REGISTERS ----------
#define OFF_X 0X22
#define OFF_Y 0X23
#define OFF_Z 0X24

// OUTPUT BUFFER CONFIG ---------------------------
#define BUFF_CONFIG1 0X26
#define BUFF_CONFIG2 0X27

// ORIENTATION DETECTION FUNC, CONFIG AND STATUS --
#define ORIENT_STATUS 0X28
#define ORIENT_CONFIG 0X29
#define ORIENT_DB_COUNT 0X2A
#define ORIENT_BF_ZCOUNT 0X2B
#define ORIENT_THS_REG 0X2C

// SENSOR DATA CHANGE DETECTION, CONFIG AND STATUS
#define SDCD_INT_SRC1 0X2D
#define SDCD_INT_SRC2 0X2E
#define SDCD_CONFIG1 0X2F
#define SDCD_CONFIG2 0X30
#define SDCD_OT_DBCNT 0X31
#define SDCD_WT_DBCNT 0X32
#define SDCD_LTHS_LSB 0X33
#define SDCD_LTHS_MSB 0X34
#define SDCD_UTHS_LSB 0X35
#define SDCD_UTHS_MSB 0X36
#define SELF_TEST_CONFIG1 0X37
#define SELF_TEST_CONFIG2 0X38
// -------------------------------------------------

#define WAKE_SLEEP_ACCEL_PERIOD_MS 	0.3125
#define MAX_MS_TO_WAKE_SLEEP		1280

static accel4click_i2c_transfer g_transfer_function = 0;

static uint8_t					g_accel_initialized = 0;

// I2C functions -------------------------------------------------------------------------------


void set_transfer_function(accel4click_i2c_transfer function)
{
	g_transfer_function = function;
}
// ---------------------------------------------------------------------------------------------

accel4click_status_t Accel4Click_init()
{
	accel4click_status_t status;
	status = Accel4Click_do_software_reset();
	if(!status)
	{
		status |= Accel4Click_set_full_scale_range(k_range_2g);
		status |= Accel4Click_set_operating_mode(k_accel_active_mode);
		if(!status) g_accel_initialized = 1;
	}
	return status;
}

uint8_t Accel4Click_isReady()
{
	return g_accel_initialized;
}

// CONFIG FUNCTIONS ----------------------------------------------------------------------------
accel4click_status_t Accel4Click_do_software_reset()
{
	accel4click_status_t retval;
	uint8_t data = 0x80;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_write);
	if(retval == 0)
	{
		do
		{
			retval = g_transfer_function(ADDRESS, INT_STATUS, &data, 1, k_accel_read);
		}while(!(data & 0x01));
	}
	return retval;
}

accel4click_status_t Accel4Click_do_self_test_axis(accel4click_axis_t option, accel4click_displacement_polarity_t polarity)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x07<<4);
		data |= ((((uint8_t)polarity)<<4)|(((uint8_t)option)<<5));
		retval = g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_full_scale_range(accel4click_full_scale_range_t range)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x03<<1);
		data |= (((uint8_t)range)<<1);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_operating_mode(accel4click_modes_t mode)
{
	accel4click_status_t status;
	uint8_t data;
	status 	= g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_read);
	if(!status)
	{
		data	&= ~(0x01);
		data 	|= mode;
		status 	= g_transfer_function(ADDRESS, SENS_CONFIG1, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_Wake_mode(accel4click_power_modes_t mode)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x03<<6);
		data |= (((uint8_t)mode)<<6);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_Sleep_mode(accel4click_power_modes_t mode)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x03<<4);
		data |= (((uint8_t)mode)<<4);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_in_little_endian()
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x01<<3);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_in_big_endian()
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_read);
	if(!retval)
	{
		data |= (0x01<<3);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_normal_read_mode()
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x01<<0);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_fast_read_mode()
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_read);
	if(!retval)
	{
		data |= (0x01<<0);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_wake_decimation_option(accel4click_decimation_options_t option)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG3, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x0F<<4);
		data |= (((uint8_t)option)<<4);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG3, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_sleep_decimation_option(accel4click_decimation_options_t option)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG3, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x0F<<0);
		data |= (((uint8_t)option)<<0);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG3, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_ex_trigger_as_single_ADC_sample()
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!retval)
	{
		data &= ~(0x01<<7);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_set_ex_trigger_as_multiple_ADC_sample()
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!retval)
	{
		data |= (0x01<<7);
		retval = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_enable_auto_wake_sdcd_within_treshold(bool enable)
{
	accel4click_status_t retval;
	uint8_t data;
	retval = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!retval)
	{
		data = (enable)? data|(0x01<<6):data&(~(0x01<<6));
		retval = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return retval;
}

accel4click_status_t Accel4Click_enable_auto_wake_sdcd_outside_treshold(bool enable)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data = (enable)? data|(0x01<<6):data&(~(0x01<<5));
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_enable_auto_wake_change_orientation(bool enable)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data = (enable)? data|(0x01<<6):data&(~(0x01<<4));
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_int2_pin_as_int2()
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data &= ~(0x01<<2);
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_int2_pin_as_ext_trigger()
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data |= (0x01<<2);
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_enable_open_drain_source_on_int_pin()
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data |= (0x01<<1);
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_disable_open_drain_source_on_int_pin()
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data &= ~(0x01<<1);
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_int_pin_active_high()
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data |= (0x01<<0);
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_int_pin_active_low()
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_read);
	if(!status)
	{
		data &= ~(0x01<<0);
		status = g_transfer_function(ADDRESS, SENS_CONFIG4, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_wake_time(uint16_t milliseconds)
{
	accel4click_status_t status = -1;
	uint16_t count;
	if(MAX_MS_TO_WAKE_SLEEP < milliseconds)
	{
		count = milliseconds / WAKE_SLEEP_ACCEL_PERIOD_MS;
		status = g_transfer_function(ADDRESS, WAKE_IDLE_LSB, (uint8_t*)&count, 2, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_sleep_time(uint16_t milliseconds)
{
	accel4click_status_t status = -1;
	uint16_t count;
	if(MAX_MS_TO_WAKE_SLEEP < milliseconds)
	{
		count = milliseconds / WAKE_SLEEP_ACCEL_PERIOD_MS;
		status = g_transfer_function(ADDRESS, SLEEP_IDLE_LSB, (uint8_t*)&count, 2, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_inactivity_time_to_sleep_time(uint16_t count)
{
	accel4click_status_t status = -1;

	status = g_transfer_function(ADDRESS, ASLP_COUNT_LSB, (uint8_t*)&count, 2, k_accel_write);

	return status;
}

accel4click_status_t Accel4Click_set_interrupt_to_pin(accel4click_interrupt_enable_t interrupt, accel4click_interrupt_pins_t pin)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, INT_PIN_SEL, &data, 1, k_accel_read);
	if(!status)
	{
		data = (pin == k_int1_pin)? (data&(~((uint8_t)interrupt))):(data|((uint8_t)interrupt));
		status = g_transfer_function(ADDRESS, INT_PIN_SEL, &data, 1, k_accel_write);
	}
	return status;
}

accel4click_status_t Accel4Click_set_x_offset(uint8_t offset)
{
	accel4click_status_t status;

	status = g_transfer_function(ADDRESS, OFF_X, (uint8_t*)&offset, 1, k_accel_write);

	return status;
}

accel4click_status_t Accel4Click_set_y_offset(uint8_t offset)
{
	accel4click_status_t status;

	status = g_transfer_function(ADDRESS, OFF_Y, (uint8_t*)&offset, 1, k_accel_write);

	return status;
}

accel4click_status_t Accel4Click_set_z_offset(uint8_t offset)
{
	accel4click_status_t status;

	status = g_transfer_function(ADDRESS, OFF_Z, (uint8_t*)&offset, 1, k_accel_write);

	return status;
}

accel4click_status_t Accel4Click_set_buff_config(accel4click_buff_config_t *buff_config)
{
	accel4click_status_t retval;
	uint8_t data = 0;

	data = ((uint8_t)buff_config->buff_read_order)<<7;
	data |= ((uint8_t)buff_config->buff_mode)<<5;
	data |= ((uint8_t)buff_config->buff_gate)<<4;
	data |= ((uint8_t)buff_config->sdcd_within_threshold_trigger)<<3;
	data |= ((uint8_t)buff_config->sdcd_outside_threshold_trigger)<<2;
	data |= ((uint8_t)buff_config->orientation_change_trigger);

	retval = g_transfer_function(ADDRESS, BUFF_CONFIG1, &data, 1, k_accel_write);

	if(!retval)
	{
		data = ((uint8_t)buff_config->buff_flush_enable)<<7;
		data |= ((uint8_t)buff_config->wake_to_sleep_on_buff_event)<<6;
		data |= ((uint8_t)buff_config->buff_watermark)&0x3F;
		retval = g_transfer_function(ADDRESS, BUFF_CONFIG2, &data, 1, k_accel_write);
	}
	return retval;
}
// TODO: ORIENT CONFIG

// TODO: SDCD CONFIG
// ---------------------------------------------------------------------------------------------

// GETTERS -------------------------------------------------------------------------------------
accel4click_status_t Accel4Click_get_rev(uint8_t *retval)
{
	accel4click_status_t status;
	status = g_transfer_function(ADDRESS, PROD_REV, retval, 1, k_accel_read);
	return status;
}

accel4click_status_t Accel4Click_get_id(uint8_t *retval)
{
	accel4click_status_t status;
	status = g_transfer_function(ADDRESS, WHO_AM_I, retval, 1, k_accel_read);
	return status;
}

accel4click_status_t Accel4Click_get_system_status_reg(accel4click_sys_mode_val_t *retval)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, SYS_MODE, &data, 1, k_accel_read);
	retval->buff_gate_count = (data>>2)&0x1F;
	retval->sys_mode		= data&0x03;
	retval->buff_mode		= data >> 7;
	return status;
}

accel4click_status_t Accel4Click_get_status_flags(accel4click_status_interrupt_t *retval)
{
	accel4click_status_t status;
	status = g_transfer_function(ADDRESS, INT_STATUS, (uint8_t*)retval, 1, k_accel_read);
	return status;
}

accel4click_status_t Accel4Click_get_temperature(float32_t *retval)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, TEMP_OUT, &data, 1, k_accel_read);
	*retval = data + 25;
	return status;
}


float32_t get_lsb_val()
{
	accel4click_status_t status;
	float32_t lsb_val = 0;
	uint16_t data;
	status = g_transfer_function(ADDRESS, SENS_CONFIG1, (uint8_t*)&data, 1, k_accel_read);
	if(!status)
	{
		data = (data >> 1) & 0x03;
		if(0x00 == data) 		lsb_val = 0.0096138;
		else if(0x01 == data) 	lsb_val = 0.0191295;
		else if(0x02 == data) 	lsb_val = 0.0383571;
		else 					lsb_val = 0.0766161;
	}
	return lsb_val;
}

accel4click_status_t Accel4Click_get_vector_magnitude(float32_t *retval)
{
	accel4click_status_t status = -1;
	float32_t lsb_val;
	uint16_t data;
	lsb_val = get_lsb_val();
	if(0.0 != lsb_val)
	{
		status = g_transfer_function(ADDRESS, VECM_LSB, (uint8_t*)&data, 2, k_accel_read);
		if(status)
		{
			g_accel_initialized = false;
		}
		*retval = data * lsb_val;
	}
	return status;
}
accel4click_status_t Accel4Click_get_x_acceleration(float32_t *retval)
{
	accel4click_status_t status = -1;
	float32_t lsb_val;
	int16_t data;
	lsb_val = get_lsb_val();
	if(0.0 != lsb_val)
	{
		status = g_transfer_function(ADDRESS, OUT_X_LSB, (uint8_t*)&data, 2, k_accel_read);
		if(status)
		{
			g_accel_initialized = false;
		}
		*retval = data * lsb_val;
	}
	return status;
}

accel4click_status_t Accel4Click_get_y_acceleration(float32_t *retval)
{
	accel4click_status_t status = -1;
	float32_t lsb_val;
	int16_t data;
	lsb_val = get_lsb_val();
	if(0.0 != lsb_val)
	{
		status = g_transfer_function(ADDRESS, OUT_Y_LSB, (uint8_t*)&data, 2, k_accel_read);
		if(status)
		{
			g_accel_initialized = false;
		}
		*retval = data * lsb_val;
	}
	return status;
}

accel4click_status_t Accel4Click_get_z_acceleration(float32_t *retval)
{
	accel4click_status_t status = -1;
	float32_t lsb_val;
	int16_t data;
	lsb_val = get_lsb_val();
	if(0.0 != lsb_val)
	{
		status = g_transfer_function(ADDRESS, OUT_Z_LSB, (uint8_t*)&data, 2, k_accel_read);
		if(status)
		{
			g_accel_initialized = false;
		}
		*retval = data * lsb_val;
	}
	return status;
}

accel4click_status_t Accel4Click_get_accelerations(accel4click_accelerations_t *retval)
{
	accel4click_status_t status = -1;
	float32_t lsb_val;
	int16_t data[3];
	lsb_val = get_lsb_val();
	if(0.0 != lsb_val)
	{
		status = g_transfer_function(ADDRESS, OUT_X_LSB, (uint8_t*)data, 6, k_accel_read);
		if(status)
		{
			g_accel_initialized = false;
		}
		retval->x = data[0] * lsb_val;
		retval->y = data[1] * lsb_val;
		retval->z = data[2] * lsb_val;
	}
	return status;
}

// BUFFER GET FUNCTIONS -------------------------
accel4click_status_t Accel4Click_get_buff_status_flags(accel4click_status_buff_t *retval)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, BUFF_STATUS, &data, 1, k_accel_read);
	*((uint8_t*)retval) = (data & 0xC0);
	return status;
}

accel4click_status_t Accel4Click_get_buff_counter(uint8_t *retval)
{
	accel4click_status_t status;
	uint8_t data;
	status = g_transfer_function(ADDRESS, BUFF_STATUS, &data, 1, k_accel_read);
	if(status)
	{
		g_accel_initialized = false;
	}
	*retval = (data & 0x3F);
	return status;
}

accel4click_status_t Accel4Click_get_buff_x_acceleration(float32_t *retval, uint8_t elements)
{
	return -1;
}

accel4click_status_t Accel4Click_get_buff_y_acceleration(float32_t *retval, uint8_t elements)
{
	return -1;
}

accel4click_status_t Accel4Click_get_buff_z_acceleration(float32_t *retval, uint8_t elements)
{
	return -1;
}
// ----------------------------------------------

// ---------------------------------------------------------------------------------------------


