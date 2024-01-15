/*
 * stepper.h
 *
 * Created on: Nov 24, 2023
 * Author: phi
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

#include "stm32f030x8.h"
#include <stdint.h>
#include <stdbool.h>
#include "tim.h"

// modify these to match the MX configurations
#define TIM htim1
#define IN1_PIN DR1_SP_IN1_Pin
#define IN2_PIN DR1_SP_IN2_Pin
#define IN3_PIN DR1_SP_IN3_Pin
#define IN4_PIN DR1_SP_IN4_Pin
#define IN1_PORT DR1_SP_IN1_GPIO_Port
#define IN2_PORT DR1_SP_IN2_GPIO_Port
#define IN3_PORT DR1_SP_IN3_GPIO_Port
#define IN4_PORT DR1_SP_IN4_GPIO_Port

#define OPEN_ROTATION 1000
#define CLOSE_ROTATION 1000
#define DELAY_US 1400
#define CLOCKWISE 1
#define COUNTER_CLOCKWISE 0

/* Structure definition for stepper configuration */
typedef struct
{
    GPIO_TypeDef *gpio_in[4];
    uint16_t pin_in[4];
} StepperConfig;


void stepper_rotate(uint16_t steps, uint16_t delay_us, bool is_clockwise);

#endif /* INC_STEPPER_H_ */
