/*
 * segment.c
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */


#include "segment.h"


void operate_segment(ButtonIndex button_index)
{
	if (is_pressed(button_index))
	{
		if (!was_pressed(button_index)) set_count(0);
		_7SEG_SetNumber(DGT1, get_count(SEC), get_count(MS) < 5 ? ON : OFF);
		_7SEG_SetNumber(DGT2, get_count(MS), OFF);
	}
	else
	{
		DGT1_DP_ON;
	}
}
