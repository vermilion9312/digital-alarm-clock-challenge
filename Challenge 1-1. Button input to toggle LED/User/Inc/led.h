/*
 * led.h
 *
 *  Created on: Mar 7, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdlib.h>
#include "main.h"
#include "button.h"

typedef struct _LED LED;

struct _LED {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	void (* operate)(LED*, Button*);
};

LED* new_LED(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* INC_LED_H_ */
