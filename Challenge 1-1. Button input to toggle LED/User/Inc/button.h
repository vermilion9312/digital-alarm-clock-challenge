/*
 * button.h
 *
 *  Created on: Mar 7, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

typedef struct _Button Button;

struct _Button {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	bool button_state;
	void (* operate)(Button*);
	bool (* is_pressed)(Button*);
};

Button* new_Button(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* INC_BUTTON_H_ */
