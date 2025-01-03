/*
 * _103_seven_segment.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include <_103_seven_segment.h>

static void set_state(SevenSegment* this, OperateSegment operate);
static Mode get_current_mode(SevenSegment* this);
static void operate_stop(SevenSegment* this);
static void operate_pause(SevenSegment* this);
static void operate_run(SevenSegment* this);

SevenSegment segment = { .mode = NULL, .is_transitioned = false, get_current_mode, set_state, operate_stop };

static void set_state(SevenSegment* this, OperateSegment operate)
{
	this->operate = operate;
}

static Mode get_current_mode(SevenSegment* this)
{
	return *this->mode;
}


static void operate_stop(SevenSegment* this)
{
	Timer* timer = GET_INSTANCE(timer);
	Button* button_2 = GET_INSTANCE(button_2);
	static bool last_button = false;

	DGT1_DP_ON;
	DGT2_DP_OFF;

	timer->set_count(timer, 0);

	_7SEG_SetNumber(DGT1, timer->get_time(timer, SECONDS), ON);
	_7SEG_SetNumber(DGT2, timer->get_time(timer, _100_MILLISECONDS), OFF);

	if (this->is_transitioned == false)
	{
		if (last_button == false && button_2->is_pressed(button_2) == true)
		{
			this->set_state(this, operate_run);
			this->is_transitioned = true;
		}
	}

	if (last_button == true && button_2->is_pressed(button_2) == false)
	{
		this->is_transitioned = false;
	}


	last_button = button_2->is_pressed(button_2);
}

static void operate_run(SevenSegment* this)
{
	Timer* timer = GET_INSTANCE(timer);
	Button* button_2 = GET_INSTANCE(button_2);
	Time* recorded_time = GET_INSTANCE(recorded_time);
	static bool last_button = false;

	_7SEG_SetNumber(DGT1, timer->get_time(timer, SECONDS), timer->get_time(timer, _100_MILLISECONDS) < 5 ? ON : OFF);
	_7SEG_SetNumber(DGT2, timer->get_time(timer, _100_MILLISECONDS), OFF);

	if (this->is_transitioned == false)
	{
		if (last_button == false && button_2->is_pressed(button_2) == true)
		{
			timer->record_time(timer, recorded_time);
			this->set_state(this, operate_pause);
			this->is_transitioned = true;
		}
	}

	if (last_button == true && button_2->is_pressed(button_2) == false)
	{
		this->is_transitioned = false;
	}

	last_button = button_2->is_pressed(button_2);
}

static void operate_pause(SevenSegment* this)
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

	if (this->is_transitioned == false)
	{
		if (last_button_2 == false && button_2->is_pressed(button_2) == true)
		{
			this->set_state(this, operate_run);
			this->is_transitioned = true;
		}

		if (last_button_3 == false && button_3->is_pressed(button_3) == true)
		{
			this->set_state(this, operate_stop);
			this->is_transitioned = true;
		}
	}

	if (last_button_2 == true && button_2->is_pressed(button_2) == false)
	{
		this->is_transitioned = false;
	}

	if (last_button_3 == true && button_3->is_pressed(button_3) == false)
	{
		this->is_transitioned = false;
	}

	last_button_2 = button_2->is_pressed(button_2);
	last_button_3 = button_3->is_pressed(button_3);
}

SevenSegment* get_segment(void)
{
	segment.mode = GET_INSTANCE(mode);
	return &segment;
}

