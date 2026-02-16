/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "eth_comunication.h"
#include "fsl_clock.h"
#include "pin_mux.h"
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "screen.h"
#include "measures.h"
#include "screen_app.h"
#include "motor_control.h"
#include "usb_comunication.h"
#include "can_comunication.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
void idle_task(void* args);

int main()
{
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
    BOARD_I2C_ReleaseBus();
	BOARD_InitDebugConsole();

	CLOCK_SetupClockCtrl(kCLOCK_FRO12MHZ_ENA);
	
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);

    CLOCK_SetClkDiv(kCLOCK_DivFlexioClk, 1u);
    CLOCK_AttachClk(kPLL0_to_FLEXIO);

    CLOCK_SetupExtClocking(BOARD_XTAL0_CLK_HZ);

    measures_init();
    comunication_init();
    BOARD_InitSmartDMA();
    screen_setCallback(screenEventCallback);
    motor_control_init();
	motor_control_stop();

	xTaskCreate(screenTask, "screen", configMINIMAL_STACK_SIZE + 1500, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(usb_task, "usb_task", configMINIMAL_STACK_SIZE + 1000, NULL, tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(can_comunication_task, "can_task", configMINIMAL_STACK_SIZE + 500, NULL, tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(measures_task, "measures", configMINIMAL_STACK_SIZE + 500, NULL, tskIDLE_PRIORITY + 1, NULL);
	xTaskCreate(motor_control_task, "motor_control", configMINIMAL_STACK_SIZE + 500, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(idle_task, "idle", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
	vTaskStartScheduler();
	while(1)
	{

	}
	return 0;
}



void vApplicationTickHook(void)
{
	screenTick();
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
   PRINTF("Stack Overflow\r\n");
    while(1);
}

void vApplicationMallocFailedHook(void)
{
	PRINTF("Malloc Fail\r\n");
    while(1);
}

void idle_task(void* args)
{
	vTaskSetApplicationTaskTag( NULL, ( void * ) 0);/*Task Tag*/

	while(1)
	{
		vTaskDelay(10);
	}
}
