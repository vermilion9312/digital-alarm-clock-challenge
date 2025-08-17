/*
 * output.h
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

#include <common.h>

typedef enum {
	ACTIVE_LOW,
	ACTIVE_HIGH
} OutputType;

CLASS(COutput) {
	void (* turn_on)(COutput*);
	void (* turn_off)(COutput*);
	void (* toggle)(COutput*);
	bool (* is_on)(COutput*);
};

PRIVATE(COutput) {
	COutput public;

	GPIO_TypeDef* port;
	uint16_t      pin;
	OutputType    type;
	bool          state;
};

COutput* new_Output(GPIO_TypeDef*, uint16_t, OutputType);

#endif /* INC_OUTPUT_H_ */
