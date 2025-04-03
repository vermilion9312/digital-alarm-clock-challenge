/*
 * behavior_tree.h
 *
 *  Created on: Apr 1, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_BEHAVIOR_TREE_H_
#define INC_BEHAVIOR_TREE_H_

#include <stddef.h>

typedef enum {
	NODE_SUCCESS,
	NODE_FAILURE
} NodeState;

typedef NodeState (* Tick)(void*);
typedef struct _LeafNode LeafNode;
typedef struct _CompositeNode CompositeNode;

struct _LeafNode {
	Tick tick;
	void* data;
};

struct _CompositeNode {
	Tick tick;
	void** children;
	size_t count;
};

NodeState run_sequence(void* this);
NodeState run_selector(void* this);

#endif /* INC_BEHAVIOR_TREE_H_ */
