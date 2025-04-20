/*
 * gpio_config.h
 *
 *  Created on: Mar 22, 2025
 *      Author: vermilion9312
 */

#ifndef INC_GPIO_CONFIG_H_
#define INC_GPIO_CONFIG_H_

#include "stm32f4xx_hal.h"

typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t      GPIO_Pin;
} GPIO_Config;

#endif /* INC_GPIO_CONFIG_H_ */
