/*
 * _105_button.h
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef INC__105_BUTTON_H_
#define INC__105_BUTTON_H_

#include <stdbool.h>
#include "main.h"

typedef struct _Button Button;

struct _Button {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	bool button_state;
	void (* const update)(Button*);
	bool (* const is_pressed)(Button*);
};

Button* get_button_1(void);
Button* get_button_2(void);
Button* get_button_3(void);
Button* get_button_4(void);

#endif /* INC__105_BUTTON_H_ */
