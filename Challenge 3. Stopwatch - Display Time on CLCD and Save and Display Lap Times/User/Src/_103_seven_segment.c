/*
 * _103_seven_segment.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include <_103_seven_segment.h>

static void set_state(SevenSegment* this, OperateSegment operate);
static Mode get_current_mode(SevenSegment* this);



SevenSegment segment = { .mode = NULL, get_current_mode, set_state, operate_stop };


static void set_state(SevenSegment* this, OperateSegment operate)
{
	this->operate = operate;
}

static Mode get_current_mode(SevenSegment* this)
{
	return *this->mode;
}


void operate_stop(SevenSegment* this)
{
	Timer* timer = GET_INSTANCE(timer);
	Button* button_2 = GET_INSTANCE(button_2);
	static bool last_button = false;

	DGT1_DP_ON;
	DGT2_DP_OFF;

	timer->set_count(timer, 0);

//	_7SEG_SetNumber(DGT1, timer->get_time(timer, SECONDS), ON);
//	_7SEG_SetNumber(DGT2, timer->get_time(timer, _100_MILLISECONDS), OFF);
	_7SEG_SetNumber(DGT2, this->get_current_mode(this), ON);

	if (this->get_current_mode(this) == STOPWATCH_MODE)
	{
		if (last_button == false && button_2->is_pressed(button_2) == true)
		{
			this->set_state(this, operate_run);
		}
	}


	last_button = button_2->is_pressed(button_2);
}

void operate_run(SevenSegment* this)
{
	Timer* timer = GET_INSTANCE(timer);
	Button* button_2 = GET_INSTANCE(button_2);
	static bool last_button = false;

	_7SEG_SetNumber(DGT1, timer->get_time(timer, SECONDS), timer->get_time(timer, _100_MILLISECONDS) < 5 ? ON : OFF);
	_7SEG_SetNumber(DGT2, timer->get_time(timer, _100_MILLISECONDS), OFF);


	if (this->get_current_mode(this) == STOPWATCH_MODE)
	{
		if (last_button == false && button_2->is_pressed(button_2) == true)
		{
			this->set_state(this, operate_pause);
		}
	}

	last_button = button_2->is_pressed(button_2);
}

void operate_pause(SevenSegment* this)
{
	Timer* timer = GET_INSTANCE(timer);
	Button* button_2 = GET_INSTANCE(button_2);
	Button* button_3 = GET_INSTANCE(button_3);
	static bool last_button_2 = false;
	static bool last_button_3 = false;

	DGT1_DP_ON;

	timer->set_count(timer, timer->get_recorded_count(timer));

	_7SEG_SetNumber(DGT1, timer->get_time(timer, SECONDS), ON);
	_7SEG_SetNumber(DGT2, timer->get_time(timer, _100_MILLISECONDS), OFF);

	if (this->get_current_mode(this) == STOPWATCH_MODE)
	{
		if (last_button_2 == false && button_2->is_pressed(button_2) == true)
		{
			this->set_state(this, operate_run);
		}

		if (last_button_3 == false && button_3->is_pressed(button_3) == true)
		{
			this->set_state(this, operate_stop);
		}
	}

	last_button_2 = button_2->is_pressed(button_2);
	last_button_3 = button_3->is_pressed(button_3);
}

SevenSegment* get_segment(void)
{
	segment.mode = GET_INSTANCE(mode);
	return &segment;
}

