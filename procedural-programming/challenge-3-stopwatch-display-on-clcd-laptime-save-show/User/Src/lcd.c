/*
 * lcd.c
 *
 *  Created on: Mar 27, 2025
 *      Author: LeeJooHo
 */


#include "lcd.h"

static void display_stopwatch(void);
static void diaplay_lap_stop(int8_t index, ...);
static void display_lap_reg(int8_t index, ...);
static void display_lap_full(int8_t index, ...);
static void display_lap_log(int8_t index, ...);

static char top_ine_buffer[30];
static char bottom_ine_buffer[30];

LCD_TopOperation operate_lcd_top = display_stopwatch;
LCD_BottomOperation operate_lcd_bottom = diaplay_lap_stop;


static void display_stopwatch(void)
{
	sprintf(top_ine_buffer, "STW %02lu:%02lu:%02lu:%03lu", get_count(HOUR), get_count(MIN), get_count(SEC), get_count(MS));
	CLCD_Puts(0, 0, (unsigned char*) top_ine_buffer);
}

static void diaplay_lap_stop(int8_t index, ...)
{
	sprintf(bottom_ine_buffer, "                ");
	CLCD_Puts(0, 1, (unsigned char*) bottom_ine_buffer);
	if (index > -1)
	{
		operate_lcd_bottom = display_lap_reg;
	}
}

static void display_lap_reg(int8_t index, ...)
{
	sprintf(bottom_ine_buffer, "LP%d %02lu:%02lu:%02lu:%03lu", index + 1,
			get_lap_time(index + 1, HOUR), get_lap_time(index + 1, MIN),
			get_lap_time(index + 1, SEC),  get_lap_time(index + 1, MS));
	CLCD_Puts(0, 1, (unsigned char*) bottom_ine_buffer);

	if (index > LAP_TIME_SIZE - 1)
	{
		operate_lcd_bottom = display_lap_full;
	}
}

static void display_lap_full(int8_t index, ...)
{
	sprintf(bottom_ine_buffer, "LAP FULL(9/9)   ");
	CLCD_Puts(0, 1, (unsigned char*) bottom_ine_buffer);

	if (index < 0)
	{
		operate_lcd_bottom = diaplay_lap_stop;
	}
}

static void display_lap_log(int8_t index, ...)
{
	va_list ap;
	va_start(ap, index);
	int8_t lap_index = (int8_t) va_arg(ap, int);
	int8_t log_index = (int8_t) va_arg(ap, int);
	va_end(ap);

	sprintf(bottom_ine_buffer, "%d/%d %02lu:%02lu:%02lu:%03lu", log_index + 1, lap_index,
			get_lap_time(log_index + 1, HOUR), get_lap_time(log_index + 1, MIN),
			get_lap_time(log_index + 1, SEC),  get_lap_time(log_index + 1, MS));
	CLCD_Puts(0, 1, (unsigned char*) bottom_ine_buffer);

	if (index < 0 )
	{
		operate_lcd_bottom = diaplay_lap_stop;
	}
}

