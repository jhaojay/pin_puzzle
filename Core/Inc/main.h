/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED6_Pin GPIO_PIN_13
#define LED6_GPIO_Port GPIOC
#define LED7_Pin GPIO_PIN_14
#define LED7_GPIO_Port GPIOC
#define LED8_Pin GPIO_PIN_15
#define LED8_GPIO_Port GPIOC
#define LED9_Pin GPIO_PIN_0
#define LED9_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOF
#define LED5_Pin GPIO_PIN_0
#define LED5_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_1
#define LED4_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOC
#define SLOT7_Pin GPIO_PIN_3
#define SLOT7_GPIO_Port GPIOA
#define SAMP_BTN_Pin GPIO_PIN_4
#define SAMP_BTN_GPIO_Port GPIOF
#define SAMP_BTN_EXTI_IRQn EXTI4_15_IRQn
#define SAMP_LED_Pin GPIO_PIN_5
#define SAMP_LED_GPIO_Port GPIOF
#define SLOT5_Pin GPIO_PIN_4
#define SLOT5_GPIO_Port GPIOA
#define SLOT3_Pin GPIO_PIN_5
#define SLOT3_GPIO_Port GPIOA
#define SLOT4_Pin GPIO_PIN_6
#define SLOT4_GPIO_Port GPIOA
#define SLOT2_Pin GPIO_PIN_7
#define SLOT2_GPIO_Port GPIOA
#define SLOT6_Pin GPIO_PIN_4
#define SLOT6_GPIO_Port GPIOC
#define SLOT1_Pin GPIO_PIN_5
#define SLOT1_GPIO_Port GPIOC
#define SLOT8_Pin GPIO_PIN_0
#define SLOT8_GPIO_Port GPIOB
#define SLOT9_Pin GPIO_PIN_1
#define SLOT9_GPIO_Port GPIOB
#define DR1_SP_IN4_Pin GPIO_PIN_12
#define DR1_SP_IN4_GPIO_Port GPIOB
#define DR1_SP_IN3_Pin GPIO_PIN_13
#define DR1_SP_IN3_GPIO_Port GPIOB
#define DR1_SP_IN2_Pin GPIO_PIN_14
#define DR1_SP_IN2_GPIO_Port GPIOB
#define DR1_SP_IN1_Pin GPIO_PIN_15
#define DR1_SP_IN1_GPIO_Port GPIOB
#define DR2_SV_PWM_Pin GPIO_PIN_8
#define DR2_SV_PWM_GPIO_Port GPIOA
#define MAN_DR2_SWT_Pin GPIO_PIN_6
#define MAN_DR2_SWT_GPIO_Port GPIOB
#define MAN_DR2_SWT_EXTI_IRQn EXTI4_15_IRQn
#define MAN_DR1_SWT_Pin GPIO_PIN_9
#define MAN_DR1_SWT_GPIO_Port GPIOB
#define MAN_DR1_SWT_EXTI_IRQn EXTI4_15_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
