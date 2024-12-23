/*
 * _103_seven_segment.h
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */

#ifndef INC__103_SEVEN_SEGMENT_H_
#define INC__103_SEVEN_SEGMENT_H_

#include <_000_common.h>
#include <_002_timer.h>
#include <_105_button.h>
#include <stdint.h>
#include <stdbool.h>
#include "7SEG.h"
#include <_001_mode.h>

typedef struct _SevenSegment SevenSegment;

typedef void (* OperateSegment)(SevenSegment*);

struct _SevenSegment {
	Mode* mode;
	Mode (* const get_current_mode)(SevenSegment*);
	void (* const set_state)(SevenSegment*, OperateSegment);
	void (* operate)(SevenSegment*);
};

void operate_stop(SevenSegment* this);
void operate_pause(SevenSegment* this);
void operate_run(SevenSegment* this);

SevenSegment* get_segment(void);

#endif /* INC__103_SEVEN_SEGMENT_H_ */
