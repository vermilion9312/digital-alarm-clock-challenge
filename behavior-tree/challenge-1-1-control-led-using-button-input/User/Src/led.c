/*
 * led.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#include "led.h"

NodeState turn_off_led(void* node)
{
	LeafNode*     leaf_node     = (LeafNode*    ) node;
	ButtonConfig* button_config = (ButtonConfig*) leaf_node->data;
	GPIO_Config   gpio_config   = (GPIO_Config  ) button_config->gpio_config;

	HAL_GPIO_WritePin(gpio_config.GPIOx, gpio_config.GPIO_Pin, GPIO_PIN_SET);

	return NODE_SUCCESS;
}

NodeState turn_on_led(void* node)
{
	LeafNode*     leaf_node     = (LeafNode*    ) node;
	ButtonConfig* button_config = (ButtonConfig*) leaf_node->data;
	GPIO_Config   gpio_config   = (GPIO_Config  ) button_config->gpio_config;

	HAL_GPIO_WritePin(gpio_config.GPIOx, gpio_config.GPIO_Pin, GPIO_PIN_RESET);

	return NODE_SUCCESS;
}
