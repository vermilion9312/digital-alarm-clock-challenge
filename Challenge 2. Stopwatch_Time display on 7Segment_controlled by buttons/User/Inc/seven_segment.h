/*
 * seven_segment.h
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */

#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

#include <stdint.h>
#include <stdbool.h>
#include "7SEG.h"
#include "button.h"
#include "common.h"
#include "timer.h"

typedef struct _SevenSegment SevenSegment;

struct _SevenSegment {
	void (* operate)(SevenSegment*);
};

SevenSegment* get_segment(void);

#endif /* INC_SEVEN_SEGMENT_H_ */
