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
#include "common.h"
#include "uart.h"

#define TURN_ON_LED  HAL_GPIO_WritePin(this->state->GPIOx, this->state->GPIO_Pin, GPIO_PIN_RESET)
#define TURN_OFF_LED HAL_GPIO_WritePin(this->state->GPIOx, this->state->GPIO_Pin, GPIO_PIN_SET)

typedef enum { LEFT, RIGHT } Direction;
typedef enum { ON, OFF } OutputState;

typedef struct _State {
	Direction direction;
	OutputState output;
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
} State;

typedef struct _Led Led;
struct _Led {
	State* state;
	bool last_button;
	char id;

	void (* operate)(Led*, Button*);
	void (* const on)(Led*, Button*);
	void (* const off)(Led*, Button*);
	void (* const set_state)(Led*, State*);
	Direction (* const get_direction)(Led*);
	OutputState (* const get_output_state)(Led*);
};

Led* get_red(void);
Led* get_green(void);
Led* get_blue(void);
void change_direction(void);

#endif /* INC_H_ */
