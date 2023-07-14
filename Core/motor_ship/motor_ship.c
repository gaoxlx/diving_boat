#include "motor_ship.h"


void boat_motor_init(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,MIN_SPEED);
    Servo_To(motor_r2,MIN_SPEED);
    Servo_To(motor_l1,MIN_SPEED);
    Servo_To(motor_l2,MIN_SPEED);
    HAL_Delay(1000);
    Servo_To(motor_r1,MAX_SPEED);
    Servo_To(motor_r2,MAX_SPEED);
    Servo_To(motor_l1,MAX_SPEED);
    Servo_To(motor_l2,MAX_SPEED);
    HAL_Delay(1000);
    Servo_To(motor_r1,MIN_SPEED);
    Servo_To(motor_r2,MIN_SPEED);
    Servo_To(motor_l1,MIN_SPEED);
    Servo_To(motor_l2,MIN_SPEED);
}

void boat_down()
{
    HAL_GPIO_WritePin(rod_pull_GPIO_Port,rod_pull_Pin,GPIO_PIN_SET);
    HAL_Delay(PULL_TIME);
    HAL_GPIO_WritePin(rod_pull_GPIO_Port,rod_pull_Pin,GPIO_PIN_RESET);
}

void boat_up()
{
    HAL_GPIO_WritePin(rod_push_GPIO_Port,rod_push_Pin,GPIO_PIN_SET);
    HAL_Delay(PUSH_TIME);
    HAL_GPIO_WritePin(rod_push_GPIO_Port,rod_push_Pin,GPIO_PIN_RESET);
}

void boat_left(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,MID_SPEED);
    Servo_To(motor_r2,MID_SPEED);
    Servo_To(motor_l1,STOP_SPEED);
    Servo_To(motor_l2,STOP_SPEED);
}

void boat_right(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,STOP_SPEED);
    Servo_To(motor_r2,STOP_SPEED);
    Servo_To(motor_l1,MID_SPEED);
    Servo_To(motor_l2,MID_SPEED);
}

void boat_go_left(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,HIGH_SPEED);
    Servo_To(motor_r2,HIGH_SPEED);
    Servo_To(motor_l1,LOW_SPEED);
    Servo_To(motor_l2,LOW_SPEED);
}

void boat_go_right(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,LOW_SPEED);
    Servo_To(motor_r2,LOW_SPEED);
    Servo_To(motor_l1,HIGH_SPEED);
    Servo_To(motor_l2,HIGH_SPEED);    
}

void boat_go(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,MID_SPEED);
    Servo_To(motor_r2,MID_SPEED);
    Servo_To(motor_l1,MID_SPEED);
    Servo_To(motor_l2,MID_SPEED);    
}

void Clockwise_adjust(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    
}

void Counterclockwise_adjust(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    
}

void boat_stop(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2)
{
    Servo_To(motor_r1,STOP_SPEED);
    Servo_To(motor_r2,STOP_SPEED);
    Servo_To(motor_l1,STOP_SPEED);
    Servo_To(motor_l2,STOP_SPEED);
}

void boat_servo_test(Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2)
{
    Servo_To(servo_ud1,120);
    Servo_To(servo_ud2,60);
    HAL_Delay(1000);
    Servo_To(servo_ud1,60);
    Servo_To(servo_ud2,120);
    HAL_Delay(1000);
    Servo_To(servo_ud1,90);
    Servo_To(servo_ud2,90);
    HAL_Delay(1000);
    Servo_To(servo_lr1,120);
    Servo_To(servo_lr2,60);
    HAL_Delay(1000);
    Servo_To(servo_lr1,60);
    Servo_To(servo_lr2,120);
    HAL_Delay(1000);
    Servo_To(servo_lr1,90);
    Servo_To(servo_lr2,90);
}

void con_boat_state(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2,
                    Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2)
{
    uint8_t state = rx_buffer[0];
    switch(state)
    {
        case BOAT_UP: 
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1);          
            boat_up();
        break;
        
        case BOAT_DOWN:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_down();
        break;
        
        case BOAT_GO:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_go(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_GO_LEFT:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_go_left(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_GO_RIGHT:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_go_right(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_LEFT:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_left(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_RIGHT:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_right(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_STOP:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_stop(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_CLO_ADJ:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            Clockwise_adjust(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_COUNCLO_ADJ:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            Counterclockwise_adjust(motor_r1,motor_r2,motor_l1,motor_l2);
        break;
        
        case BOAT_SERVO:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1); 
            boat_servo_test(servo_ud1,servo_ud2,servo_lr1,servo_lr2);
        break;
        
        case BOAT_OVER:
            HAL_UART_Transmit_DMA(&huart1, &state,1);HAL_Delay(1);
            boat_over(motor_r1,motor_r2,motor_l1,motor_l2,servo_ud1,servo_ud2,servo_lr1,servo_lr2);
        break;
        
        default:
            HAL_UART_Transmit_DMA(&huart1,(uint8_t*)"invalid_instruction",19);HAL_Delay(1);
        break;
    }
    
}

void boat_control(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2,
                    Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2)
{
    if(recv_end_flag == 1)  //接收完成标志
		{
			//HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"okni",4);
			DMA_Usart1_Send(rx_buffer, rx_len);
            HAL_Delay(1);
			recv_end_flag = 0;//清除接收结束标志使
            con_boat_state(motor_r1,motor_r2,motor_l1,motor_l2,servo_ud1,servo_ud2,servo_lr1,servo_lr2);
        }
		HAL_UART_Receive_DMA(&huart1,rx_buffer,BUFFER_SIZE);//重新打开DMA接收
}

void boat_servo_init(Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2)
{
    Servo_To(servo_ud1,90);
    Servo_To(servo_ud2,90);
    Servo_To(servo_lr1,90);
    Servo_To(servo_lr2,90);
}

void boat_over(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2,
                Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2)
{
        int i;
      HAL_Delay(1000);
//      
//      for(i=0;i<30;i++)boat_up();
//      HAL_Delay(3000);
      
      for(i=0;i<100;i++)boat_down();
      HAL_Delay(3000);
      
      boat_servo_test(servo_ud1,servo_ud2,servo_lr1,servo_lr2);
      HAL_Delay(10000);
      
      HAL_Delay(2000);
      Servo_To(motor_l1,LOW_SPEED);
      HAL_Delay(2000);
      Servo_To(motor_l1,MID_SPEED);
      HAL_Delay(2000);
      Servo_To(motor_l1,HIGH_SPEED);
      HAL_Delay(2000);
      Servo_To(motor_l1,STOP_SPEED);
}
