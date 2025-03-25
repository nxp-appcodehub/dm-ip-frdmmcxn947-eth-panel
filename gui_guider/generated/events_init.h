/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_

#include "gui_guider.h"
#include "screen.h"

void events_init(lv_ui *ui);

void set_Callback(screenCallback callback);

void events_init_init_screen(lv_ui *ui);
void events_init_connection_config_screen(lv_ui *ui);
void events_init_server_ip_screen(lv_ui *ui);
void events_init_stand_by_screen(lv_ui *ui);
void events_init_menu_screen(lv_ui *ui);
void events_init_cpu_performance_screen(lv_ui *ui);
void events_init_temperature_measure_screen(lv_ui *ui);
void events_init_accelerometer_measure_screen(lv_ui *ui);
void events_init_touch_measure_screen(lv_ui *ui);
void events_init_set_time_screen(lv_ui *ui);
void events_init_control_panel_screen(lv_ui *ui);

#endif /* EVENT_CB_H_ */
