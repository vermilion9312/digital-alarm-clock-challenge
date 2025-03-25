/*
 * timer.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include "timer.h"

static uint16_t count;

void count_up(void)
{
	count++;
}

uint16_t get_count(TimeType type)
{
	if (type == SEC)
	{
		return count / 10;
	}
	else
	{
		return count % 10;
	}
}

void set_count(uint16_t _count)
{
	count = _count;
}
