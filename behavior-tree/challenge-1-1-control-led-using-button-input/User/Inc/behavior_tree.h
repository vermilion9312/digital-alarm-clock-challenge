/*
 * behavior_tree.h
 *
 *  Created on: Apr 1, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_BEHAVIOR_TREE_H_
#define INC_BEHAVIOR_TREE_H_

#include "button.h"
#include "led.h"

typedef enum {
	SUCCESS,
	FAILURE
} NodeState;

typedef NodeState (* Node)(void);

#endif /* INC_BEHAVIOR_TREE_H_ */
