/*
 * root.c
 *
 *  Created on: Apr 3, 2025
 *      Author: LeeJooHo
 */


#include "root.h"

static ButtonConfig button_1_config = { { BUTTON_1_GPIO_Port, BUTTON_1_Pin } };
//static ButtonConfig button_2_config = { { BUTTON_2_GPIO_Port, BUTTON_2_Pin } };
//static ButtonConfig button_3_config = { { BUTTON_3_GPIO_Port, BUTTON_3_Pin } };
//static ButtonConfig button_4_config = { { BUTTON_4_GPIO_Port, BUTTON_4_Pin } };
//
static LED_Config left_led_config    = { { LEFT_RED_GPIO_Port,    LEFT_RED_Pin    } };
//static LED_Config left_green_config  = { { LEFT_GREEN_GPIO_Port,  LEFT_GREEN_Pin  } };
//static LED_Config left_blue_config   = { { LEFT_BLUE_GPIO_Port,   LEFT_BLUE_Pin   } };
//static LED_Config right_led_config   = { { RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin   } };
//static LED_Config right_green_config = { { RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin } };
//static LED_Config right_blue_config  = { { RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin  } };

static LeafNode is_button_1_rising_edge  = { is_rising_edge,     &button_1_config };
//static LeafNode is_button_1_falling_edge = { is_falling_edge,    &button_1_config };
static LeafNode button_1_update          = { update_button,      &button_1_config };
static LeafNode last_button_1_update     = { update_last_button, &button_1_config };

static LeafNode left_red_turn_on  = { turn_on_led, &left_led_config  };
static LeafNode left_red_turn_off = { turn_off_led, &left_led_config };

static void* left_red_seq_children[] = { &is_button_1_rising_edge, &left_red_turn_on };
static CompositeNode left_red_seq = { run_sequence, left_red_seq_children, 2 };

static void* lef_red_sel_children[] = { &left_red_seq, &left_red_turn_off };
static CompositeNode left_red_sel = { run_selector, lef_red_sel_children, 2 };

static void* root_children[] = { &button_1_update, &left_red_sel, &last_button_1_update };
static CompositeNode root = { run_sequence, root_children, 3};

CompositeNode* get_root(void)
{
	return &root;
}

