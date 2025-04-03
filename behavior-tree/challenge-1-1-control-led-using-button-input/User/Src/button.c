/*
 * button.c
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#ifndef SRC_BUTTON_C_
#define SRC_BUTTON_C_

#include "button.h"

NodeState update_button(void* node)
{
	LeafNode*     leaf_node     = (LeafNode*    ) node;
	ButtonConfig* button_config = (ButtonConfig*) leaf_node->data;
	GPIO_Config   gpio_config   = (GPIO_Config  ) button_config->gpio_config;

	button_config->state = HAL_GPIO_ReadPin(gpio_config.GPIOx, gpio_config.GPIO_Pin);

	return NODE_SUCCESS;
}

NodeState update_last_button(void* node)
{
	LeafNode*     leaf_node     = (LeafNode*    ) node;
	ButtonConfig* button_config = (ButtonConfig*) leaf_node->data;

	button_config->last_state = button_config->state;

	return NODE_SUCCESS;
}

NodeState is_rising_edge(void* node)
{
	LeafNode*     leaf_node     = (LeafNode*    ) node;
	ButtonConfig* button_config = (ButtonConfig*) leaf_node->data;

	if (button_config->last_state) return NODE_FAILURE;
	if (!button_config->state    ) return NODE_FAILURE;

	return NODE_SUCCESS;
}

NodeState is_falling_edge(void* node)
{
	LeafNode*     leaf_node     = (LeafNode*    ) node;
	ButtonConfig* button_config = (ButtonConfig*) leaf_node->data;

	if (!button_config->last_state) return NODE_FAILURE;
	if (button_config->state      ) return NODE_FAILURE;

	return NODE_SUCCESS;
}

#endif /* SRC_BUTTON_C_ */
