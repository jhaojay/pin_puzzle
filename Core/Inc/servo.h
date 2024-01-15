/*
 * servo.h
 *
 *  Created on: Dec 1, 2023
 *      Author: phi
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include <stdint.h>
#include "tim.h"

#define htim htim1

#define DESIRED_ARR (20000-1)  // (1MHz clock / wanted 50Hz PWM) - 1
#define NEG_90 (0.128 * (DESIRED_ARR))
#define POS_90 (0.03 * (DESIRED_ARR))

void init_servo ();
void turn_servo (int8_t degrees);

#endif /* INC_SERVO_H_ */
