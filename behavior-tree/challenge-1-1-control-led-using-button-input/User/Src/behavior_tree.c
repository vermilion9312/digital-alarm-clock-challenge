/*
 * behavior_tree.c
 *
 *  Created on: Apr 1, 2025
 *      Author: LeeJooHo
 */


#include "behavior_tree.h"


NodeState LED_Off(void)
{
	HAL_GPIO_WritePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin, GPIO_PIN_SET);
	return FAILURE;
}

NodeState LED_On(void)
{
	HAL_GPIO_WritePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin, GPIO_PIN_SET);
	return FAILURE;
}

NodeState Selector(Node* children, size_t child_count)
{
	for (size_t i = 0; i < child_count; i++)
	{
		if (children[i]() == SUCCESS)
		{
			return SUCCESS;
		}
	}

	return FAILURE;
}

NodeState Sequence(Node* children, size_t child_count)
{
	for (size_t i = 0; i < child_count; i++)
	{
		if (children[i]() != SUCCESS)
		{
			return FAILURE;
		}
	}

	return FAILURE;
}

Node* led_operation = { LED_Off, LED_On };
