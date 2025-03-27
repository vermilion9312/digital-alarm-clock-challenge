/*
 * led.h
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "gpio_config.h"
#include "main.h"
#include <stdbool.h>
#include "button.h"

typedef enum {
	RED,
	GREEN,
	BLUE,
	LED_COUNT
} LED_Index;

void led_init(void);
void change_led_direction(void);
void operate_led(ButtonIndex button_index, LED_Index led_index);

#endif /* INC_LED_H_ */
