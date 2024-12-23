/*
 * _101_digital_clock.c
 *
 *  Created on: Dec 20, 2024
 *      Author: LeeJooHo
 */


#include <_101_digital_clock.h>

static void set_mode(DigitalClock* this, OperateClock operate);
static void operate_clock_mode(DigitalClock* this);
static void operate_alarm_mode(DigitalClock* this);
static void operate_stopwatch_mode(DigitalClock* this);
static void operate_timer_mode(DigitalClock* this);

static DigitalClock clock = { .mode = NULL, set_mode, operate_clock_mode };


static void set_mode(DigitalClock* this, OperateClock operate)
{
	*(this->mode) = (*this->mode + 1) % MODE_COUNT;
	this->operate = operate;
}

static void operate_clock_mode(DigitalClock* this)
{
	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;

	HAL_GPIO_WritePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin, 1);

	if (last_button == false && button_1->is_pressed(button_1) == true)
	{
		this->set_mode(this, operate_alarm_mode);
	}

	last_button = button_1->is_pressed(button_1);
}

static void operate_alarm_mode(DigitalClock* this)
{
	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;

	HAL_GPIO_WritePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin, 1);

	if (last_button == false && button_1->is_pressed(button_1) == true)
	{
		this->set_mode(this, operate_stopwatch_mode);
	}

	last_button = button_1->is_pressed(button_1);
}

static void operate_stopwatch_mode(DigitalClock* this)
{

	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;

	HAL_GPIO_WritePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin, 0);

	if (last_button == false && button_1->is_pressed(button_1) == true)
	{
		this->set_mode(this, operate_timer_mode);
	}



	last_button = button_1->is_pressed(button_1);

}

static void operate_timer_mode(DigitalClock* this)
{
	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;

	if (last_button == false && button_1->is_pressed(button_1) == true) // sw1_short_press
	{
		this->set_mode(this, operate_clock_mode);
	}

	last_button = button_1->is_pressed(button_1);
}

DigitalClock* get_clock(void)
{
	clock.mode = GET_INSTANCE(mode);
	return &clock;
}

