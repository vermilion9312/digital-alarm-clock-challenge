/*
 * lcd.h
 *
 *  Created on: Dec 13, 2024
 *      Author: LeeJooHo
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include <stdio.h>
#include <string.h>
#include "CLCD.h"
#include "timer.h"
#include "button.h"
#include "common.h"

typedef enum { STOP, OTHERS } State;
typedef enum { TOP_LINE, BOTTOM_LINE } Line;

typedef struct _Lcd Lcd;

struct _Lcd {
	void (* operate)(Lcd*);
};

Lcd* get_lcd(void);

#endif /* INC_LCD_H_ */
