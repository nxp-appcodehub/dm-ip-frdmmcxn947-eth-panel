/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2022, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CAN_COMUNICATION_H_
#define CAN_COMUNICATION_H_

#include <stdint.h>
#include "comunication.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief FlexCAN Init function
 *
 * @param none
 */
void can_init(void);

/*!
 * @brief CAN transmission function. Will send the CAN Message with the
 *        given data.
 *
 * @param data - pointer to data message
 * @param length - size in bytes of the data
 */
void can_tx_char_data(uint8_t *data, uint8_t char_length);

/*!
 * @brief CAN reception task. Once the CAN message was received it will be process
 *        in this function and will active reception again.
 *        given data.
 *
 * @param data - double pointer to return the pointer to the data buffer
 * @param char_length - Pointer to variable to return length in bytes
 */
uint32_t can_rx_task(uint8_t **data ,uint8_t *length);

/*!
 * @ Return the CAN Reception Status
 *
 * @return Reception status.
 */
bool get_can_rx_status(void);

void can_send_to_ip(uint16_t slider, int16_t rpm);

void can_comunication_task(void *arg);

#endif /*CAN_APIS_H_*/
