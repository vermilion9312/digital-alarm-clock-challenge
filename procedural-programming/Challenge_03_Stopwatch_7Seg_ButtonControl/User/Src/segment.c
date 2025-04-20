/*
 * segment.c
 *
 *  Created on: Apr 18, 2025
 *      Author: vermilion9312
 */


#include "segment.h"


void operate_segment(void)
{
	_7SEG_SetNumber(DGT1, get_time(SECONDS), (is_button_on(BUTTON_1) && get_time(_100MS) < 5) ? OFF : ON);
	_7SEG_SetNumber(DGT2, get_time(_100MS), OFF);
}
