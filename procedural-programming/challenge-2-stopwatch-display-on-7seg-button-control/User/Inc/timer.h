/*
 * timer.h
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum {
	SEC,
	MS
} TimeType;

typedef enum {
	DEACTIVATE,
	ACTIVATE
} TimerState;

void count_up(void);
uint16_t get_count(TimeType type);
void set_count(uint16_t _count);
void set_timer(bool state);

#endif /* INC_TIMER_H_ */
