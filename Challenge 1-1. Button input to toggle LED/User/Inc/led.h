/*
 * led.h
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdbool.h>
#include "main.h"

typedef struct _Led Led;

struct _Led {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	bool state;
	void (* const toggle)(Led*);
};

Led* get_led_left_red(void);
Led* get_led_left_green(void);
Led* get_led_left_blue(void);
Led* get_led_right_red (void);
Led* get_led_right_green(void);
Led* get_led_right_blue(void);

#endif /* INC_LED_H_ */
