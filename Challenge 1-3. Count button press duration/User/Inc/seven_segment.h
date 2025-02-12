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

typedef struct _SevenSegment SevenSegment;

struct _SevenSegment {
	uint8_t count;

	void (* display)(SevenSegment*);

	void (* const count_up)(SevenSegment*);
	void (* const set_count_zero)(SevenSegment*);
	uint8_t (* const get_seconds)(SevenSegment*);
	uint8_t (* const get_milliseconds)(SevenSegment*);
};

SevenSegment* get_segment(void);

#endif /* INC_SEVEN_SEGMENT_H_ */
