/*
 * stopwatch_mode.h
 *
 *  Created on: Mar 25, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_STOPWATCH_MODE_H_
#define INC_STOPWATCH_MODE_H_


#include "button.h"
#include "timer.h"
#include <stdio.h>
#include <inttypes.h>
#include "segment.h"
#include "lcd.h"

typedef void (* StopwatchModeOperation)(void);
extern StopwatchModeOperation operate_stopwatch_mode;

void stopped(void);
void running(void);
void paused(void);

#endif /* INC_STOPWATCH_MODE_H_ */
