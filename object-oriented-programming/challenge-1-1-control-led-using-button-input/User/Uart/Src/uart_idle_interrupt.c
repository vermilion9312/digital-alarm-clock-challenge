/*
 * uart_idle_interrupt.c
 *
 *  Created on: Jul 5, 2025
 *      Author: vermi
 */


#include "uart_idle_interrupt.h"

static void receive(IUart* uart)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

}

static void transmit(IUart* uart, const uint8_t* date, size_t len)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt) uart;

	this->tx_buffer = data;
	this->tx_length = len;
	this->tx_done = false;

	HAL_UART_Transmit_IT(this->huart, this->tx_buffer, this->tx_length);
}

