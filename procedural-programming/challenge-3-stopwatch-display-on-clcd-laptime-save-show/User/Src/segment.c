/*
 * segment.c
 *
 *  Created on: Mar 27, 2025
 *      Author: LeeJooHo
 */


#include "segment.h"

static void display_stop(StopwatchModeOperation operation);
static void display_count_up(StopwatchModeOperation operation);

SegmentOperation operate_segment = display_stop;

static void display_stop(StopwatchModeOperation operation)
{
	_7SEG_SetNumber(DGT1, get_count(SEC), ON);
	_7SEG_SetNumber(DGT2, get_count(_100MS), OFF);

	if (operation ==  running)
	{
		operate_segment = display_count_up;
	}
}

static void display_count_up(StopwatchModeOperation operation)
{
	_7SEG_SetNumber(DGT1, get_count(SEC), get_count(_100MS) < 5 ? ON : OFF);
	_7SEG_SetNumber(DGT2, get_count(_100MS), OFF);

	if (operation != running)
	{
		operate_segment = display_stop;
	}
}


