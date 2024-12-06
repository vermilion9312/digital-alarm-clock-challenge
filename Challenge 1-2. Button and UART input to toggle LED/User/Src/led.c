/*
 * led.c
 *
 *  Created on: Nov 30, 2024
 *      Author: vermi
 */

#ifndef SRC_C_
#define SRC_C_

#include "led.h"

static void turn_on_led(Led* this, Button* button);
static void turn_off_led(Led* this, Button* button);
static void set_state(Led* this, State* state);
static Direction get_direction(Led* this);

static State left_red    = { LEFT,  OFF, LEFT_RED_GPIO_Port,    LEFT_RED_Pin    };
static State left_green  = { LEFT,  OFF, LEFT_GREEN_GPIO_Port,  LEFT_GREEN_Pin  };
static State left_blue   = { LEFT,  OFF, LEFT_BLUE_GPIO_Port,   LEFT_BLUE_Pin   };

static State right_red   = { RIGHT, OFF, RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin   };
static State right_green = { RIGHT, OFF, RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin };
static State right_blue  = { RIGHT, OFF, RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin  };

static Led red   = { .state = &left_red,   .last_button = false, .operate = turn_off_led, turn_on_led, turn_off_led, set_state, get_direction };
static Led green = { .state = &left_green, .last_button = false, .operate = turn_off_led, turn_on_led, turn_off_led, set_state, get_direction };
static Led blue  = { .state = &left_blue,  .last_button = false, .operate = turn_off_led, turn_on_led, turn_off_led, set_state, get_direction };

static void turn_on_led(Led* this, Button* button)
{
	Uart* uart = GET_INSTANCE(uart);

	TURN_ON_LED;

	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->operate = turn_off_led;
		this->state->output = OFF;
	}

	this->last_button = button->is_pressed(button);



}

static void turn_off_led(Led* this, Button* button)
{

	Uart* uart = GET_INSTANCE(uart);

	TURN_OFF_LED;

	if (this->last_button == false && button->is_pressed(button) == true)
	{
		this->operate = turn_on_led;
		this->state->output = ON;
	}

	this->last_button = button->is_pressed(button);

	if (uart->get_data(uart))
	{
		this->operate = turn_on_led;
		this->state->output = ON;
	}
}

static void set_state(Led* this, State* state)
{
	 this->state = state;

	 if (this->state->output == ON)
	 {
		 this->operate = turn_on_led;
	 }

	 if (this->state->output == OFF)
	 {
		 this->operate = turn_off_led;
	 }
}

static Direction get_direction(Led* this)
{
	return this->state->direction;
}

void change_direction(void)
{
	Button* button_4 = GET_INSTANCE(button_4);
	static bool last_button_4 = 0;

	if (last_button_4 == false && button_4->is_pressed(button_4) == true)
	{
		if (red.get_direction(&red) == LEFT)
		{
			red.set_state(&red, &right_red);
		}
		else
		{
			red.set_state(&red, &left_red);
		}

		if (green.get_direction(&green) == LEFT)
		{
			green.set_state(&green, &right_green);
		}
		else
		{
			green.set_state(&green, &left_green);
		}

		if (blue.get_direction(&blue) == LEFT)
		{
			blue.set_state(&blue, &right_blue);
		}
		else
		{
			blue.set_state(&blue, &left_blue);
		}
	}

	last_button_4 = button_4->is_pressed(button_4);
}

Led* get_red(void)
{
	return &red;
}

Led* get_green(void)
{
	return &green;
}

Led* get_blue(void)
{
	return &blue;
}

#endif /* SRC_C_ */
