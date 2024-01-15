/*
 * led_indicator.c
 *
 *  Created on: Nov 24, 2023
 *      Author: phi
 */

#include <interface.h>

void init_leds ()
{
//    HAL_GPIO_WritePin(LED1_Port, LED1, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(LED2_Port, LED2, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(LED3_Port, LED3, GPIO_PIN_RESET);
}

void turn_on_led_number (uint8_t n)
{
	// n = [1, 9]

	switch (n) {
	case 1:
	    HAL_GPIO_WritePin(LED1_Port, LED1, GPIO_PIN_SET);
		break;
	case 2:
	    HAL_GPIO_WritePin(LED2_Port, LED2, GPIO_PIN_SET);
		break;
	case 3:
	    HAL_GPIO_WritePin(LED3_Port, LED3, GPIO_PIN_SET);
		break;
	case 4:
	    HAL_GPIO_WritePin(LED4_Port, LED4, GPIO_PIN_SET);
		break;
	case 5:
	    HAL_GPIO_WritePin(LED5_Port, LED5, GPIO_PIN_SET);
		break;
	case 6:
	    HAL_GPIO_WritePin(LED6_Port, LED6, GPIO_PIN_SET);
		break;
	case 7:
	    HAL_GPIO_WritePin(LED7_Port, LED7, GPIO_PIN_SET);
		break;
	case 8:
	    HAL_GPIO_WritePin(LED8_Port, LED8, GPIO_PIN_SET);
		break;
	case 9:
	    HAL_GPIO_WritePin(LED9_Port, LED9, GPIO_PIN_SET);
		break;

	}
}

void turn_off_led_number (uint8_t n)
{
	// n = [1, 9]

	switch (n) {
	case 1:
	    HAL_GPIO_WritePin(LED1_Port, LED1, GPIO_PIN_RESET);
		break;
	case 2:
	    HAL_GPIO_WritePin(LED2_Port, LED2, GPIO_PIN_RESET);
		break;
	case 3:
	    HAL_GPIO_WritePin(LED3_Port, LED3, GPIO_PIN_RESET);
		break;
	case 4:
	    HAL_GPIO_WritePin(LED4_Port, LED4, GPIO_PIN_RESET);
		break;
	case 5:
	    HAL_GPIO_WritePin(LED5_Port, LED5, GPIO_PIN_RESET);
		break;
	case 6:
	    HAL_GPIO_WritePin(LED6_Port, LED6, GPIO_PIN_RESET);
		break;
	case 7:
	    HAL_GPIO_WritePin(LED7_Port, LED7, GPIO_PIN_RESET);
		break;
	case 8:
	    HAL_GPIO_WritePin(LED8_Port, LED8, GPIO_PIN_RESET);
		break;
	case 9:
	    HAL_GPIO_WritePin(LED9_Port, LED9, GPIO_PIN_RESET);
		break;

	}
}

void toggle_led_number (uint8_t n)
{
	// n = [1, 9]

	switch (n) {
	case 1:
		HAL_GPIO_TogglePin(LED1_Port, LED1);
		break;
	case 2:
		HAL_GPIO_TogglePin(LED2_Port, LED2);
		break;
	case 3:
		HAL_GPIO_TogglePin(LED3_Port, LED3);
		break;
	case 4:
		HAL_GPIO_TogglePin(LED4_Port, LED4);
		break;
	case 5:
		HAL_GPIO_TogglePin(LED5_Port, LED5);
		break;
	case 6:
		HAL_GPIO_TogglePin(LED6_Port, LED6);
		break;
	case 7:
		HAL_GPIO_TogglePin(LED7_Port, LED7);
		break;
	case 8:
		HAL_GPIO_TogglePin(LED8_Port, LED8);
		break;
	case 9:
		HAL_GPIO_TogglePin(LED9_Port, LED9);
		break;

	}
}

bool is_led_on (uint8_t n)
{
	// n = [1, 9]

	switch (n) {
	case 1:
		return HAL_GPIO_ReadPin(LED1_Port, LED1);
		break;
	case 2:
		return HAL_GPIO_ReadPin(LED2_Port, LED2);
		break;
	case 3:
		return HAL_GPIO_ReadPin(LED3_Port, LED3);
		break;
	case 4:
		return HAL_GPIO_ReadPin(LED4_Port, LED4);
		break;
	case 5:
		return HAL_GPIO_ReadPin(LED5_Port, LED5);
		break;
	case 6:
		return HAL_GPIO_ReadPin(LED6_Port, LED6);
		break;
	case 7:
		return HAL_GPIO_ReadPin(LED7_Port, LED7);
		break;
	case 8:
		return HAL_GPIO_ReadPin(LED8_Port, LED8);
		break;
	case 9:
		return HAL_GPIO_ReadPin(LED9_Port, LED9);
		break;
	default:
		return 0;
	}}

void control_all_num_leds (bool state)
{

	if (state) {
		for (size_t i = 0; i < 9; i++) {
			turn_on_led_number(i+1);
		}
		turn_on_sample_led();
	} else {
		for (size_t i = 0; i < 9; i++) {
			turn_off_led_number(i+1);
		}
		turn_off_sample_led();
	}
}

void turn_on_sample_led ()
{
	HAL_GPIO_WritePin(SAMP_LED_Port, SAMP_LED, GPIO_PIN_SET);
}

void turn_off_sample_led ()
{
	HAL_GPIO_WritePin(SAMP_LED_Port, SAMP_LED, GPIO_PIN_RESET);
}
