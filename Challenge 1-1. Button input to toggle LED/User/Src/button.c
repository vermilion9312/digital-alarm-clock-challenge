/*
 * button.c
 *
 *  Created on: Mar 7, 2025
 *      Author: LeeJooHo
 */


#include "button.h"

static void operate(Button* this)
{
	this->button_state = HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin);
}

static bool is_pressed(Button* this)
{
	return this->button_state;
}

Button* new_Button(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	Button* this = malloc(sizeof(Button));

	this->GPIOx        = GPIOx;
	this->GPIO_Pin     = GPIO_Pin;
	this->button_state = false;
	this->operate      = operate;
	this->is_pressed   = is_pressed;

	return this;
}
