/*
 * _001_mode.h
 *
 *  Created on: Dec 21, 2024
 *      Author: vermi
 */

#ifndef INC__001_MODE_H_
#define INC__001_MODE_H_


typedef struct _DigitalClock DigitalClock;
typedef struct _SevenSegment SevenSegment;
typedef struct _Lcd Lcd;

typedef struct _Led Led;

typedef enum { CLOCK_MODE, ALARM_MODE, STOPWATCH_MODE, TIMER_MODE, MODE_COUNT } Mode;

Mode* get_mode(void);

#endif /* INC__001_MODE_H_ */
