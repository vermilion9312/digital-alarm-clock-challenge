/*
 * _102_lcd.h
 *
 *  Created on: Dec 13, 2024
 *      Author: LeeJooHo
 */

#ifndef INC__102_LCD_H_
#define INC__102_LCD_H_

#include <_000_common.h>
#include <_002_timer.h>
#include <_105_button.h>
#include <stdio.h>
#include <string.h>
#include <_001_mode.h>
#include "CLCD.h"

typedef enum { STOP, OTHERS } State;
typedef enum { TOP_LINE, BOTTOM_LINE } Line;

typedef struct _Lcd Lcd;

struct _Lcd {
	Mode* mode;
	void (* operate)(Lcd*);
};

void operate_clock_mode_lcd(Lcd* this);
void operate_alarm_mode_lcd(Lcd* this);
void operate_stopwatch_mode_lcd(Lcd* this);
void operate_timer_mode_lcd(Lcd* this);

Lcd* get_lcd(void);

#endif /* INC__102_LCD_H_ */
