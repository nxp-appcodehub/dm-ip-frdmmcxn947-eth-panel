/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

static screenCallback g_callback = 0;

// Screen API Management -------------------------------------
void set_Callback(screenCallback callback)
{
	g_callback = callback;
}
// -----------------------------------------------------------


// Init Screen Events ----------------------------------------
static void init_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void init_screen_master_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_masterBtn_event);
		break;
	}
	default:
		break;
	}
}
static void init_screen_interface_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_interfaceBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_init_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->init_screen, init_screen_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(ui->init_screen_master_btn, init_screen_master_btn_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(ui->init_screen_interface_btn, init_screen_interface_btn_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// Common Screen Events of ip --------------------------------
void SaveBTN_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_save_btn_event);
    }
}

void IPMask1_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_ip_mask_0_event);
    }
}

void IPMask2_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_ip_mask_1_event);
    }
}

void IPMask3_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_ip_mask_2_event);
    }
}

void IPMask4_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_ip_mask_3_event);
    }
}

void N0Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number0_btn_event);
    }
}

void N1Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number1_btn_event);
    }
}

void N2Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number2_btn_event);
    }
}

void N3Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number3_btn_event);
    }
}

void N4Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number4_btn_event);
    }
}

void N5Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number5_btn_event);
    }
}

void N6Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number6_btn_event);
    }
}

void N7Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number7_btn_event);
    }
}

void N8Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number8_btn_event);
    }
}

void N9Btn_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_number9_btn_event);
    }
}
// -----------------------------------------------------------




// ConnectionConfig Screen Events ----------------------------
void connectionConfig_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_clicked_event);
    }
}

void dhcpSelected_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_dhcp_selected_event);
    }
}

void staticSelected_sceen_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
    	g_callback(k_screen_static_selected_event);
    }
}

void events_init_connection_config_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->connection_config_screen, connectionConfig_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_ConnectionModeRad_item0, dhcpSelected_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_ConnectionModeRad_item1, staticSelected_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_IPCnf1, IPMask1_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_IPCnf2, IPMask2_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_IPCnf3, IPMask3_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_IPCnf4, IPMask4_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_SaveIPBTN, SaveBTN_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N0Btn, N0Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N1Btn, N1Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N2Btn, N2Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N3Btn, N3Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N4Btn, N4Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N5Btn, N5Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N6Btn, N6Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N7Btn, N7Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N8Btn, N8Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->connection_config_screen_N9Btn, N9Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// ServerIP Screen Events ------------------------------------
void events_init_server_ip_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->server_ip_screen, connectionConfig_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_IPCnf1, IPMask1_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_IPCnf2, IPMask2_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_IPCnf3, IPMask3_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_IPCnf4, IPMask4_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_SaveIPBTN, SaveBTN_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N0Btn, N0Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N1Btn, N1Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N2Btn, N2Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N3Btn, N3Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N4Btn, N4Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N5Btn, N5Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N6Btn, N6Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N7Btn, N7Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N8Btn, N8Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->server_ip_screen_N9Btn, N9Btn_sceen_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// StandBy Screen Events -------------------------------------
static void stand_by_screen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_standByTouch_event);
		break;
	}
	default:
		break;
	}
}

void events_init_stand_by_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->stand_by_screen, stand_by_screen_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// Menu Screen Events ----------------------------------------
static void menu_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void menu_screen_PerformanceBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuPerfBtn_event);
		break;
	}
	default:
		break;
	}
}

static void menu_screen_TemperatureBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuTempBtn_event);
		break;
	}
	default:
		break;
	}
}

static void menu_screen_AccelBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuAccBtn_event);
		break;
	}
	default:
		break;
	}
}

static void menu_screen_TouchSenseBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuTouchBtn_event);
		break;
	}
	default:
		break;
	}
}

static void menu_screen_TimeBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuSetTimeBtn_event);
		break;
	}
	default:
		break;
	}
}

static void menu_screen_PanelBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuCtrlPanelBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_menu_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->menu_screen, menu_screen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->menu_screen_PerformanceBTN, menu_screen_PerformanceBTN_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->menu_screen_TemperatureBTN, menu_screen_TemperatureBTN_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->menu_screen_AccelBTN, menu_screen_AccelBTN_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->menu_screen_TouchSenseBTN, menu_screen_TouchSenseBTN_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->menu_screen_TimeBTN, menu_screen_TimeBTN_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->menu_screen_PanelBTN, menu_screen_PanelBTN_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// CPUPerformance Screen Events ------------------------------
static void cpu_performance_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void cpu_performance_screen_MenuBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_cpu_performance_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->cpu_performance_screen, cpu_performance_screen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->cpu_performance_screen_MenuBTN, cpu_performance_screen_MenuBTN_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// Temperature Screen Events ---------------------------------
static void temperature_measure_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void temperature_measure_screen_MenuBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_temperature_measure_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->temperature_measure_screen, temperature_measure_screen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->temperature_measure_screen_MenuBTN, temperature_measure_screen_MenuBTN_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// Accelerometer Screen Events -------------------------------
static void accelerometer_measure_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void accelerometer_measure_screen_MenuBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_accelerometer_measure_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->accelerometer_measure_screen, accelerometer_measure_screen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->accelerometer_measure_screen_MenuBTN, accelerometer_measure_screen_MenuBTN_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// Touch Screen Events ---------------------------------------
static void touch_measure_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void touch_measure_screen_MenuBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_touch_measure_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->touch_measure_screen, touch_measure_screen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->touch_measure_screen_MenuBTN, touch_measure_screen_MenuBTN_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// SetTime Screen Events -------------------------------------
static void set_time_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void set_time_screen_MenuBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuBtn_event);
		break;
	}
	default:
		break;
	}
}

static void set_time_screen_SetBtn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_setTimeBtn_event);
		break;
	}
	default:
		break;
	}
}

void events_init_set_time_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->set_time_screen, set_time_screen_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->set_time_screen_MenuBTN, set_time_screen_MenuBTN_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->set_time_screen_SetBtn, set_time_screen_SetBtn_event_handler, LV_EVENT_CLICKED, ui);
}
// -----------------------------------------------------------




// ControlPanel Screen Events --------------------------------
static void control_panel_screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	g_callback(k_screen_clicked_event);
        break;
    }
    default:
        break;
    }
}

static void control_panel_screen_MenuBTN_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		g_callback(k_screen_menuBtn_event);
		break;
	}
	default:
		break;
	}
}

static void control_panel_screen_RPMSlider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		g_callback(k_screen_rpmReleased_event);
		break;
	}
	case LV_EVENT_PRESSED:
		g_callback(k_screen_rpmPressed_event);
	break;
	default:
		break;
	}
}
void events_init_control_panel_screen(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->control_panel_screen, control_panel_screen_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(ui->control_panel_screen_MenuBTN, control_panel_screen_MenuBTN_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(ui->control_panel_screen_RPMSlider, control_panel_screen_RPMSlider_event_handler, LV_EVENT_ALL, ui);
}
// -----------------------------------------------------------

void events_init(lv_ui *ui)
{

}
