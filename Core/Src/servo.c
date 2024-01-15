/*
 * servo.c
 *
 *  Created on: Dec 1, 2023
 *      Author: phi
 */

#include "servo.h"

void init_servo ()
{
	htim.Instance->ARR = DESIRED_ARR;
	HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1);
}

void turn_servo (int8_t degrees)
{
    uint16_t desired_ccr;

    // Map degrees (-90 to +90) to CCR (NEG_90 to POS_90)
    desired_ccr = (uint16_t)((degrees + 90) * (POS_90 - NEG_90) / 180 + NEG_90);

    htim.Instance->CCR1 = desired_ccr;
}
