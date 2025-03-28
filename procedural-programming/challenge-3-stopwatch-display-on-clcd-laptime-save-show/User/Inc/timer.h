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
#include <string.h>

#define LAP_TIME_SIZE 9

typedef enum {
	HOUR,
	MIN,
	SEC,
	_100MS,
	MS
} TimeType;

typedef enum {
	DEACTIVATE,
	ACTIVATE
} TimerState;

void count_up(void);
uint32_t get_count(TimeType type);
void set_count(uint16_t _count);
void set_timer(bool state);
void clear_lap_time(void);
void save_lap_time(int8_t* index);
uint32_t get_lap_time(uint8_t index, TimeType type);

#endif /* INC_TIMER_H_ */
