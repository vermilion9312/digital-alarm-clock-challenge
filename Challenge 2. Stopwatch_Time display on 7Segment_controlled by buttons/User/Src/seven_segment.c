/*
 * seven_segment.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include "seven_segment.h"

static void stop(SevenSegment* this);
static void pause(SevenSegment* this);
static void run(SevenSegment* this);

SevenSegment segment = { .operate = stop };

static void stop(SevenSegment* this)
{
	Button* button_2 = GET_INSTANCE(button_2);
	Timer* timer = GET_INSTANCE(timer);
	static bool previous_button_state = false;

	DGT1_DP_ON;
	DGT2_DP_OFF;

	timer->set_count(timer, 0);

	_7SEG_SetNumber(DGT1, timer->get_seconds(timer), ON);
	_7SEG_SetNumber(DGT2, timer->get_milliseconds(timer), OFF);

	if (previous_button_state == false && button_2->is_pressed(button_2) == true)
	{
		this->operate = run;
	}

	previous_button_state = button_2->is_pressed(button_2);
}

static void pause(SevenSegment* this)
{
	Button* button_2 = GET_INSTANCE(button_2);
	Button* button_3 = GET_INSTANCE(button_3);
	Timer* timer = GET_INSTANCE(timer);
	static bool previous_button_state_2 = false;
	static bool previous_button_state_3 = false;

	DGT1_DP_ON;

	if (previous_button_state_2 == false && button_2->is_pressed(button_2) == true)
	{
		timer->set_count(timer, timer->get_recorded_count(timer));
		this->operate = run;
	}

	if (previous_button_state_3 == false && button_3->is_pressed(button_3) == true)
	{
		timer->set_count(timer, 0);
		this->operate = stop;
	}

	previous_button_state_2 = button_2->is_pressed(button_2);
	previous_button_state_3 = button_3->is_pressed(button_3);
}

static void run(SevenSegment* this)
{
	Button* button_2 = GET_INSTANCE(button_2);
	Timer* timer = GET_INSTANCE(timer);
	static bool previous_button_state = false;

	_7SEG_SetNumber(DGT1, timer->get_seconds(timer), timer->get_milliseconds(timer) < 5 ? ON : OFF);
	_7SEG_SetNumber(DGT2, timer->get_milliseconds(timer), OFF);

	if (previous_button_state == false && button_2->is_pressed(button_2) == true)
	{
		timer->record_count(timer);
		this->operate = pause;
	}

	previous_button_state = button_2->is_pressed(button_2);
}

SevenSegment* get_segment(void)
{
	return &segment;
}
