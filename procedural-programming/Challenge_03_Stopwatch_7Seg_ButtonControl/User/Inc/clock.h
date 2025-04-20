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

typedef enum {
	MODE_STOPWATCH,
	MODE_COUNT
} ModeIndex;

typedef enum {
	STATE_STOPPED,
	STATE_RUNNING,
	STATE_PAUSE,
	STATE_COUNT
} StateIndex;

typedef void (* ModeOperation)(void);
typedef void (* StateOperation)(void);

void operate_left_led(ButtonIndex button_index, LED_Index led_index);
void operate_right_led(ButtonIndex button_index, LED_Index led_index);
void operate_clock(void);
StateIndex get_state(void);


#endif /* INC_CLOCK_H_ */
