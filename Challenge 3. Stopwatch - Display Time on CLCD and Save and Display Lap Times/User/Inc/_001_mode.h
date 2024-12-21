/*
 * _001_mode.h
 *
 *  Created on: Dec 21, 2024
 *      Author: vermi
 */

#ifndef INC__001_MODE_H_
#define INC__001_MODE_H_

#include <_101_digital_clock.h>
#include <_102_lcd.h>
#include <_103_seven_segment.h>
#include <_104_led.h>
#include <stdbool.h>
#include <_000_common.h>

typedef struct _DigitalClock DigitalClock;
typedef struct _SevenSegment SevenSegment;
typedef struct _Lcd Lcd;
typedef struct _Mode Mode;
typedef struct _Led Led;

struct _Mode {
	void (* const operate_clock)(DigitalClock*);
	void (* const operate_lcd)(Lcd*);
	void (* const operate_segment)(SevenSegment*);
	void (* const operate_led)(Led*);
};

Mode* get_clock_mode(void);
Mode* get_alarm_mode(void);
Mode* get_stopwatch_mode(void);
Mode* get_timer_mode(void);

#endif /* INC__001_MODE_H_ */