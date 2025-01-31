/*
 * led.h
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef INC_H_
#define INC_H_

#include <stdbool.h>
#include "main.h"
#include "button.h"

#define TURN_OFF_LED HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_SET)
#define TURN_ON_LED  HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_RESET)

typedef struct _Led Led;
typedef void (* Operate)(Led*, Button*);
typedef struct _LedState LedState;

struct _Led {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	Operate operate;
	void (* const set_state)(Led*, Operate);
	bool last_button;
};

Led* get_left_red(void);
Led* get_left_green(void);
Led* get_left_blue(void);

Led* get_right_red (void);
Led* get_right_green(void);
Led* get_right_blue(void);

#endif /* INC_H_ */
