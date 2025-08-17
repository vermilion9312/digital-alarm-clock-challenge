/*
 * input.c
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */


#include <input.h>

static void update(CInput* public)
{

}

static bool is_pressed(CInput* public)
{
	return false;
}

static bool is_rising(CInput* public)
{
	return false;
}

static bool is_falling(CInput* public)
{
	return false;
}

CInput* new_Output(GPIO_TypeDef* port, uint16_t pin, InputType type)
{
	CInputPrivate* this = malloc(sizeof(CInputPrivate));

	return (CInput*) this;
}
