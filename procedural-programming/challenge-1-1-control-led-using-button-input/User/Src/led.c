/*
 * led.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#include "led.h"

static GPIO_Config led_config[LED_COUNT] = {
		{ LEFT_RED_GPIO_Port,    LEFT_RED_Pin    },
		{ LEFT_GREEN_GPIO_Port,  LEFT_GREEN_Pin  },
		{ LEFT_BLUE_GPIO_Port,   LEFT_BLUE_Pin   },
		{ RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin   },
		{ RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin },
		{ RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin  },
};

static bool led_state[LED_COUNT];

void update_led(LED_Index index)
{
	led_state[index] = !led_state[index];
}

bool is_on(LED_Index index)
{
	return led_state[index];
}

void turn_on(LED_Index index)
{
	HAL_GPIO_WritePin(led_config[index].GPIOx, led_config[index].GPIO_Pin, GPIO_PIN_RESET);
}

void turn_off(LED_Index index)
{
	HAL_GPIO_WritePin(led_config[index].GPIOx, led_config[index].GPIO_Pin, GPIO_PIN_SET);
}

