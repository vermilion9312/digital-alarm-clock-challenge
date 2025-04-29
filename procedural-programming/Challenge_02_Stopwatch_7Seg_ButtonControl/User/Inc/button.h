/*
 * button.h
 *
 *  Created on: Mar 22, 2025
 *      Author: vermilion9312
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdbool.h>
#include "gpio_config.h"
#include "main.h"

typedef enum {
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	BUTTON_COUNT
} ButtonIndex;

void update_button(ButtonIndex button_index);
void update_last_button(ButtonIndex button_index);
bool is_button_pressed(ButtonIndex button_index);
bool is_button_released(ButtonIndex button_index);
bool is_button_on(ButtonIndex button_index);

#endif /* INC_BUTTON_H_ */
