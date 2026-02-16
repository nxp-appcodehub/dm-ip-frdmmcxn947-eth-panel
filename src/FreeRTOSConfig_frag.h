/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FREERTOS_CONFIG_FRAG_H
#define FREERTOS_CONFIG_FRAG_H

#include "measures.h"


volatile static int value = 0;

#define traceTASK_SWITCHED_IN()					\
{												\
	switch((int)pxCurrentTCB->pxTaskTag)		\
	{											\
		case 0:									\
			measures_idle_core1_task_in();		\
		break;									\
												\
		case 1:									\
			measures_lvgl_task_in();			\
		break;									\
												\
		case 2:						     		\
			measures_sensor_task_in();			\
		break;									\
												\
		case 3:						     		\
			measures_ethernet_task_in();		\
		break;									\
												\
		case 4:						     		\
			measures_motor_control_task_in();	\
		break;									\
	}											\
}


#define traceTASK_SWITCHED_OUT()				\
{												\
	switch((int)pxCurrentTCB->pxTaskTag)		\
	{											\
		case 0:									\
			measures_idle_core1_task_out();		\
		break;									\
												\
		case 1:									\
			measures_lvgl_task_out();			\
		break;									\
												\
		case 2:						     		\
			measures_sensor_task_out();			\
		break;									\
												\
		case 3:						     		\
			measures_ethernet_task_out();		\
		break;									\
												\
		case 4:						     		\
			measures_motor_control_task_out();	\
		break;									\
	}											\
}

#endif /* FREERTOS_CONFIG_FRAG_H */
