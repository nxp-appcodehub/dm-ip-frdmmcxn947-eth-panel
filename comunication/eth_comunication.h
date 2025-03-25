/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef ETH_COMUNICATION_H_
#define ETH_COMUNICATION_H_

#include "lwipopts.h"
#include <stdint.h>
#include "arm_math.h"
#include <stdint.h>
#include <stdbool.h>
#include "comunication.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* @TEST_ANCHOR */

/* IP address configuration. */
#ifndef configIP_ADDR0_SERVER
#define configIP_ADDR0_SERVER 192
#endif
#ifndef configIP_ADDR1_SERVER
#define configIP_ADDR1_SERVER 168
#endif
#ifndef configIP_ADDR2_SERVER
#define configIP_ADDR2_SERVER 0
#endif
#ifndef configIP_ADDR3_SERVER
#define configIP_ADDR3_SERVER 100
#endif

/* IP address configuration. */
#ifndef configIP_ADDR0_CLIENT
#define configIP_ADDR0_CLIENT 192
#endif
#ifndef configIP_ADDR1_CLIENT
#define configIP_ADDR1_CLIENT 168
#endif
#ifndef configIP_ADDR2_CLIENT
#define configIP_ADDR2_CLIENT 0
#endif
#ifndef configIP_ADDR3_CLIENT
#define configIP_ADDR3_CLIENT 101
#endif

/* Netmask configuration. */
#ifndef configNET_MASK0
#define configNET_MASK0 255
#endif
#ifndef configNET_MASK1
#define configNET_MASK1 255
#endif
#ifndef configNET_MASK2
#define configNET_MASK2 255
#endif
#ifndef configNET_MASK3
#define configNET_MASK3 0
#endif

/* Gateway address configuration. */
#ifndef configGW_ADDR0
#define configGW_ADDR0 192
#endif
#ifndef configGW_ADDR1
#define configGW_ADDR1 168
#endif
#ifndef configGW_ADDR2
#define configGW_ADDR2 0
#endif
#ifndef configGW_ADDR3
#define configGW_ADDR3 1
#endif

/* Ethernet configuration. */
#define EXAMPLE_ENET_BASE    ENET0
#define EXAMPLE_PHY_ADDRESS  BOARD_ENET0_PHY_ADDRESS
#define EXAMPLE_PHY_OPS      &phylan8741_ops
#define EXAMPLE_PHY_RESOURCE &g_phy_resource
#define EXAMPLE_CLOCK_FREQ   (50000000U)

#define MAX_SOCKET_CLIENTS 6

#ifndef EXAMPLE_NETIF_INIT_FN
/*! @brief Network interface initialization function. */
#define EXAMPLE_NETIF_INIT_FN ethernetif0_init
#endif /* EXAMPLE_NETIF_INIT_FN */

/*! @brief Stack size of the temporary lwIP initialization thread. */
#define INIT_THREAD_STACKSIZE 1024

/*! @brief Priority of the temporary lwIP initialization thread. */
#define INIT_THREAD_PRIO DEFAULT_THREAD_PRIO



void comunication_init(void);

void comunication_task(void* arg);

void server_socket_task(void *arg);

void client_socket_task(void *arg);

int comunication_get_socket(uint8_t n_socket);

uint32_t comunication_get_ip();

int32_t comunication_send(int socket, uint8_t *data, uint8_t size, uint8_t option);

int32_t comunication_rcv(int socket, uint8_t *data, uint8_t size);

comunication_transfer_t* comunication_get_values(void);

comunication_updates_t get_comunication_updates(void);

#endif /* ETH_COMUNICATION_H_ */
