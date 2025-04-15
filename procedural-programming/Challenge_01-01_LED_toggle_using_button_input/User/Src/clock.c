/*
 * clock.c
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */


#include "clock.h"


void operate_left_led(ButtonIndex button_index, LED_Index led_index)
{
	if (is_button_rising(button_index))
	{
		is_led_on(led_index) ? turn_off_led(led_index) : turn_on_led(led_index);
	}
}


void operate_right_led(ButtonIndex button_index, LED_Index led_index)
{
	if (is_button_falling(button_index))
	{
		is_led_on(led_index) ? turn_off_led(led_index) : turn_on_led(led_index);
	}
}
