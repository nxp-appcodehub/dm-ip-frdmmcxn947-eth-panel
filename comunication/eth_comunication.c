/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <eth_comunication.h>
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_clock.h"
#include "lwip/opt.h"
#include "fsl_adapter_gpio.h"
#include "lwip/netifapi.h"
#include "lwip/tcpip.h"
#include "netif/ethernet.h"
#include "ethernetif.h"
#include "lwip/dhcp.h"
#include "lwip/prot/dhcp.h"

#include "pin_mux.h"
#include "board.h"
#ifndef configMAC_ADDR
#include "fsl_silicon_id.h"
#endif
#include "fsl_phy.h"

#include "fsl_enet.h"
#include "fsl_phylan8741.h"

#include "include/lwip/sockets.h"

#include "semphr.h"

#include "screen_app.h"
#include "screen.h"
#include "motor_control.h"
#include "comunication.h"
#include "can_comunication.h"


// Variables --------------------------------------------------------------------
phy_lan8741_resource_t g_phy_resource;

static phy_handle_t phyHandle;
static struct netif netif;
static int32_t g_socket[MAX_SOCKET_CLIENTS] = {0};
static uint8_t g_socket_enable[MAX_SOCKET_CLIENTS] = {0};
static uint8_t g_socket_error[MAX_SOCKET_CLIENTS] = {0};
static uint8_t g_socket_timeout_flag[MAX_SOCKET_CLIENTS] = {0};
static comunication_transfer_t 	g_data_transfer;
static comunication_updates_t	g_comunication_updates;
static uint8_t					g_dhcp_bounded = 0;
static uint32_t					g_serv_addr;


static SemaphoreHandle_t 		g_rcv_sem;
static SemaphoreHandle_t 		g_comunication_error_in_socket[MAX_SOCKET_CLIENTS];
static SemaphoreHandle_t 		g_comunication_wait_for_close_task[MAX_SOCKET_CLIENTS];

// ------------------------------------------------------------------------------

static void MDIO_Init(void)
{
    (void)CLOCK_EnableClock(s_enetClock[ENET_GetInstance(EXAMPLE_ENET_BASE)]);
    ENET_SetSMI(EXAMPLE_ENET_BASE, CLOCK_GetCoreSysClkFreq());
}

static status_t MDIO_Write(uint8_t phyAddr, uint8_t regAddr, uint16_t data)
{
    return ENET_MDIOWrite(EXAMPLE_ENET_BASE, phyAddr, regAddr, data);
}

static status_t MDIO_Read(uint8_t phyAddr, uint8_t regAddr, uint16_t *pData)
{
    return ENET_MDIORead(EXAMPLE_ENET_BASE, phyAddr, regAddr, pData);
}

static void print_dhcp_state(void *arg)
{
    struct netif *netif = (struct netif *)arg;
    struct dhcp *dhcp;
    u8_t dhcp_last_state = DHCP_STATE_OFF;

    while (netif_is_up(netif))
    {
        dhcp = netif_dhcp_data(netif);

        if (dhcp == NULL)
        {
            dhcp_last_state = DHCP_STATE_OFF;
        }
        else if (dhcp_last_state != dhcp->state)
        {
            dhcp_last_state = dhcp->state;

            PRINTF(" DHCP state       : ");
            switch (dhcp_last_state)
            {
                case DHCP_STATE_OFF:
                    PRINTF("OFF");
                    break;
                case DHCP_STATE_REQUESTING:
                    PRINTF("REQUESTING");
                    break;
                case DHCP_STATE_INIT:
                    PRINTF("INIT");
                    break;
                case DHCP_STATE_REBOOTING:
                    PRINTF("REBOOTING");
                    break;
                case DHCP_STATE_REBINDING:
                    PRINTF("REBINDING");
                    break;
                case DHCP_STATE_RENEWING:
                    PRINTF("RENEWING");
                    break;
                case DHCP_STATE_SELECTING:
                    PRINTF("SELECTING");
                    break;
                case DHCP_STATE_INFORMING:
                    PRINTF("INFORMING");
                    break;
                case DHCP_STATE_CHECKING:
                    PRINTF("CHECKING");
                    break;
                case DHCP_STATE_BOUND:
                    PRINTF("BOUND");
                    g_dhcp_bounded = 1;
                    break;
                case DHCP_STATE_BACKING_OFF:
                    PRINTF("BACKING_OFF");
                    break;
                default:
                    PRINTF("%u", dhcp_last_state);
                    assert(0);
                    break;
            }
            PRINTF("\r\n");
        }
        sys_msleep(20U);
    }
}

void comunication_init(void)
{
    CLOCK_AttachClk(MUX_A(CM_ENETRMIICLKSEL, 0));
    CLOCK_EnableClock(kCLOCK_Enet);
    SYSCON0->PRESETCTRL2 = SYSCON_PRESETCTRL2_ENET_RST_MASK;
    SYSCON0->PRESETCTRL2 &= ~SYSCON_PRESETCTRL2_ENET_RST_MASK;

    MDIO_Init();

	g_rcv_sem 					= xSemaphoreCreateBinary();
	xSemaphoreGive(g_rcv_sem);

    g_phy_resource.read  = MDIO_Read;
    g_phy_resource.write = MDIO_Write;

    can_init();
}

void comunication_task(void* arg)
{
	uint8_t *address = (uint8_t*)arg;
    ip4_addr_t netif_ipaddr, netif_netmask, netif_gw;
    ethernetif_config_t enet_config = {
        .phyHandle   = &phyHandle,
        .phyAddr     = EXAMPLE_PHY_ADDRESS,
        .phyOps      = EXAMPLE_PHY_OPS,
        .phyResource = EXAMPLE_PHY_RESOURCE,
        .srcClockHz  = EXAMPLE_CLOCK_FREQ,
    };

    SILICONID_ConvertToMacAddr(&enet_config.macAddress);
    tcpip_init(NULL, NULL);

    if(*((uint32_t*)arg))
    {
        ((uint8_t*)(&(netif_ipaddr.addr)))[0] = address[3];
        ((uint8_t*)(&(netif_ipaddr.addr)))[1] = address[2];
        ((uint8_t*)(&(netif_ipaddr.addr)))[2] = address[1];
        ((uint8_t*)(&(netif_ipaddr.addr)))[3] = address[0];
        IP4_ADDR(&netif_netmask, configNET_MASK0, configNET_MASK1, configNET_MASK2, configNET_MASK3);
        IP4_ADDR(&netif_gw, configGW_ADDR0, configGW_ADDR1, configGW_ADDR2, configGW_ADDR3);
        netifapi_netif_add(&netif, &netif_ipaddr, &netif_netmask, &netif_gw, &enet_config, EXAMPLE_NETIF_INIT_FN, tcpip_input);
    }
    else
    {
        netifapi_netif_add(&netif, NULL, NULL, NULL, &enet_config, EXAMPLE_NETIF_INIT_FN, tcpip_input);
    }

    netifapi_netif_set_default(&netif);
    netifapi_netif_set_up(&netif);

    while (ethernetif_wait_linkup(&netif, 5000) != ERR_OK)
    {
        PRINTF("PHY Auto-negotiation failed. Please check the cable connection and link partner setting.\r\n");
    }

	PRINTF("\r\n************************************************\r\n");
	PRINTF(" INDUSTRIAL PANEL example\r\n");
	PRINTF("************************************************\r\n");
    if(!(*((uint32_t*)arg)))
	{
		netifapi_dhcp_start(&netif);
		xTaskCreate(print_dhcp_state, "dhcp", configMINIMAL_STACK_SIZE + 300, (void*)&netif, tskIDLE_PRIORITY + 3, NULL);
		while(!g_dhcp_bounded);
		netif_ipaddr 	= netif.ip_addr;
		netif_netmask 	= netif.netmask;
		netif_gw		= netif.gw;
	}
	PRINTF(" IPv4 Address     : %u.%u.%u.%u\r\n", ((u8_t *)&netif_ipaddr)[0], ((u8_t *)&netif_ipaddr)[1],
		   ((u8_t *)&netif_ipaddr)[2], ((u8_t *)&netif_ipaddr)[3]);
	PRINTF(" IPv4 Subnet mask : %u.%u.%u.%u\r\n", ((u8_t *)&netif_netmask)[0], ((u8_t *)&netif_netmask)[1],
		   ((u8_t *)&netif_netmask)[2], ((u8_t *)&netif_netmask)[3]);
	PRINTF(" IPv4 Gateway     : %u.%u.%u.%u\r\n", ((u8_t *)&netif_gw)[0], ((u8_t *)&netif_gw)[1],
		   ((u8_t *)&netif_gw)[2], ((u8_t *)&netif_gw)[3]);
	PRINTF("************************************************\r\n");

	screenApp_setIP(netif_ipaddr.addr);

	g_serv_addr = *((uint32_t*)arg);
}

void server_rcv_task(void *arg)
{
	int32_t status;
	uint8_t socket = *((uint8_t*)arg);
	comunication_transfer_t data_transfer;
	measures_time_t			time;
	while(1)
	{
		status = comunication_rcv(g_socket[socket], (uint8_t*)&data_transfer, sizeof(data_transfer));

		xSemaphoreTake(g_comunication_error_in_socket[socket], portMAX_DELAY);
		g_socket_timeout_flag[socket] = 0;
		if(g_socket_error[socket])
		{
			PRINTF("Server receive task to client %d deleted\n\r", socket);
			xSemaphoreGive(g_comunication_wait_for_close_task[socket]);
			xSemaphoreGive(g_comunication_error_in_socket[socket]);
			vTaskDelete(NULL);
		}
		else
		{
			if(status == -1)
			{
				lwip_close(socket);
				g_socket_error[socket] = 1;
				PRINTF("Server receive task to client %d deleted\n\r", socket);
				xSemaphoreGive(g_comunication_error_in_socket[socket]);
				xSemaphoreGive(g_comunication_wait_for_close_task[socket]);
				vTaskDelete(NULL);
			}
		}
		xSemaphoreGive(g_comunication_error_in_socket[socket]);

		if(data_transfer.comunication_command == k_comunication_command_send_date)
		{
			time.hours 		= data_transfer.comunication_data.comunication_date.comunication_hours;
			time.minutes 	= data_transfer.comunication_data.comunication_date.comunication_minutes;
			time.seconds 	= data_transfer.comunication_data.comunication_date.comunication_seconds;
			time.meridian 	= data_transfer.comunication_data.comunication_date.comunication_meridian;
			xSemaphoreTake(g_rcv_sem, portMAX_DELAY);
			measures_set_time(time);
			xSemaphoreGive(g_rcv_sem);
		}
		else if(data_transfer.comunication_command == k_comunication_command_send_rpm)
		{
			screen_setRPMSlider(data_transfer.comunication_data.comunication_motor.comunication_motor_rpm_slider);
			motor_control_set_speed(data_transfer.comunication_data.comunication_motor.comunication_motor_rpm);
		}
	}
}

void server_snd_task(void *arg)
{
	static comunication_transfer_t s_data_transfer;
	int32_t status;
	uint8_t socket = *((uint8_t*)arg);
	measures_date_t date;
	measures_time_t time;
	measures_accel_t accel;
	measures_performance_core1_t performance_c1;
	measures_performance_core2_t performance_c2;

	while(1)
		{
			date = measures_get_date();
			time = measures_get_time();
			accel = measures_get_accel_values();
			performance_c1 = measures_get_performance_core1();
			performance_c2 = measures_get_performance_core2();

			s_data_transfer.comunication_command = k_comunication_command_update_data;

			s_data_transfer.comunication_data.comunication_date.comunication_day 		= date.day;
			s_data_transfer.comunication_data.comunication_date.comunication_month 		= date.month;
			s_data_transfer.comunication_data.comunication_date.comunication_year 		= date.year;
			s_data_transfer.comunication_data.comunication_date.comunication_hours 		= time.hours;
			s_data_transfer.comunication_data.comunication_date.comunication_minutes 	= time.minutes;
			s_data_transfer.comunication_data.comunication_date.comunication_seconds 	= time.seconds;
			s_data_transfer.comunication_data.comunication_date.comunication_meridian 	= time.meridian;

			s_data_transfer.comunication_data.comunication_performance.comunication_idle_core_1 			= performance_c1.measures_idle_perf_core1;
			s_data_transfer.comunication_data.comunication_performance.comunication_lvgl_core_1 			= performance_c1.measures_lvgl_perf_core1;
			s_data_transfer.comunication_data.comunication_performance.comunication_sensors_core_1 			= performance_c1.measures_sensors_perf_core1_t;
			s_data_transfer.comunication_data.comunication_performance.comunication_ethernet_core_1 		= performance_c1.measures_ethernet_perf_core1;
			s_data_transfer.comunication_data.comunication_performance.comunication_motor_control_core_1 	= performance_c1.measures_motor_perf_core1_t;
			s_data_transfer.comunication_data.comunication_performance.comunication_idle_core_2 			= performance_c2.measures_idle_perf_core2;

			s_data_transfer.comunication_data.comunication_temperature.comunication_brd_temperature = measures_get_brd_temperature();
			s_data_transfer.comunication_data.comunication_temperature.comunication_mcu_temperature = measures_get_mcu_temperature();

			s_data_transfer.comunication_data.comunication_accel.accel_enable = measuresAccelIsReady();
			s_data_transfer.comunication_data.comunication_accel.comunication_accel_x = accel.accelX;
			s_data_transfer.comunication_data.comunication_accel.comunication_accel_y = accel.accelY;
			s_data_transfer.comunication_data.comunication_accel.comunication_accel_z = accel.accelZ;

			s_data_transfer.comunication_data.comunication_motor.comunication_motor_rpm_slider = (int32_t)screen_getRPMSliderSave();
			s_data_transfer.comunication_data.comunication_motor.comunication_motor_rpm = measures_get_rpm();

			status = comunication_send(g_socket[socket] ,(uint8_t*)&s_data_transfer, sizeof(s_data_transfer), 1);

			xSemaphoreTake(g_comunication_error_in_socket[socket], portMAX_DELAY);
			if(g_socket_error[socket])
			{
				PRINTF("Server send task to client %d deleted\n\r", socket);
				xSemaphoreGive(g_comunication_wait_for_close_task[socket]);
				xSemaphoreGive(g_comunication_error_in_socket[socket]);
				vTaskDelete(NULL);
			}
			else
			{
				if(status == -1)
				{
					PRINTF("Server send task to client %d deleted\n\r", socket);
					g_socket_error[socket] = 1;
					xSemaphoreGive(g_comunication_error_in_socket[socket]);
					xSemaphoreGive(g_comunication_wait_for_close_task[socket]);
					vTaskDelete(NULL);
				}
			}
			xSemaphoreGive(g_comunication_error_in_socket[socket]);
			vTaskDelay(50);
		}
}

void server_socket_connect(void *arg)
{
	struct sockaddr_in serv_addr_udp;
	struct sockaddr_in client_addr_udp;
	int32_t status;
	TaskHandle_t rcv_task_handler;
	uint32_t client_len;
	uint8_t socket = *((uint8_t*)arg);

    g_comunication_error_in_socket[socket] 	= xSemaphoreCreateBinary();
    g_comunication_wait_for_close_task[socket] 	= xSemaphoreCreateCounting(5, 0);
	xSemaphoreGive(g_comunication_error_in_socket[socket]);


	do
	{
		if(!g_socket_timeout_flag[socket])
		{
			serv_addr_udp.sin_family = AF_INET;
			((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[0] = ((uint8_t*)&g_serv_addr)[3];
			((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[1] = ((uint8_t*)&g_serv_addr)[2];
			((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[2] = ((uint8_t*)&g_serv_addr)[1];
			((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[3] = ((uint8_t*)&g_serv_addr)[0];

			serv_addr_udp.sin_port = htons(8000+socket);
			g_socket[socket] = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
			status = lwip_bind(g_socket[socket], (struct sockaddr *)&serv_addr_udp, sizeof(serv_addr_udp));
			status = lwip_listen(g_socket[socket], 1);
		}
		g_socket[socket] = lwip_accept(socket, (struct sockaddr *)&client_addr_udp, &client_len);

		PRINTF("Client %d connected!\r\n", socket);
		g_socket_error[socket] = 0;
		xTaskCreate(server_rcv_task, "server_rcv", configMINIMAL_STACK_SIZE + 500, arg, tskIDLE_PRIORITY + 3, &rcv_task_handler);
		xTaskCreate(server_snd_task, "server_snd", configMINIMAL_STACK_SIZE + 500, arg, tskIDLE_PRIORITY + 3, NULL);
//		vTaskDelete(NULL);
		g_socket_timeout_flag[socket] = 0;
		// For reconnection with timeout ------------------------------------------
		if(socket != 0)
		{
			while(!g_socket_timeout_flag[socket])
			{
				xSemaphoreTake(g_comunication_error_in_socket[socket], portMAX_DELAY);
				if(g_socket_error[socket])
				{
					xSemaphoreGive(g_comunication_error_in_socket[socket]);
					break;
				}
				g_socket_timeout_flag[socket] = 1;
				xSemaphoreGive(g_comunication_error_in_socket[socket]);
				vTaskDelay(2000);
			}
			xSemaphoreTake(g_comunication_error_in_socket[socket], portMAX_DELAY);
			g_socket_error[socket] = 1;
			xSemaphoreGive(g_comunication_error_in_socket[socket]);
		}
		// -------------------------------------------------------------------------
		if(g_socket_timeout_flag[socket])
		{
			xSemaphoreTake(g_comunication_wait_for_close_task[socket], portMAX_DELAY);
			vTaskDelete(rcv_task_handler);
			PRINTF("Server receive task to client %d deleted\n\r", socket);
		}
		else
		{
			xSemaphoreTake(g_comunication_wait_for_close_task[socket], portMAX_DELAY);
			xSemaphoreTake(g_comunication_wait_for_close_task[socket], portMAX_DELAY);
		}
		lwip_close(g_socket[socket]);
		PRINTF("Client %d disconnected\n\r", socket);
		vSemaphoreDelete(g_comunication_error_in_socket[socket]);

	    g_comunication_error_in_socket[socket] 	= xSemaphoreCreateBinary();
		xSemaphoreGive(g_comunication_error_in_socket[socket]);

	}while(1);
}

void server_socket_task(void *arg)
{
	uint8_t index;

	vTaskSetApplicationTaskTag( NULL, ( void * ) 3);/*Task Tag*/
	comunication_task(arg);
	for(index = 0; index < MAX_SOCKET_CLIENTS; index ++)
	{
		g_socket_enable[index] = index;
		if(xTaskCreate(server_socket_connect, "server_connect", configMINIMAL_STACK_SIZE + 300, g_socket_enable+index, tskIDLE_PRIORITY + 4, NULL) != pdPASS)
		{
			PRINTF("Can not create server socket task %d\r\n", index);
		}
		else
		{
			PRINTF("Server socket task %d created\r\n", index);
		}
	}
	vTaskDelete(NULL);
}

void client_socket_task(void *arg)
{
	static struct sockaddr_in serv_addr_udp;
	comunication_transfer_t data_transfer;
	vTaskSetApplicationTaskTag( NULL, ( void * ) 3);/*Task Tag*/
	comunication_task(arg);

	serv_addr_udp.sin_family = AF_INET;
	serv_addr_udp.sin_port = htons(8003);
	((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[0] = ((uint8_t*)(((uint32_t*)arg)+1))[3];
	((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[1] = ((uint8_t*)(((uint32_t*)arg)+1))[2];
	((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[2] = ((uint8_t*)(((uint32_t*)arg)+1))[1];
	((uint8_t*)(&(serv_addr_udp.sin_addr.s_addr)))[3] = ((uint8_t*)(((uint32_t*)arg)+1))[0];

	g_socket[0] = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	lwip_connect(g_socket[0], (struct sockaddr *)&serv_addr_udp, sizeof(serv_addr_udp));
	while(1)
	{
		comunication_rcv(g_socket[0], (uint8_t*)&data_transfer, sizeof(data_transfer));
		if(!data_transfer.comunication_data.comunication_accel.accel_enable)
		{
			g_comunication_updates.comunication_accel_update = true;
		}
		if(g_data_transfer.comunication_data.comunication_accel.accel_enable != data_transfer.comunication_data.comunication_accel.accel_enable ||
		   g_data_transfer.comunication_data.comunication_accel.comunication_accel_x != data_transfer.comunication_data.comunication_accel.comunication_accel_x ||
		   g_data_transfer.comunication_data.comunication_accel.comunication_accel_y != data_transfer.comunication_data.comunication_accel.comunication_accel_y ||
		   g_data_transfer.comunication_data.comunication_accel.comunication_accel_z != data_transfer.comunication_data.comunication_accel.comunication_accel_z )
		{
			g_data_transfer.comunication_data.comunication_accel.accel_enable = data_transfer.comunication_data.comunication_accel.accel_enable;
			g_data_transfer.comunication_data.comunication_accel.comunication_accel_x = data_transfer.comunication_data.comunication_accel.comunication_accel_x;
			g_data_transfer.comunication_data.comunication_accel.comunication_accel_y = data_transfer.comunication_data.comunication_accel.comunication_accel_y;
			g_data_transfer.comunication_data.comunication_accel.comunication_accel_z = data_transfer.comunication_data.comunication_accel.comunication_accel_z;
			g_comunication_updates.comunication_accel_update = true;
		}
		if(g_data_transfer.comunication_data.comunication_date.comunication_seconds != data_transfer.comunication_data.comunication_date.comunication_seconds)
		{
			g_data_transfer.comunication_data.comunication_date.comunication_day = data_transfer.comunication_data.comunication_date.comunication_day;
			g_data_transfer.comunication_data.comunication_date.comunication_hours = data_transfer.comunication_data.comunication_date.comunication_hours;
			g_data_transfer.comunication_data.comunication_date.comunication_meridian = data_transfer.comunication_data.comunication_date.comunication_meridian;
			g_data_transfer.comunication_data.comunication_date.comunication_minutes = data_transfer.comunication_data.comunication_date.comunication_minutes;
			g_data_transfer.comunication_data.comunication_date.comunication_month = data_transfer.comunication_data.comunication_date.comunication_month;
			g_data_transfer.comunication_data.comunication_date.comunication_seconds = data_transfer.comunication_data.comunication_date.comunication_seconds;
			g_data_transfer.comunication_data.comunication_date.comunication_year = data_transfer.comunication_data.comunication_date.comunication_year;
			g_comunication_updates.comunication_date_update = true;
			g_comunication_updates.comunication_time_update = true;
		}
		if(g_data_transfer.comunication_data.comunication_performance.comunication_idle_core_1 != data_transfer.comunication_data.comunication_performance.comunication_idle_core_1||
		   g_data_transfer.comunication_data.comunication_performance.comunication_idle_core_2 != data_transfer.comunication_data.comunication_performance.comunication_idle_core_2)
		{
			g_data_transfer.comunication_data.comunication_performance.comunication_ethernet_core_1 = data_transfer.comunication_data.comunication_performance.comunication_ethernet_core_1;
			g_data_transfer.comunication_data.comunication_performance.comunication_idle_core_1 = data_transfer.comunication_data.comunication_performance.comunication_idle_core_1;
			g_data_transfer.comunication_data.comunication_performance.comunication_idle_core_2 = data_transfer.comunication_data.comunication_performance.comunication_idle_core_2;
			g_data_transfer.comunication_data.comunication_performance.comunication_lvgl_core_1 = data_transfer.comunication_data.comunication_performance.comunication_lvgl_core_1;
			g_data_transfer.comunication_data.comunication_performance.comunication_motor_control_core_1 = data_transfer.comunication_data.comunication_performance.comunication_motor_control_core_1;
			g_data_transfer.comunication_data.comunication_performance.comunication_sensors_core_1 = data_transfer.comunication_data.comunication_performance.comunication_sensors_core_1;

			g_comunication_updates.comunication_performance_core1_update = true;
			g_comunication_updates.comunication_performance_core2_update = true;
		}

		if(g_data_transfer.comunication_data.comunication_temperature.comunication_brd_temperature != data_transfer.comunication_data.comunication_temperature.comunication_brd_temperature)
		{
			g_data_transfer.comunication_data.comunication_temperature.comunication_brd_temperature = data_transfer.comunication_data.comunication_temperature.comunication_brd_temperature;
			g_comunication_updates.comunication_brd_temperature_update = true;
		}

		if(g_data_transfer.comunication_data.comunication_temperature.comunication_mcu_temperature != data_transfer.comunication_data.comunication_temperature.comunication_mcu_temperature)
		{
			g_data_transfer.comunication_data.comunication_temperature.comunication_mcu_temperature = data_transfer.comunication_data.comunication_temperature.comunication_mcu_temperature;
			g_comunication_updates.comunication_mcu_temperature_update = true;
		}

		g_data_transfer.comunication_data.comunication_motor.comunication_motor_rpm_slider = data_transfer.comunication_data.comunication_motor.comunication_motor_rpm_slider;
		g_data_transfer.comunication_data.comunication_motor.comunication_motor_rpm = data_transfer.comunication_data.comunication_motor.comunication_motor_rpm;
		g_comunication_updates.comunication_rpm_update = true;
	}
}

int comunication_get_socket(uint8_t n_socket)
{
	return g_socket[n_socket];
}

uint32_t comunication_get_ip()
{
	if(g_dhcp_bounded)
	{
		return netif.ip_addr.addr;
	}
	return 0;
}

int32_t comunication_send(int socket, uint8_t *data, uint8_t size, uint8_t option)
{
	int32_t error = 0;
	socklen_t len = sizeof (error);
	int32_t status;
	status = lwip_getsockopt(socket, SOL_SOCKET, SO_ERROR, &error, &len);
	if(status == 0)
	{
		status = lwip_send(socket, data, size, 0);
	}
	return status;
}

int32_t comunication_rcv(int socket, uint8_t *data, uint8_t size)
{
	int32_t status;
	status = lwip_recv(socket, (void*)data, size, 0);
	return status;
}

comunication_transfer_t* comunication_get_values(void)
{
	return &g_data_transfer;
}

comunication_updates_t get_comunication_updates(void)
{
	comunication_updates_t retval = g_comunication_updates;
	g_comunication_updates.comunication_accel_update = false;
	g_comunication_updates.comunication_brd_temperature_update = false;
	g_comunication_updates.comunication_date_update = false;
	g_comunication_updates.comunication_mcu_temperature_update = false;
	g_comunication_updates.comunication_performance_core1_update = false;
	g_comunication_updates.comunication_performance_core2_update = false;
	g_comunication_updates.comunication_rpm_update = false;
	g_comunication_updates.comunication_time_update = false;
	g_comunication_updates.comunication_touch_update = false;
	return retval;
}
