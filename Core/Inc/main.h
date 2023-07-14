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
#include "stm32f1xx_hal.h"

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
#define servo_ud1_Pin GPIO_PIN_0
#define servo_ud1_GPIO_Port GPIOA
#define servo_ud2_Pin GPIO_PIN_1
#define servo_ud2_GPIO_Port GPIOA
#define servo_lr1_Pin GPIO_PIN_2
#define servo_lr1_GPIO_Port GPIOA
#define servo_lr2_Pin GPIO_PIN_3
#define servo_lr2_GPIO_Port GPIOA
#define motor_rm_Pin GPIO_PIN_6
#define motor_rm_GPIO_Port GPIOA
#define motor_lm_Pin GPIO_PIN_7
#define motor_lm_GPIO_Port GPIOA
#define motor_MC_Pin GPIO_PIN_0
#define motor_MC_GPIO_Port GPIOB
#define rod_pull_Pin GPIO_PIN_14
#define rod_pull_GPIO_Port GPIOB
#define rod_push_Pin GPIO_PIN_15
#define rod_push_GPIO_Port GPIOB
#define motor_l2_Pin GPIO_PIN_8
#define motor_l2_GPIO_Port GPIOA
#define motor_l1_Pin GPIO_PIN_9
#define motor_l1_GPIO_Port GPIOA
#define motor_r2_Pin GPIO_PIN_10
#define motor_r2_GPIO_Port GPIOA
#define motor_r1_Pin GPIO_PIN_11
#define motor_r1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
