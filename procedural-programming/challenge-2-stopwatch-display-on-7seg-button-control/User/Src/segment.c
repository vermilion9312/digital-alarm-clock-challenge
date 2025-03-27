/*
 * segment.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include "segment.h"

static void stopped(void);
static void running(void);
static void paused(void);

void (* operate_segment)(void) = stopped;

static void stopped(void)
{
	_7SEG_SetNumber(DGT1, get_count(SEC), ON);
	_7SEG_SetNumber(DGT2, get_count(MS), OFF);

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(ACTIVATE);
		operate_segment = running;
	}
}

static void running(void)
{
	_7SEG_SetNumber(DGT1, get_count(SEC), get_count(MS) < 5 ? ON : OFF);
	_7SEG_SetNumber(DGT2, get_count(MS), OFF);

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(DEACTIVATE);
		operate_segment = paused;
	}
}

static void paused(void)
{
	_7SEG_SetNumber(DGT1, get_count(SEC), ON);
	_7SEG_SetNumber(DGT2, get_count(MS), OFF);

	if (!was_pressed(BUTTON_2) && is_pressed(BUTTON_2))
	{
		set_timer(ACTIVATE);
		operate_segment = running;
	}

	if (!was_pressed(BUTTON_3) && is_pressed(BUTTON_3))
	{
		set_timer(DEACTIVATE);
		set_count(0);
		operate_segment = stopped;
	}
}
