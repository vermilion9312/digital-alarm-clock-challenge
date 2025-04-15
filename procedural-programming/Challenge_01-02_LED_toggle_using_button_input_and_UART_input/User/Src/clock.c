/*
 * clock.c
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */


#include "clock.h"


void operate_led(ButtonIndex button_index, LED_Index led_index)
{
	if (is_button_rising(button_index))
	{
		is_led_on(led_index) ? turn_off_led(led_index) : turn_on_led(led_index);
		return;
	}

//	uint8_t index = get_rxd();
//	if (index > 3) return;
//	is_led_on(index) ? turn_off_led(index) : turn_on_led(index);
//	index = 99;
}

