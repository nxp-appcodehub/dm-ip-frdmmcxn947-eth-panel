/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2022, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "comunication.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Macro definition to convert an ASCII value into decimal */
#define NUMERIC_ASCII_TO_DEC(x)  (x-'0')
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Build the package needed to request an update on the RPM of the motor
 *
 * @param   ptr_data - Pointer to buffer where the data should be loaded
 * @param   ptr_size - Pointer to variable to return the size of the package
 * @param   rmp_val - RMP value to be added in the buffer data
 *
 *
 * @return  none
 */
void build_indutrialpanel_rpm_request(uint8_t *ptr_data, uint8_t *ptr_size, uint16_t rpm_val)
{
    uint8_t i=0;

    /* Use the array received from the parameter to convert it into correct type */
	comunication_transfer_can_usb_t  * rpm_request_command = (comunication_transfer_can_usb_t *)ptr_data;

	/* Return the size of the commands that is the size of the custom type*/
	*ptr_size = sizeof(comunication_transfer_can_usb_t);

	/* Clean buffer just to make sure there is nothing on it */
	for(i=0; i < *ptr_size; i++)
	{
		*ptr_data = 0x00;
	}

	/* Add RMP Update Request command value */
	rpm_request_command->comunication_command = k_comunication_command_set_rpm_req;
	/* Add the RPM value received as parameter */
	rpm_request_command->comunication_motor_data.comunication_motor_rpm = rpm_val;

}

/*!
 * @brief commad update on the RPM of the motor
 *
 * @param   ptr_data - Pointer to buffer where the data should be loaded
 * @param   ptr_size - Pointer to variable to return the size of the package
 * @param   rmp_val - RMP value to be added in the buffer data
 *
 *
 * @return  none
 */
void build_indutrialpanel_rpm_update(uint8_t *ptr_data, uint8_t *ptr_size, uint16_t speed_percetage, int16_t rpm)
{
    uint8_t i=0;

    /* Use the array received from the parameter to convert it into correct type */
	comunication_transfer_can_usb_t  * rpm_request_command = (comunication_transfer_can_usb_t *)ptr_data;

	/* Return the size of the commands that is the size of the custom type*/
	*ptr_size = sizeof(comunication_transfer_can_usb_t);

	/* Clean buffer just to make sure there is nothing on it */
	for(i=0; i < *ptr_size; i++)
	{
		*ptr_data = 0x00;
	}

	/* Add RMP Update command value */
	rpm_request_command->comunication_command = k_comunication_command_send_rpm;
	/* Add calculated RPM based on the percentage  */
	rpm_request_command->comunication_motor_data.comunication_motor_rpm = rpm;
	/* Add the Percentage value received as parameter */
	rpm_request_command->comunication_motor_data.comunication_motor_rpm_slider = speed_percetage;

}

/*!
 * @brief This function will convert the RMP received in ASCII from the wireless tool box to decimal value
 *
 * @param   ascii_buff - Pointer to buffer where the ASCII value is located
 * @param   dec_val - Pointer to variable to return the decimal value
 * @param   ascii_length - Length of the ASCII package received.
 *
 *
 * @return  none
 */
void industrialpanel_ascci_rpm_to_dec(uint8_t *ascii_buff, uint16_t *dec_val, uint16_t ascii_length)
{
    switch(ascii_length)
    {
    	case 4:
        	*dec_val =( (NUMERIC_ASCII_TO_DEC(ascii_buff[0])*1000) + (NUMERIC_ASCII_TO_DEC(ascii_buff[1])*100) +
        			(NUMERIC_ASCII_TO_DEC(ascii_buff[2])*10) + (NUMERIC_ASCII_TO_DEC(ascii_buff[3])*1) );
    		break;

    	case 3:
        	*dec_val =( (NUMERIC_ASCII_TO_DEC(ascii_buff[0])*100) + (NUMERIC_ASCII_TO_DEC(ascii_buff[1])*10) +
        			(NUMERIC_ASCII_TO_DEC(ascii_buff[2])*1) );
    		break;

    	case 2:
        	*dec_val =( (NUMERIC_ASCII_TO_DEC(ascii_buff[0])*10) + (NUMERIC_ASCII_TO_DEC(ascii_buff[1])*1) );
    		break;

    	case 1:
    		*dec_val =( (NUMERIC_ASCII_TO_DEC(ascii_buff[0])*1) );
    		break;

    }

}




