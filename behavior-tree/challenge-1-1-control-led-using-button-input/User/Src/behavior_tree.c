/*
 * behavior_tree.c
 *
 *  Created on: Apr 1, 2025
 *      Author: LeeJooHo
 */


#include "behavior_tree.h"

NodeState run_sequence(void* this)
{
	CompositeNode* node = (CompositeNode*)this;

	for (size_t i = 0; i < node->count; ++i)
	{
		Tick tick = ((LeafNode*)node->children[i])->tick;

		if (tick(node->children[i]) == NODE_FAILURE)
		{
			return NODE_FAILURE;
		}
	}
	return NODE_SUCCESS;
}

NodeState run_selector(void* this)
{
	CompositeNode* node = (CompositeNode*)this;

	for (size_t i = 0; i < node->count; ++i)
	{
		Tick tick = ((LeafNode*)node->children[i])->tick;

		if (tick(node->children[i]) == NODE_SUCCESS)
		{
			return NODE_SUCCESS;
		}
	}
	return NODE_FAILURE;
}
