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
typedef void (* OperateLcd)(Lcd*);

struct _Lcd {
	Mode* mode;
	void (* const set_state)(Lcd*, OperateLcd);
	void (* operate)(Lcd*);
};

Lcd* get_lcd(void);

#endif /* INC__102_LCD_H_ */
