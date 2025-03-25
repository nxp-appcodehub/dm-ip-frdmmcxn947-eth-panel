/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef COMUNICATION_H_
#define COMUNICATION_H_

#include <stdint.h>
#include <stdbool.h>
#include "arm_math.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*Max number of RMP */
#define MAX_RPM (4000U)
/* Max percentage */
#define MAX_PERCENTAGE (100U)
/*******************************************************************************
 * Variables
 ******************************************************************************/

// Data comunication structures -----------------------------
typedef enum _comunication_command_t
{
	k_comunication_command_none,
	k_comunication_command_update_data,
	k_comunication_command_send_date,
	k_comunication_command_send_rpm,
	k_comunication_command_set_rpm_req
} comunication_command_t;

typedef struct _comunication_date_t
{
	uint8_t comunication_hours;
	uint8_t comunication_minutes;
	uint8_t comunication_seconds;
	uint8_t comunication_meridian;
	uint8_t comunication_day;
	uint8_t comunication_month;
	uint16_t comunication_year;
} comunication_date_t;

typedef struct _comunication_temperature_t
{
	float32_t comunication_mcu_temperature;
	float32_t comunication_brd_temperature;
} comunication_temperature_t;

typedef struct _comunication_performance_t
{
	uint8_t comunication_idle_core_1;
	uint8_t comunication_idle_core_2;
	uint8_t comunication_lvgl_core_1;
	uint8_t comunication_sensors_core_1;
	uint8_t comunication_ethernet_core_1;
	uint8_t comunication_motor_control_core_1;
} comunication_performance_t;

typedef struct _comunication_accel_t
{
	uint8_t	  accel_enable;
	float32_t comunication_accel_x;
	float32_t comunication_accel_y;
	float32_t comunication_accel_z;
} comunication_accel_t;

typedef struct _comunication_motor_t
{
	int32_t comunication_motor_rpm;
	int32_t comunication_motor_rpm_slider;
} comunication_motor_t;

typedef struct _comunication_data_reception_t
{
	comunication_date_t			comunication_date;
	comunication_temperature_t 	comunication_temperature;
	comunication_performance_t	comunication_performance;
	comunication_accel_t		comunication_accel;
	comunication_motor_t		comunication_motor;
} comunication_data_transmision_t;

typedef struct _comunication_transfer_t
{
	comunication_command_t			comunication_command;
	comunication_data_transmision_t comunication_data;
} comunication_transfer_t;

typedef struct _comunication_transfer_can_usb_t
{
	comunication_command_t			comunication_command;
	comunication_motor_t            comunication_motor_data;
} comunication_transfer_can_usb_t;

typedef struct _comunication_updates_t
{
	bool comunication_accel_update;
	bool comunication_performance_core1_update;
	bool comunication_performance_core2_update;
	bool comunication_touch_update;
	bool comunication_mcu_temperature_update;
	bool comunication_brd_temperature_update;
	bool comunication_time_update;
	bool comunication_date_update;
	bool comunication_rpm_update;
} comunication_updates_t;
// ----------------------------------------------------------
/*******************************************************************************
 * Functions prototype
 ******************************************************************************/
/*!
 * @brief Build de data needed to request an update on the RPM of the motor
 *
 * @param   ptr_data - Pointer to buffer where the data should be loaded
 * @param   ptr_size - Pointer to variable to return the size of the package
 * @param   rmp_val - RMP value to be added in the buffer data
 *
 *
 * @return  none
 */
void build_indutrialpanel_rpm_request(uint8_t *ptr_data, uint8_t *ptr_size, uint16_t rpm_val);

/*!
 * @brief commad update on the RPM of the motor
 *
 * @param   ptr_data - Pointer to buffer where the data should be loaded
 * @param   ptr_size - Pointer to variable to return the size of the package
 * @param   rmp_val - RMP value to be added in the buffer data
 *
 *
 * @return  none
 */
void build_indutrialpanel_rpm_update(uint8_t *ptr_data, uint8_t *ptr_size, uint16_t speed_percetage, int16_t rpm);

/*!
 * @brief This function will convert the RMP received in ASCII from the wireless tool box to decimal value
 *
 * @param   ascii_buff - Pointer to buffer where the ASCII value is located
 * @param   dec_val - Pointer to variable to return the decimal value
 * @param   ascii_length - Length of the ASCII package received.
 *
 *
 * @return  none
 */
void industrialpanel_ascci_rpm_to_dec(uint8_t *ascii_buff, uint16_t *dec_val, uint16_t ascii_length);

#endif /* COMUNICATION_H_ */
