/*
 * timer.c
 *
 *  Created on: Apr 19, 2025
 *      Author: vermilion9312
 */


#include "timer.h"

static uint32_t count;

uint32_t get_time(TimeIndex index)
{
	static uint32_t time[TIME_COUNT];
	time[SECONDS] = (count / 1000) % 10;
	time[_100MS]  = (count /  100) % 10;

	return time[index];
}

void count_up(void)
{
	count++;
}

void set_count_zero(void)
{
	count = 0;
}
