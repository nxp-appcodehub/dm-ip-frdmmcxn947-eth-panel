/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include "fsl_inputmux.h"


void BOARD_InitBootPins(void)
{
    BOARD_InitDEBUG_UARTPins();
    BOARD_InitLcdPins();
    BOARD_InitAccelPins();
    BOARD_InitI3CPins();
    BOARD_InitADCTemperature();
    BOARD_InitENETHPins();
    BOARD_InitUSB();
    BOARD_InitCANPins();
}

void BOARD_InitDEBUG_UARTPins(void)
{
    const port_pin_config_t uart_pin_config =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt2,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    /* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);
    /* PORT1_8 (pin A1) is configured as FC4_P0 */
    PORT_SetPinConfig(BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PORT, BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RX_PIN, &uart_pin_config);
    /* PORT1_9 (pin B1) is configured as FC4_P1 */
    PORT_SetPinConfig(BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PORT, BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TX_PIN, &uart_pin_config);
}


void BOARD_InitLcdPins(void)
{
    const port_pin_config_t flexio_pin_config =
    {
		kPORT_PullUp,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt6,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };

    const port_pin_config_t gpio_pin_config =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt0,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };

    const port_pin_config_t flex_comm_pin_config =
    {
		kPORT_PullUp,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt2,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    /* Enables the clock for GPIO0: Enables clock */
    CLOCK_EnableClock(kCLOCK_Gpio0);
    /* Enables the clock for GPIO4: Enables clock */
    CLOCK_EnableClock(kCLOCK_Gpio4);
    /* Enables the clock for PORT0 controller: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port0);
    /* Enables the clock for PORT2: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port2);
    /* Enables the clock for PORT4: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port4);

    gpio_pin_config_t gpio_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_7 (pin C13)  */
    GPIO_PinInit(GPIO0, 7U, &gpio_config);
    /* Initialize GPIO functionality on pin PIO0_12 (pin D11)  */
    GPIO_PinInit(GPIO0, 12U, &gpio_config);
    /* Initialize GPIO functionality on pin PIO4_7 (pin T4)  */
    GPIO_PinInit(GPIO4, 7U, &gpio_config);
    /* Initialize GPIO functionality on pin PIO0_13 (pin F12)  */
    gpio_config.pinDirection = kGPIO_DigitalInput;
    GPIO_PinInit(GPIO0, 13U, &gpio_config);
    /* Initialize GPIO functionality on pin PIO4_6 (pin N7)  */
    GPIO_PinInit(GPIO4, 6U, &gpio_config);

    /* PORT0_12 (pin D11) is configured as PIO0_12 */
    PORT_SetPinConfig(PORT0, 12U, &gpio_pin_config);
    /* PORT0_13 (pin F12) is configured as PIO0_13 */
    PORT_SetPinConfig(PORT0, 13U, &gpio_pin_config);
    /* PORT0_7 (pin C13) is configured as PIO0_7 */
    PORT_SetPinConfig(PORT0, 7U, &gpio_pin_config);
    /* PORT4_6 (pin N7) is configured as PIO4_6 */
    PORT_SetPinConfig(PORT4, 6U, &gpio_pin_config);
    /* PORT4_7 (pin T4) is configured as PIO4_7 */
    PORT_SetPinConfig(PORT4, 7U, &gpio_pin_config);

    /* PORT0_8 (pin C12) is configured as FLEXIO0_D0 */
    PORT_SetPinConfig(PORT0, 8U, &flexio_pin_config);
    /* PORT0_9 (pin A12) is configured as FLEXIO0_D1 */
    PORT_SetPinConfig(PORT0, 9U, &flexio_pin_config);
    /* PORT2_10 (pin M3) is configured as FLEXIO0_D18 */
    PORT_SetPinConfig(PORT2, 10U, &flexio_pin_config);
    /* PORT2_11 (pin N4) is configured as FLEXIO0_D19 */
    PORT_SetPinConfig(PORT2, 11U, &flexio_pin_config);
    /* PORT2_8 (pin M2) is configured as FLEXIO0_D16 */
    PORT_SetPinConfig(PORT2, 8U, &flexio_pin_config);
    /* PORT2_9 (pin M1) is configured as FLEXIO0_D17 */
    PORT_SetPinConfig(PORT2, 9U, &flexio_pin_config);
    /* PORT4_12 (pin T6) is configured as FLEXIO0_D20 */
    PORT_SetPinConfig(PORT4, 12U, &flexio_pin_config);
    /* PORT4_13 (pin T7) is configured as FLEXIO0_D21 */
    PORT_SetPinConfig(PORT4, 13U, &flexio_pin_config);
    /* PORT4_14 (pin N8) is configured as FLEXIO0_D22 */
    PORT_SetPinConfig(PORT4, 14U, &flexio_pin_config);
    /* PORT4_15 (pin T8) is configured as FLEXIO0_D23 */
    PORT_SetPinConfig(PORT4, 15U, &flexio_pin_config);
    /* PORT4_16 (pin R8) is configured as FLEXIO0_D24 */
    PORT_SetPinConfig(PORT4, 16U, &flexio_pin_config);
    /* PORT4_17 (pin R9) is configured as FLEXIO0_D25 */
    PORT_SetPinConfig(PORT4, 17U, &flexio_pin_config);
    /* PORT4_18 (pin N10) is configured as FLEXIO0_D26 */
    PORT_SetPinConfig(PORT4, 18U, &flexio_pin_config);
    /* PORT4_19 (pin R10) is configured as FLEXIO0_D27 */
    PORT_SetPinConfig(PORT4, 19U, &flexio_pin_config);
    /* PORT4_20 (pin T10) is configured as FLEXIO0_D28 */
    PORT_SetPinConfig(PORT4, 20U, &flexio_pin_config);
    /* PORT4_21 (pin T11) is configured as FLEXIO0_D29 */
    PORT_SetPinConfig(PORT4, 21U, &flexio_pin_config);
    /* PORT4_22 (pin T12) is configured as FLEXIO0_D30 */
    PORT_SetPinConfig(PORT4, 22U, &flexio_pin_config);
    /* PORT4_23 (pin U12) is configured as FLEXIO0_D31 */
    PORT_SetPinConfig(PORT4, 23U, &flexio_pin_config);

    /* PORT4_0 (pin P1) is configured as FC2_P0 */
    PORT_SetPinConfig(PORT4, 0U, &flex_comm_pin_config);
    /* PORT4_1 (pin P2) is configured as FC2_P1 */
    PORT_SetPinConfig(PORT4, 1U, &flex_comm_pin_config);
}

void BOARD_InitAccelPins(void)
{
	port_pin_config_t pin_config =
	{
			kPORT_PullUp,
            kPORT_HighPullResistor,
            kPORT_FastSlewRate,
            kPORT_PassiveFilterDisable,
            kPORT_OpenDrainEnable,
			kPORT_HighDriveStrength,
            kPORT_MuxAlt2,
            kPORT_InputBufferEnable,
            kPORT_InputNormal,
            kPORT_UnlockRegister
	};
	CLOCK_EnableClock(kCLOCK_Port1);
	PORT_SetPinConfig(PORT1, 1, &pin_config);
	PORT_SetPinConfig(PORT1, 0, &pin_config);
}

void BOARD_InitI3CPins(void)
{
    PORT_DisableEFTDetectInterrupts(PORT1, 0x30E0F0u);


    /* PORT1_16 (pin F6) is configured as I3C1_SDA */
    port_pin_config_t pin_config_i3c =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt10,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    PORT_SetPinConfig(PORT1, 16, &pin_config_i3c);
    PORT_SetPinConfig(PORT1, 17, &pin_config_i3c);
}

void BOARD_InitADCTemperature(void)
{
    /*Temperature sensor*/
   const port_pin_config_t adc_pin_config = {
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt0,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
   };
   /* PORT0_16 (pin P0) is configured as ADC0_B12/NVM_TM0 */
   PORT_SetPinConfig(PORT0, 12U, &adc_pin_config);
}

void BOARD_InitENETHPins(void)
{
    const port_pin_config_t enet_pin_config =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt9,
		kPORT_InputBufferEnable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    /* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);
    /* PORT1_13 (pin D1) is configured as ENET0_RXDV */
    PORT_SetPinConfig(PORT1, 13U, &enet_pin_config);
    /* PORT1_14 (pin D4) is configured as ENET0_RXD0 */
    PORT_SetPinConfig(PORT1, 14U, &enet_pin_config);
    /* PORT1_15 (pin E4) is configured as ENET0_RXD1 */
    PORT_SetPinConfig(PORT1, 15U, &enet_pin_config);
    /* PORT1_20 (pin K5) is configured as ENET0_MDC */
    PORT_SetPinConfig(PORT1, 20U, &enet_pin_config);
    /* PORT1_21 (pin L5) is configured as ENET0_MDIO */
    PORT_SetPinConfig(PORT1, 21U, &enet_pin_config);
    /* PORT1_4 (pin A4) is configured as ENET0_TX_CLK */
    PORT_SetPinConfig(PORT1, 4U, &enet_pin_config);
    /* PORT1_5 (pin B3) is configured as ENET0_TXEN */
    PORT_SetPinConfig(PORT1, 5U, &enet_pin_config);
    /* PORT1_6 (pin B2) is configured as ENET0_TXD0 */
    PORT_SetPinConfig(PORT1, 6U, &enet_pin_config);
    /* PORT1_7 (pin A2) is configured as ENET0_TXD1 */
    PORT_SetPinConfig(PORT1, 7U, &enet_pin_config);
}

void BOARD_InitADC(void)
{
    const port_pin_config_t motor_control_adc_pin_config =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt0,
		kPORT_InputBufferDisable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    PORT_SetPinConfig(PORT5, 2U, &motor_control_adc_pin_config);
    PORT_SetPinConfig(PORT5, 3U, &motor_control_adc_pin_config);
    PORT_SetPinConfig(PORT5, 4U, &motor_control_adc_pin_config);
}

void BOARD_InitPWM(void)
{
    const port_pin_config_t motor_control_adc_pin_config =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt5,
		kPORT_InputBufferDisable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    /* Enables the clock for INPUTMUX: Enables clock */
    CLOCK_EnableClock(kCLOCK_InputMux0);
    /* Enables the clock for PORT2: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port2);
    /* CMP1_OUT is selected as trigger input for FlexPWM1 FAULT0 0 */
    INPUTMUX_AttachSignal(INPUTMUX0, 0U, kINPUTMUX_Cmp1OutToFlexPwm1Fault0);

    /* PORT2_2 (pin H3) is configured as PWM1_A2 */
    PORT_SetPinConfig(BOARD_INITPWM_PWM1_A2_PORT, BOARD_INITPWM_PWM1_A2_PIN, &motor_control_adc_pin_config);
    /* PORT2_3 (pin J3) is configured as PWM1_B2 */
    PORT_SetPinConfig(BOARD_INITPWM_PWM1_B2_PORT, BOARD_INITPWM_PWM1_B2_PIN, &motor_control_adc_pin_config);
    /* PORT2_4 (pin K3) is configured as PWM1_A1 */
    PORT_SetPinConfig(BOARD_INITPWM_PWM1_A1_PORT, BOARD_INITPWM_PWM1_A1_PIN, &motor_control_adc_pin_config);
    /* PORT2_5 (pin K1) is configured as PWM1_B1 */
    PORT_SetPinConfig(BOARD_INITPWM_PWM1_B1_PORT, BOARD_INITPWM_PWM1_B1_PIN, &motor_control_adc_pin_config);
    /* PORT2_6 (pin K2) is configured as PWM1_A0 */
    PORT_SetPinConfig(BOARD_INITPWM_PWM1_A0_PORT, BOARD_INITPWM_PWM1_A0_PIN, &motor_control_adc_pin_config);
    /* PORT2_7 (pin L2) is configured as PWM1_B0 */
    PORT_SetPinConfig(BOARD_INITPWM_PWM1_B0_PORT, BOARD_INITPWM_PWM1_B0_PIN, &motor_control_adc_pin_config);
}

void BOARD_InitCMP(void)
{
    const port_pin_config_t cmp_pin_config =
    {
		kPORT_PullDisable,
		kPORT_LowPullResistor,
		kPORT_FastSlewRate,
		kPORT_PassiveFilterDisable,
		kPORT_OpenDrainDisable,
		kPORT_LowDriveStrength,
		kPORT_MuxAlt0,
		kPORT_InputBufferDisable,
		kPORT_InputNormal,
		kPORT_UnlockRegister
    };
    /* Enables the clock for PORT0 controller: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port0);
    /* PORT0_3 (pin B15) is configured as CMP1_IN1 */
    PORT_SetPinConfig(PORT0, 3U, &cmp_pin_config);
}

void BOARD_InitUSB(void)
{
    CLOCK_EnableClock(kCLOCK_Port0);

    const port_pin_config_t port0_2_pinB16_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* High drive strength is configured */
                                                     kPORT_HighDriveStrength,
                                                     /* Pin is configured as SWO */
                                                     kPORT_MuxAlt1,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT0_2 (pin B16) is configured as SWO */
    PORT_SetPinConfig(PORT0, 2U, &port0_2_pinB16_config);
}

void BOARD_InitCANPins(void)
{
    /* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);

    const port_pin_config_t port1_10_pinG4_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as CAN0_TXD */
                                                     kPORT_MuxAlt11,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT1_18 (pin G4) is configured as CAN0_TXD */
    PORT_SetPinConfig(PORT1, 10U, &port1_10_pinG4_config);

    const port_pin_config_t port1_11_pinG5_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as CAN0_RXD */
                                                     kPORT_MuxAlt11,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT1_19 (pin G5) is configured as CAN0_RXD */
    PORT_SetPinConfig(PORT1, 11U, &port1_11_pinG5_config);

}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
