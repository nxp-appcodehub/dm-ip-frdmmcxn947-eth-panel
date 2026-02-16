/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PORT PORT1               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PIN 8U                   /*!<@brief PORT pin number */

#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PORT PORT1               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PIN 9U                   /*!<@brief PORT pin number */

#define BOARD_INITADC_CUR_B_PORT PORT5               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITADC_CUR_B_PIN 2U                   /*!<@brief PORT pin number */

#define BOARD_INITADC_CUR_C_PORT PORT5               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITADC_CUR_C_PIN 3U                   /*!<@brief PORT pin number */

#define BOARD_INITADC_VOLT_DCB_PORT PORT5               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITADC_VOLT_DCB_PIN 4U                   /*!<@brief PORT pin number */

#define BOARD_INITPWM_PWM1_A0_PORT PORT2               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPWM_PWM1_A0_PIN 6U                   /*!<@brief PORT pin number */
                                                       /* @} */
#define BOARD_INITPWM_PWM1_B0_PORT PORT2               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPWM_PWM1_B0_PIN 7U                   /*!<@brief PORT pin number */

#define BOARD_INITPWM_PWM1_A1_PORT PORT2               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPWM_PWM1_A1_PIN 4U                   /*!<@brief PORT pin number */

#define BOARD_INITPWM_PWM1_B1_PORT PORT2               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPWM_PWM1_B1_PIN 5U                   /*!<@brief PORT pin number */

#define BOARD_INITPWM_PWM1_A2_PORT PORT2               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPWM_PWM1_A2_PIN 2U                   /*!<@brief PORT pin number */

#define BOARD_INITPWM_PWM1_B2_PORT PORT2               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPWM_PWM1_B2_PIN 3U                   /*!<@brief PORT pin number */


void BOARD_InitBootPins(void);

void BOARD_InitDEBUG_UARTPins(void);

void BOARD_InitLcdPins(void);

void BOARD_InitAccelPins(void);

void BOARD_InitI3CPins(void);

void BOARD_InitADCTemperature(void);

void BOARD_InitENETHPins(void);

void BOARD_InitADC(void);

void BOARD_InitPWM(void);

void BOARD_InitCMP(void);

void BOARD_InitUSB(void);

void BOARD_InitCANPins(void);

#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
