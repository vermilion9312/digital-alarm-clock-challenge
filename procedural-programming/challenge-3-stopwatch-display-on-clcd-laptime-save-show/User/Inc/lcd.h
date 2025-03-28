/*
 * lcd.h
 *
 *  Created on: Mar 27, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include <stdio.h>
#include "CLCD.h"
#include "timer.h"
#include "stopwatch_mode.h"
#include <stdarg.h>

typedef void (* LCD_TopOperation)(void);
typedef void (* LCD_BottomOperation)(int8_t, ...);

extern LCD_TopOperation operate_lcd_top;
extern LCD_BottomOperation operate_lcd_bottom;

#endif /* INC_LCD_H_ */
