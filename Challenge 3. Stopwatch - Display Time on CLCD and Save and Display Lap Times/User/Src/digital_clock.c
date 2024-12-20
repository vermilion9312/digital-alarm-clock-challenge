/*
 * digital_clock.c
 *
 *  Created on: Dec 20, 2024
 *      Author: LeeJooHo
 */


#include "digital_clock.h"

void set_mode(DigitalClock* this, Mode* mode);
static void operate(DigitalClock* this);
static void operate_clock_mode(DigitalClock* this);
static void operate_alarm_mode(DigitalClock* this);
static void operate_stopwatch_mode(DigitalClock* this);
static void operate_timer_mode(DigitalClock* this);


Mode clock_mode     = { .operate = operate_clock_mode     };
Mode alarm_mode     = { .operate = operate_alarm_mode     };
Mode stopwatch_mode = { .operate = operate_stopwatch_mode };
Mode timer_mode     = { .operate = operate_timer_mode     };

DigitalClock clock = { .mode = &clock_mode, set_mode, operate };

void set_mode(DigitalClock* this, Mode* mode)
{
	this->mode = mode;
}

static void operate(DigitalClock* this)
{
	this->mode->operate(this);
}

static void operate_clock_mode(DigitalClock* this)
{

	if (sw1_is_pressed == true)
	{
		this->set_mode(this, &alarm_mode);
	}
}

static void operate_alarm_mode(DigitalClock* this)
{
	if (sw1_is_pressed == true)
	{
		this->set_mode(this, &alarm_mode);
	}
}

static void operate_stopwatch_mode(DigitalClock* this)
{

}

static void operate_timer_mode(DigitalClock* this)
{

}






DigitalClock* get_clock(void)
{
	return &clock;
}

