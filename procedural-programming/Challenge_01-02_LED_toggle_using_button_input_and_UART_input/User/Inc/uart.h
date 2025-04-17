/*
 * uart.h
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "led.h"
#include "main.h"

#define MAGIC_NUMBER 9;

typedef enum _LED_Index LED_Index;

void receive_data(void);
LED_Index get_rxd(void);
void reset_data(void);

#endif /* INC_UART_H_ */
