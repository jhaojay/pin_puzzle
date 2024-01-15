/*
 * slot.adc.h
 *
 *  Created on: Nov 24, 2023
 *      Author: phi
 */

#ifndef INC_SLOT_ADC_H_
#define INC_SLOT_ADC_H_

#include <stdint.h>
#include <stdbool.h>

#include "adc.h"

void capture_raw_values (ADC_HandleTypeDef* hadc, uint16_t* adc_values, size_t num_of_slots);
void map_raw_vals_to_digits (uint16_t* adc_values, uint8_t* digits, size_t num_of_slots);
bool check_slots_full (uint8_t* digits, size_t num_of_slots);


bool check_15 ();

#endif /* INC_SLOT_ADC_H_ */
