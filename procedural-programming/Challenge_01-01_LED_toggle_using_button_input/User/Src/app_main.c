/*
 * app_main.c
 *
 *  Created on: Aug 17, 2025
 *      Author: vermi
 */


#include <app_main.h>

static CInput* button_1;
static CInput* button_2;
static CInput* button_3;

static COutput* left_red;
static COutput* left_green;
static COutput* left_blue;

static COutput* right_red;
static COutput* right_green;
static COutput* right_blue;

static CIOManager* io_manager_1;
static CIOManager* io_manager_2;
static CIOManager* io_manager_3;

void app_init(void)
{
	button_1 = new_Input(BUTTON_1_GPIO_Port, BUTTON_1_Pin, NOMAL_OPEN);
	button_2 = new_Input(BUTTON_2_GPIO_Port, BUTTON_2_Pin, NOMAL_OPEN);
	button_3 = new_Input(BUTTON_3_GPIO_Port, BUTTON_3_Pin, NOMAL_OPEN);

	left_red   = new_Output(LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   ACTIVE_LOW);
	left_green = new_Output(LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, ACTIVE_LOW);
	left_blue  = new_Output(LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  ACTIVE_LOW);

	right_red   = new_Output(RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   ACTIVE_LOW);
	right_green = new_Output(RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, ACTIVE_LOW);
	right_blue  = new_Output(RIGHT_BLUE_GPIO_Port,  RIGHT_GLUE_Pin,  ACTIVE_LOW);

	io_manager_1 = new_IO_Manager(button_1, left_red,   right_red  );
	io_manager_2 = new_IO_Manager(button_2, left_green, right_green);
	io_manager_3 = new_IO_Manager(button_3, left_blue,  right_blue );
}

void app_main(void)
{
	button_1->update(button_1);
	button_2->update(button_2);
	button_3->update(button_3);

	io_manager_1->operate(io_manager_1);
	io_manager_2->operate(io_manager_2);
	io_manager_3->operate(io_manager_3);
}
