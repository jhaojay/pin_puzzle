#include "stepper.h"

// Define the unipolar half-stepping pattern for the stepper motor
const uint8_t UNIPOLAR_HS_PATTERN[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}
};

// Function to create a microsecond delay using a timer
void microDelay(uint16_t delay) {
    __HAL_TIM_SET_COUNTER(&TIM, 0);  // Reset the timer counter
    while (__HAL_TIM_GET_COUNTER(&TIM) < delay);  // Wait for the delay
}

// Function to step the motor according to the provided pattern
void step_motor(const uint8_t* pattern) {
    HAL_GPIO_WritePin(IN1_PORT, IN1_PIN, pattern[0]);
    HAL_GPIO_WritePin(IN2_PORT, IN2_PIN, pattern[1]);
    HAL_GPIO_WritePin(IN3_PORT, IN3_PIN, pattern[2]);
    HAL_GPIO_WritePin(IN4_PORT, IN4_PIN, pattern[3]);
}

// Rotate the stepper motor
void stepper_rotate(uint16_t steps, uint16_t delay_us, bool is_clockwise) {
    if (steps < 0) {
        steps = -steps;  // Convert to positive steps
        is_clockwise = !is_clockwise;  // Invert the direction
    }

    for (int i = 0; i < steps; i++) {
        for (int r = 0; r < 8; r++) {
            int index = is_clockwise ? r : 7 - r;
            step_motor(UNIPOLAR_HS_PATTERN[index]);
            microDelay(delay_us);
        }
    }
}


