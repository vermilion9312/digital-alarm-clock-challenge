/*
 * input.h
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include <common.h>

typedef enum {
	NOMAL_OPEN,
	NOMAL_CLOSE
} InputType;

CLASS(CInput) {
	void (* update)(CInput*);
	bool (* is_pressed)(CInput*);
	bool (* is_rising)(CInput*);
	bool (* is_falling)(CInput*);
};

PRIVATE(CInput) {
	CInput public;

	GPIO_TypeDef* port;
	uint16_t      pin;
	InputType     type;
	bool          last_state;
	bool          state;
};

CInput* new_Output(GPIO_TypeDef*, uint16_t, InputType);

#endif /* INC_INPUT_H_ */
