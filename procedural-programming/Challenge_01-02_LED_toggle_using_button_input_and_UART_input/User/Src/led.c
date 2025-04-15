/*
 * led.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermilion9312
 */

#include "led.h"

static GPIO_Config left_led_config[LED_COUNT] = {
		{ LEFT_RED_GPIO_Port,    LEFT_RED_Pin    },
		{ LEFT_GREEN_GPIO_Port,  LEFT_GREEN_Pin  },
		{ LEFT_BLUE_GPIO_Port,   LEFT_BLUE_Pin   },
};

static GPIO_Config right_led_config[LED_COUNT] = {
		{ RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin   },
		{ RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin },
		{ RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin  },
};

static bool  left_led_state[LED_COUNT];
static bool  right_led_state[LED_COUNT];

static GPIO_Config* led_config = left_led_config;
static bool*        led_state  = left_led_state;

bool is_led_on(LED_Index led_index)
{
	return led_state[led_index];
}

void turn_on_led(LED_Index led_index)
{
	HAL_GPIO_WritePin(led_config[led_index].GPIOx, led_config[led_index].GPIO_Pin, GPIO_PIN_RESET);
	led_state[led_index] = !led_state[led_index];
}

void turn_off_led(LED_Index led_index)
{
	HAL_GPIO_WritePin(led_config[led_index].GPIOx, led_config[led_index].GPIO_Pin, GPIO_PIN_SET);
	led_state[led_index] = !led_state[led_index];
}

void change_led_direction(ButtonIndex button_index)
{
	if (is_button_rising(button_index) || get_rxd() == '4')
	{
		if (led_config == left_led_config)
		{
			led_config = right_led_config;
			led_state  = right_led_state;
			return;
		}

		if (led_config == right_led_config)
		{
			led_config = left_led_config;
			led_state  = left_led_state;
		}
	}
}

