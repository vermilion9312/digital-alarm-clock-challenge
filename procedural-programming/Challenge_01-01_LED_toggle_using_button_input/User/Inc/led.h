/*
 * led.h
 *
 *  Created on: Mar 22, 2025
 *      Author: vermilion9312
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

typedef struct {
	GPIO_Config gpio_config;

};

bool is_led_on(LED_Index led_index);
void turn_on_led(LED_Index led_index);
void turn_off_led(LED_Index led_index);

#endif /* INC_LED_H_ */
