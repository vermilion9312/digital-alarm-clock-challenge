/*
 * _101_digital_clock.c
 *
 *  Created on: Dec 20, 2024
 *      Author: LeeJooHo
 */


#include <_101_digital_clock.h>

static Mode get_current_mode(DigitalClock* this);
static void set_mode(DigitalClock* this, OperateClock operate);
static void operate_clock_mode(DigitalClock* this);
static void operate_alarm_mode(DigitalClock* this);
static void operate_stopwatch_mode(DigitalClock* this);
static void operate_timer_mode(DigitalClock* this);

static DigitalClock clock = { .mode = NULL, .is_transitioned = false, get_current_mode, set_mode, operate_clock_mode };

static Mode get_current_mode(DigitalClock* this)
{
	return *this->mode;
}

static void set_mode(DigitalClock* this, OperateClock operate)
{
	*this->mode = (*this->mode + 1) % MODE_COUNT;
	this->operate = operate;
}

static void operate_clock_mode(DigitalClock* this)
{
	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;

	if (this->is_transitioned == false)
	{
		if (last_button == false && button_1->is_pressed(button_1) == true)
		{
			this->set_mode(this, operate_alarm_mode);
			this->is_transitioned = true;
		}
	}

	if (last_button == true && button_1->is_pressed(button_1) == false)
	{
		this->is_transitioned = false;
	}

	last_button = button_1->is_pressed(button_1);
}

static void operate_alarm_mode(DigitalClock* this)
{
	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;

	HAL_GPIO_WritePin(RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, 0);

	if (this->is_transitioned == false)
	{
		if (last_button == false && button_1->is_pressed(button_1) == true)
		{
			this->set_mode(this, operate_stopwatch_mode);
			this->is_transitioned = true;
		}
	}

	if (last_button == true && button_1->is_pressed(button_1) == false)
	{
		this->is_transitioned = false;
	}

	last_button = button_1->is_pressed(button_1);
}

static void operate_stopwatch_mode(DigitalClock* this)
{

	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;


	HAL_GPIO_WritePin(LEFT_RED_GPIO_Port, LEFT_RED_Pin, 0);

	if (this->is_transitioned == false)
	{
		if (last_button == false && button_1->is_pressed(button_1) == true)
		{
			this->set_mode(this, operate_timer_mode);
			this->is_transitioned = true;
		}
	}

	if (last_button == true && button_1->is_pressed(button_1) == false)
	{
		this->is_transitioned = false;
	}

	last_button = button_1->is_pressed(button_1);
}

static void operate_timer_mode(DigitalClock* this)
{
	Button* button_1 = GET_INSTANCE(button_1);
	static bool last_button = false;


	if (this->is_transitioned == false)
	{
		if (last_button == false && button_1->is_pressed(button_1) == true) // sw1_short_press
		{
			this->set_mode(this, operate_clock_mode);
			this->is_transitioned = true;
		}
	}

	if (last_button == true && button_1->is_pressed(button_1) == false)
	{
		this->is_transitioned = false;
	}

	last_button = button_1->is_pressed(button_1);
}

DigitalClock* get_clock(void)
{
	clock.mode = GET_INSTANCE(mode);
	return &clock;
}

