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
	if (last_button_state[button_index]) return false;
	if (!button_state[button_index]    ) return false;

	return true;
}

bool is_button_released(ButtonIndex button_index)
{
	if (!last_button_state[button_index]) return false;
	if (button_state[button_index]      ) return false;

	return true;
}

#endif /* SRC_BUTTON_C_ */
