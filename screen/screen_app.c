/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <eth_comunication.h>
#include "screen_app.h"
#include "FreeRTOS.h"
#include "task.h"
#include "motor_control.h"
#include "usb_comunication.h"
#include "can_comunication.h"


static comunication_transfer_t *g_comunication_data;
static uint32_t					g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
static bool						g_ip_config_ready = false;
static bool    					g_standBy = false;
static screen_app_mode_t		g_mode = k_screen_app_master;

static bool						g_slider_is_pressed = false;

static screen_ip_mode_t			g_ip_mode				      	= k_screen_dhcp;
static uint8_t					g_config_ip[4]				  	= {192, 168, 1, 110};
static uint32_t					g_internal_ip				  	= 0;
static uint32_t					g_server_ip					  	= 0;
static uint8_t					g_ipconf_mask_selected	  	  	= 0;
static uint8_t 					g_multiplier 					= 100;
static uint8_t 					g_update_slider_count 			= 0;

void performance_core1_update(screen_app_mode_t mode);
void performance_core2_update(screen_app_mode_t mode);
void performance_update(screen_app_mode_t mode);
void accelerometer_update(screen_app_mode_t mode);
void brd_temperature_update(screen_app_mode_t mode);
void mcu_temperature_update(screen_app_mode_t mode);
void date_update(screen_app_mode_t mode);
void rpm_update(screen_app_mode_t mode);
void time_update(screen_app_mode_t mode);
void touch_update(screen_app_mode_t mode);
void set_time_event(screen_app_mode_t mode);
void screenApp_init_eventHandler();
void screenApp_clickScreen_eventHandler();
void screenApp_MasterBTN_eventHandler();
void screenApp_InterfaceBTN_eventHandler();
void screenApp_SaveBTN_eventHandler();
void screenApp_MenuBTN_eventHandler();
void screenApp_MenuPerfBTN_eventHandler();
void screenApp_MenuTempBTN_eventHandler();
void screenApp_MenuAccBTN_eventHandler();
void screenApp_MenuTouchBTN_eventHandler();
void screenApp_MenuSetTimeBTN_eventHandler();
void screenApp_MenuControlPanelBTN_eventHandler();
void screenApp_StandByScreenClick_eventHandler();
void screenApp_SetTimeBTN_eventHandler();
void screenApp_RPMUpdate_eventHandler();
void screenApp_ScreenUpdate_eventHandler();
void screenApp_IPMaskCnf_eventHandler(uint8_t n_mask);
void screenApp_NumberBTN_eventHandler(uint8_t number);
void screenApp_ConnectionMode_ForceUpdate(screen_ip_mode_t mode);
void screenApp_ConnectionMode_eventHandler(screen_ip_mode_t mode);

void screenApp_setIP(uint32_t ip)
{
	((uint8_t*)&g_internal_ip)[0] = ((uint8_t*)&ip)[3];
	((uint8_t*)&g_internal_ip)[1] = ((uint8_t*)&ip)[2];
	((uint8_t*)&g_internal_ip)[2] = ((uint8_t*)&ip)[1];
	((uint8_t*)&g_internal_ip)[3] = ((uint8_t*)&ip)[0];
	screen_setIPMask(g_internal_ip);
}

void performance_core1_update(screen_app_mode_t mode)
{
	measures_performance_core1_t performance_c1;
	screen_perf_core1_t screen_perf_c1;

	if(mode == k_screen_app_master)
	{
		performance_c1 = measures_get_performance_core1();
		screen_perf_c1.idle_perf = performance_c1.measures_idle_perf_core1;
		screen_perf_c1.ethernet_perf = performance_c1.measures_ethernet_perf_core1;
		screen_perf_c1.lvgl_perf = performance_c1.measures_lvgl_perf_core1;
		screen_perf_c1.sensor_perf = performance_c1.measures_sensors_perf_core1_t;
		screen_perf_c1.motor_perf = performance_c1.measures_motor_perf_core1_t;
	}
	else
	{
		screen_perf_c1.idle_perf 		= g_comunication_data->comunication_data.comunication_performance.comunication_idle_core_1;
		screen_perf_c1.ethernet_perf 	= g_comunication_data->comunication_data.comunication_performance.comunication_ethernet_core_1;
		screen_perf_c1.lvgl_perf 		= g_comunication_data->comunication_data.comunication_performance.comunication_lvgl_core_1;
		screen_perf_c1.sensor_perf 		= g_comunication_data->comunication_data.comunication_performance.comunication_sensors_core_1;
		screen_perf_c1.motor_perf		= g_comunication_data->comunication_data.comunication_performance.comunication_motor_control_core_1;
	}
	screen_setPerfCore1(screen_perf_c1);
}

void performance_core2_update(screen_app_mode_t mode)
{
	measures_performance_core2_t performance_c2;
	screen_perf_core2_t screen_perf_c2;

	performance_c2 = measures_get_performance_core2();
	screen_perf_c2.idle_perf = performance_c2.measures_idle_perf_core2;
	screen_perf_c2.motorControl_perf = performance_c2.measures_motorControl_perf_core2;
	screen_setPerfCore2(screen_perf_c2);
}

void performance_update(screen_app_mode_t mode)
{
	performance_core1_update(mode);
	performance_core2_update(mode);
}

void accelerometer_update(screen_app_mode_t mode)
{
	measures_accel_t accel;
	screen_accel_t screen_accel;
	if(mode == k_screen_app_master)
	{
		screen_setAccelButton(measuresAccelIsReady());
		if(measuresAccelIsReady())
		{
			accel = measures_get_accel_values();
			screen_accel.accelX = accel.accelX;
			screen_accel.accelY = accel.accelY;
			screen_accel.accelZ = accel.accelZ;
		}
		else
		{
			screen_accel.accelX = 0;
			screen_accel.accelY = 0;
			screen_accel.accelZ = 0;
		}
	}
	else
	{
		if(g_comunication_data->comunication_data.comunication_accel.accel_enable)
		{
			screen_accel.accelX = g_comunication_data->comunication_data.comunication_accel.comunication_accel_x;
			screen_accel.accelY = g_comunication_data->comunication_data.comunication_accel.comunication_accel_y;
			screen_accel.accelZ = g_comunication_data->comunication_data.comunication_accel.comunication_accel_z;
		}
		else
		{
			screen_accel.accelX = 0;
			screen_accel.accelY = 0;
			screen_accel.accelZ = 0;
		}
		screen_setAccelButton(g_comunication_data->comunication_data.comunication_accel.accel_enable);
	}
	screen_setAccel(screen_accel);
}

void brd_temperature_update(screen_app_mode_t mode)
{
	float32_t temperature;
	if(mode == k_screen_app_master)
	{
		temperature = measures_get_brd_temperature();
	}
	else
	{
		temperature = g_comunication_data->comunication_data.comunication_temperature.comunication_brd_temperature;
	}
	//screen_setBRDTemp(temperature);
}

void mcu_temperature_update(screen_app_mode_t mode)
{
	float32_t temperature;
	if(mode == k_screen_app_master)
	{
		temperature = measures_get_mcu_temperature();
	}
	else
	{
		temperature = g_comunication_data->comunication_data.comunication_temperature.comunication_mcu_temperature;
	}
	screen_setMCUTemp(temperature);
	screen_setBRDTemp(temperature);
}

void date_update(screen_app_mode_t mode)
{
	screen_date_t screen_date;
	measures_date_t date;
	if(mode == k_screen_app_master)
	{
		date = measures_get_date();
		screen_date.day = date.day;
		screen_date.month = date.month;
		screen_date.year = date.year;
	}
	else
	{
		screen_date.day = g_comunication_data->comunication_data.comunication_date.comunication_day;
		screen_date.month = g_comunication_data->comunication_data.comunication_date.comunication_month;
		screen_date.year = g_comunication_data->comunication_data.comunication_date.comunication_year;
	}
	screen_setDate(screen_date);
}

void rpm_update(screen_app_mode_t mode)
{
	static uint8_t s_can_send_count = CAN_SEND_COUNT;
	int32_t rpm;
	int32_t slider;
	if(mode == k_screen_app_master)
	{
		slider = screen_getRPMSliderSave();
		rpm = measures_get_rpm();
	}
	else
	{
		slider = g_comunication_data->comunication_data.comunication_motor.comunication_motor_rpm_slider;
		rpm = g_comunication_data->comunication_data.comunication_motor.comunication_motor_rpm;
		if(!g_slider_is_pressed)
		{
			if(g_update_slider_count == 0)
			{
				screen_setRPMSlider(slider);
			}
			else
			{
				g_update_slider_count --;
			}
		}
	}

	if(!s_can_send_count)
	{
		s_can_send_count = CAN_SEND_COUNT;
		can_send_to_ip(screen_getRPMSliderSave(), rpm);
	}
	else
	{
		s_can_send_count --;
	}
	usb_update_values(rpm, slider);
	screen_setRPMGraphic(rpm);
	screen_setRPMLabel(rpm);
}

void time_update(screen_app_mode_t mode)
{
	screen_time_t screen_time;
	measures_time_t time;
	if(mode == k_screen_app_master)
	{
		time = measures_get_time();
		screen_time.hours = time.hours;
		screen_time.meridian = time.meridian;
		screen_time.minutes = time.minutes;
		screen_time.seconds = time.seconds;
	}
	else
	{
		screen_time.hours =  g_comunication_data->comunication_data.comunication_date.comunication_hours;
		screen_time.meridian = g_comunication_data->comunication_data.comunication_date.comunication_meridian;
		screen_time.minutes = g_comunication_data->comunication_data.comunication_date.comunication_minutes;
		screen_time.seconds = g_comunication_data->comunication_data.comunication_date.comunication_seconds;
	}
	screen_setTime(screen_time);
}

void touch_update(screen_app_mode_t mode)
{
	float32_t voltage;
	if(mode == k_screen_app_master)
	{
		voltage = measures_get_electrode();
	}
	else
	{

	}
	screen_setTouch(voltage);
}

void ip_internal_update()
{
	screen_setNumberLabelMask(0, g_config_ip[0]);
	screen_setNumberLabelMask(1, g_config_ip[1]);
	screen_setNumberLabelMask(2, g_config_ip[2]);
	screen_setNumberLabelMask(3, g_config_ip[3]);
}

void set_time_event(screen_app_mode_t mode)
{
	static comunication_transfer_t data_transfer;
	measures_time_t measure_time;
	screen_time_t screen_time_config;
	screen_time_config = screen_getConfigTime();
	if(mode == k_screen_app_master)
	{
		measure_time.hours = screen_time_config.hours;
		measure_time.meridian = screen_time_config.meridian;
		measure_time.minutes = screen_time_config.minutes;
		measure_time.seconds = 0;
		measures_set_time(measure_time);
	}
	else
	{
		data_transfer.comunication_command = k_comunication_command_send_date;
		data_transfer.comunication_data.comunication_date.comunication_hours = screen_time_config.hours;
		data_transfer.comunication_data.comunication_date.comunication_minutes = screen_time_config.minutes;
		data_transfer.comunication_data.comunication_date.comunication_meridian = screen_time_config.meridian;
		data_transfer.comunication_data.comunication_date.comunication_seconds = 0;
		comunication_send(comunication_get_socket(0), (uint8_t*)&data_transfer, sizeof(comunication_transfer_t), 0);
	}
}

screen_app_mode_t screenApp_getDemoMode(void)
{
	return g_mode;
}

void screenApp_setConnection(uint8_t auto_config)
{
	static uint32_t s_client_ip[2];
	g_multiplier 	= 100;
	if(g_mode == k_screen_app_master)
	{
		if(auto_config)
		{
			g_ip_mode = k_screen_static_ip;
			g_config_ip[0] = 192;
			g_config_ip[1] = 168;
			g_config_ip[2] = 001;
			g_config_ip[3] = 110;
		}
		if(g_ip_mode == k_screen_static_ip)
		{
			g_internal_ip = ((uint32_t)g_config_ip[0])<<24;
			g_internal_ip |= ((uint32_t)g_config_ip[1])<<16;
			g_internal_ip |= ((uint32_t)g_config_ip[2])<<8;
			g_internal_ip |= ((uint32_t)g_config_ip[3]);
		}
		else
		{
			g_internal_ip = 0;
		}
		xTaskCreate(server_socket_task, "server", configMINIMAL_STACK_SIZE + 200, (void*)&g_internal_ip, tskIDLE_PRIORITY + 3, NULL);
		screen_setScreen(k_menu_screen);
	}
	else
	{
		g_comunication_data = comunication_get_values();
		if(auto_config)
		{
			g_ip_config_ready = true;
			g_config_ip[0] = 192;
			g_config_ip[1] = 168;
			g_config_ip[2] = 001;
			g_config_ip[3] = 111;
			g_internal_ip = ((uint32_t)g_config_ip[0])<<24;
			g_internal_ip |= ((uint32_t)g_config_ip[1])<<16;
			g_internal_ip |= ((uint32_t)g_config_ip[2])<<8;
			g_internal_ip |= ((uint32_t)g_config_ip[3]);

			g_config_ip[3] = 110;
			g_server_ip = ((uint32_t)g_config_ip[0])<<24;
			g_server_ip |= ((uint32_t)g_config_ip[1])<<16;
			g_server_ip |= ((uint32_t)g_config_ip[2])<<8;
			g_server_ip |= ((uint32_t)g_config_ip[3]);

			s_client_ip[0] = g_internal_ip;
			s_client_ip[1] = g_server_ip;

			xTaskCreate(client_socket_task, "client", configMINIMAL_STACK_SIZE + 1000, (void*)s_client_ip, tskIDLE_PRIORITY + 3, NULL);
			screen_setScreen(k_menu_screen);
		}
		else
		{
			if(!g_ip_config_ready)
			{
				if(g_ip_mode == k_screen_static_ip)
				{
					g_internal_ip = ((uint32_t)g_config_ip[0])<<24;
					g_internal_ip |= ((uint32_t)g_config_ip[1])<<16;
					g_internal_ip |= ((uint32_t)g_config_ip[2])<<8;
					g_internal_ip |= ((uint32_t)g_config_ip[3]);
				}
				else
				{
					g_internal_ip = 0;
				}
				g_ip_config_ready = true;
				screen_setScreen(k_server_ip_screen);
			}
			else
			{
				g_server_ip = ((uint32_t)g_config_ip[0])<<24;
				g_server_ip |= ((uint32_t)g_config_ip[1])<<16;
				g_server_ip |= ((uint32_t)g_config_ip[2])<<8;
				g_server_ip |= ((uint32_t)g_config_ip[3]);
				s_client_ip[0] = g_internal_ip;
				s_client_ip[1] = g_server_ip;
				xTaskCreate(client_socket_task, "client", configMINIMAL_STACK_SIZE + 1000, (void*)s_client_ip, tskIDLE_PRIORITY + 3, NULL);
				screen_setScreen(k_menu_screen);
			}
		}
	}
	ip_internal_update();
	screen_setIPMask(g_internal_ip);
}

void screenApp_init_eventHandler()
{
	#if AUTO_CONFIG_NETWORK == 1
		#if MASTER_MODE == 1
			screenApp_MasterBTN_eventHandler();
		#else
			screen_setScreen(k_menu_screen);
		#endif
	#endif
}

void screenApp_clickScreen_eventHandler()
{
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
}

void screenApp_MasterBTN_eventHandler()
{
	g_mode = k_screen_app_master;
	if(screen_getCheckButtonState())
	{
		screen_setScreen(k_connection_config_screen);
		screenApp_ConnectionMode_ForceUpdate(k_screen_dhcp);
		ip_internal_update();
	}
	else
	{
		screenApp_setConnection(1);
	}
	mcu_temperature_update(g_mode);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
}

void screenApp_InterfaceBTN_eventHandler()
{
	g_mode = k_screen_app_interface;
	if(screen_getCheckButtonState())
	{
		screen_setScreen(k_connection_config_screen);
		screenApp_ConnectionMode_ForceUpdate(k_screen_dhcp);
		ip_internal_update();
	}
	else
	{
		screenApp_setConnection(1);
	}
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
}

void screenApp_SaveBTN_eventHandler()
{
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	screenApp_setConnection(0);
	mcu_temperature_update(g_mode);
}

void screenApp_MenuBTN_eventHandler()
{
	screen_setScreen(k_menu_screen);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	mcu_temperature_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_MenuPerfBTN_eventHandler()
{
	screen_setScreen(k_performance_screen);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	mcu_temperature_update(g_mode);
	performance_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_MenuTempBTN_eventHandler()
{
	screen_setScreen(k_temperature_screen);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	mcu_temperature_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_MenuAccBTN_eventHandler()
{
	screen_setScreen(k_accelerometer_screen);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	accelerometer_update(g_mode);
	mcu_temperature_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_MenuTouchBTN_eventHandler()
{
	screen_setScreen(k_touch_screen);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	mcu_temperature_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_MenuSetTimeBTN_eventHandler()
{
	screen_setScreen(k_setTime_screen);
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	mcu_temperature_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_MenuControlPanelBTN_eventHandler()
{
	screen_setScreen(k_control_panel_screen);
	screen_refreshRPMSlider();
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	mcu_temperature_update(g_mode);
	screen_setIPMask(g_internal_ip);
}

void screenApp_StandByScreenClick_eventHandler()
{
	screen_setPreviusScreen();
	screen_refreshRPMSlider();
	mcu_temperature_update(g_mode);
	screenApp_ConnectionMode_ForceUpdate(g_ip_mode);
	ip_internal_update();
	screen_setIPMask(g_internal_ip);
	g_standBy = false;
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
}

void screenApp_SetTimeBTN_eventHandler()
{
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	set_time_event(g_mode);
}

void screenApp_RPMUpdate_eventHandler()
{
	static comunication_transfer_t data_transfer;
	int32_t slider = screen_getRPMSlider();
	int32_t rpm	   = slider*40;
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	if(g_mode == k_screen_app_master)
	{
		screen_setRPMSlider(screen_getRPMSlider());
		motor_control_set_speed(rpm);
	}
	else
	{
		data_transfer.comunication_command = k_comunication_command_send_rpm;
		data_transfer.comunication_data.comunication_motor.comunication_motor_rpm = rpm;
		data_transfer.comunication_data.comunication_motor.comunication_motor_rpm_slider = slider;
		comunication_send(comunication_get_socket(0), (uint8_t*)&data_transfer, sizeof(comunication_transfer_t), 0);
	}
}

void screenApp_ScreenUpdate_eventHandler()
{
	static comunication_transfer_t data_transfer;
	static uint8_t send_server_msj_count = 2;
	static uint8_t start_count = 0;
	measure_updates_t updates;
	comunication_updates_t comunication_updates;

#if AUTO_CONFIG_NETWORK == 1
#if MASTER_MODE == 0
	if(start_count == 0)
	{
		vTaskDelay(15000);
		screenApp_InterfaceBTN_eventHandler();
		start_count = 1;
	}

#endif
#endif
	#if STAND_BY_ENABLE == 1
		if(g_standBy_count == 0)
		{
			if(!g_standBy)
			{
				screen_setScreen(k_standBy_screen);
				g_standBy = true;
				screen_setIPMask(g_internal_ip);
			}
		}
		else
		{
			g_standBy_count --;
		}
	#endif

	if(g_mode == k_screen_app_interface)
	{
		if(!send_server_msj_count)
		{
			send_server_msj_count = 2;
			data_transfer.comunication_command = k_comunication_command_none;
			comunication_send(comunication_get_socket(0), (uint8_t*)&data_transfer, sizeof(comunication_transfer_t), 0);
		}
		else
		{
			send_server_msj_count --;
		}
	}

	if(g_mode == k_screen_app_master)
	{
		updates = measures_get_updates();
	}
	else
	{
		comunication_updates = get_comunication_updates();
	}
	if((updates.accel_update&&g_mode) || comunication_updates.comunication_accel_update)
	{
		accelerometer_update(g_mode);
	}
	if((updates.performance_core1_update&&g_mode) || comunication_updates.comunication_performance_core1_update)
	{
		performance_core1_update(g_mode);
	}
	if((updates.performance_core2_update&&g_mode) || comunication_updates.comunication_performance_core2_update)
	{
		performance_core2_update(g_mode);
	}
	if((updates.brd_temperature_update&&g_mode) || comunication_updates.comunication_brd_temperature_update)
	{
		brd_temperature_update(g_mode);
	}
	if((updates.mcu_temperature_update&&g_mode) || comunication_updates.comunication_mcu_temperature_update)
	{
		mcu_temperature_update(g_mode);
	}
	if((updates.date_update&&g_mode) || comunication_updates.comunication_date_update)
	{
		date_update(g_mode);
	}
	if((updates.rpm_update&&g_mode) || comunication_updates.comunication_rpm_update)
	{
		rpm_update(g_mode);
	}
	if((updates.time_update&&g_mode) || comunication_updates.comunication_time_update)
	{
		time_update(g_mode);
	}
	if((updates.touch_update&&g_mode) || comunication_updates.comunication_touch_update)
	{
		touch_update(g_mode);
	}
}

void screenApp_setIPMaskCnf(uint8_t n_mask)
{
	uint8_t index = 0;
	g_ipconf_mask_selected 	= n_mask;
	if(n_mask <= 3)
	{
		g_config_ip[n_mask] 	= 0;
		g_multiplier 			= 100;
	}
	for(index = 0; index < 4; index ++)
	{
		if(index == n_mask) screen_setBGColorMask(index, 0xDADADA);
		else				screen_setBGColorMask(index, 0x848484);
	}
	ip_internal_update();
}

void screenApp_IPMaskCnf_eventHandler(uint8_t n_mask)
{
	screenApp_ConnectionMode_eventHandler(k_screen_static_ip);

	g_standBy_count 		= MS_TO_STAND_BY/MS_UPDATE_EVENT;
	screenApp_setIPMaskCnf(n_mask);
}

void screenApp_NumberBTN_eventHandler(uint8_t number)
{
	g_standBy_count = MS_TO_STAND_BY/MS_UPDATE_EVENT;
	screenApp_ConnectionMode_eventHandler(k_screen_static_ip);

	if(g_ipconf_mask_selected > 3)
	{
		screenApp_setIPMaskCnf(0);
		g_config_ip[g_ipconf_mask_selected] = 0;
		g_multiplier = 100;
	}
	g_config_ip[g_ipconf_mask_selected] += number*g_multiplier;
	ip_internal_update();
	if(g_multiplier == 100)
	{
		g_multiplier = 10;
	}
	else if(g_multiplier == 10)
	{
		g_multiplier = 1;
	}
	else
	{
		screenApp_setIPMaskCnf(g_ipconf_mask_selected + 1);
		if(g_ipconf_mask_selected <= 3)
		{
			g_multiplier = 100;
			g_config_ip[g_ipconf_mask_selected] = 0;
		}
	}
}

void screenApp_ConnectionMode_ForceUpdate(screen_ip_mode_t mode)
{
	g_ip_mode = mode;
	screen_setConnectionMode(mode);
	if(mode == k_screen_dhcp)
	{
		g_ipconf_mask_selected = 4;
		screen_setNumberButtonsColor(0x848484);
	}
	else
	{
		screen_setNumberButtonsColor(0x2195F6);
	}
	screenApp_setIPMaskCnf(g_ipconf_mask_selected);
}

void screenApp_ConnectionMode_eventHandler(screen_ip_mode_t mode)
{
	if(g_ip_mode != mode)
	{
		screenApp_ConnectionMode_ForceUpdate(mode);
	}
}

void screenEventCallback(screen_events_t event)
{
	switch(event)
	{
		case k_screen_init_event:
			screenApp_init_eventHandler();
		break;
		case k_screen_clicked_event:
			screenApp_clickScreen_eventHandler();
		break;

		case k_screen_masterBtn_event:
			screenApp_MasterBTN_eventHandler();
		break;

		case k_screen_interfaceBtn_event:
			screenApp_InterfaceBTN_eventHandler();
		break;

		case k_screen_save_btn_event:
			screenApp_SaveBTN_eventHandler();
		break;

		case k_screen_standByTouch_event:
			screenApp_StandByScreenClick_eventHandler();
		break;

		case k_screen_menuPerfBtn_event:
			screenApp_MenuPerfBTN_eventHandler();
		break;

		case k_screen_menuTempBtn_event:
			screenApp_MenuTempBTN_eventHandler();
		break;

		case k_screen_menuAccBtn_event:
			screenApp_MenuAccBTN_eventHandler();
		break;

		case k_screen_menuTouchBtn_event:
			screenApp_MenuTouchBTN_eventHandler();
		break;

		case k_screen_menuSetTimeBtn_event:
			screenApp_MenuSetTimeBTN_eventHandler();
		break;

		case k_screen_menuCtrlPanelBtn_event:
			screenApp_MenuControlPanelBTN_eventHandler();
		break;

		case k_screen_menuBtn_event:
			screenApp_MenuBTN_eventHandler();
		break;

		case k_screen_setTimeBtn_event:
			screenApp_SetTimeBTN_eventHandler();
		break;

		case k_screen_rpmPressed_event:
			g_slider_is_pressed = true;
		break;

		case k_screen_rpmReleased_event:
			screenApp_RPMUpdate_eventHandler();
			g_slider_is_pressed = false;
			g_update_slider_count = COUNT_UPDATE_SLIDER_VAL;
		break;

		case k_screen_update_event:
			screenApp_ScreenUpdate_eventHandler();
		break;

		case k_screen_ip_mask_0_event:
			screenApp_IPMaskCnf_eventHandler(0);
		break;

		case k_screen_ip_mask_1_event:
			screenApp_IPMaskCnf_eventHandler(1);
		break;

		case k_screen_ip_mask_2_event:
			screenApp_IPMaskCnf_eventHandler(2);
		break;

		case k_screen_ip_mask_3_event:
			screenApp_IPMaskCnf_eventHandler(3);
		break;

		case k_screen_number0_btn_event:
			screenApp_NumberBTN_eventHandler(0);
		break;

		case k_screen_number1_btn_event:
			screenApp_NumberBTN_eventHandler(1);
		break;

		case k_screen_number2_btn_event:
			screenApp_NumberBTN_eventHandler(2);
		break;

		case k_screen_number3_btn_event:
			screenApp_NumberBTN_eventHandler(3);
		break;

		case k_screen_number4_btn_event:
			screenApp_NumberBTN_eventHandler(4);
		break;

		case k_screen_number5_btn_event:
			screenApp_NumberBTN_eventHandler(5);
		break;

		case k_screen_number6_btn_event:
			screenApp_NumberBTN_eventHandler(6);
		break;

		case k_screen_number7_btn_event:
			screenApp_NumberBTN_eventHandler(7);
		break;

		case k_screen_number8_btn_event:
			screenApp_NumberBTN_eventHandler(8);
		break;

		case k_screen_number9_btn_event:
			screenApp_NumberBTN_eventHandler(9);
		break;

		case k_screen_dhcp_selected_event:
			screenApp_ConnectionMode_eventHandler(k_screen_dhcp);
		break;

		case k_screen_static_selected_event:
			screenApp_ConnectionMode_eventHandler(k_screen_static_ip);
		break;
	}
}
