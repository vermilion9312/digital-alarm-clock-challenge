/*
 * stopwatch_mode.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include <stopwatch_mode.h>

static void stopped(void);
static void running(void);
static void paused(void);

void (* operate_stopwatch_mode)(void) = stopped;
static char top_ine_buffer[20];
static char bottom_ine_buffer[20];
static int8_t lap_time_index = -1;

static void display_segment(void (* operate_stopwatch_mode)(void))
{
	if (operate_stopwatch_mode == running)
	{
		_7SEG_SetNumber(DGT1, get_count(SEC), get_count(_100MS) < 5 ? ON : OFF);
	}
	else
	{
		_7SEG_SetNumber(DGT1, get_count(SEC), ON);
	}

	_7SEG_SetNumber(DGT2, get_count(_100MS), OFF);
}

static void display_lcd(void)
{
	sprintf(top_ine_buffer, "STW %02lu:%02lu:%02lu:%0lu", get_count(HOUR), get_count(MIN), get_count(SEC), get_count(MS));
	CLCD_Puts(0, 0, (unsigned char*) top_ine_buffer);

	if (lap_time_index > LAP_TIME_SIZE - 1)
	{
		sprintf(bottom_ine_buffer, "LAP FULL(9/9)   ");
	}
	else if (lap_time_index > -1)
	{
		sprintf(bottom_ine_buffer, "LP%d %02lu:%02lu:%02lu:%03lu", lap_time_index + 1,
				get_lap_time(lap_time_index, HOUR), get_lap_time(lap_time_index, MIN),
				get_lap_time(lap_time_index, SEC),  get_lap_time(lap_time_index, MS));

	}
	else
	{
		sprintf(bottom_ine_buffer, "                ");
	}


	CLCD_Puts(0, 1, (unsigned char*) bottom_ine_buffer);
}

static void stopped(void)
{
	display_segment(stopped);
	display_lcd();

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(ACTIVATE);
		operate_stopwatch_mode = running;
	}
}

static void running(void)
{
	display_segment(running);
	display_lcd();

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(DEACTIVATE);
		operate_stopwatch_mode = paused;
	}

	if (!was_pressed(BUTTON_3) && is_pressed(BUTTON_3))
	{
		save_lap_time();
		lap_time_index++;
	}
}

static void paused(void)
{
	display_segment(paused);
	display_lcd();

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

	}
}
