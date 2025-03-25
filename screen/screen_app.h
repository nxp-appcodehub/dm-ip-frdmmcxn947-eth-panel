/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SCREEN_APP_H_
#define SCREEN_APP_H_

#include <stdbool.h>
#include <stdint.h>
#include "arm_math.h"
#include "screen.h"
#include "measures.h"

#define AUTO_CONFIG_NETWORK 0
#define MASTER_MODE 1
#define STAND_BY_ENABLE 1

#define CAN_SEND_COUNT 0
#define COUNT_UPDATE_SLIDER_VAL 3

typedef enum _screen_app_mode_t
{
	k_screen_app_interface,
	k_screen_app_master
} screen_app_mode_t;

screen_app_mode_t screenApp_getDemoMode(void);

void screenApp_setIP(uint32_t ip);

void screenEventCallback(screen_events_t event);

#endif /* SCREEN_APP_H_ */
