/*
 * io_manager.h
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */

#ifndef INC_IO_MANAGER_H_
#define INC_IO_MANAGER_H_

#include <input.h>
#include <output.h>

CLASS(CIOManager) {
	void (* operate)(CIOManager*);
};

PRIVATE(CIOManager) {
	CIOManager public;

	CInput*  input;
	COutput* left;
	COutput* right;
};

CIOManager* new_IO_Manager(CInput*, COutput*, COutput*);

#endif /* INC_IO_MANAGER_H_ */
