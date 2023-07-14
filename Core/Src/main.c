/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "servoTo.h"
#include "motor_ship.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
Servo_init Servo_ud1;
Servo_init Servo_ud2;
Servo_init Servo_lr1;
Servo_init Servo_lr2;
Servo_init Motor_l1;
Servo_init Motor_l2;
Servo_init Motor_r1;
Servo_init Motor_r2;
Servo_init Motor_MC;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
    servo_Pin_Init(&Servo_ud1,&htim2,servo_ud1_GPIO_Port,servo_ud1_Pin,TIM_CHANNEL_1);
    servo_Pin_Init(&Servo_ud2,&htim2,servo_ud2_GPIO_Port,servo_ud2_Pin,TIM_CHANNEL_2);
    servo_Pin_Init(&Servo_lr1,&htim2,servo_lr1_GPIO_Port,servo_lr1_Pin,TIM_CHANNEL_3);
    servo_Pin_Init(&Servo_lr2,&htim2,servo_lr2_GPIO_Port,servo_lr2_Pin,TIM_CHANNEL_4);
    servo_Pin_Init(&Motor_l2,&htim1,motor_l2_GPIO_Port,motor_l2_Pin,TIM_CHANNEL_1);
    servo_Pin_Init(&Motor_l1,&htim1,motor_l1_GPIO_Port,motor_l1_Pin,TIM_CHANNEL_2);
    servo_Pin_Init(&Motor_r2,&htim1,motor_r2_GPIO_Port,motor_r2_Pin,TIM_CHANNEL_3);
    servo_Pin_Init(&Motor_r1,&htim1,motor_r1_GPIO_Port,motor_r1_Pin,TIM_CHANNEL_4);
    servo_Pin_Init(&Motor_MC,&htim3,motor_MC_GPIO_Port,motor_MC_Pin,TIM_CHANNEL_3);
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(rod_pull_GPIO_Port,rod_pull_Pin,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(rod_push_GPIO_Port,rod_push_Pin,GPIO_PIN_RESET);
  boat_motor_init(&Motor_l1,&Motor_l2,&Motor_r1,&Motor_r2);
  boat_servo_init(&Servo_ud1,&Servo_ud2,&Servo_lr1,&Servo_lr2);
  uint8_t speed_motor = 45;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
   uint8_t toangle=0;
   int i;
  while (1)
  {  

      
      
      boat_control(&Motor_l1,&Motor_l2,&Motor_r1,&Motor_r2,&Servo_ud1,&Servo_ud2,&Servo_lr1,&Servo_lr2);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//        if(recv_end_flag == 1)  //接收完成标志
//		{
//			//HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"okni",4);
//			DMA_Usart1_Send(rx_buffer, rx_len);
//            HAL_Delay(1);
//			recv_end_flag = 0;//清除接收结束标志�?
//            con_boat_state(&Motor_r1,&Motor_r2,&Motor_l1,&Motor_l2);
//        }
//		HAL_UART_Receive_DMA(&huart1,rx_buffer,BUFFER_SIZE);//重新打开DMA接收   
//        Servo_To(&Motor_l1,180);
//        HAL_Delay(1000);
//        Servo_To(&Motor_l1,0);
//        HAL_Delay(1000);        
  }
  

 
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
