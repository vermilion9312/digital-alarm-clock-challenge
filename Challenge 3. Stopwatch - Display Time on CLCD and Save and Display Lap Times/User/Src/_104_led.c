/*
 * _104_led.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef SRC_C_
#define SRC_C_

#include <_104_led.h>

static void turn_on_led(Led* this, Button* button);
static void turn_off_led(Led* this, Button* button);

Led left_red    = { .mode = NULL, .is_transitioned = false, .GPIOx = LEFT_RED_GPIO_Port,    .GPIO_Pin = LEFT_RED_Pin,    .last_button = false, .operate = turn_off_led };
Led left_green  = { .mode = NULL, .is_transitioned = false, .GPIOx = LEFT_GREEN_GPIO_Port,  .GPIO_Pin = LEFT_GREEN_Pin,  .last_button = false, .operate = turn_off_led };
Led left_blue   = { .mode = NULL, .is_transitioned = false, .GPIOx = LEFT_BLUE_GPIO_Port,   .GPIO_Pin = LEFT_BLUE_Pin,   .last_button = false, .operate = turn_off_led };

Led right_red   = { .mode = NULL, .is_transitioned = false, .GPIOx = RIGHT_RED_GPIO_Port,   .GPIO_Pin = RIGHT_RED_Pin,   .last_button = false, .operate = turn_off_led };
Led right_green = { .mode = NULL, .is_transitioned = false, .GPIOx = RIGHT_GREEN_GPIO_Port, .GPIO_Pin = RIGHT_GREEN_Pin, .last_button = false, .operate = turn_off_led };
Led right_blue  = { .mode = NULL, .is_transitioned = false, .GPIOx = RIGHT_BLUE_GPIO_Port,  .GPIO_Pin = RIGHT_BLUE_Pin,  .last_button = false, .operate = turn_off_led };


static void turn_on_led(Led* this, Button* button)
{
//	static bool last_button = false;

	TURN_ON_LED;


	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->operate = turn_off_led;
	}

	this->last_button = button->is_pressed(button);
}

static void turn_off_led(Led* this, Button* button)
{
//	static bool last_button = false;

	TURN_OFF_LED;


	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->operate = turn_on_led;
	}

	this->last_button = button->is_pressed(button);
}

Led* get_left_red(void)
{
	return &left_red;
}

Led* get_left_green(void)
{
	return &left_green;
}

Led* get_left_blue(void)
{
	return &left_blue;
}

Led* get_right_red (void)
{
	return &right_red ;
}

Led* get_right_green(void)
{
	return &right_green;
}

Led* get_right_blue(void)
{
	return &right_blue;
}



#endif /* SRC_C_ */
