/*
 * Copyright 2022, 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BRD_TEMP_SENSOR_H_
#define _BRD_TEMP_SENSOR_H_

#include "fsl_common.h"
#include "fsl_i3c.h"

#define EXAMPLE_MASTER             I3C1
#define I3C_MASTER_CLOCK_FREQUENCY CLOCK_GetI3cClkFreq(1)
#define SENSOR_SLAVE_ADDR          0x48U
#define I3C_TIME_OUT_INDEX         100000000U

#define SENSOR_ADDR 0x08U
#define CCC_RSTDAA  0x06U
#define CCC_SETDASA 0x87

#ifndef EXAMPLE_I2C_BAUDRATE
#define EXAMPLE_I2C_BAUDRATE 400000
#endif
#ifndef EXAMPLE_I3C_OD_BAUDRATE
#define EXAMPLE_I3C_OD_BAUDRATE 1500000
#endif
#ifndef EXAMPLE_I3C_PP_BAUDRATE
#define EXAMPLE_I3C_PP_BAUDRATE 4000000
#endif

static void i3c_master_callback(I3C_Type *base, i3c_master_handle_t *handle, status_t status, void *userData);

double P3T1755_get_temperature();

void P3T1755_InitTemperature(void);

#endif 
