/*
 * uart_interface.h
 *
 *  Created on: Jul 5, 2025
 *      Author: vermilion9312
 */

#ifndef UART_INC_UART_INTERFACE_H_
#define UART_INC_UART_INTERFACE_H_

#include <stddef.h>
#include <>

typedef struct _IUart IUart;

struct _IUart {
	void (* transmit)(IUart*);
	void (* receive)(IUart*);
};

#endif /* UART_INC_UART_INTERFACE_H_ */
