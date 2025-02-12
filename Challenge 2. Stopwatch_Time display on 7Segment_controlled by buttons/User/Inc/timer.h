/*
 * timer.h
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>

typedef struct _Timer Timer;

struct _Timer {
	uint32_t count;
	uint32_t recorded_count;

	void (* const count_up)(Timer*);
	void (* const set_count)(Timer*, uint32_t);

	void (* const record_count)(Timer*);
	uint32_t (*const get_recorded_count)(Timer*);

	uint8_t (* const get_milliseconds)(Timer*);
	uint8_t (* const get_seconds)(Timer*);
	uint8_t (* const get_minutes)(Timer*);
	uint8_t (* const get_hours)(Timer*);
};

Timer* get_timer(void);

#endif /* INC_TIMER_H_ */
