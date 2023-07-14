#include "servoTo.h"

void servo_Pin_Init(Servo_init* servo_pin,TIM_HandleTypeDef *servo_tim,GPIO_TypeDef* pwm_gpiox, uint32_t pwm_pin,uint32_t channel)
{
	servo_pin->htim=servo_tim;
	servo_pin->pwm_gpio=pwm_gpiox;
	servo_pin->pwm_pin=pwm_pin;
	servo_pin->pulse_channel=channel;
	servo_pin->Period=servo_tim->Init.Period;
}

//void Servo_state_Init(Servo_pin* servo_pin,Servo_init* servo_init,uint32_t speed)
//{
//	servo_init->s=servo_pin;
//	servo_init->currentposition=90;
//	servo_init->speed=speed;
//}

void Servo_To(Servo_init* servo_init,uint32_t angle)
{
	HAL_TIM_PWM_Start(servo_init->htim,servo_init->pulse_channel);
	__HAL_TIM_SET_COMPARE(servo_init->htim,servo_init->pulse_channel,(servo_init->htim->Init.Period*0.5+servo_init->htim->Init.Period*angle*2/180)/20);//PERIOD/20*(0.5+angle*2/180)
	servo_init->currentposition=angle;
}

void Servo_Speed_to(Servo_init* servo_init,uint32_t angle)
{
	HAL_TIM_PWM_Start(servo_init->htim,servo_init->pulse_channel);
	
	__HAL_TIM_SET_COMPARE(servo_init->htim,servo_init->pulse_channel,(servo_init->htim->Init.Period*0.5+servo_init->htim->Init.Period*angle*2/180)/20);//PERIOD/20*(0.5+angle*2/180)
	servo_init->currentposition=angle;
}

uint32_t Servo_currentposition(Servo_init* servo_init)
{
	return servo_init->currentposition;
}
	
