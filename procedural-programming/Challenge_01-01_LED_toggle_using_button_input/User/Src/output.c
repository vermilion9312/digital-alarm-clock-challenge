/*
 * output.c
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */


#include <output.h>

static void turn_on(COutput* public)
{

}

static void turn_off(COutput* public)
{

}

static void toggle(COutput* public)
{

}

static bool is_on(COutput* public)
{

}

COutput* new_Output(GPIO_TypeDef* port, uint16_t pin, OutputType type)
{
	COutputPrivate* this = malloc(sizeof(COutputPrivate));


	return (Output*) this;
}
