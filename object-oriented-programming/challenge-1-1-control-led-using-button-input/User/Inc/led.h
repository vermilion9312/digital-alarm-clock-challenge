/*
 * led.h
 *
 *  Created on: Mar 22, 2025
 *      Author: vermi
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "gpio_config.h"
#include "main.h"
#include <stdbool.h>
#include "button.h"

typedef struct _LED_Config LED_Config;

struct _LED_Config {
	GPIO_Config gpio_config;
	bool state;
};

NodeState turn_off_led(void*);
NodeState turn_on_led(void*);
NodeState is_led_on(void* node);

#endif /* INC_LED_H_ */
