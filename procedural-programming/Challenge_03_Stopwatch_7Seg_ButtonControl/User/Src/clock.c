/*
 * clock.c
 *
 *  Created on: Apr 15, 2025
 *      Author: vermilion9312
 */


#include "clock.h"

static void stopwatch_mode(void);
static void stopped(void);
static void running(void);
static void paused(void);



static ModeOperation mode_operation[MODE_COUNT] = { stopwatch_mode };
static StateOperation state_operation[STATE_COUNT] = { stopped, running, paused };
static ModeIndex mode_index = MODE_STOPWATCH;
static StateIndex state_index = STATE_STOPPED;

void operate_clock(void)
{
	mode_operation[mode_index]();
}

StateIndex get_state(void)
{
	return state_index;
}

void operate_left_led(ButtonIndex button_index, LED_Index led_index)
{
	if (is_button_pressed(button_index))
	{
		is_led_on(led_index) ? turn_off_led(led_index) : turn_on_led(led_index);
	}
}


void operate_right_led(ButtonIndex button_index, LED_Index led_index)
{
	if (is_button_released(button_index))
	{
		is_led_on(led_index) ? turn_off_led(led_index) : turn_on_led(led_index);
	}
}


static void stopwatch_mode(void)
{
	state_operation[state_index]();
}

static void stopped(void)
{

	if (is_button_pressed(BUTTON_2)) state_index = STATE_RUNNING;
}

static void running(void)
{
	_7SEG_SetNumber(DGT1, get_time(SECONDS), (is_button_on(BUTTON_1) && get_time(_100MS) < 5) ? OFF : ON);
	_7SEG_SetNumber(DGT2, get_time(_100MS), OFF);

	if (is_button_pressed(BUTTON_2)) state_index = STATE_PAUSE;
}

static void paused(void)
{
	if (is_button_pressed(BUTTON_2)) state_index = STATE_RUNNING;
	if (is_button_pressed(BUTTON_3)) state_index = STATE_STOPPED;
}

