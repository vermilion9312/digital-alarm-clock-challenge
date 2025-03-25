/*
 * timer.h
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>

typedef enum {
	SEC,
	MS
} TimeType;

void count_up(void);
uint16_t get_count(TimeType type);
void set_count(uint16_t _count);


#endif /* INC_TIMER_H_ */
