/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2022, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "fsl_flexcan.h"
#include "can_comunication.h"
#include "motor_control.h"
#include "eth_comunication.h"
#include "screen_app.h"
#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define USE_CANFD             (1)
#define EXAMPLE_CAN           CAN0
#define RX_MESSAGE_BUFFER_NUM (0)
#define TX_MESSAGE_BUFFER_NUM (1)

#define EXAMPLE_CAN_CLK_FREQ       CLOCK_GetFlexcanClkFreq(0U)
#define USE_IMPROVED_TIMING_CONFIG (1)


/*
 *    DWORD_IN_MB    DLC    BYTES_IN_MB             Maximum MBs
 *    2              8      kFLEXCAN_8BperMB        64
 *    4              10     kFLEXCAN_16BperMB       42
 *    8              13     kFLEXCAN_32BperMB       25
 *    16             15     kFLEXCAN_64BperMB       14
 *
 * Dword in each message buffer, Length of data in bytes, Payload size must align,
 * and the Message Buffers are limited corresponding to each payload configuration:
 */
#define DLC         (15)
#define BYTES_IN_MB kFLEXCAN_64BperMB


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint8_t can_data_length_to_dlc(uint8_t length);

/*******************************************************************************
 * Variables
 ******************************************************************************/
flexcan_handle_t flexcanHandle;
volatile bool txComplete = true;
volatile bool rxComplete = false;
volatile bool wakenUp    = false;
flexcan_mb_transfer_t txXfer, rxXfer;
flexcan_fd_frame_t frame;

uint32_t txIdentifier = 0x123;;
uint32_t rxIdentifier = 0x321;
comunication_transfer_can_usb_t g_ip_can_comunication_snd;
comunication_transfer_can_usb_t *g_ip_can_comunication_rcv;
comunication_transfer_t			g_eth_ip_comunication;
TaskHandle_t g_can_task_handler;
/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Calculate DLC value based on the given data length on bytes
 *
 * @param   Length on bytes of the data.
 * @return  dlc - Calculated CAN DLC
 */
static uint8_t can_data_length_to_dlc(uint8_t length)
{
	uint8_t dlc;

	/* Check the length in bytes */
	if(length > 32)
	{
		dlc = 15;
	}
	else if(length > 16)
	{
		dlc = 13;
	}
	else if(length > 8)
	{
		dlc = 10;
	}
	else
	{
		/* If less than 8 DLC must be same size as the length in bytes*/
		dlc = length;
	}

	/* Return DLC value */
	return(dlc);

}

/*!
 * @brief FlexCAN Call Back function
 */
static FLEXCAN_CALLBACK(flexcan_callback)
{
    switch (status)
    {
        case kStatus_FLEXCAN_RxIdle:
            if (RX_MESSAGE_BUFFER_NUM == result)
            {
            	xTaskResumeFromISR(g_can_task_handler);
            }
            break;

        case kStatus_FLEXCAN_TxIdle:
            if (TX_MESSAGE_BUFFER_NUM == result)
            {
                txComplete = true;
            }
            break;

        case kStatus_FLEXCAN_WakeUp:
            wakenUp = true;
            break;

        default:
            break;
    }
}

/*!
 * @brief FlexCAN Init function
 *
 * @param none
 */
void can_init(void)
{
    flexcan_config_t flexcanConfig;
    flexcan_rx_mb_config_t mbConfig;

    /* attach PLL1Clk0 to FLEXCAN0 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcan0Clk, 1U);
    CLOCK_AttachClk(kPLL0_to_FLEXCAN0);

    /* Get FlexCAN module default Configuration. */
    /*
     * flexcanConfig.clkSrc                 = kFLEXCAN_ClkSrc0;
     * flexcanConfig.bitRate               = 1000000U;
     * flexcanConfig.bitRateFD             = 2000000U;
     * flexcanConfig.maxMbNum               = 16;
     * flexcanConfig.enableLoopBack         = false;
     * flexcanConfig.enableSelfWakeup       = false;
     * flexcanConfig.enableIndividMask      = false;
     * flexcanConfig.disableSelfReception   = false;
     * flexcanConfig.enableListenOnlyMode   = false;
     * flexcanConfig.enableDoze             = false;
     */
    FLEXCAN_GetDefaultConfig(&flexcanConfig);

    flexcanConfig.bitRate = 1000000U;
    flexcanConfig.bitRateFD = 2000000U;

#if defined(EXAMPLE_CAN_CLK_SOURCE)
    flexcanConfig.clkSrc = EXAMPLE_CAN_CLK_SOURCE;
#endif

#if defined(EXAMPLE_CAN_BIT_RATE)
    flexcanConfig.bitRate = EXAMPLE_CAN_BIT_RATE;
#endif

/* If special quantum setting is needed, set the timing parameters. */
#if (defined(SET_CAN_QUANTUM) && SET_CAN_QUANTUM)
    flexcanConfig.timingConfig.phaseSeg1 = PSEG1;
    flexcanConfig.timingConfig.phaseSeg2 = PSEG2;
    flexcanConfig.timingConfig.propSeg   = PROPSEG;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
    flexcanConfig.timingConfig.fphaseSeg1 = FPSEG1;
    flexcanConfig.timingConfig.fphaseSeg2 = FPSEG2;
    flexcanConfig.timingConfig.fpropSeg   = FPROPSEG;
#endif
#endif

#if (defined(USE_IMPROVED_TIMING_CONFIG) && USE_IMPROVED_TIMING_CONFIG)
    flexcan_timing_config_t timing_config;
    memset(&timing_config, 0, sizeof(flexcan_timing_config_t));
    if (FLEXCAN_FDCalculateImprovedTimingValues(EXAMPLE_CAN, flexcanConfig.bitRate, flexcanConfig.bitRateFD,
                                                EXAMPLE_CAN_CLK_FREQ, &timing_config))
    {
        /* Update the improved timing configuration*/
        memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
    else
    {
    }

#endif

    FLEXCAN_FDInit(EXAMPLE_CAN, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ, BYTES_IN_MB, true);


    /* Create FlexCAN handle structure and set call back function. */
    FLEXCAN_TransferCreateHandle(EXAMPLE_CAN, &flexcanHandle, flexcan_callback, NULL);

    /* Set Rx Masking mechanism. */
    FLEXCAN_SetRxMbGlobalMask(EXAMPLE_CAN, FLEXCAN_RX_MB_STD_MASK(rxIdentifier, 0, 0));

    /* Setup Rx Message Buffer. */
    mbConfig.format = kFLEXCAN_FrameFormatStandard;
    mbConfig.type   = kFLEXCAN_FrameTypeData;
    mbConfig.id     = FLEXCAN_ID_STD(rxIdentifier);
    FLEXCAN_SetFDRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);


/* Setup Tx Message Buffer. */
    FLEXCAN_SetFDTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);

    /* Start receive data through Rx Message Buffer. */
//    rxXfer.mbIdx = (uint8_t)RX_MESSAGE_BUFFER_NUM;
//    rxXfer.framefd = &frame;

//    (void)FLEXCAN_TransferFDReceiveNonBlocking(EXAMPLE_CAN, &flexcanHandle, &rxXfer);

}

/*!
 * @brief CAN transmission function. Will send the CAN Message with the
 *        given data.
 *
 * @param data - pointer to data message
 * @param length - size in bytes of the data
 */
void can_tx_char_data(uint8_t *data, uint8_t char_length)
{
	uint8_t i;
	uint32_t *ptrdatabuffer = (uint32_t *)frame.dataWord;
	uint32_t *datasource = (uint32_t *)data;

	/* Check if there is no Tx pending */
//	if(txComplete == true)
//	{

		frame.id     = FLEXCAN_ID_STD(txIdentifier);
		frame.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
		frame.type   = (uint8_t)kFLEXCAN_FrameTypeData;
		frame.length = can_data_length_to_dlc(char_length);
		frame.brs = 1U;
		frame.edl = 1U;
		txXfer.mbIdx = (uint8_t)TX_MESSAGE_BUFFER_NUM;
		txXfer.framefd = &frame;

		for(i=0;i<(char_length/4);i++)
		{
		   ptrdatabuffer[i] = datasource[i];
		}


		(void)FLEXCAN_TransferFDSendNonBlocking(EXAMPLE_CAN, &flexcanHandle, &txXfer);

		/* Use this variable as flag to wait until Tx was completed*/
		txComplete = false;

//	}



}

/*!
 * @brief CAN reception task. Once the CAN message was received it will be process
 *        in this function and will active reception again.
 *        given data.
 *
 * @param data - double pointer to return the pointer to the data buffer
 * @param char_length - Pointer to variable to return length in bytes
 */
uint32_t can_rx_task(uint8_t **data ,uint8_t *char_length)
{
	uint32_t status;

	/* Start receive data through Rx Message Buffer. */
	rxXfer.mbIdx = (uint8_t)RX_MESSAGE_BUFFER_NUM;
	rxXfer.framefd = &frame;

	status = FLEXCAN_TransferFDReceiveNonBlocking(EXAMPLE_CAN, &flexcanHandle, &rxXfer);

	*data = (uint8_t *)&(rxXfer.framefd->dataWord[0]);

	return status;
}

/*!
 * @ Return the CAN Reception Status
 *
 * @return Reception status.
 */
bool get_can_rx_status(void)
{
	return rxComplete;
}

void can_send_to_ip(uint16_t slider, int16_t rpm)
{
	uint8_t size;
	build_indutrialpanel_rpm_update((uint8_t*)&g_ip_can_comunication_snd, &size, slider, rpm);
	can_tx_char_data((uint8_t*)&g_ip_can_comunication_snd, size);
}

void can_comunication_task(void *arg)
{
	uint8_t size;
	uint16_t slider_value;
	int16_t rpm_value;
	while(1)
	{
		can_rx_task((uint8_t**)&g_ip_can_comunication_rcv, &size);
		g_can_task_handler = xTaskGetCurrentTaskHandle();
		vTaskSuspend(NULL);
		if(g_ip_can_comunication_rcv->comunication_command == k_comunication_command_set_rpm_req)
		{
			slider_value = g_ip_can_comunication_rcv->comunication_motor_data.comunication_motor_rpm_slider;
			rpm_value = g_ip_can_comunication_rcv->comunication_motor_data.comunication_motor_rpm;
			if(screenApp_getDemoMode() == k_screen_app_master)
			{
				screen_setRPMSlider(slider_value);
				motor_control_set_speed(rpm_value);
			}
			else
			{
				g_eth_ip_comunication.comunication_command = k_comunication_command_send_rpm;
				g_eth_ip_comunication.comunication_data.comunication_motor.comunication_motor_rpm_slider = g_ip_can_comunication_rcv->comunication_motor_data.comunication_motor_rpm_slider;
				g_eth_ip_comunication.comunication_data.comunication_motor.comunication_motor_rpm = g_ip_can_comunication_rcv->comunication_motor_data.comunication_motor_rpm;
				comunication_send(comunication_get_socket(0), (uint8_t*)&g_eth_ip_comunication, sizeof(comunication_transfer_t), 0);
			}
		}
	}
}


