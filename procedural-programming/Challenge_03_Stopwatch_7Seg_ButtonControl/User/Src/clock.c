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

void (* operate_clock)(void) = stopwatch_mode;
static void (* operate_state)(void) = stopped;
static bool running_state;

bool is_running(void)
{
	return running_state;
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
	operate_state();
}

static void stopped(void)
{
	_7SEG_SetNumber(DGT1, get_time(SECONDS), ON);
	_7SEG_SetNumber(DGT2, get_time(_100MS), OFF);

	if (is_button_pressed(BUTTON_2))
	{
		operate_state = running;
		running_state = true;
	}
}

static void running(void)
{
	_7SEG_SetNumber(DGT1, get_time(SECONDS), (get_time(_100MS) < 5) ? ON : OFF);
	_7SEG_SetNumber(DGT2, get_time(_100MS), OFF);

	if (is_button_pressed(BUTTON_2))
	{
		operate_state = paused;
		running_state = false;
	}
}

static void paused(void)
{
	_7SEG_SetNumber(DGT1, get_time(SECONDS), ON);
	_7SEG_SetNumber(DGT2, get_time(_100MS), OFF);

	if (is_button_pressed(BUTTON_2))
	{
		operate_state = running;
		running_state = true;
		return;
	}

	if (is_button_pressed(BUTTON_3))
	{
		operate_state = stopped;
		set_count_zero();
	}
}

