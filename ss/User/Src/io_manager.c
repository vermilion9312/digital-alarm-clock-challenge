/*
 * io_manager.c
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */


#include <io_manager.h>

static void set_output(CIOManagerPrivate* this, COutput* output)
{
	this->output = output;
}

static void operate(CIOManager* public)
{
	CIOManagerPrivate* this = (CIOManagerPrivate*) public;
	CInput*  input    = this->input;
	CInput*  button_4 = this->button_4;
	COutput* output   = this->output;

	if (button_4->is_falling(button_4) /* || get_uart*/)
	{
		set_output(this, )
	}

	if (input->is_rising(input))
	{
		output->toggle(output);
	}
}


CIOManager* new_IO_Manager(CInput* input, COutput* output)
{
	CIOManagerPrivate* this = malloc(sizeof(CIOManagerPrivate));


	return (CIOManager*) this;
}
