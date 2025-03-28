/*
 * timer.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include "timer.h"

static volatile uint32_t count;
static bool timer_state;
static uint32_t lap_time[LAP_TIME_SIZE];


void count_up(void)
{
	if (timer_state) count++;
}

uint32_t get_count(TimeType type)
{
	uint32_t local = count;

	switch (type)
	{
	case   HOUR: return (local / 3600000) %   24;
	case    MIN: return (local /   60000) %   60;
	case    SEC: return (local /    1000) %   60;
	case _100MS: return (local /     100) %   10;
	case     MS: return (local /       1) % 1000;
	default    : return                        0;
	}
}

void set_count(uint16_t _count)
{
	count = _count;
}

void set_timer(bool state)
{
	timer_state = state;
}

void save_lap_time(int8_t* index)
{
	if (*index == LAP_TIME_SIZE) return;
	lap_time[++(*index)] = count;
}

uint32_t get_lap_time(uint8_t index, TimeType type)
{
	uint32_t local = lap_time[index - 1];

	switch (type)
	{
	case   HOUR: return (local / 3600000) %   24;
	case    MIN: return (local /   60000) %   60;
	case    SEC: return (local /    1000) %   60;
	case _100MS: return (local /     100) %   10;
	case     MS: return (local /       1) % 1000;
	default    : return                        0;
	}
}

void clear_lap_time(void)
{
	memset(lap_time, 0, sizeof(lap_time));
}

