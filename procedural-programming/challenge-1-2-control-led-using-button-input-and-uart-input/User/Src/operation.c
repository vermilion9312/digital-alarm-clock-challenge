/*
 * operateion.c
 *
 *  Created on: Mar 25, 2025
 *      Author: vermi
 */


#include "operation.h"

void operate(ButtonIndex button_index, LED_Index led_index)
{
	update_button(button_index);

	if (!was_pressed(button_index) && is_pressed(button_index))
	{
	  if (is_on(led_index))
	  {
		  turn_off(led_index);
		  update_led(led_index);
	  }
	  else
	  {
		  turn_on(led_index);
		  update_led(led_index);
	  }
	}

	update_last_button(button_index);
}
