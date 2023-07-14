#ifndef SERVOTO_H
#define SERVOTO_H

#include "main.h"


//每个时钟对应一个舵机
typedef struct Servo_init {
	TIM_HandleTypeDef  *htim;		//这个用哪个时钟
	uint32_t 					pulse_channel;		
	uint32_t                    Period;
	GPIO_TypeDef 			    *pwm_gpio;					//控制方向用的GPIO
	uint32_t 				    pwm_pin;					//控制方向用的PIN
    uint32_t speed;
    uint32_t  currentposition; 
} Servo_init;

//typedef struct Servo_init {
//	Servo_pin *s;
//	
//	
//}Servo_init;

void servo_Pin_Init(Servo_init* servo_init,TIM_HandleTypeDef *servo_tim,GPIO_TypeDef* pwm_gpiox, uint32_t pwm_pin,uint32_t channel);

//void Servo_state_Init(Servo_pin* servo_pin,Servo_init* servo_init,uint32_t speed);

void Servo_To(Servo_init* servo_init,uint32_t angle);

void Servo_Speed_to(Servo_init* servo_init,uint32_t angle);

uint32_t Servo_currentposition(Servo_init* servo_init);

#endif