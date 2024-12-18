/*
 * timer.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include "timer.h"

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

static uint8_t get_milliseconds(Timer* this)
{
	return this->count % 10;
}

static uint8_t get_senconds(Timer* this)
{
	return this->count / 10;
}

static uint8_t get_minutes(Timer* this)
{
	return this->count / 60000;
}

static uint8_t get_hours(Timer* this)
{
	return this->count / 3600000;
}

Timer timer = {
		.count = 0,
		.recorded_count = 0,

		count_up,
		set_count,

		record_count,
		get_recorded_count,

		get_milliseconds,
		get_senconds,
		get_minutes,
		get_hours
};

Timer* get_timer(void)
{
	return &timer;
}

