/*
 * uart.c
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */


#include "uart.h"

static uint8_t data = MAGIC_NUMBER;

void receive_data(void)
{
	HAL_UART_Receive_IT(&huart3, &data, sizeof(data));
}

LED_Index get_rxd(void)
{
	if (data == '1') return RED;
	if (data == '2') return GREEN;
	if (data == '3') return BLUE;
	if (data == '4') return CHANGE_DIRECTION;

	return MAGIC_NUMBER;
}

void reset_data(void)
{
	data = MAGIC_NUMBER;
}
