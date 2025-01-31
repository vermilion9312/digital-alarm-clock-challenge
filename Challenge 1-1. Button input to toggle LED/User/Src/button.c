/*
 * button.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */


#include "button.h"

static void update(Button* this)
{
	this->button_state = HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin);
}

static bool is_pressed(Button* this)
{
	return this->button_state;
}

static Button button_1 = { BUTTON_1_GPIO_Port, BUTTON_1_Pin, update, is_pressed };
static Button button_2 = { BUTTON_2_GPIO_Port, BUTTON_2_Pin, update, is_pressed };
static Button button_3 = { BUTTON_3_GPIO_Port, BUTTON_3_Pin, update, is_pressed };

Button* get_button_1(void)
{
	return &button_1;
}

Button* get_button_2(void)
{
	return &button_2;
}

Button* get_button_3(void)
{
	return &button_3;
}
