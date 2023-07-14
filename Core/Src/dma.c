/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    dma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
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
#include "dma.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */
void DMA_Usart1_end_flag(void)
{   
         if(recv_end_flag == 1)  //接收完成标志
		{
			
			//HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"okni",4);
			//HAL_UART_Transmit_DMA(&huart1, rx_buffer,rx_len);
			DMA_Usart1_Send(rx_buffer, rx_len);
			//HAL_Delay(1000);
			recv_end_flag = 0;//清除接收结束标志�?
//			for(uint8_t i=0;i<rx_len;i++)
//				{
//					rx_buffer[i]=0;//清接收缓�?
//				}
//				//memset(rx_buffer,0,rx_len);
//                //rx_len = 0;//清除计数
        }
		HAL_UART_Receive_DMA(&huart1,rx_buffer,BUFFER_SIZE);//重新打开DMA接收
}

void DMA_Usart1_Send(uint8_t *buf,uint8_t len)//串口发�?�封�?
{
 if(HAL_UART_Transmit_DMA(&huart1, buf,len)!= HAL_OK)   //判断是否发�?�正常，如果出现异常则进入异常中断函�?
  {
   Error_Handler();
  }

}


void DMA_Usart1_Read(uint8_t *Data,uint8_t len)//串口接收封装
{
	HAL_UART_Receive_DMA(&huart1,Data,len);//重新打开DMA接收
}
/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/* USER CODE BEGIN 2 */

  
/* USER CODE END 2 */

