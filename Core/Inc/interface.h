/*
 * led_indicator.h
 *
 *  Created on: Nov 24, 2023
 *      Author: phi
 */

#ifndef INC_INTERFACE_H_
#define INC_INTERFACE_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

#define SAMP_LED SAMP_LED_Pin
#define LED1 LED1_Pin
#define LED2 LED2_Pin
#define LED3 LED3_Pin
#define LED4 LED4_Pin
#define LED5 LED5_Pin
#define LED6 LED6_Pin
#define LED7 LED7_Pin
#define LED8 LED8_Pin
#define LED9 LED9_Pin

#define SAMP_LED_Port SAMP_LED_GPIO_Port
#define LED1_Port LED1_GPIO_Port
#define LED2_Port LED2_GPIO_Port
#define LED3_Port LED3_GPIO_Port
#define LED4_Port LED4_GPIO_Port
#define LED5_Port LED5_GPIO_Port
#define LED6_Port LED6_GPIO_Port
#define LED7_Port LED7_GPIO_Port
#define LED8_Port LED8_GPIO_Port
#define LED9_Port LED9_GPIO_Port

void init_leds (void);
void turn_on_led_number (uint8_t n);
void toggle_led_number (uint8_t n);
bool is_led_on (uint8_t n);
void turn_on_led_number (uint8_t n);
void turn_off_led_number (uint8_t n);
void control_all_num_leds (bool state);

void turn_on_sample_led ();
void turn_off_sample_led ();

#endif /* INC_INTERFACE_H_ */
