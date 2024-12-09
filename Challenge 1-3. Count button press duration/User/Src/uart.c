/*
 * uart.c
 *
 *  Created on: Dec 6, 2024
 *      Author: LeeJooHo
 */


#include "uart.h"

extern UART_HandleTypeDef huart3;

static void receive(Uart* this)
{
	HAL_UART_Receive_IT(this->huart, this->pData, this->Size);
}

static uint8_t get_data(Uart* this)
{
	return *this->pData;
}

static uint8_t reset_data(Uart* this)
{
	*(this->pData) = 0;
}

static uint8_t data;

static Uart uart = { &huart3, &data, 1, NULL, receive, get_data, reset_data };

Uart* get_uart(void)
{
	return &uart;
}
