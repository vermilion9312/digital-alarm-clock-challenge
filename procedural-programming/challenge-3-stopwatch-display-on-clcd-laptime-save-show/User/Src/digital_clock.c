/*
 * digital_clock.c
 *
 *  Created on: Mar 27, 2025
 *      Author: LeeJooHo
 */

#include "digital_clock.h"

static void stopwatch_mode(void);

void (* operate_digital_clock)(void) = stopwatch_mode;

static void clock_mode(void)
{

}

static void timer_mode(void)
{

}

static void stopwatch_mode(void)
{
	update_button(BUTTON_1);
	update_button(BUTTON_2);
	update_button(BUTTON_3);
	update_button(BUTTON_4);

	operate_led(BUTTON_1, LEFT_RED  );
	operate_led(BUTTON_2, LEFT_GREEN);
	operate_led(BUTTON_3, LEFT_BLUE );
	operate_led(BUTTON_4, RIGHT_RED );

	operate_stopwatch_mode();

	update_last_button(BUTTON_1);
	update_last_button(BUTTON_2);
	update_last_button(BUTTON_3);
	update_last_button(BUTTON_4);
}

static void alarm_mode(void)
{

}

static void music_player_mode(void)
{

}


