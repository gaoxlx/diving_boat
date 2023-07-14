#ifndef MOTOR_SHIP_H
#define MOTOR_SHIP_H

#include "main.h"
#include "servoTo.h"
#include "gpio.h"
#include "usart.h"
#include "dma.h"

#define PUSH_TIME 500
#define PULL_TIME 500
#define MAX_SPEED 135
#define MIN_SPEED 45
#define STOP_SPEED 45
#define LOW_SPEED 75
#define MID_SPEED 105
#define HIGH_SPEED 135
#define BOAT_SERVO 't'
#define BOAT_UP '8'
#define BOAT_DOWN '2'
#define BOAT_GO 'w'
#define BOAT_LEFT 'a'
#define BOAT_RIGHT 'd'
#define BOAT_GO_LEFT 'q'
#define BOAT_GO_RIGHT 'e'
#define BOAT_STOP 's'
#define BOAT_CLO_ADJ 'c'
#define BOAT_COUNCLO_ADJ 'z'
#define BOAT_OVER '0'

//extern Servo_init Servo_ud1;
//extern Servo_init Servo_ud2;
//extern Servo_init Servo_lr1;
//extern Servo_init Servo_lr2;
//extern Servo_init Motor_l1;
//extern Servo_init Motor_l2;
//extern Servo_init Motor_r1;
//extern Servo_init Motor_r2;
//extern Servo_init Motor_MC;

void boat_down();
void boat_up();
void boat_stop(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void boat_motor_init(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void boat_left(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void boat_right(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void boat_go_left(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void boat_go_right(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void boat_go(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void Clockwise_adjust(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void Counterclockwise_adjust(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2);
void con_boat_state(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2,
                    Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2);
void boat_control(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2,
                    Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2);
void boat_servo_init(Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2);
void boat_servo_test(Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2);
void boat_over(Servo_init* motor_r1,Servo_init* motor_r2,Servo_init* motor_l1,Servo_init* motor_l2,
                Servo_init* servo_ud1,Servo_init* servo_ud2,Servo_init* servo_lr1,Servo_init* servo_lr2);

#endif