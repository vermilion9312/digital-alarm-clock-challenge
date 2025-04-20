/*
 * timer.h
 *
 *  Created on: Apr 19, 2025
 *      Author: vermilion9312
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>

typedef enum {
	SECONDS,
	_100MS,
	TIME_COUNT
} TimeIndex;

uint32_t get_time(TimeIndex);
void count_up(void);

#endif /* INC_TIMER_H_ */
