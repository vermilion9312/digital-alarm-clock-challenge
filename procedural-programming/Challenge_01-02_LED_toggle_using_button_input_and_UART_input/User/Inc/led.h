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
#include "uart.h"

typedef enum {
	RED,
	GREEN,
	BLUE,
	LED_COUNT
} LED_Index;

bool is_led_on(LED_Index led_index);
void turn_on_led(LED_Index led_index);
void turn_off_led(LED_Index led_index);
void change_led_direction(ButtonIndex button_index);

#endif /* INC_LED_H_ */
