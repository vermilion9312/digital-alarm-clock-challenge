/*
 * _101_digital_clock.h
 *
 *  Created on: Dec 20, 2024
 *      Author: LeeJooHo
 */

#ifndef INC__101_DIGITAL_CLOCK_H_
#define INC__101_DIGITAL_CLOCK_H_

#include <_001_mode.h>
#include <_104_led.h>
#include <stdbool.h>
#include <_000_common.h>
#include "7SEG.h"


typedef struct _DigitalClock DigitalClock;
typedef void (* OperateClock)(DigitalClock*);

struct _DigitalClock {
	Mode* mode;
	bool is_transitioned;
	Mode (* const get_current_mode)(DigitalClock*);
	void (* const set_mode)(DigitalClock*, OperateClock);
	void (* operate)(DigitalClock*);
};

DigitalClock* get_clock(void);

#endif /* INC__101_DIGITAL_CLOCK_H_ */
