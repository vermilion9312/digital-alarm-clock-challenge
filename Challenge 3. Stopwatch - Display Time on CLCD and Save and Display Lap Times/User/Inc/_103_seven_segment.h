/*
 * _103_seven_segment.h
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */

#ifndef INC__103_SEVEN_SEGMENT_H_
#define INC__103_SEVEN_SEGMENT_H_

#include <_000_common.h>
#include <_001_mode.h>
#include <_002_timer.h>
#include <_105_button.h>
#include <stdint.h>
#include <stdbool.h>
#include "7SEG.h"

typedef struct _SevenSegment SevenSegment;
typedef struct _DigitalClock DigitalClock;

struct _SevenSegment {
	DigitalClock* clock;
	void (* operate)(SevenSegment*);
};

void operate_clock_mode_segment(SevenSegment* this);
void operate_alarm_mode_segment(SevenSegment* this);
void operate_stopwatch_mode_segment(SevenSegment* this);
void operate_timer_mode_segment(SevenSegment* this);

SevenSegment* get_segment(void);

#endif /* INC__103_SEVEN_SEGMENT_H_ */