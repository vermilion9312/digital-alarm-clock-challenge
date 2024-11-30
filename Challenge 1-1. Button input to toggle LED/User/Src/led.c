/*
 * led.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef SRC_LED_C_
#define SRC_LED_C_

#include "led.h"

static void toggle_left(Led* this)
{
	this->state = HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin);
	this->state ^= 1;
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, this->state);
}

static void toggle_right(Led* this)
{
	this->state = ~HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin);
	this->state ^= 1;
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, this->state);
}

Led led_left_red   = { LED_LEFT_RED_GPIO_Port,   LED_LEFT_RED_Pin,   false, toggle_left };
Led led_left_green = { LED_LEFT_GREEN_GPIO_Port, LED_LEFT_GREEN_Pin, false, toggle_left };
Led led_left_blue  = { LED_LEFT_BLUE_GPIO_Port,  LED_LEFT_BLUE_Pin,  false, toggle_left };

Led led_right_red   = { LED_RIGHT_RED_GPIO_Port,   LED_RIGHT_RED_Pin,   false, toggle_right };
Led led_right_green = { LED_RIGHT_GREEN_GPIO_Port, LED_RIGHT_GREEN_Pin, false, toggle_right };
Led led_right_blue  = { LED_RIGHT_BLUE_GPIO_Port,  LED_RIGHT_BLUE_Pin,  false, toggle_right };

Led* get_led_left_red(void)
{
	return &led_left_red;
}

Led* get_led_left_green(void)
{
	return &led_left_green;
}

Led* get_led_left_blue(void)
{
	return &led_left_blue;
}

Led* get_led_right_red (void)
{
	return &led_right_red ;
}

Led* get_led_right_green(void)
{
	return &led_right_green;
}

Led* get_led_right_blue(void)
{
	return &led_right_blue;
}

#endif /* SRC_LED_C_ */
