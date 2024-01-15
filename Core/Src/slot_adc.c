/*
 * slot_adc.c
 *
 *  Created on: Nov 24, 2023
 *      Author: phi
 */

#include "slot_adc.h"

//uint8_t channels[9] = {3, 4, 5, 6, 7, 8, 9, 14, 15};

//uint8_t channels[9] = {4, 3, 5, 8, 6, 9, 7, 14, 15};
uint8_t channels[9] = {7, 14, 15, 4, 5, 6, 3, 8, 9};

void adc_select_channel(ADC_HandleTypeDef* hadc, uint8_t channel)
{
    ADC_ChannelConfTypeDef s_config = {0};
    // Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
    s_config.Channel = channel;
    s_config.Rank = ADC_RANK_CHANNEL_NUMBER;
    s_config.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
    if (HAL_ADC_ConfigChannel(hadc, &s_config) != HAL_OK)
    {
    	Error_Handler();
    }
}


void adc_disable_channel (ADC_HandleTypeDef* hadc, uint8_t channel)
{
    ADC_ChannelConfTypeDef s_config = {0};
    // Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
    s_config.Channel = channel;
    s_config.Rank = ADC_RANK_NONE;
    s_config.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
    if (HAL_ADC_ConfigChannel(hadc, &s_config) != HAL_OK)
    {
    	Error_Handler();
    }
}

void capture_raw_values (ADC_HandleTypeDef* hadc, uint16_t *adc_values, size_t num_of_slots)
{
		// sampling keys inserted into the slots and put the values into adc_values[]

	for (size_t i = 0; i < num_of_slots; i++) {
			uint8_t channel = channels[i];
			adc_select_channel(hadc, channel);
			HAL_ADC_Start(hadc);
			HAL_ADC_PollForConversion(hadc, 1000);
			adc_values[i] = HAL_ADC_GetValue(hadc);
			adc_disable_channel(hadc, channel);
	}
	HAL_ADC_Stop(hadc);
}

void map_raw_vals_to_digits(uint16_t* adc_values, uint8_t* digits, size_t num_of_slots) {
    // Reference ADC values corresponding to specific digits
    uint16_t reference_adc_values[11] = {0, 340, 740, 1170, 1600, 1985, 2390, 2840, 3190, 3620, 4030};

    // Mapped digits for the respective ADC values
    uint8_t mapped_digits[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 0 means shorted, 10 means no key is inserted

    // Define a threshold for the maximum value
    uint16_t max_value_threshold = 20; // Example threshold

    // Iterate over each ADC value to convert it to its corresponding digit
    for (size_t i = 0; i < num_of_slots; i++) {
        uint16_t current_adc_value = adc_values[i];

        // Handle values close to the upper limit
        if (current_adc_value > reference_adc_values[10] - max_value_threshold) {
            digits[i] = 10;  // no key inserted
            continue;
        }

        if (current_adc_value <= 0) {
            digits[i] = 0;  // shorted
            continue;
        }

        // Find the closest reference ADC value
        for (size_t ref_i = 1; ref_i < 11; ref_i++) {
            if (current_adc_value <= reference_adc_values[ref_i]) {
                uint16_t diff_with_previous = current_adc_value - reference_adc_values[ref_i - 1];
                uint16_t diff_with_current = reference_adc_values[ref_i] - current_adc_value;

                // Choose the closer reference, whether it's the current or the previous one
                digits[i] = (diff_with_previous < diff_with_current) ? mapped_digits[ref_i - 1] : mapped_digits[ref_i];
                break; // Exit the loop once the closest reference is found
            }
        }
    }
}


bool check_slots_full (uint8_t* digits, size_t num_of_slots)
{
	for (size_t i = 0; i < num_of_slots; i++) {
		if (digits[i] == 10)
			return false;
	}
	return true;
}



bool check_15 ()
{

}
