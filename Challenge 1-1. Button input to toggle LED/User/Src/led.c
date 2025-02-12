/*
 * led.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef SRC_C_
#define SRC_C_

#include "led.h"

static void set_state(Led* this, Operate operate);
static void turn_on_left(Led* this, Button* button);
static void turn_off_left(Led* this, Button* button);
static void turn_on_right(Led* this, Button* button);
static void turn_off_right(Led* this, Button* button);

static Led left_red   = { LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   turn_off_left, set_state };
static Led left_green = { LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, turn_off_left, set_state };
static Led left_blue  = { LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  turn_off_left, set_state };

static Led right_red   = { RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   turn_off_right, set_state };
static Led right_green = { RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, turn_off_right, set_state };
static Led right_blue  = { RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin,  turn_off_right, set_state };

static void set_state(Led* this, Operate operate)
{
	this->operate = operate;
}

static void turn_off_left(Led* this, Button* button)
{
	TURN_OFF_LED;

	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->set_state(this, turn_on_left);
	}

	this->last_button = button->is_pressed(button);
}

static void turn_on_left(Led* this, Button* button)
{
	TURN_ON_LED;

	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->set_state(this, turn_off_left);
	}

	this->last_button = button->is_pressed(button);
}

static void turn_off_right(Led* this, Button* button)
{
	TURN_OFF_LED;

	if (this->last_button== true && button->is_pressed(button) == false)
	{
		this->operate = turn_on_right;
	}

	this->last_button = button->is_pressed(button);
}

static void turn_on_right(Led* this, Button* button)
{
	TURN_ON_LED;

	if (this->last_button == true && button->is_pressed(button) == false)
	{
		this->operate = turn_off_right;
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
