/*
 * seven_segment.c
 *
 *  Created on: Dec 10, 2024
 *      Author: LeeJooHo
 */


#include "seven_segment.h"

static void count_up(SevenSegment* this);
static void set_count_zero(SevenSegment* this);
static uint8_t get_seconds(SevenSegment* this);
static uint8_t get_milliseconds(SevenSegment* this);
static void count_seconds(SevenSegment* this);
static void count_stop(SevenSegment* this);

// 초기화 시 count는 0, display 상태는 count_stop으로 시작
SevenSegment segment = { .count = 0, .display = count_stop, count_up, set_count_zero, get_seconds, get_milliseconds };

static void count_up(SevenSegment* this)
{
	this->count++;
}

static void set_count_zero(SevenSegment* this)
{
	this->count = 0;
}

static uint8_t get_seconds(SevenSegment* this)
{
	return this->count / 10;
}

static uint8_t get_milliseconds(SevenSegment* this)
{
	return this->count % 10;
}

static void count_stop(SevenSegment* this)
{
	// 첫 번쩨 버튼만 사용하기게 굳이 button 구조체 포인터를 매개변수로 받지 않았습니다.
	Button* button_1 = GET_INSTANCE(button_1);

	// 카운트가 멈출 때 3.4초가 34초가 되는 상황을 방지하기 위해
	// 첫 번쨰 점은 멈춘 동안 계속 ON 시켜줍니다.
	DGT1_DP_ON;

	// 첫 번째 버튼을 누르는 순간
	if (button_1->is_pressed(button_1) == true)
	{
		// count 변수를 0으로 세팅하고
		this->set_count_zero(this);
		// display 함수 포인터를 count_senconds로 할당합니다.
		this->display = count_seconds;
	}
}

static void count_seconds(SevenSegment* this)
{
	Button* button_1 = GET_INSTANCE(button_1);

	// 삼항 연산자로 0.5 간격으로 점이 깜빡이게 구현합니다.
	_7SEG_SetNumber(DGT1, this->get_seconds(this), this->get_milliseconds(this) < 5 ? ON : OFF);
	_7SEG_SetNumber(DGT2, this->get_milliseconds(this), OFF);

	// 버튼이 떨어지는 순간
	if (button_1->is_pressed(button_1) == false)
	{
		// display 함수 포인터를 count_stop로 할당합니다.
		this->display = count_stop;
	}
}

SevenSegment* get_segment(void)
{
	return &segment;
}
