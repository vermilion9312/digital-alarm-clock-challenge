/*
 * io_manager.c
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */


#include <io_manager.h>

static void operate(CIOManager* public)
{
	CIOManagerPrivate* this = (CIOManagerPrivate*) public;
	CInput*  input = this->input;
	COutput* left  = this->left;
	COutput* right = this->right;

	if (input->is_rising(input))
	{
		left->toggle(left);
	}

	if (input->is_falling(input))
	{
		right->toggle(right);
	}
}


CIOManager* new_IO_Manager(CInput* input, COutput* left, COutput* right)
{
	CIOManagerPrivate* this = malloc(sizeof(CIOManagerPrivate));


	return (CIOManager*) this;
}
