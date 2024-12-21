/*
 * _002_timer.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include <_002_timer.h>

static void count_up(Timer* this);
static void set_count(Timer* this, uint32_t count);
static void record_count(Timer* this);
static uint32_t get_recorded_count(Timer* this);
static void record_time(Timer* this, Time* time);
static uint8_t get_recorded_time(Timer* this, Time* time, TimeKind time_kind);
static uint8_t get_time(Timer* this, TimeKind time_kind);

static Time current_time;
static Time recorded_run_time;
static Time lap_time[9];

Timer timer = {
		.time = &recorded_run_time,

		.count = 0,
		.recorded_count = 0,

		count_up,
		set_count,

		record_count,
		get_recorded_count,
		record_time,
		get_recorded_time,
		get_time
};

static void count_up(Timer* this)
{
	this->count++;
}

static void set_count(Timer* this, uint32_t count)
{
	this->count = count;
}

static void record_count(Timer* this)
{
	this->recorded_count = this->count;
}

static uint32_t get_recorded_count(Timer* this)
{
	return this->recorded_count;
}

static void record_time(Timer* this, Time* time)
{
	this->time = time;
	this->time->hours             = this->count / 3600000 % 24;
	this->time->minutes           = this->count / 60000 % 60;
	this->time->seconds           = this->count / 1000 % 60;
	this->time->_100_milliseconds = this->count / 100;
	this->time->milliseconds      = this->count;
}

static uint8_t get_recorded_time(Timer* this, Time* time, TimeKind time_kind)
{
	this->time = time;
	switch(time_kind)
	{
	case HOURS:
		return this->time->hours;
		break;
	case MINUTES:
		return this->time->minutes;
		break;
	case SECONDS:
		return this->time->seconds;
		break;
	case _100_MILLISECONDS:
		return this->time->_100_milliseconds;
		break;
	case MILLISECONDS:
		return this->time->milliseconds;
		break;
	default:
		break;
	}

	return -1;
}

static uint8_t get_time(Timer* this, TimeKind time_kind)
{
	switch(time_kind)
	{
	case HOURS:
		return this->count / 3600000 % 24;
		break;
	case MINUTES:
		return this->count / 60000 % 60;
		break;
	case SECONDS:
		return this->count / 1000 % 60;
		break;
	case _100_MILLISECONDS:
		return this->count % 1000 / 100;
		break;
	case MILLISECONDS:
		return this->count;
		break;
	default:
		break;
	}

	return -1;
}

Time* get_recorded_run_time(void)
{
	return &recorded_run_time;
}

Timer* get_timer(void)
{
	return &timer;
}

Time* get_lap_time(void)
{
	return lap_time;
}
