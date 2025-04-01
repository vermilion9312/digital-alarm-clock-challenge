/*
 * button.h
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdbool.h>
#include "main.h"
#include "behavior_tree.h"

typedef enum {
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	BUTTON_COUNT
} ButtonIndex;

void update_button(ButtonIndex index);
void update_last_button(ButtonIndex index);
bool is_pressed(ButtonIndex index);
bool was_pressed(ButtonIndex index);

#endif /* INC_BUTTON_H_ */
