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
#include "gpio_config.h"

typedef struct _ButtonConfig ButtonConfig;

struct _ButtonConfig {
	GPIO_Config gpio_config;
	bool state;
	bool last_state;
};

NodeState update_button(void*);
NodeState update_last_button(void*);
NodeState is_rising_edge(void*);
NodeState is_falling_edge(void*);

#endif /* INC_BUTTON_H_ */
