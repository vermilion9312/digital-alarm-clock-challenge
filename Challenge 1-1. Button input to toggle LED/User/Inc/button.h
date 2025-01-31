/*
 * button.h
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdbool.h>
#include "main.h"

typedef struct _Button Button;

struct _Button {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	void (* const update)(Button*);
	bool (* const is_pressed)(Button*);
	bool button_state;
};

Button* get_button_1(void);
Button* get_button_2(void);
Button* get_button_3(void);

#endif /* INC_BUTTON_H_ */
