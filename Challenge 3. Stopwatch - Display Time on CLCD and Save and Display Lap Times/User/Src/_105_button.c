/*
 * _105_button.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */


#include <_105_button.h>

static void update(Button* this)
{
	if (HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin) == GPIO_PIN_SET)
	{
		if (this->_is_pressed == false) this->_is_pressed = true;
	}
	else
	{
		if (this->_is_pressed == true) this->_is_pressed = false;
	}
}

static bool is_pressed(Button* this)
{
	return this->_is_pressed;
}

static Button button_1 = { BUTTON_1_GPIO_Port, BUTTON_1_Pin, false, update, is_pressed };
static Button button_2 = { BUTTON_2_GPIO_Port, BUTTON_2_Pin, false, update, is_pressed };
static Button button_3 = { BUTTON_3_GPIO_Port, BUTTON_3_Pin, false, update, is_pressed };
static Button button_4 = { BUTTON_4_GPIO_Port, BUTTON_4_Pin, false, update, is_pressed };

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

Button* get_button_4(void)
{
	return &button_4;
}
