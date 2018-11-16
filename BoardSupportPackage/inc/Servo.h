/*
 * Servo.h
 *
 *  Created on: Oct 17, 2018
 *      Author: Alex Perera
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <stdint.h>
#include "gpio.h"
#include "timer_a.h"
#include "pwm.h"

#define SERVO_TIMER         (Timer_A_Type *)TIMER_A1
#define RIGHT_ARM           4
#define LEFT_ARM            3
#define HEAD                2


void Servo_Init();

void Servo_Stop(uint8_t compareRegister);

void Servo_Restart(uint8_t compareRegister);

void Servo_Change_Position(Timer_A_Type * servo_timer, uint16_t pos, uint8_t compareRegister);

void Servo_Up_Down(uint8_t iterations);

void Servo_Up();

#endif /* SERVO_H_ */
