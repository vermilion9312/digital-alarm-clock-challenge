/*
 * root.c
 *
 *  Created on: Apr 3, 2025
 *      Author: LeeJooHo
 */


#include "root.h"

static ButtonConfig button_config = { { BUTTON_1_GPIO_Port, BUTTON_1_Pin } };
static LED_Config   led_config    = { { LEFT_RED_GPIO_Port, LEFT_RED_Pin } };

static LeafNode is_button_rising_edge = { is_rising_edge,     &button_config };
static LeafNode button_update         = { update_button,      &button_config };
static LeafNode last_button_update    = { update_last_button, &button_config };

static LeafNode led_is_on    = { is_led_on,    &led_config };
static LeafNode led_turn_on  = { turn_on_led,  &led_config };
static LeafNode led_turn_off = { turn_off_led, &led_config };

static void* led_seq_children[] = { &led_is_on, &led_turn_off };
static CompositeNode led_seq = { run_sequence, led_seq_children, 2 };

static void* led_sel_children[] = { &led_seq, &led_turn_on };
static CompositeNode led_sel = { run_selector, led_sel_children, 2 };

static void* seq_children[] = { &is_button_rising_edge, &led_sel };
static CompositeNode seq = { run_sequence, seq_children, 2 };

static void* root_children[] = { &button_update, &seq, &last_button_update };
static CompositeNode root = { run_sequence, root_children, 3 };


CompositeNode* get_root(void)
{
	return &root;
}

