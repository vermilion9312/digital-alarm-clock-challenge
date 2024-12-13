/*
 * timer.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include "timer.h"

static void count_up(Timer* this);
static void set_count(Timer* this, uint32_t count);
static void record_count(Timer* this);
static uint32_t get_recorded_count(Timer* this);
static uint8_t get_milliseconds(Timer* this);
static uint8_t get_100_milliseconds(Timer* this);
static uint8_t get_senconds(Timer* this);
static uint8_t get_minutes(Timer* this);
static uint8_t get_hours(Timer* this);
static void record_time(Timer* this, Time* time);

static Time real_time;
static Time run_time;
static Time lap_time[9];

Timer timer = {
		.time = &run_time,

		.count = 0,
		.recorded_count = 0,

		count_up,
		set_count,

		record_count,
		get_recorded_count,
		record_time,

		get_milliseconds,
		get_100_milliseconds,
		get_senconds,
		get_minutes,
		get_hours
};

static void count_up(Timer* this)
{
	this->count++;
	this->time->hours             = this->count / 3600000 % 24;;
	this->time->minutes           = this->count / 60000 % 60;;
	this->time->seconds           = this->count / 1000 % 60;
	this->time->_100_milliseconds = this->count / 100;
	this->time->milliseconds      = this->count;
}

static void set_time(Timer* this)
{

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
	this->time->hours             = this->count / 3600000 % 24;;
	this->time->minutes           = this->count / 60000 % 60;;
	this->time->seconds           = this->count / 1000 % 60;
	this->time->_100_milliseconds = this->count / 100;
	this->time->milliseconds      = this->count;
}

static uint8_t get_milliseconds(Timer* this)
{
	return this->time->milliseconds;
}

static uint8_t get_100_milliseconds(Timer* this)
{
	return this->time->_100_milliseconds;
}

static uint8_t get_senconds(Timer* this)
{
	return this->time->seconds;
}

static uint8_t get_minutes(Timer* this)
{
	return this->time->minutes;
}

static uint8_t get_hours(Timer* this)
{
	return this->time->hours;
}

Timer* get_timer(void)
{
	return &timer;
}

Time* get_lap_time(void)
{
	return lap_time;
}

Time* get_run_time(void)
{
	return &run_time;
}

