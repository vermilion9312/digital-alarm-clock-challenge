/*
 * led.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef SRC_C_
#define SRC_C_

#include "led.h"

static void turn_on_left(Led* this, Button* button);
static void turn_off_left(Led* this, Button* button);
static void turn_on_right(Led* this, Button* button);
static void turn_off_right(Led* this, Button* button);

Led left_red    = { .GPIOx = LEFT_RED_GPIO_Port,    .GPIO_Pin = LEFT_RED_Pin,    .last_button = false, .operate = turn_off_left,  .on = turn_on_left,  .off = turn_off_left };
Led left_green  = { .GPIOx = LEFT_GREEN_GPIO_Port,  .GPIO_Pin = LEFT_GREEN_Pin,  .last_button = false, .operate = turn_off_left,  .on = turn_on_left,  .off = turn_off_left };
Led left_blue   = { .GPIOx = LEFT_BLUE_GPIO_Port,   .GPIO_Pin = LEFT_BLUE_Pin,   .last_button = false, .operate = turn_off_left,  .on = turn_on_left,  .off = turn_off_left };

Led right_red   = { .GPIOx = RIGHT_RED_GPIO_Port,   .GPIO_Pin = RIGHT_RED_Pin,   .last_button = false, .operate = turn_off_right, .on = turn_on_right, .off = turn_off_right };
Led right_green = { .GPIOx = RIGHT_GREEN_GPIO_Port, .GPIO_Pin = RIGHT_GREEN_Pin, .last_button = false, .operate = turn_off_right, .on = turn_on_right, .off = turn_off_right };
Led right_blue  = { .GPIOx = RIGHT_BLUE_GPIO_Port,  .GPIO_Pin = RIGHT_BLUE_Pin,  .last_button = false, .operate = turn_off_right, .on = turn_on_right, .off = turn_off_right };

static void turn_on_left(Led* this, Button* button)
{
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_RESET);

	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->operate = turn_off_left;
	}

	this->last_button = button->is_pressed(button);
}

static void turn_off_left(Led* this, Button* button)
{
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_SET);

	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->operate = turn_on_left;
	}

	this->last_button = button->is_pressed(button);
}

static void turn_on_right(Led* this, Button* button)
{
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_RESET);

	if (this->last_button == true && button->is_pressed(button) == false)
	{
		this->operate = turn_off_right;
	}

	this->last_button = button->is_pressed(button);
}

static void turn_off_right(Led* this, Button* button)
{
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_SET);

	if (this->last_button== true && button->is_pressed(button) == false)
	{
		this->operate = turn_on_right;
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
