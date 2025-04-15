/*
 * uart.c
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */


#include "uart.h"

static uint8_t data = 99;

void receive_data(void)
{
	HAL_UART_Receive_IT(&huart3, &data, sizeof(data));
}

uint8_t get_rxd(void)
{
	if (data == '1') return 0;
	if (data == '2') return 1;
	if (data == '3') return 2;
	if (data == '4') return 3;

	return 0;
}

void reset_data(void)
{
	data = 0;
}
