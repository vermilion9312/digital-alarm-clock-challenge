/*
 * digital_clock.h
 *
 *  Created on: Dec 20, 2024
 *      Author: LeeJooHo
 */

#ifndef INC_DIGITAL_CLOCK_H_
#define INC_DIGITAL_CLOCK_H_

typedef struct _Mode Mode;

struct _Mode {
	void (* operate)(DigitalClock*);
};

typedef struct _DigitalClock DigitalClock;

struct _DigitalClock {
	Mode* mode;
	void (* const set_mode)(DigitalClock*, Mode*);
	void (* const operate)(DigitalClock*);
};

DigitalClock* get_clock(void);

#endif /* INC_DIGITAL_CLOCK_H_ */
