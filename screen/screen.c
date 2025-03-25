/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "screen.h"
#include "lvgl.h"
#include "lvgl_support.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#define CHAR_TO_INT -48
#define INT_TO_CHAR 48

lv_ui guider_ui;
static bool g_lvgl_initialized = false;
static screen_t g_actual_screen  = k_init_screen;
static screen_t g_previus_screen = k_init_screen;

static screenCallback g_event_callback = 0;

static int32_t g_rpm_slider = 0;

const char c_month_array[][4] = {"Ene", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dec"};

static SemaphoreHandle_t 		g_slider_sem;
/********************************************************************************************
	@brief : This function convert string to integer.
	@param : buffer -> String to convert, support negative number "-00050" or "-50" or "50"
	@param : size   -> Size of string
	@return: Integer number
*********************************************************************************************/
int32_t string_to_int(char* buffer, uint8_t size) // Ends when character is not a number or reach size
{
	uint8_t index;
	int32_t retval = 0;
	sign_of_string_t sign = positive;
	if(NULL != buffer)
	{
		for(index = 0; index < size && index < 100; index ++)
		{
			if('-' == buffer[index])
			{
				sign = negative;
			}
			else if('0' <= buffer[index] && '9' >= buffer[index])
			{
				retval *= 10;
				retval += (int8_t)buffer[index] + CHAR_TO_INT;
			}
			else
			{
				break;
			}
		}
		if(negative == sign)
		{
			retval *= -1;
		}
	}
	return retval;
}
// ------------------------------------------------------------------------------------------

/********************************************************************************************
	@brief : This function convert integer to string
	@param : value   -> Integer value to convert
	@param : string  -> Buffer pointer to save string number
	@param : int_len -> String length, if is more than number need is filled with '0'
	@return: Return sign of number (Not put '-' in string)
*********************************************************************************************/
sign_of_string_t int_to_string(int32_t value, char* string, uint8_t int_len)
{
	uint8_t counter;
	uint8_t index;
	uint8_t pow_cnt;
	uint32_t divisor;
	uint32_t suma = 0;
	sign_of_string_t sign = positive;

	if(value < 0)
	{
		sign = negative;
		value *= -1;
	}
	for(index = 0, counter = int_len; index < int_len; index ++, counter --)
	{
		divisor = 1;
		for(pow_cnt = 1; pow_cnt < counter; pow_cnt ++)
		{
			divisor *= 10;
		}
		string[index] = (value-suma)/divisor;
		suma += string[index]*divisor;
		string[index] += INT_TO_CHAR;
	}
	return sign;
}
// ------------------------------------------------------------------------------------------

void screen_setScreen(screen_t screen)
{
	lv_obj_t * act_scr = lv_scr_act();
	lv_obj_t * screen_ptr  = 0;
	g_previus_screen = g_actual_screen;
	g_actual_screen = screen;
	switch(screen)
	{
		case k_init_screen:
			lv_obj_clean(act_scr);
			setup_scr_init_screen(&guider_ui);
			screen_ptr = guider_ui.init_screen;
		break;
		case k_connection_config_screen:
			lv_obj_clean(act_scr);
			setup_scr_connection_config_screen(&guider_ui);
			screen_ptr = guider_ui.connection_config_screen;
		break;
		case k_server_ip_screen:
			lv_obj_clean(act_scr);
			setup_scr_server_ip_screen(&guider_ui);
			screen_ptr = guider_ui.server_ip_screen;
		break;
		case k_standBy_screen:
			lv_obj_clean(act_scr);
			setup_scr_stand_by_screen(&guider_ui);
			screen_ptr = guider_ui.stand_by_screen;
		break;
		case k_menu_screen:
			lv_obj_clean(act_scr);
			setup_scr_menu_screen(&guider_ui);
			screen_ptr = guider_ui.menu_screen;
		break;
		case k_performance_screen:
			lv_obj_clean(act_scr);
			setup_scr_cpu_performance_screen(&guider_ui);
			screen_ptr = guider_ui.cpu_performance_screen;
		break;
		case k_temperature_screen:
			lv_obj_clean(act_scr);
			setup_scr_temperature_measure_screen(&guider_ui);
			screen_ptr = guider_ui.temperature_measure_screen;
		break;
		case k_accelerometer_screen:
			lv_obj_clean(act_scr);
			setup_scr_accelerometer_measure_screen(&guider_ui);
			screen_ptr = guider_ui.accelerometer_measure_screen;
		break;
		case k_setTime_screen:
			lv_obj_clean(act_scr);
			setup_scr_set_time_screen(&guider_ui);
			screen_ptr = guider_ui.set_time_screen;
		break;
		case k_touch_screen:
			lv_obj_clean(act_scr);
			setup_scr_touch_measure_screen(&guider_ui);
			screen_ptr = guider_ui.touch_measure_screen;
		break;
		case k_control_panel_screen:
			lv_obj_clean(act_scr);
			setup_scr_control_panel_screen(&guider_ui);
			screen_ptr = guider_ui.control_panel_screen;
		break;
	}
	lv_scr_load_anim(screen_ptr, SCREEN_ANIMATION, TIME_PERIOD_ANIMATION, TIME_DELAY_ANIMATION, true);
}

void screen_setPreviusScreen(void)
{
	screen_setScreen(g_previus_screen);
}

void screen_setCallback(screenCallback fnc)
{
	g_event_callback = fnc;
	set_Callback(fnc);
}


void screen_setBGColorMask(uint32_t mask_element, uint32_t color)
{
	if(g_actual_screen == k_connection_config_screen)
	{
		if(mask_element == 0) 		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_IPCnf1, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		else if(mask_element == 1) 	lv_obj_set_style_bg_color(guider_ui.connection_config_screen_IPCnf2, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		else if(mask_element == 2) 	lv_obj_set_style_bg_color(guider_ui.connection_config_screen_IPCnf3, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		else if(mask_element == 3) 	lv_obj_set_style_bg_color(guider_ui.connection_config_screen_IPCnf4, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	else if(g_actual_screen == k_server_ip_screen)
	{
		if(mask_element == 0) 		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_IPCnf1, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		else if(mask_element == 1) 	lv_obj_set_style_bg_color(guider_ui.server_ip_screen_IPCnf2, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		else if(mask_element == 2) 	lv_obj_set_style_bg_color(guider_ui.server_ip_screen_IPCnf3, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		else if(mask_element == 3) 	lv_obj_set_style_bg_color(guider_ui.server_ip_screen_IPCnf4, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}

void screen_setConnectionMode(screen_ip_mode_t mode)
{
	if(g_actual_screen == k_connection_config_screen)
	{
		lv_obj_clear_state(guider_ui.connection_config_screen_ConnectionModeRad_item0, LV_STATE_PRESSED | LV_STATE_CHECKED);
		lv_obj_clear_state(guider_ui.connection_config_screen_ConnectionModeRad_item1, LV_STATE_PRESSED | LV_STATE_CHECKED);
		if(mode == k_screen_dhcp)
		{
			lv_obj_add_state(guider_ui.connection_config_screen_ConnectionModeRad_item0, LV_STATE_CHECKED);
			lv_obj_add_state(guider_ui.connection_config_screen_ConnectionModeRad_item1, LV_STATE_DEFAULT);
		}
		else
		{
			lv_obj_add_state(guider_ui.connection_config_screen_ConnectionModeRad_item0, LV_STATE_DEFAULT);
			lv_obj_add_state(guider_ui.connection_config_screen_ConnectionModeRad_item1, LV_STATE_CHECKED);
		}
	}
}

void screen_setNumberButtonsColor(uint32_t color)
{
	if(g_actual_screen == k_connection_config_screen)
	{
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N0Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N1Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N2Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N3Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N4Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N5Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N6Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N7Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N8Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.connection_config_screen_N9Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	else if(g_actual_screen == k_server_ip_screen)
	{
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N0Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N1Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N2Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N3Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N4Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N5Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N6Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N7Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N8Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(guider_ui.server_ip_screen_N9Btn, lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
}

void screen_setNumberLabelMask(uint32_t mask_element, uint8_t number)
{
	uint8_t label_text[4] = {0};
	int_to_string((int32_t)number, (char*)label_text, 3);
	if(g_actual_screen == k_connection_config_screen)
	{
		if(mask_element == 0) 		lv_label_set_text(guider_ui.connection_config_screen_IPCnf1_label, (char*)label_text);
		else if(mask_element == 1) 	lv_label_set_text(guider_ui.connection_config_screen_IPCnf2_label, (char*)label_text);
		else if(mask_element == 2) 	lv_label_set_text(guider_ui.connection_config_screen_IPCnf3_label, (char*)label_text);
		else if(mask_element == 3) 	lv_label_set_text(guider_ui.connection_config_screen_IPCnf4_label, (char*)label_text);
	}
	else if(g_actual_screen == k_server_ip_screen)
	{
		if(mask_element == 0) 		lv_label_set_text(guider_ui.server_ip_screen_IPCnf1_label, (char*)label_text);
		else if(mask_element == 1) 	lv_label_set_text(guider_ui.server_ip_screen_IPCnf2_label, (char*)label_text);
		else if(mask_element == 2) 	lv_label_set_text(guider_ui.server_ip_screen_IPCnf3_label, (char*)label_text);
		else if(mask_element == 3) 	lv_label_set_text(guider_ui.server_ip_screen_IPCnf4_label, (char*)label_text);
	}
}

void screen_setIPMask(uint32_t ip)
{
	uint8_t label_text[] = "192.168.000.100";
	uint8_t addr0 = (ip>>24)&0xFF;
	uint8_t addr1 = (ip>>16)&0xFF;
	uint8_t addr2 = (ip>>8)&0xFF;
	uint8_t addr3 = (ip)&0xFF;
	int_to_string((int32_t)addr0, (char*)(label_text), 3);
	int_to_string((int32_t)addr1, (char*)(label_text + 4), 3);
	int_to_string((int32_t)addr2, (char*)(label_text + 8), 3);
	int_to_string((int32_t)addr3, (char*)(label_text + 12), 3);
	if(g_actual_screen == k_standBy_screen) lv_label_set_text(guider_ui.stand_by_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_menu_screen) lv_label_set_text(guider_ui.menu_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_performance_screen) lv_label_set_text(guider_ui.cpu_performance_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_temperature_screen) lv_label_set_text(guider_ui.temperature_measure_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_accelerometer_screen) lv_label_set_text(guider_ui.accelerometer_measure_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_touch_screen) lv_label_set_text(guider_ui.touch_measure_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_setTime_screen) lv_label_set_text(guider_ui.set_time_screen_IPLabel, (char*)label_text);
	else if(g_actual_screen == k_control_panel_screen) lv_label_set_text(guider_ui.control_panel_screen_IPLabel, (char*)label_text);
}

void screen_setTime(screen_time_t time)
{
	char new_string[12];
	int_to_string((int32_t)time.hours, new_string, 2);
	new_string[2] = ':';
	int_to_string((int32_t)time.minutes, new_string+3, 2);
	new_string[5] = ':';
	int_to_string((int32_t)time.seconds, new_string+6, 2);
	new_string[8] = ' ';
	new_string[9] = (time.meridian == k_screen_am)? 'a':'p';
	new_string[10] = 'm';
	new_string[11] = 0;
	switch(g_actual_screen)
	{
		case k_init_screen:
			lv_label_set_text(guider_ui.init_screen_HourLabel, new_string);
		break;
		case k_connection_config_screen:
			lv_label_set_text(guider_ui.connection_config_screen_HourLabel, new_string);
		break;
		case k_server_ip_screen:
			lv_label_set_text(guider_ui.server_ip_screen_HourLabel, new_string);
		break;
		case k_standBy_screen:
			lv_label_set_text(guider_ui.stand_by_screen_HourLabel, new_string);
		break;
		case k_menu_screen:
			lv_label_set_text(guider_ui.menu_screen_HourLabel, new_string);
		break;
		case k_performance_screen:
			lv_label_set_text(guider_ui.cpu_performance_screen_HourLabel, new_string);
		break;
		case k_temperature_screen:
			lv_label_set_text(guider_ui.temperature_measure_screen_HourLabel, new_string);
		break;
		case k_accelerometer_screen:
			lv_label_set_text(guider_ui.accelerometer_measure_screen_HourLabel, new_string);
		break;
		case k_setTime_screen:
			lv_label_set_text(guider_ui.set_time_screen_HourLabel, new_string);
		break;
		case k_touch_screen:
			lv_label_set_text(guider_ui.touch_measure_screen_HourLabel, new_string);
		break;
		case k_control_panel_screen:
			lv_label_set_text(guider_ui.control_panel_screen_HourLabel, new_string);
		break;
	}
}

void screen_setMCUTemp(float32_t temp)
{
	char new_string[8];
	int8_t temp_int = (uint8_t)temp;
	int8_t temp_dec = (uint8_t)((temp-(float32_t)temp_int)*100.0);
	int_to_string((int32_t)temp_int, new_string, 2);
	new_string[2] = '.';
	int_to_string((int32_t)temp_dec, new_string+3, 2);
	new_string[5] = 248;
	new_string[6] = 'C';
	new_string[7] = 0;
	switch(g_actual_screen)
	{
		case k_init_screen:
			lv_label_set_text(guider_ui.init_screen_MCUTempLabel, new_string);
		break;
		case k_connection_config_screen:
			lv_label_set_text(guider_ui.connection_config_screen_MCUTempLabel, new_string);
		break;
		case k_server_ip_screen:
			lv_label_set_text(guider_ui.server_ip_screen_MCUTempLabel, new_string);
		break;
		case k_standBy_screen:
		break;
		case k_menu_screen:
			lv_label_set_text(guider_ui.menu_screen_MCUTempLabel, new_string);
		break;
		case k_performance_screen:
			lv_label_set_text(guider_ui.cpu_performance_screen_MCUTempLabel, new_string);
		break;
		case k_temperature_screen:
			lv_label_set_text(guider_ui.temperature_measure_screen_MCUTempLabel, new_string);
			lv_label_set_text(guider_ui.temperature_measure_screen_MCUTempScreenLabel, new_string);
			lv_meter_set_indicator_value(guider_ui.temperature_measure_screen_MCUTempMeter, guider_ui.temperature_measure_screen_MCUTempMeter_scale_0_ndline_0, (int32_t)temp_int);
		break;
		case k_accelerometer_screen:
			lv_label_set_text(guider_ui.accelerometer_measure_screen_MCUTempLabel, new_string);
		break;
		case k_setTime_screen:
			lv_label_set_text(guider_ui.set_time_screen_MCUTempLabel, new_string);
		break;
		case k_touch_screen:
			lv_label_set_text(guider_ui.touch_measure_screen_MCUTempLabel, new_string);
		break;
		case k_control_panel_screen:
			lv_label_set_text(guider_ui.control_panel_screen_MCUTempLabel, new_string);
		break;
	}
}

void screen_setBRDTemp(float32_t temp)
{
	char new_string[8];
	int8_t temp_int = (uint8_t)temp;
	int8_t temp_dec = (uint8_t)((temp-(float32_t)temp_int)*100.0);
	int_to_string((int32_t)temp_int, new_string, 2);
	new_string[2] = '.';
	int_to_string((int32_t)temp_dec, new_string+3, 2);
	new_string[5] = 248;
	new_string[6] = 'C';
	new_string[7] = 0;
	switch(g_actual_screen)
	{
		case k_init_screen:
			lv_label_set_text(guider_ui.init_screen_BRDTempLabel, new_string);
		break;
		case k_connection_config_screen:
			lv_label_set_text(guider_ui.connection_config_screen_BRDTempLabel, new_string);
		break;
		case k_server_ip_screen:
			lv_label_set_text(guider_ui.server_ip_screen_BRDTempLabel, new_string);
		break;
		case k_standBy_screen:
		break;
		case k_menu_screen:
			lv_label_set_text(guider_ui.menu_screen_BRDTempLabel, new_string);
		break;
		case k_performance_screen:
			lv_label_set_text(guider_ui.cpu_performance_screen_BRDTempLabel, new_string);
		break;
		case k_temperature_screen:
			lv_label_set_text(guider_ui.temperature_measure_screen_BRDTempLabel, new_string);
			lv_label_set_text(guider_ui.temperature_measure_screen_BRDTempScreenLabel, new_string);
			lv_meter_set_indicator_value(guider_ui.temperature_measure_screen_BRDTempMeter, guider_ui.temperature_measure_screen_BRDTempMeter_scale_0_ndline_0, (int32_t)temp_int);
		break;
		case k_accelerometer_screen:
			lv_label_set_text(guider_ui.accelerometer_measure_screen_BRDTempLabel, new_string);
		break;
		case k_setTime_screen:
			lv_label_set_text(guider_ui.set_time_screen_BRDTempLabel, new_string);
		break;
		case k_touch_screen:
			lv_label_set_text(guider_ui.touch_measure_screen_BRDTempLabel, new_string);
		break;
		case k_control_panel_screen:
			lv_label_set_text(guider_ui.control_panel_screen_BRDTempLabel, new_string);
		break;
	}
}

void screen_setDate(screen_date_t date)
{
	char new_string[14];
	new_string[0] = c_month_array[date.month-1][0];
	new_string[1] = c_month_array[date.month-1][1];
	new_string[2] = c_month_array[date.month-1][2];
	new_string[3] = ',';
	new_string[4] = ' ';
	int_to_string((int32_t)date.day, new_string+5, 2);
	new_string[7] = ',';
	new_string[8] = ' ';
	int_to_string((int32_t)date.year, new_string+9, 4);
	new_string[13] = 0;
	switch(g_actual_screen)
	{
		case k_init_screen:
			lv_label_set_text(guider_ui.init_screen_DateLabel, new_string);
		break;
		case k_connection_config_screen:
			lv_label_set_text(guider_ui.connection_config_screen_DateLabel, new_string);
		break;
		case k_server_ip_screen:
			lv_label_set_text(guider_ui.server_ip_screen_DateLabel, new_string);
		break;
		case k_standBy_screen:
			lv_label_set_text(guider_ui.stand_by_screen_DateLabel, new_string);
		break;
		case k_menu_screen:
			lv_label_set_text(guider_ui.menu_screen_DateLabel, new_string);
		break;
		case k_performance_screen:
			lv_label_set_text(guider_ui.cpu_performance_screen_DateLabel, new_string);
		break;
		case k_temperature_screen:
			lv_label_set_text(guider_ui.temperature_measure_screen_DateLabel, new_string);
		break;
		case k_accelerometer_screen:
			lv_label_set_text(guider_ui.accelerometer_measure_screen_DateLabel, new_string);
		break;
		case k_setTime_screen:
			lv_label_set_text(guider_ui.set_time_screen_DateLabel, new_string);
		break;
		case k_touch_screen:
			lv_label_set_text(guider_ui.touch_measure_screen_DateLabel, new_string);
		break;
		case k_control_panel_screen:
			lv_label_set_text(guider_ui.control_panel_screen_DateLabel, new_string);
		break;
	}
}

void screen_setPerfCore1(screen_perf_core1_t performance)
{
	int16_t lvgl_arc_value;
	int16_t ethernet_arc_rotation;
	int16_t ethernet_arc_value;
	int16_t idle_arc_rotation;
	int16_t idle_arc_value;
	int16_t sensor_arc_rotation;
	int16_t sensor_arc_value;
	int16_t motor_arc_rotation;
	int16_t motor_arc_value;

	if(g_actual_screen == k_performance_screen)
	{
		lvgl_arc_value 			= ((float32_t)performance.lvgl_perf*3.6);
		ethernet_arc_rotation 	= lvgl_arc_value;
		ethernet_arc_value	  	= ((float32_t)performance.ethernet_perf*3.6);
		idle_arc_rotation		= ethernet_arc_rotation + ethernet_arc_value;
		idle_arc_value			= ((float32_t)performance.idle_perf*3.6);
		sensor_arc_rotation		= idle_arc_rotation + idle_arc_value;
		sensor_arc_value		= ((float32_t)performance.sensor_perf*3.6);
		motor_arc_rotation		= sensor_arc_rotation + sensor_arc_value;
		motor_arc_value			= ((float32_t)performance.motor_perf*3.6);

		lv_arc_set_rotation(guider_ui.cpu_performance_screen_LvglArc, 0);
		lv_arc_set_value(guider_ui.cpu_performance_screen_LvglArc, lvgl_arc_value);

		lv_arc_set_rotation(guider_ui.cpu_performance_screen_EthernetArc, ethernet_arc_rotation);
		lv_arc_set_value(guider_ui.cpu_performance_screen_EthernetArc, ethernet_arc_value);

		lv_arc_set_rotation(guider_ui.cpu_performance_screen_IdleArc1, idle_arc_rotation);
		lv_arc_set_value(guider_ui.cpu_performance_screen_IdleArc1, idle_arc_value);

		lv_arc_set_rotation(guider_ui.cpu_performance_screen_SensorArc, sensor_arc_rotation);
		lv_arc_set_value(guider_ui.cpu_performance_screen_SensorArc, sensor_arc_value);

		lv_arc_set_rotation(guider_ui.cpu_performance_screen_MotorControlArc, motor_arc_rotation);
		lv_arc_set_value(guider_ui.cpu_performance_screen_MotorControlArc, motor_arc_value);
	}
}

void screen_setPerfCore2(screen_perf_core2_t performance)
{
	int16_t idle_arc_value;
	int16_t idle_arc_rotation;
	int16_t motorControl_arc_value;

	if(g_actual_screen == k_performance_screen)
	{
		motorControl_arc_value	  	= ((uint16_t)performance.motorControl_perf*360)/100;
		idle_arc_rotation 			= motorControl_arc_value;
		idle_arc_value 				= ((uint16_t)performance.idle_perf*360)/100;

		lv_arc_set_rotation(guider_ui.cpu_performance_screen_IdleArc2, idle_arc_rotation);
		lv_arc_set_value(guider_ui.cpu_performance_screen_IdleArc2, idle_arc_value);
	}
}

void screen_setAccel(screen_accel_t accelerometer)
{
	static char new_string[13] = " 00.00 m/s^2";
	int32_t accelX_int;
	int32_t accelX_tens;
	int32_t accelY_int;
	int32_t accelY_tens;
	int32_t accelZ_int;
	int32_t accelZ_tens;
	if(g_actual_screen == k_accelerometer_screen)
	{
		accelX_int 	= (int32_t)accelerometer.accelX;
		accelY_int 	= (int32_t)accelerometer.accelY;
		accelZ_int 	= (int32_t)accelerometer.accelZ;
		accelX_tens	= (int32_t)((accelerometer.accelX-(float32_t)accelX_int)*100.0);
		accelY_tens	= (int32_t)((accelerometer.accelY-(float32_t)accelY_int)*100.0);
		accelZ_tens	= (int32_t)((accelerometer.accelZ-(float32_t)accelZ_int)*100.0);

		if(int_to_string(accelX_int, new_string+1, 2) == negative) 	new_string[0] = '-';
		else														new_string[0] = ' ';
		int_to_string(accelX_tens, new_string+4, 2);
		lv_label_set_text(guider_ui.accelerometer_measure_screen_AccelXLabel, new_string);

		if(int_to_string(accelY_int, new_string+1, 2) == negative) 	new_string[0] = '-';
		else														new_string[0] = ' ';
		int_to_string(accelY_tens, new_string+4, 2);
		lv_label_set_text(guider_ui.accelerometer_measure_screen_AccelYLabel, new_string);

		if(int_to_string(accelZ_int, new_string+1, 2) == negative) 	new_string[0] = '-';
		else														new_string[0] = ' ';
		int_to_string(accelZ_tens, new_string+4, 2);
		lv_label_set_text(guider_ui.accelerometer_measure_screen_AccelZLabel, new_string);

		lv_bar_set_value(guider_ui.accelerometer_measure_screen_AccelXBar, accelX_int, LV_ANIM_ON);
		lv_bar_set_value(guider_ui.accelerometer_measure_screen_AccelYBar, accelY_int, LV_ANIM_ON);
		lv_bar_set_value(guider_ui.accelerometer_measure_screen_AccelZBar, accelZ_int, LV_ANIM_ON);
	}
}

void screen_setTouch(float32_t touchVoltage) // 0-3.3v
{
	char new_string[5];
	int32_t touch_int;
	int32_t touch_tens;
	uint8_t percentage;
	if(g_actual_screen == k_touch_screen)
	{
		touch_int 	= (int32_t)touchVoltage;
		touch_tens 	= (int32_t)((touchVoltage-(float32_t)touch_int)*100.0);
		percentage  = (int32_t)(touchVoltage*100.0/3.3);
		int_to_string(touch_int, new_string, 1);
		new_string[1] = '.';
		int_to_string(touch_tens, new_string+2, 2);
		new_string[4] = 0;
		lv_arc_set_value(guider_ui.touch_measure_screen_TouchArc, percentage);
		lv_label_set_text(guider_ui.touch_measure_screen_ElectrodeLabel, new_string);
	}
}

void screen_setAccelButton(uint8_t enable)
{
	if(g_actual_screen == k_menu_screen)
	{
		if(enable)
		{
			lv_obj_set_style_bg_color(guider_ui.menu_screen_AccelBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
		    //lv_obj_set_style_text_color(guider_ui.menu_screen_AccelBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
		}
		else
		{
			lv_obj_set_style_bg_color(guider_ui.menu_screen_AccelBTN, lv_color_hex(0x828282), LV_PART_MAIN|LV_STATE_DEFAULT);
		    //lv_obj_set_style_text_color(guider_ui.menu_screen_AccelBTN, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
		}
	}
}

void screen_setRPMLabel(int16_t rpm)
{
	char new_string[5];
	if(g_actual_screen == k_control_panel_screen)
	{
		int_to_string(rpm, new_string, 4);
		new_string[4] = 0;
		lv_label_set_text(guider_ui.control_panel_screen_RPMLabel, new_string);
	}
}

void screen_setRPMGraphic(int16_t rpm)
{
	static uint8_t s_index = 0;
	if(g_actual_screen == k_control_panel_screen)
	{
		lv_chart_set_value_by_id(guider_ui.control_panel_screen_RPMChart, guider_ui.control_panel_screen_RPMChart_0, s_index, rpm);
		s_index = (s_index < (ELEMENTS_IN_RPM_CHART-1))? (s_index + 1):0;
	}
}

screen_time_t screen_getConfigTime(void)
{
	screen_time_t time;
	if(g_actual_screen == k_setTime_screen)
	{
		time.hours = lv_roller_get_selected(guider_ui.set_time_screen_HourRoller) + 1;
		time.minutes = lv_roller_get_selected(guider_ui.set_time_screen_MinutesTensRoller)*10;
		time.minutes += lv_roller_get_selected(guider_ui.set_time_screen_MinutesUnitsRoller);
		time.meridian = (lv_roller_get_selected(guider_ui.set_time_screen_MeridianRoller) == 0)? k_screen_am:k_screen_pm;
		time.seconds	= 0;
	}
	return time;
}

void screen_getRPMSliderEvent()
{

}

void screen_setRPMSlider(int32_t val)
{
	xSemaphoreTake(g_slider_sem, portMAX_DELAY);
	g_rpm_slider = val;
	if(g_actual_screen == k_control_panel_screen)
	{
		lv_slider_set_value(guider_ui.control_panel_screen_RPMSlider, val, LV_ANIM_OFF);
	}
	xSemaphoreGive(g_slider_sem);
}

int32_t screen_getRPMSlider(void)
{
	if(g_actual_screen == k_control_panel_screen)
	{
		return lv_slider_get_value(guider_ui.control_panel_screen_RPMSlider);
	}
	return 0;
}

void screen_refreshRPMSlider(void)
{
	if(g_actual_screen == k_control_panel_screen)
	{
		lv_slider_set_value(guider_ui.control_panel_screen_RPMSlider, g_rpm_slider, LV_ANIM_OFF);
	}
}

int32_t screen_getRPMSliderSave(void)
{
	return g_rpm_slider;
}

uint8_t screen_getCheckButtonState(void)
{
	uint8_t retval = 0;
	if(g_actual_screen == k_init_screen)
	{
		retval = (lv_obj_get_state(guider_ui.init_screen_ip_manual_check_box)&LV_STATE_CHECKED)? 1:0;
	}
	return retval;
}

void screenTask(void*args)
{
	static uint16_t s_ticks_to_event = (MS_UPDATE_EVENT/MS_TASK_DELAY)-1;
	static uint16_t s_count			 = (MS_UPDATE_EVENT/MS_TASK_DELAY)-1;

	vTaskSetApplicationTaskTag( NULL, ( void * ) 1);/*Task Tag*/

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    g_slider_sem = xSemaphoreCreateBinary();
	xSemaphoreGive(g_slider_sem);

    g_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    g_event_callback(k_screen_init_event);

    for (;;)
    {
    	if(s_count == 0)
    	{
    		s_count = s_ticks_to_event;
    		g_event_callback(k_screen_update_event);
    	}
    	else
    	{
    		s_count --;
    	}
        lv_task_handler();
        vTaskDelay(MS_TASK_DELAY);
    }
}

void screenTick(void)
{
    if (g_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}
