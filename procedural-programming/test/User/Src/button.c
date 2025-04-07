/*
 * button.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
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

void update_button(ButtonIndex index)
{
	button_state[index] = HAL_GPIO_ReadPin(button_config[index].GPIOx, button_config[index].GPIO_Pin);
}

void update_last_button(ButtonIndex index)
{
	last_button_state[index] = is_pressed(index);
}

bool is_pressed(ButtonIndex index)
{
	return button_state[index];
}

bool was_pressed(ButtonIndex index)
{
	return last_button_state[index];
}

#endif /* SRC_BUTTON_C_ */
