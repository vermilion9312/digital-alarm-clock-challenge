/*
 * _003_uart.h
 *
 *  Created on: Dec 6, 2024
 *      Author: LeeJooHo
 */

#ifndef INC__003_UART_H_
#define INC__003_UART_H_

#include "main.h"

typedef struct _Uart Uart;

struct _Uart {
	UART_HandleTypeDef* huart;
	uint8_t* pData;
	uint16_t Size;

	void (* const transmit)(Uart*);
	void (* const receive)(Uart*);
	uint8_t (* const get_data)(Uart*);
	void (* const reset_data)(Uart*);
};

Uart* get_uart(void);

#endif /* INC__003_UART_H_ */
