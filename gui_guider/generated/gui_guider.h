/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *init_screen;
	bool init_screen_del;
	lv_obj_t *init_screen_HourLabel;
	lv_obj_t *init_screen_label_1;
	lv_obj_t *init_screen_MCUTempLabel;
	lv_obj_t *init_screen_label_2;
	lv_obj_t *init_screen_BRDTempLabel;
	lv_obj_t *init_screen_DateLabel;
	lv_obj_t *init_screen_label_3;
	lv_obj_t *init_screen_master_btn;
	lv_obj_t *init_screen_master_btn_label;
	lv_obj_t *init_screen_interface_btn;
	lv_obj_t *init_screen_interface_btn_label;
	lv_obj_t *init_screen_ip_manual_check_box;
	lv_obj_t *connection_config_screen;
	bool connection_config_screen_del;
	lv_obj_t *connection_config_screen_label_1;
	lv_obj_t *connection_config_screen_label_2;
	lv_obj_t *connection_config_screen_label_3;
	lv_obj_t *connection_config_screen_label_4;
	lv_obj_t *connection_config_screen_label_8;
	lv_obj_t *connection_config_screen_label_5;
	lv_obj_t *connection_config_screen_label_6;
	lv_obj_t *connection_config_screen_label_7;
	lv_obj_t *connection_config_screen_HourLabel;
	lv_obj_t *connection_config_screen_MCUTempLabel;
	lv_obj_t *connection_config_screen_BRDTempLabel;
	lv_obj_t *connection_config_screen_DateLabel;
	lv_obj_t *connection_config_screen_static_ip_check_box;
	lv_obj_t *connection_config_screen_SaveIPBTN;
	lv_obj_t *connection_config_screen_SaveIPBTN_label;
	lv_obj_t *connection_config_screen_IPCnf1;
	lv_obj_t *connection_config_screen_IPCnf1_label;
	lv_obj_t *connection_config_screen_IPCnf2;
	lv_obj_t *connection_config_screen_IPCnf2_label;
	lv_obj_t *connection_config_screen_IPCnf3;
	lv_obj_t *connection_config_screen_IPCnf3_label;
	lv_obj_t *connection_config_screen_IPCnf4;
	lv_obj_t *connection_config_screen_IPCnf4_label;
	lv_obj_t *connection_config_screen_N1Btn;
	lv_obj_t *connection_config_screen_N1Btn_label;
	lv_obj_t *connection_config_screen_N2Btn;
	lv_obj_t *connection_config_screen_N2Btn_label;
	lv_obj_t *connection_config_screen_N3Btn;
	lv_obj_t *connection_config_screen_N3Btn_label;
	lv_obj_t *connection_config_screen_N4Btn;
	lv_obj_t *connection_config_screen_N4Btn_label;
	lv_obj_t *connection_config_screen_N5Btn;
	lv_obj_t *connection_config_screen_N5Btn_label;
	lv_obj_t *connection_config_screen_N6Btn;
	lv_obj_t *connection_config_screen_N6Btn_label;
	lv_obj_t *connection_config_screen_N7Btn;
	lv_obj_t *connection_config_screen_N7Btn_label;
	lv_obj_t *connection_config_screen_N8Btn;
	lv_obj_t *connection_config_screen_N8Btn_label;
	lv_obj_t *connection_config_screen_N9Btn;
	lv_obj_t *connection_config_screen_N9Btn_label;
	lv_obj_t *connection_config_screen_N0Btn;
	lv_obj_t *connection_config_screen_N0Btn_label;
	lv_obj_t *server_ip_screen;
	bool server_ip_screen_del;
	lv_obj_t *server_ip_screen_label_1;
	lv_obj_t *server_ip_screen_label_2;
	lv_obj_t *server_ip_screen_label_3;
	lv_obj_t *server_ip_screen_label_7;
	lv_obj_t *server_ip_screen_label_5;
	lv_obj_t *server_ip_screen_label_6;
	lv_obj_t *server_ip_screen_label_8;
	lv_obj_t *server_ip_screen_label_9;
	lv_obj_t *server_ip_screen_MCUTempLabel;
	lv_obj_t *server_ip_screen_BRDTempLabel;
	lv_obj_t *server_ip_screen_HourLabel;
	lv_obj_t *server_ip_screen_DateLabel;
	lv_obj_t *server_ip_screen_SaveIPBTN;
	lv_obj_t *server_ip_screen_SaveIPBTN_label;
	lv_obj_t *server_ip_screen_IPCnf1;
	lv_obj_t *server_ip_screen_IPCnf1_label;
	lv_obj_t *server_ip_screen_IPCnf2;
	lv_obj_t *server_ip_screen_IPCnf2_label;
	lv_obj_t *server_ip_screen_IPCnf3;
	lv_obj_t *server_ip_screen_IPCnf3_label;
	lv_obj_t *server_ip_screen_IPCnf4;
	lv_obj_t *server_ip_screen_IPCnf4_label;
	lv_obj_t *server_ip_screen_N1Btn;
	lv_obj_t *server_ip_screen_N1Btn_label;
	lv_obj_t *server_ip_screen_N2Btn;
	lv_obj_t *server_ip_screen_N2Btn_label;
	lv_obj_t *server_ip_screen_N3Btn;
	lv_obj_t *server_ip_screen_N3Btn_label;
	lv_obj_t *server_ip_screen_N4Btn;
	lv_obj_t *server_ip_screen_N4Btn_label;
	lv_obj_t *server_ip_screen_N5Btn;
	lv_obj_t *server_ip_screen_N5Btn_label;
	lv_obj_t *server_ip_screen_N6Btn;
	lv_obj_t *server_ip_screen_N6Btn_label;
	lv_obj_t *server_ip_screen_N7Btn;
	lv_obj_t *server_ip_screen_N7Btn_label;
	lv_obj_t *server_ip_screen_N8Btn;
	lv_obj_t *server_ip_screen_N8Btn_label;
	lv_obj_t *server_ip_screen_N9Btn;
	lv_obj_t *server_ip_screen_N9Btn_label;
	lv_obj_t *server_ip_screen_N0Btn;
	lv_obj_t *server_ip_screen_N0Btn_label;
	lv_obj_t *stand_by_screen;
	bool stand_by_screen_del;
	lv_obj_t *stand_by_screen_IPLabel;
	lv_obj_t *stand_by_screen_DateLabel;
	lv_obj_t *stand_by_screen_HourLabel;
	lv_obj_t *menu_screen;
	bool menu_screen_del;
	lv_obj_t *menu_screen_label_1;
	lv_obj_t *menu_screen_label_2;
	lv_obj_t *menu_screen_label_3;
	lv_obj_t *menu_screen_HourLabel;
	lv_obj_t *menu_screen_MCUTempLabel;
	lv_obj_t *menu_screen_BRDTempLabel;
	lv_obj_t *menu_screen_DateLabel;
	lv_obj_t *menu_screen_IPLabel;
	lv_obj_t *menu_screen_PerformanceBTN;
	lv_obj_t *menu_screen_PerformanceBTN_label;
	lv_obj_t *menu_screen_TemperatureBTN;
	lv_obj_t *menu_screen_TemperatureBTN_label;
	lv_obj_t *menu_screen_AccelBTN;
	lv_obj_t *menu_screen_AccelBTN_label;
	lv_obj_t *menu_screen_TouchSenseBTN;
	lv_obj_t *menu_screen_TouchSenseBTN_label;
	lv_obj_t *menu_screen_TimeBTN;
	lv_obj_t *menu_screen_TimeBTN_label;
	lv_obj_t *menu_screen_PanelBTN;
	lv_obj_t *menu_screen_PanelBTN_label;
	lv_obj_t *cpu_performance_screen;
	bool cpu_performance_screen_del;
	lv_obj_t *cpu_performance_screen_label_1;
	lv_obj_t *cpu_performance_screen_label_2;
	lv_obj_t *cpu_performance_screen_label_3;
	lv_obj_t *cpu_performance_screen_label_4;
	lv_obj_t *cpu_performance_screen_label_5;
	lv_obj_t *cpu_performance_screen_label_6;
	lv_obj_t *cpu_performance_screen_label_7;
	lv_obj_t *cpu_performance_screen_label_8;
	lv_obj_t *cpu_performance_screen_label_9;
	lv_obj_t *cpu_performance_screen_label_10;
	lv_obj_t *cpu_performance_screen_label_11;
	lv_obj_t *cpu_performance_screen_label_12;
	lv_obj_t *cpu_performance_screen_label_13;
	lv_obj_t *cpu_performance_screen_label_14;
	lv_obj_t *cpu_performance_screen_label_15;
	lv_obj_t *cpu_performance_screen_BRDTempLabel;
	lv_obj_t *cpu_performance_screen_MCUTempLabel;
	lv_obj_t *cpu_performance_screen_HourLabel;
	lv_obj_t *cpu_performance_screen_DateLabel;
	lv_obj_t *cpu_performance_screen_IPLabel;
	lv_obj_t *cpu_performance_screen_MenuBTN;
	lv_obj_t *cpu_performance_screen_MenuBTN_label;
	lv_obj_t *cpu_performance_screen_LvglArc;
	lv_obj_t *cpu_performance_screen_EthernetArc;
	lv_obj_t *cpu_performance_screen_SensorArc;
	lv_obj_t *cpu_performance_screen_IdleArc1;
	lv_obj_t *cpu_performance_screen_MotorControlArc;
	lv_obj_t *cpu_performance_screen_IdleArc2;
	lv_obj_t *cpu_performance_screen_img_2;
	lv_obj_t *temperature_measure_screen;
	bool temperature_measure_screen_del;
	lv_obj_t *temperature_measure_screen_label_1;
	lv_obj_t *temperature_measure_screen_label_2;
	lv_obj_t *temperature_measure_screen_label_3;
	lv_obj_t *temperature_measure_screen_MCUTempLabel;
	lv_obj_t *temperature_measure_screen_BRDTempLabel;
	lv_obj_t *temperature_measure_screen_HourLabel;
	lv_obj_t *temperature_measure_screen_DateLabel;
	lv_obj_t *temperature_measure_screen_IPLabel;
	lv_obj_t *temperature_measure_screen_MenuBTN;
	lv_obj_t *temperature_measure_screen_MenuBTN_label;
	lv_obj_t *temperature_measure_screen_MCUTempMeter;
	lv_obj_t *temperature_measure_screen_MCUTempMeter_ndline_0;
	lv_obj_t *temperature_measure_screen_BRDTempMeter;
	lv_obj_t *temperature_measure_screen_BRDTempMeter_ndline_0;
	lv_obj_t *temperature_measure_screen_label_4;
	lv_obj_t *temperature_measure_screen_label_5;
	lv_obj_t *temperature_measure_screen_label_6;
	lv_obj_t *temperature_measure_screen_label_7;
	lv_obj_t *temperature_measure_screen_MCUTempScreenLabel;
	lv_obj_t *temperature_measure_screen_BRDTempScreenLabel;
	lv_obj_t *accelerometer_measure_screen;
	bool accelerometer_measure_screen_del;
	lv_obj_t *accelerometer_measure_screen_label_1;
	lv_obj_t *accelerometer_measure_screen_label_2;
	lv_obj_t *accelerometer_measure_screen_label_3;
	lv_obj_t *accelerometer_measure_screen_label_4;
	lv_obj_t *accelerometer_measure_screen_label_5;
	lv_obj_t *accelerometer_measure_screen_label_6;
	lv_obj_t *accelerometer_measure_screen_MenuBTN;
	lv_obj_t *accelerometer_measure_screen_MenuBTN_label;
	lv_obj_t *accelerometer_measure_screen_MCUTempLabel;
	lv_obj_t *accelerometer_measure_screen_BRDTempLabel;
	lv_obj_t *accelerometer_measure_screen_HourLabel;
	lv_obj_t *accelerometer_measure_screen_DateLabel;
	lv_obj_t *accelerometer_measure_screen_IPLabel;
	lv_obj_t *accelerometer_measure_screen_AccelZBar;
	lv_obj_t *accelerometer_measure_screen_AccelYBar;
	lv_obj_t *accelerometer_measure_screen_AccelXBar;
	lv_obj_t *accelerometer_measure_screen_AccelXLabel;
	lv_obj_t *accelerometer_measure_screen_AccelYLabel;
	lv_obj_t *accelerometer_measure_screen_AccelZLabel;
	lv_obj_t *touch_measure_screen;
	bool touch_measure_screen_del;
	lv_obj_t *touch_measure_screen_label_1;
	lv_obj_t *touch_measure_screen_label_2;
	lv_obj_t *touch_measure_screen_label_3;
	lv_obj_t *touch_measure_screen_label_4;
	lv_obj_t *touch_measure_screen_MenuBTN;
	lv_obj_t *touch_measure_screen_MenuBTN_label;
	lv_obj_t *touch_measure_screen_MCUTempLabel;
	lv_obj_t *touch_measure_screen_BRDTempLabel;
	lv_obj_t *touch_measure_screen_HourLabel;
	lv_obj_t *touch_measure_screen_DateLabel;
	lv_obj_t *touch_measure_screen_IPLabel;
	lv_obj_t *touch_measure_screen_ElectrodeLabel;
	lv_obj_t *touch_measure_screen_TouchArc;
	lv_obj_t *touch_measure_screen_img_2;
	lv_obj_t *set_time_screen;
	bool set_time_screen_del;
	lv_obj_t *set_time_screen_label_1;
	lv_obj_t *set_time_screen_label_2;
	lv_obj_t *set_time_screen_label_3;
	lv_obj_t *set_time_screen_label_4;
	lv_obj_t *set_time_screen_label_5;
	lv_obj_t *set_time_screen_MenuBTN;
	lv_obj_t *set_time_screen_MenuBTN_label;
	lv_obj_t *set_time_screen_SetBtn;
	lv_obj_t *set_time_screen_SetBtn_label;
	lv_obj_t *set_time_screen_MCUTempLabel;
	lv_obj_t *set_time_screen_BRDTempLabel;
	lv_obj_t *set_time_screen_DateLabel;
	lv_obj_t *set_time_screen_HourLabel;
	lv_obj_t *set_time_screen_IPLabel;
	lv_obj_t *set_time_screen_HourRoller;
	lv_obj_t *set_time_screen_MinutesTensRoller;
	lv_obj_t *set_time_screen_MinutesUnitsRoller;
	lv_obj_t *set_time_screen_MeridianRoller;
	lv_obj_t *control_panel_screen;
	bool control_panel_screen_del;
	lv_obj_t *control_panel_screen_label_1;
	lv_obj_t *control_panel_screen_label_2;
	lv_obj_t *control_panel_screen_label_3;
	lv_obj_t *control_panel_screen_label_4;
	lv_obj_t *control_panel_screen_MenuBTN;
	lv_obj_t *control_panel_screen_MenuBTN_label;
	lv_obj_t *control_panel_screen_MCUTempLabel;
	lv_obj_t *control_panel_screen_BRDTempLabel;
	lv_obj_t *control_panel_screen_HourLabel;
	lv_obj_t *control_panel_screen_DateLabel;
	lv_obj_t *control_panel_screen_IPLabel;
	lv_obj_t *control_panel_screen_RPMLabel;
	lv_obj_t *control_panel_screen_RPMChart;
	lv_chart_series_t *control_panel_screen_RPMChart_0;
	lv_obj_t *control_panel_screen_RPMSlider;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_init_screen(lv_ui *ui);
void setup_scr_connection_config_screen(lv_ui *ui);
void setup_scr_server_ip_screen(lv_ui *ui);
void setup_scr_stand_by_screen(lv_ui *ui);
void setup_scr_menu_screen(lv_ui *ui);
void setup_scr_cpu_performance_screen(lv_ui *ui);
void setup_scr_temperature_measure_screen(lv_ui *ui);
void setup_scr_accelerometer_measure_screen(lv_ui *ui);
void setup_scr_touch_measure_screen(lv_ui *ui);
void setup_scr_set_time_screen(lv_ui *ui);
void setup_scr_control_panel_screen(lv_ui *ui);

LV_IMAGE_DECLARE(_Slide2_RGB565A8_480x320);

LV_FONT_DECLARE(lv_font_montserratMedium_11)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_60)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_12)


#ifdef __cplusplus
}
#endif
#endif
