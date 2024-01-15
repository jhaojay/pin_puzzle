/*
 * level.c
 *
 *  Created on: Nov 24, 2023
 *      Author: phi
 */


#include "level.h"

bool is_door_1_open = false;
bool is_door_2_open = false;

void init_levels ()
{
	init_servo();  // for door 2


	// turn off all number leds except num 9's
//	turn_on_led_number(1);
//	turn_on_led_number(2);
//	turn_on_led_number(3);
//	turn_on_led_number(4);
//	turn_on_led_number(5);
//	turn_on_led_number(6);
//	turn_on_led_number(7);
//	turn_on_led_number(8);
	turn_on_led_number(9);

}

bool is_level_1_clear ()
{
	return (
			is_led_on(1) &&
			is_led_on(2) &&
			is_led_on(3) &&
			is_led_on(4) &&
			is_led_on(5) &&
			is_led_on(6) &&
			is_led_on(7) &&
			is_led_on(8) &&
			is_led_on(9)
	);
}

void open_door_1 ()
{
//	if (!is_door_1_open) {
		stepper_rotate(OPEN_ROTATION, DELAY_US, CLOCKWISE);
//		is_door_1_open = true;
//	}
}

void close_door_1 ()
{
//	if (is_door_1_open) {
		stepper_rotate(CLOSE_ROTATION, DELAY_US, COUNTER_CLOCKWISE);
//		is_door_1_open = false;
//	}
}

void open_door_2 ()
{
	turn_servo(DR2_OPEN_DEG);
	is_door_2_open = true;
}

void close_door_2 ()
{
	turn_servo(DR2_CLOSE_DEG);
	is_door_2_open = false;
}

bool are_first_6_slots_inserted (const uint8_t * const digits)
{
	for (size_t i = 0; i < 6; i++) {
		if ((digits[i] > 9) || (digits[i] < 1)) {
			return false;
		}
	}
	return true;
}


bool are_all_slots_inserted (const uint8_t * const digits)
{
	for (size_t i = 0; i < 9; i++) {
		if ((digits[i] > 9) || (digits[i] < 1)) {
			return false;
		}
	}
	return true;
}

uint8_t find_digital_root (uint8_t n1, uint8_t n2, uint8_t n3)
{
    uint8_t sum = n1 + n2 + n3;
    uint8_t tens = sum / 10;       // Extract the tens digit
    uint8_t ones = sum % 10;       // Extract the ones digit
    uint8_t result = tens + ones;  // Sum of the tens and ones digits

    if (result > 9) {
        // If the result is more than a single digit, find the digital root of the result
        result = find_digital_root(result / 10, result % 10, 0);
    }
    return result;
}

bool is_magic_square_solved(const uint8_t * const digits)
{
	return (digits[0] + digits[1] + digits[2] == 15 &&
	            digits[3] + digits[4] + digits[5] == 15 &&
	            digits[6] + digits[7] + digits[8] == 15 &&
	            digits[0] + digits[3] + digits[6] == 15 &&
	            digits[1] + digits[4] + digits[7] == 15 &&
	            digits[2] + digits[5] + digits[8] == 15 &&
	            digits[0] + digits[4] + digits[8] == 15 &&
	            digits[2] + digits[4] + digits[6] == 15);
}

void level_clear_blink ()
{
	control_all_num_leds(0);
	HAL_Delay(300);
	control_all_num_leds(1);
	HAL_Delay(300);
	control_all_num_leds(0);
	HAL_Delay(300);
	control_all_num_leds(1);
	HAL_Delay(300);
	control_all_num_leds(0);
	HAL_Delay(300);
	control_all_num_leds(1);
	HAL_Delay(300);
	control_all_num_leds(0);
}
