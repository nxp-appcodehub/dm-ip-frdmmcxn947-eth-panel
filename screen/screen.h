/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdint.h>
#include <stdbool.h>
#include "arm_math.h"

#define MS_TASK_DELAY		  	30
#define MS_UPDATE_EVENT		  	100
#define MS_TO_STAND_BY		  	15000
#define ELEMENTS_IN_RPM_CHART 	21
#define SCREEN_ANIMATION		LV_SCR_LOAD_ANIM_FADE_ON //LV_SCR_LOAD_ANIM_NONE //LV_SCR_LOAD_ANIM_FADE_ON
#define TIME_PERIOD_ANIMATION	50
#define TIME_DELAY_ANIMATION	50

typedef enum _sign_of_string_t
{
	positive,
	negative
} sign_of_string_t;

typedef enum _screen_meridian_t
{
	k_screen_am,
	k_screen_pm
} screen_meridian_t;


typedef enum _screens_t
{
	k_init_screen,
	k_connection_config_screen,
	k_server_ip_screen,
	k_standBy_screen,
	k_menu_screen,
	k_performance_screen,
	k_temperature_screen,
	k_accelerometer_screen,
	k_touch_screen,
	k_setTime_screen,
	k_control_panel_screen
} screen_t;

typedef enum _screen_events_t
{
	k_screen_init_event,
	k_screen_clicked_event,
	k_screen_masterBtn_event,
	k_screen_interfaceBtn_event,
	k_screen_dhcp_selected_event,
	k_screen_static_selected_event,
	k_screen_ip_mask_0_event,
	k_screen_ip_mask_1_event,
	k_screen_ip_mask_2_event,
	k_screen_ip_mask_3_event,
	k_screen_number0_btn_event,
	k_screen_number1_btn_event,
	k_screen_number2_btn_event,
	k_screen_number3_btn_event,
	k_screen_number4_btn_event,
	k_screen_number5_btn_event,
	k_screen_number6_btn_event,
	k_screen_number7_btn_event,
	k_screen_number8_btn_event,
	k_screen_number9_btn_event,
	k_screen_save_btn_event,
	k_screen_standByTouch_event,
	k_screen_menuPerfBtn_event,
	k_screen_menuTempBtn_event,
	k_screen_menuAccBtn_event,
	k_screen_menuTouchBtn_event,
	k_screen_menuSetTimeBtn_event,
	k_screen_menuCtrlPanelBtn_event,
	k_screen_menuBtn_event,
	k_screen_setTimeBtn_event,
	k_screen_rpmPressed_event,
	k_screen_rpmReleased_event,
	k_screen_update_event
} screen_events_t;

typedef struct _screen_time_t
{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	screen_meridian_t meridian;
} screen_time_t;

typedef struct _screen_date_t
{
	uint8_t day;
	uint8_t month;
	uint16_t year;
} screen_date_t;

typedef struct _screen_perf_core1_t
{
	uint8_t idle_perf;
	uint8_t ethernet_perf;
	uint8_t lvgl_perf;
	uint8_t sensor_perf;
	uint8_t motor_perf;
} screen_perf_core1_t;

typedef struct _screen_perf_core2_t
{
	uint8_t idle_perf;
	uint8_t motorControl_perf;
} screen_perf_core2_t;

typedef struct _screen_accel_t
{
	float32_t accelX;
	float32_t accelY;
	float32_t accelZ;
} screen_accel_t;

typedef enum _screen_ip_mode_t
{
	k_screen_dhcp,
	k_screen_static_ip
} screen_ip_mode_t;

typedef void(*screenCallback)(screen_events_t event);

void screen_setScreen(screen_t screen);

void screen_setPreviusScreen(void);

void screen_setCallback(screenCallback fnc);

void screen_setConnectionMode(screen_ip_mode_t mode);

void screen_setBGColorMask(uint32_t mask_element, uint32_t color);

void screen_setNumberButtonsColor(uint32_t color);

void screen_setNumberLabelMask(uint32_t mask_element, uint8_t number);

void screen_setIPMask(uint32_t ip);

void screen_setTime(screen_time_t time);

void screen_setMCUTemp(float32_t temp);

void screen_setBRDTemp(float32_t temp);

void screen_setDate(screen_date_t date);

void screen_setPerfCore1(screen_perf_core1_t performance);

void screen_setPerfCore2(screen_perf_core2_t performance);

void screen_setAccel(screen_accel_t accelerometer);

void screen_setTouch(float32_t touchVoltage); // 0-3.3v

void screen_setAccelButton(uint8_t enable);

void screen_setRPMLabel(int16_t rpm);

void screen_setRPMGraphic(int16_t rpm);

screen_time_t screen_getConfigTime(void);

void screen_setRPMSlider(int32_t val);

int32_t screen_getRPMSlider(void);

void screen_refreshRPMSlider(void);

int32_t screen_getRPMSliderSave(void);

uint8_t screen_getCheckButtonState(void);

void screenTask(void*args);

void screenTick(void);

#endif /* SCREEN_H_ */
