/*
 * segment.h
 *
 *  Created on: Mar 27, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_SEGMENT_H_
#define INC_SEGMENT_H_

#include "7SEG.h"
#include "timer.h"
#include "stopwatch_mode.h"

typedef void (* StopwatchModeOperation)(void);
typedef void (* SegmentOperation)(StopwatchModeOperation);

extern SegmentOperation operate_segment;

#endif /* INC_SEGMENT_H_ */
