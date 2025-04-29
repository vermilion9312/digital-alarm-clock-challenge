/*
 * clock.h
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include "button.h"
#include "led.h"
#include "segment.h"
#include "timer.h"

void operate_left_led(ButtonIndex button_index, LED_Index led_index);
void operate_right_led(ButtonIndex button_index, LED_Index led_index);
bool is_running(void);

extern void (* operate_clock)(void);

#endif /* INC_CLOCK_H_ */
