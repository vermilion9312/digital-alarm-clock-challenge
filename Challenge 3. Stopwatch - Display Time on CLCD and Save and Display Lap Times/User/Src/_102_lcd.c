/*
 * _102_lcd.c
 *
 *  Created on: Dec 13, 2024
 *      Author: LeeJooHo
 */


#include <_102_lcd.h>

static void operate(Lcd* this);
static void stop(Lcd* this);
static void run(Lcd* this);
static void pause(Lcd* this);
static void display_time(char* head, Line line, State state, Time* time);

Lcd lcd = { .mode = NULL, operate };

static void operate(Lcd* this)
{
}


void operate_clock_mode_lcd(Lcd* this)
{

}

void operate_alarm_mode_lcd(Lcd* this)
{

}

void operate_stopwatch_mode_lcd(Lcd* this)
{

}

void operate_timer_mode_lcd(Lcd* this)
{

}


static void stop(Lcd* this)
{
	Timer* timer = GET_INSTANCE(timer);
	Button* button_2 = GET_INSTANCE(button_2);
	static bool previous_button = false;

	timer->set_count(timer, 0);

	display_time("STW", TOP_LINE, STOP, timer->time);

	if (previous_button == false && button_2->is_pressed(button_2) == true)
	{
		CLCD_Clear();
		this->operate = run;
	}

	previous_button = button_2->is_pressed(button_2);
}

static void run(Lcd* this)
{
	Button* button_2 = GET_INSTANCE(button_2);
	Button* button_3 = GET_INSTANCE(button_3);
	Button* button_4 = GET_INSTANCE(button_4);
	static bool previous_button_2 = false;
	static bool previous_button_3 = false;
	static bool previous_button_4 = false;
	Timer* timer = GET_INSTANCE(timer);
	static uint8_t lap_count = 0;
	char ttemp[5] = { 0, };
	Time* lap_time = GET_INSTANCE(lap_time);


	display_time("STW", TOP_LINE, OTHERS, timer->time);

	if (previous_button_2 == false && button_2->is_pressed(button_2) == true)
	{
		CLCD_Clear();
		this->operate = pause;
	}

	if (previous_button_3 == false && button_3->is_pressed(button_3) == true)
	{
		memcpy(&(lap_time[lap_count]), timer->time, sizeof(timer->time));

		sprintf(ttemp, "LP%d", lap_count + 1);



		if (lap_count < 10)
		{
			display_time(ttemp, BOTTOM_LINE, OTHERS, timer->time);
		}
		else
		{
			CLCD_Clear();
			CLCD_Puts(0, BOTTOM_LINE, "LAP FULL(9/9)");
		}
	}

	if (previous_button_4 == false && button_4->is_pressed(button_4) == true)
	{

	}

	previous_button_2 = button_2->is_pressed(button_2);
	previous_button_3 = button_3->is_pressed(button_3);
	previous_button_4 = button_4->is_pressed(button_4);
}

static void pause(Lcd* this)
{
	Button* button_2 = GET_INSTANCE(button_2);
	Button* button_3 = GET_INSTANCE(button_3);
	Button* button_4 = GET_INSTANCE(button_4);
	static bool previous_button_2 = false;
	static bool previous_button_3 = false;
	static bool previous_button_4 = false;
	Timer* timer = GET_INSTANCE(timer);

//	timer->set_count(timer, timer->get_recorded_count(timer));
	display_time("STW", TOP_LINE, OTHERS, timer->time);

	if (previous_button_2 == false && button_2->is_pressed(button_2) == true)
	{
		CLCD_Clear();
		this->operate = run;
	}

	if (previous_button_3 == false && button_3->is_pressed(button_3) == true)
	{
		CLCD_Clear();
		this->operate = stop;
	}

	if (previous_button_4 == false && button_4->is_pressed(button_4) == true)
	{

	}

	previous_button_2 = button_2->is_pressed(button_2);
	previous_button_3 = button_3->is_pressed(button_3);
	previous_button_4 = button_4->is_pressed(button_4);
}

static void display_time(char* head, Line line, State state, Time* time)
{
	Timer* timer = GET_INSTANCE(timer);
	char string[20] = { 0, };
	char seconds[20] = { 0, };
	char minutes[20] = { 0, };
	char housrs[20] = { 0, };

	CLCD_Puts(0, line, head);

	sprintf(housrs,"%02d", state == STOP ? timer->get_recorded_time(timer, time, HOURS) : timer->get_time(timer, HOURS));
	CLCD_Puts(4, line, housrs);

	CLCD_Puts(6, line, ":");

	sprintf(minutes,"%02d", state == STOP ? timer->get_recorded_time(timer, time, MINUTES) :timer->get_time(timer, MINUTES));
	CLCD_Puts(7, line, minutes);

	CLCD_Puts(9, line, ":");

	sprintf(seconds, "%02d", state == STOP ? timer->get_recorded_time(timer, time, SECONDS) : timer->get_time(timer, SECONDS));
	CLCD_Puts(10, line, seconds);

	CLCD_Puts(12, line, ".");

	sprintf(string, "%03d", state == STOP ? timer->get_recorded_time(timer, time, MILLISECONDS) : timer->get_time(timer, MILLISECONDS));
	CLCD_Puts(13, line, string);
}


Lcd* get_lcd(void)
{
	lcd.mode = GET_INSTANCE(mode);
	return &lcd;
}
