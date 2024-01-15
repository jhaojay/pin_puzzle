/*
 * level.h
 *
 *  Created on: Nov 24, 2023
 *      Author: phi
 */

#ifndef INC_LEVEL_H_
#define INC_LEVEL_H_

#include <interface.h>
#include <stdbool.h>
#include "servo.h"
#include "stepper.h"

#define DR2_OPEN_DEG -90
#define DR2_CLOSE_DEG 5

extern bool is_door_1_open;
extern bool is_door_2_open;

void init_levels ();

bool is_level_1_clear ();
bool is_magic_square_solved (const uint8_t * const digits);

void open_door_1 ();
void close_door_1 ();

void open_door_2 ();
void close_door_2();

bool are_first_6_slots_inserted (const uint8_t * const);
uint8_t find_digital_root (uint8_t n1, uint8_t n2, uint8_t n3);

void level_clear_blink ();


#endif /* INC_LEVEL_H_ */
