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
	LEFT_RED,
	LEFT_GREEN,
	LEFT_BLUE,
	RIGHT_RED,
	RIGHT_GREEN,
	RIGHT_BLUE,
	LED_COUNT
} LED_Index;

void operate_led(ButtonIndex button_index, LED_Index press_led_index, LED_Index release_led_index);

#endif /* INC_LED_H_ */
