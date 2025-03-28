/*
 * stopwatch_mode.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include <stopwatch_mode.h>

StopwatchModeOperation operate_stopwatch_mode = stopped;
static int8_t lap_time_index = -1;
static

void stopped(void)
{
	operate_segment(stopped);
	operate_lcd_top();
	operate_lcd_bottom(lap_time_index);

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(ACTIVATE);
		operate_stopwatch_mode = running;
	}
}

void running(void)
{
	operate_segment(running);
	operate_lcd_top();
	operate_lcd_bottom(lap_time_index);

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(DEACTIVATE);
		operate_stopwatch_mode = paused;
	}

	if (!was_pressed(BUTTON_3) && is_pressed(BUTTON_3))
	{
		save_lap_time(&lap_time_index); // lap_time++
	}

	if (!was_pressed(BUTTON_4) && is_pressed(BUTTON_4))
	{
		//lap_log++
	}
}

void paused(void)
{
	operate_segment(paused);
	operate_lcd_top();
	operate_lcd_bottom(lap_time_index);

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(ACTIVATE);
		operate_stopwatch_mode = running;
	}

	if (!was_pressed(BUTTON_3) && is_pressed(BUTTON_3))
	{
		set_timer(DEACTIVATE);
		set_count(0);
		CLCD_Clear();
		clear_lap_time();
		lap_time_index = -1;
		operate_stopwatch_mode = stopped;
	}

	if (!was_pressed(BUTTON_4) && is_pressed(BUTTON_4))
	{
		//lap_log++
	}
}
