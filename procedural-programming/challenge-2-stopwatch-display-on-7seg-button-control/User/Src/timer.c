/*
 * timer.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include "timer.h"

static uint16_t count;
static bool timer_state;

void count_up(void)
{
	if (timer_state) count++;
}

uint16_t get_count(TimeType type)
{
	if (type == SEC)
	{
		return count / 10;
	}
	else if (type == MS)
	{
		return count % 10;
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
