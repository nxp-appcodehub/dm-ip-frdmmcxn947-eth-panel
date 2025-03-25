/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MIKROE_ACCEL_4_CLICK_H_
#define MIKROE_ACCEL_4_CLICK_H_

#include <stdint.h>
#include <stdbool.h>
#include "arm_math.h"

/***************************************************************
 ************************* DEFINITIONS *************************
 ***************************************************************/
typedef int32_t accel4click_status_t;

// I2C ------------------------------------------
typedef enum _accel4click_i2c_option_t
{
	k_accel_write,
	k_accel_read
} accel4click_i2c_option_t;

typedef accel4click_status_t(*accel4click_i2c_transfer)(uint8_t address, uint8_t subaddress, uint8_t *buff, uint8_t len, accel4click_i2c_option_t option);
// ----------------------------------------------

// STRUCT AND ENUMS FOR SYSTEM MODE -------------
typedef enum _accel4click_sys_buff_mode_t
{
	k_no_buffer_gate_error_detected,
	k_buffer_gate_error_detected,
} accel4click_sys_buff_mode_t;

typedef enum _accel4click_sys_modes_t
{
	k_accel_standBy_sys_mode,
	k_accel_wake_sys_mode,
	k_accel_sleep_sys_mode,
	k_accel_exTrig_sys_mode
} accel4click_sys_modes_t;

typedef enum _accel4click_modes_t
{
	k_accel_standBy_mode,
	k_accel_active_mode
} accel4click_modes_t;

typedef struct _accel4click_sys_mode_val_t
{
	accel4click_sys_buff_mode_t buff_mode;
	uint8_t						buff_gate_count;
	accel4click_sys_modes_t		sys_mode;
} accel4click_sys_mode_val_t;
// ----------------------------------------------

// ENUM INTERRUPS FLAGS --------------------------
typedef enum _accel4click_status_interrupt_t
{
	k_accel_system_boot_complete 		= 0x01,
	k_accel_power_transition_complete 	= 0x02,
	k_accel_orientation_change 			= 0x04,
	k_accel_sdcd_within_theshold_event	= 0x08,
	k_accel_sdcd_outside_theshold_event	= 0x10,
	k_accel_output_buffer_event 		= 0x20,
	k_accel_overflow				 	= 0x40,
	k_accel_output_data_ready 			= 0x80
} accel4click_status_interrupt_t;

typedef enum _accel4click_interrupt_enable_t
{
	k_accel_wake_up_ie 						= 0x01,
	k_accel_system_boot_ie			 		= 0x02,
	k_accel_power_transition_ie				= 0x04,
	k_accel_orientation_change_ie			= 0x08,
	k_accel_sdcd_within_theshold_event_ie	= 0x10,
	k_accel_sdcd_outside_theshold_event_ie	= 0x20,
	k_accel_buffer_ie			 			= 0x40,
	k_accel_output_data_ready_ie			= 0x80
} accel4click_interrupt_enable_t;

typedef enum _accel4click_interrupt_pins_t
{
	k_int1_pin,
	k_int2_pin
} accel4click_interrupt_pins_t;
// ----------------------------------------------

// ENUM BUFF STATUS FLAGS -----------------------
typedef enum _accel4click_status_buff_t
{
	k_accel_buffer_ovf		  = 0x40,
	k_accel_buffer_wattermark = 0x80
} accel4click_status_buff_t;

// ----------------------------------------------

// SELF TEST AXIS -------------------------------
typedef enum _accel4click_self_test_axis_t
{
	k_self_test_disable,
	k_self_test_x_axis,
	k_self_test_y_axis,
	k_self_test_z_axis,
} accel4click_axis_t;

typedef enum _accel4click_displacement_polarity_t
{
	k_positive_direciton,
	k_negative_direction
} accel4click_displacement_polarity_t;
// ---------------------------------------
// ----------------------------------------------

// FULL SCALE RANGE -----------------------------
typedef enum _accel4click_full_scale_range_t
{
	k_range_2g,
	k_range_4g,
	k_range_8g,
	k_range_16g
} accel4click_full_scale_range_t;
// ----------------------------------------------

// WAKE POWER MODES -----------------------------
typedef enum _accel4click_power_modes_t
{
	k_low_power_mode,
	k_high_performance_mode,
	k_flexible_performance_mode
} accel4click_power_modes_t;
// ----------------------------------------------

// DECIMATION OPTIONS ---------------------------
typedef enum _accel4click_decimation_options_t
{
	k_3200hz,
	k_1600hz,
	k_800hz,
	k_400hz,
	k_200hz,
	k_100hz,
	k_50hz,
	k_25hz,
	k_12_5hz,
	k_6_25hz,
	k_3_125hz,
	k_1_563hz,
	k_0_781hz
} accel4click_decimation_options_t;
// ----------------------------------------------

typedef struct _accel4click_accelerations_t
{
	float32_t x;
	float32_t y;
	float32_t z;
} accel4click_accelerations_t;

// BUFFER CONFIGURATIONS ------------------------
typedef enum _accel4click_buff_read_order_t
{
	k_accel4click_buff_fifo,
	k_accel4click_buff_lifo
} accel4click_buff_read_order_t;

typedef enum _accel4click_buff_mode_t
{
	k_accel4click_buff_disable,
	k_accel4click_buff_stream,
	k_accel4click_buff_stop,
	k_accel4click_buff_trigger
} accel4click_buff_mode_t;

typedef enum _accel4click_buff_gate_t
{
	k_accel4click_buff_gate_bypassed,
	k_accel4click_buff_gate_enable
} accel4click_buff_gate_t;

typedef struct _accel4click_buff_config_t
{
	accel4click_buff_read_order_t 	buff_read_order;
	accel4click_buff_mode_t			buff_mode;
	accel4click_buff_gate_t			buff_gate;
	bool							sdcd_within_threshold_trigger;
	bool							sdcd_outside_threshold_trigger;
	bool							orientation_change_trigger;
	bool 							buff_flush_enable;
	bool							wake_to_sleep_on_buff_event;
	uint8_t							buff_watermark;
} accel4click_buff_config_t;
// --------------------------------------------

/***************************************************************
 *********************** END DEFINITIONS ***********************
 ***************************************************************/

/***************************************************************
 ************************* PROTOTIPES **************************
 ***************************************************************/
// I2C functions -------------------------------------------------------------------------------
void set_transfer_function(accel4click_i2c_transfer function);
// ---------------------------------------------------------------------------------------------

accel4click_status_t Accel4Click_init();

uint8_t Accel4Click_isReady();

// CONFIG FUNCTIONS ----------------------------------------------------------------------------
accel4click_status_t Accel4Click_do_software_reset();

accel4click_status_t Accel4Click_do_self_test_axis(accel4click_axis_t option, accel4click_displacement_polarity_t);

accel4click_status_t Accel4Click_set_full_scale_range(accel4click_full_scale_range_t range);

accel4click_status_t Accel4Click_set_operating_mode(accel4click_modes_t mode);

accel4click_status_t Accel4Click_set_Wake_mode(accel4click_power_modes_t mode);

accel4click_status_t Accel4Click_set_Sleep_mode(accel4click_power_modes_t mode);

accel4click_status_t Accel4Click_set_in_little_endian();

accel4click_status_t Accel4Click_set_in_big_endian();

accel4click_status_t Accel4Click_set_normal_read_mode();

accel4click_status_t Accel4Click_set_fast_read_mode();

accel4click_status_t Accel4Click_set_wake_decimation_option(accel4click_decimation_options_t option);

accel4click_status_t Accel4Click_set_sleep_decimation_option(accel4click_decimation_options_t option);

accel4click_status_t Accel4Click_set_ex_trigger_as_single_ADC_sample();

accel4click_status_t Accel4Click_set_ex_trigger_as_multiple_ADC_sample();

accel4click_status_t Accel4Click_enable_auto_wake_sdcd_within_treshold(bool enable);

accel4click_status_t Accel4Click_enable_auto_wake_sdcd_outside_treshold(bool enable);

accel4click_status_t Accel4Click_enable_auto_wake_change_orientation(bool enable);

accel4click_status_t Accel4Click_set_int2_pin_as_int2();

accel4click_status_t Accel4Click_set_int2_pin_as_ext_trigger();

accel4click_status_t Accel4Click_enable_open_drain_source_on_int_pin();

accel4click_status_t Accel4Click_disable_open_drain_source_on_int_pin();

accel4click_status_t Accel4Click_set_int_pin_active_high();

accel4click_status_t Accel4Click_set_int_pin_active_low();

accel4click_status_t Accel4Click_set_wake_time(uint16_t milliseconds);

accel4click_status_t Accel4Click_set_sleep_time(uint16_t milliseconds);

accel4click_status_t Accel4Click_set_inactivity_time_to_sleep_time(uint16_t count);

accel4click_status_t Accel4Click_set_interrupt_to_pin(accel4click_interrupt_enable_t interrupt, accel4click_interrupt_pins_t pin);

accel4click_status_t Accel4Click_set_x_offset(uint8_t offset);

accel4click_status_t Accel4Click_set_y_offset(uint8_t offset);

accel4click_status_t Accel4Click_set_z_offset(uint8_t offset);

accel4click_status_t Accel4Click_set_buff_config(accel4click_buff_config_t *buff_config);
// TODO: ORIENT CONFIG
// TODO: SDCD CONFIG
// ---------------------------------------------------------------------------------------------

// GETTERS -------------------------------------------------------------------------------------
accel4click_status_t Accel4Click_get_rev(uint8_t *retval);

accel4click_status_t Accel4Click_get_id(uint8_t *retval);

accel4click_status_t Accel4Click_get_system_status_reg(accel4click_sys_mode_val_t *retval);

accel4click_status_t Accel4Click_get_status_flags(accel4click_status_interrupt_t *retval);

accel4click_status_t Accel4Click_get_temperature(float32_t *retval);

accel4click_status_t Accel4Click_get_vector_magnitude(float32_t *retval);

accel4click_status_t Accel4Click_get_x_acceleration(float32_t *retval);

accel4click_status_t Accel4Click_get_y_acceleration(float32_t *retval);

accel4click_status_t Accel4Click_get_z_acceleration(float32_t *retval);

accel4click_status_t Accel4Click_get_accelerations(accel4click_accelerations_t *retval);

// BUFFER GET FUNCTIONS -------------------------
accel4click_status_t Accel4Click_get_buff_status_flags(accel4click_status_buff_t *retval);

accel4click_status_t Accel4Click_get_buff_counter(uint8_t *retval);

accel4click_status_t Accel4Click_get_buff_x_acceleration(float32_t *retval, uint8_t elements);

accel4click_status_t Accel4Click_get_buff_y_acceleration(float32_t *retval, uint8_t elements);

accel4click_status_t Accel4Click_get_buff_z_acceleration(float32_t *retval, uint8_t elements);
// ----------------------------------------------

// ---------------------------------------------------------------------------------------------

/***************************************************************
 *********************** END PROTOTIPES ************************
 ***************************************************************/


#endif /* MIKROE_ACCEL_4_CLICK_H_ */
