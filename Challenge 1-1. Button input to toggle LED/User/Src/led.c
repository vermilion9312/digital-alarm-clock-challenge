/*
 * led.c
 *
 *  Created on: Mar 7, 2025
 *      Author: LeeJooHo
 */


#include "led.h"

static void turn_on_led(LED* this, Button* button);

static void turn_off_led(LED* this, Button* button)
{
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_SET);

	if (button->is_pressed(button))
	{
		this->operate = turn_on_led;
	}
}

static void turn_on_led(LED* this, Button* button)
{
	HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_RESET);

	if (button->is_pressed(button))
	{
		this->operate = turn_off_led;
	}
}

LED* new_LED(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	LED* this = malloc(sizeof(LED));

	this->GPIOx    = GPIOx;
	this->GPIO_Pin = GPIO_Pin;
	this->operate  = turn_off_led;

	return this;
}
