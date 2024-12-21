/*
 * _101_digital_clock.c
 *
 *  Created on: Dec 20, 2024
 *      Author: LeeJooHo
 */


#include <_101_digital_clock.h>

static void set_mode(DigitalClock* this, Mode* mode);
static void operate(DigitalClock* this);


DigitalClock clock = { .mode = NULL, set_mode, operate };

static void set_mode(DigitalClock* this, Mode* mode)
{
	this->mode = mode;
}

static void operate(DigitalClock* this)
{
	this->mode->operate_clock(this);
}

void operate_clock_mode_digital_clock(DigitalClock* this)
{

	if (false) // sw1_short_press
	{
		this->set_mode(this, GET_INSTANCE(alarm_mode));
	}
}

void operate_alarm_mode_digital_clock(DigitalClock* this)
{

	if (false) // sw1_short_press
	{
		this->set_mode(this, GET_INSTANCE(stopwatch_mode));
	}
}

void operate_stopwatch_mode_digital_clock(DigitalClock* this)
{

	if (false) // sw1_short_press
	{
		this->set_mode(this, GET_INSTANCE(timer_mode));
	}
}

void operate_timer_mode_digital_clock(DigitalClock* this)
{

	if (false) // sw1_short_press
	{
		this->set_mode(this, GET_INSTANCE(clock_mode));
	}
}

DigitalClock* get_clock(void)
{
	clock.mode = GET_INSTANCE(stopwatch_mode);
	return &clock;
}
