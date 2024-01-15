/*
 * my_main.c
 *
 *  Created on: Nov 21, 2023
 *      Author: phi
 */

#include <interface.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "gpio.h"
#include "usart.h"
#include "adc.h"
#include "tim.h"

#include "slot_adc.h"
#include "level.h"
#include "interface.h"


char msg[100] = {'\0'};
uint16_t raw_vals[9] = {0};
uint8_t digits[9] = {0};

bool level_clear_blink_flag = false;
bool ready_to_sample_level_1_flag = false;
bool ready_to_sample_level_2_flag = false;

bool level_1_complete_flag = false;
bool level_2_complete_flag = false;

size_t current_level = 1;


int main ()
{
	SystemClock_Config();
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_ADC_Init();
	MX_TIM1_Init();

//	HAL_TIM_Base_Start(&htim1);




	init_levels();




	while(1) {
		if (level_1_complete_flag == true) {
			level_clear_blink();
			current_level = 2;
			open_door_1();
			level_1_complete_flag = false;
		}

		if (level_2_complete_flag == true) {
			level_clear_blink();
			HAL_Delay(200);
			control_all_num_leds(1);
			turn_on_sample_led();
			return 0;
		}

		HAL_Delay(500);  // how fast the slots should sample

		capture_raw_values(&hadc, raw_vals, 9);
		map_raw_vals_to_digits(raw_vals, digits, 9);

		char digit_info[200]; // Adjust the size as needed
		int offset = 0;

		for(int i = 0; i < 9; i++) {
			offset += sprintf(digit_info + offset, "%u ", digits[i]);
		}

		sprintf(digit_info + offset, "\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)digit_info, strlen(digit_info), HAL_MAX_DELAY);

		if (current_level == 1) {
				sprintf(msg, "In level 1: \n");
				HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
			if (are_first_6_slots_inserted(digits)) {
				sprintf(msg, "Ready to sample.\n");
				HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				turn_on_sample_led();
				ready_to_sample_level_1_flag = true;
			} else {
				sprintf(msg, "first 6 slots are NOT inserted.\n");
				HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				turn_off_sample_led();
				ready_to_sample_level_1_flag = false;
			}
		} else if ( current_level == 2) {
			if (are_all_slots_inserted(digits)) {
				sprintf(msg, "Ready to sample all slots.\n");
				HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				turn_on_sample_led();
				ready_to_sample_level_2_flag = true;
			} else {
				sprintf(msg, "Not all slots are inserted.\n");
				HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				turn_off_sample_led();
				ready_to_sample_level_2_flag = false;
			}
		}

		if (level_clear_blink_flag) {
			level_clear_blink();
			level_clear_blink_flag = false;
		}
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	static uint32_t last_press_time = 0;
	uint32_t current_time = HAL_GetTick();

	if (GPIO_Pin == SAMP_BTN_Pin) {
		if (current_time - last_press_time >= 500) {
			last_press_time = current_time;

			sprintf(msg, "Sampling Slots\n");
			HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);


			if (current_level == 1) {
				if (!ready_to_sample_level_1_flag) return;

				uint8_t num1 = find_digital_root(digits[0], digits[1], digits[2]);
				uint8_t num2 = find_digital_root(digits[3], digits[4], digits[5]);
				toggle_led_number(num1);
				toggle_led_number(num2);
				sprintf(msg, "Digital roots are: %u, %u\n", num1, num2);
				HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

				if (is_level_1_clear()) {
					sprintf(msg, "Level 1 is complete!\n");
					HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
					level_1_complete_flag = true;
				} else {
					sprintf(msg, "Level 1 is NOT yet clear\n");
					HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				}

			} else if (current_level == 2) {
				if (!ready_to_sample_level_2_flag) return;
				if (is_magic_square_solved(digits)) {
					level_2_complete_flag = true;
					sprintf(msg, "Level 2 solved!\n");
					HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				} else {
					sprintf(msg, "Level 2 NOT yet solved!\n");
					HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
				}

			}
		}
	} else if (GPIO_Pin == MAN_DR1_SWT_Pin) {
		if (HAL_GPIO_ReadPin(MAN_DR1_SWT_GPIO_Port, MAN_DR1_SWT_Pin) == GPIO_PIN_SET) {
			sprintf(msg, "Opening DR1 \r\n");
			open_door_1();
		} else {
			sprintf(msg, "Closing DR1 \r\n");
			close_door_1();
		}
		HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	} else if (GPIO_Pin == MAN_DR2_SWT_Pin) {
		if (HAL_GPIO_ReadPin(MAN_DR2_SWT_GPIO_Port, MAN_DR2_SWT_Pin) == GPIO_PIN_SET) {
			sprintf(msg, "Opening DR2 \r\n");
			open_door_2();
		} else {
			sprintf(msg, "Closing DR2 \r\n");
			close_door_2();
		}
		HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	}
}

