/*
 * button.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermilion9312
 */

#ifndef SRC_BUTTON_C_
#define SRC_BUTTON_C_

#include "button.h"

static GPIO_Config button_config[BUTTON_COUNT] = {
		{ BUTTON_1_GPIO_Port, BUTTON_1_Pin },
		{ BUTTON_2_GPIO_Port, BUTTON_2_Pin },
		{ BUTTON_3_GPIO_Port, BUTTON_3_Pin },
		{ BUTTON_4_GPIO_Port, BUTTON_4_Pin },
};

static bool button_state[BUTTON_COUNT];
static bool last_button_state[BUTTON_COUNT];

void update_button(ButtonIndex button_index)
{
	button_state[button_index] = HAL_GPIO_ReadPin(button_config[button_index].GPIOx, button_config[button_index].GPIO_Pin);
}

void update_last_button(ButtonIndex button_index)
{
	last_button_state[button_index] = button_state[button_index];
}

bool is_button_pressed(ButtonIndex button_index)
{
	if (!last_button_state[button_index] && button_state[button_index])
	{
		return true;
	}

	return false;
}

bool is_button_released(ButtonIndex button_index)
{
	if (last_button_state[button_index] && !button_state[button_index])
	{
		return true;
	}

	return false;
}

bool is_button_on(ButtonIndex button_index)
{
	return button_state[button_index];
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	static bool is_button_pressed;

	if (GPIO_Pin == BUTTON_1_Pin)
	{
		if (HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin))
		{
			if (!is_button_pressed)
			{
				is_button_pressed = !is_button_pressed;
				HAL_GPIO_TogglePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin);
			}
		}
		else
		{
			if (is_button_pressed)
			{
				is_button_pressed = !is_button_pressed;
			}
		}
	}
}

#endif /* SRC_BUTTON_C_ */
