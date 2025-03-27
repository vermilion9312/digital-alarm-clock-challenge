/*
 * led.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#include "led.h"

static GPIO_Config* led_config;

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

static bool* led_state;
static bool  left_led_state[LED_COUNT];
static bool  right_led_state[LED_COUNT];

static void update_led(LED_Index index)
{
	led_state[index] = !led_state[index];
}

static bool is_on(LED_Index index)
{
	return led_state[index];
}

static void turn_on(LED_Index index)
{
	HAL_GPIO_WritePin(led_config[index].GPIOx, led_config[index].GPIO_Pin, GPIO_PIN_RESET);
	update_led(index);
}

static void turn_off(LED_Index index)
{
	HAL_GPIO_WritePin(led_config[index].GPIOx, led_config[index].GPIO_Pin, GPIO_PIN_SET);
	update_led(index);
}

void led_init(void)
{
	led_config = left_led_config;
	led_state  = left_led_state;
}

void change_led_direction(void)
{
	if (!was_pressed(BUTTON_4) && is_pressed(BUTTON_4))
	{
		if (led_config == left_led_config)
		{
			led_config = right_led_config;
			led_state  = right_led_state;
		}
		else
		{
			led_config = left_led_config;
			led_state  = left_led_state;
		}
	}

	update_last_button(BUTTON_4);
}

void operate_led(ButtonIndex button_index, LED_Index led_index)
{
	if (!was_pressed(button_index) && is_pressed(button_index))
	{
	  if (is_on(led_index)) turn_off(led_index);
	  else                  turn_on(led_index);
	}

	update_last_button(button_index);
}

