/*
 * operateion.c
 *
 *  Created on: Mar 25, 2025
 *      Author: vermi
 */


#include "operation.h"

void operate(ButtonIndex button_index, LED_Index press_led_index, LED_Index release_led_index)
{
	update_button(button_index); // 현재 버튼 상태를 업데이트

	if (!was_pressed(button_index) && is_pressed(button_index)) // 버튼을 누르는 순간
	{
	  if (is_on(press_led_index)) // 현재 led 상태를 확인
	  {
		  turn_off(press_led_index);   // led를 끄고
		  update_led(press_led_index); // 현재 led 상태를 업데이트
	  }
	  else
	  {
		  turn_on(press_led_index);    // led를 키고
		  update_led(press_led_index); // 현재 led 상태를 업데이트
	  }
	}

	if (was_pressed(button_index) && !is_pressed(button_index)) // 버튼을 떼는 순간
	{
	  if (is_on(release_led_index)) // 현재 led 상태를 확인
	  {
		  turn_off(release_led_index);   // led를 끄고
		  update_led(release_led_index); // 현재 led 상태를 업데이트
	  }
	  else
	  {
		  turn_on(release_led_index);    // led를 키고
		  update_led(release_led_index); // 현재 led 상태를 업데이트
	  }
	}

	update_last_button(button_index); // 지난 버튼 상태를 업데이트
}
