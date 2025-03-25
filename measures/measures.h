/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MEASURES_H_
#define MEASURES_H_

#include <stdint.h>
#include <stdbool.h>
#include "arm_math.h"

#define PERFORMANCE_TIMER_PERIOD_MS 300

#define DEMO_LPADC_TEMP_SENS_CHANNEL           26U
#define DEMO_LPADC_TOUCH_SENS_CHANNEL          19U
#define DEMO_LPADC_USER_CMDID                  1U /* CMD1 */
#define DEMO_LPADC_USER_CMDID2                 2U /* CMD2 */
#define DEMO_LPADC_SAMPLE_TEMP_CHANNEL_MODE    kLPADC_SampleChannelDiffBothSide
#define DEMO_LPADC_SAMPLE_TOUCH_CHANNEL_MODE   kLPADC_SampleChannelSingleEndSideA
#define DEMO_LPADC_VREF_SOURCE                 kLPADC_ReferenceVoltageAlt2

typedef enum _measures_meridian_t
{
	k_measures_screen_am,
	k_measures_screen_pm
} measures_meridian_t;

typedef struct _measures_time_t
{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	measures_meridian_t meridian;
} measures_time_t;

typedef struct _measures_date_t
{
	uint8_t day;
	uint8_t month;
	uint16_t year;
} measures_date_t;

typedef struct _measures_updates_t
{
	bool accel_update;
	bool performance_core1_update;
	bool performance_core2_update;
	bool touch_update;
	bool mcu_temperature_update;
	bool brd_temperature_update;
	bool time_update;
	bool date_update;
	bool rpm_update;
} measure_updates_t;

typedef struct _measures_accel_t
{
	float32_t accelX;
	float32_t accelY;
	float32_t accelZ;
} measures_accel_t;

typedef struct _measures_performance_core1_t
{
	uint8_t measures_idle_perf_core1;
	uint8_t measures_ethernet_perf_core1;
	uint8_t measures_lvgl_perf_core1;
	uint8_t measures_sensors_perf_core1_t;
	uint8_t measures_motor_perf_core1_t;
} measures_performance_core1_t;

typedef struct _measures_performance_core2_t
{
	uint8_t measures_idle_perf_core2;
	uint8_t measures_motorControl_perf_core2;
} measures_performance_core2_t;

void measures_init();

measure_updates_t measures_get_updates(void);

measures_accel_t measures_get_accel_values(void);

measures_performance_core1_t measures_get_performance_core1(void);

measures_performance_core2_t measures_get_performance_core2(void);

float32_t measures_get_electrode(void); // 0-3.3

float32_t measures_get_mcu_temperature(void);

float32_t measures_get_brd_temperature(void);

measures_time_t measures_get_time(void);

measures_date_t measures_get_date(void);

int32_t	measures_get_rpm(void);

void measures_set_time(measures_time_t time);

// Task in --------------------------------
void measures_idle_core1_task_in(void);

void measures_ethernet_task_in(void);

void measures_lvgl_task_in(void);

void measures_sensor_task_in(void);

void measures_idle_core2_task_in(void);

void measures_motor_control_task_in(void);

void measures_motor_control_int_in(void);

// Task out -----------------------------
void measures_idle_core1_task_out(void);

void measures_ethernet_task_out(void);

void measures_lvgl_task_out(void);

void measures_sensor_task_out(void);

void measures_idle_core2_task_out(void);

void measures_motor_control_task_out(void);

void measures_motor_control_int_out(void);

uint8_t measuresAccelIsReady();

void measures_task(void *args);

#endif /* MEASURES_H_ */
