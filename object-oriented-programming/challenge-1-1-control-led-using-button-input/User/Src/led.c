/*
 * led.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#include "led.h"

static void update_led(LED_Config* led_config)
{
	led_config->state = !led_config->state;
}

NodeState turn_off_led(void* node)
{
	LeafNode*   leaf_node   = (LeafNode*  ) node;
	LED_Config* led_config  = (LED_Config*) leaf_node->data;
	GPIO_Config gpio_config = (GPIO_Config) led_config->gpio_config;

	HAL_GPIO_WritePin(gpio_config.GPIOx, gpio_config.GPIO_Pin, GPIO_PIN_SET);
	update_led(led_config);

	return NODE_SUCCESS;
}

NodeState turn_on_led(void* node)
{
	LeafNode*   leaf_node   = (LeafNode*  ) node;
	LED_Config* led_config  = (LED_Config*) leaf_node->data;
	GPIO_Config gpio_config = (GPIO_Config) led_config->gpio_config;

	HAL_GPIO_WritePin(gpio_config.GPIOx, gpio_config.GPIO_Pin, GPIO_PIN_RESET);
	update_led(led_config);

	return NODE_SUCCESS;
}

NodeState is_led_on(void* node)
{
	LeafNode*   leaf_node   = (LeafNode*  ) node;
	LED_Config* led_config  = (LED_Config*) leaf_node->data;

	return led_config->state ? NODE_SUCCESS : NODE_FAILURE;
}
