/*
 * operateion.c
 *
 *  Created on: Mar 25, 2025
 *      Author: vermi
 */


#include "operation.h"

void operate(ButtonIndex button_index, LED_Index press_led_index, LED_Index release_led_index)
{
	update_button(button_index);

	if (!was_pressed(button_index) && is_pressed(button_index))
	{
	  if (is_on(press_led_index))
	  {
		  turn_off(press_led_index);
		  update_led(press_led_index);
	  }
	  else
	  {
		  turn_on(press_led_index);
		  update_led(press_led_index);
	  }
	}

	if (was_pressed(button_index) && !is_pressed(button_index))
	{
	  if (is_on(release_led_index))
	  {
		  turn_off(release_led_index);
		  update_led(release_led_index);
	  }
	  else
	  {
		  turn_on(release_led_index);
		  update_led(release_led_index);
	  }
	}

	update_last_button(button_index);
}
