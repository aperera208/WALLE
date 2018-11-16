/*
 * motor_driver.h
 *
 *  Created on: Sep 21, 2018
 *      Author: Alex Perera
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

#include <stdint.h>
#include "timer_a.h"
#include "gpio.h"
#include "controller.h"

#define MOTOR_TIMER_BASE    TIMER_A0_BASE
#define MOTOR_TIMER         TIMER_A0

#define MOTOR_GPIO_PORT     GPIO_PORT_P2

#define LEFT_FW_GPIO_PIN    GPIO_PIN7
#define LEFT_BW_GPIO_PIN    GPIO_PIN6
#define RIGHT_FW_GPIO_PIN   GPIO_PIN5
#define RIGHT_BW_GPIO_PIN   GPIO_PIN4

#define LEFT_FW_REG     4
#define LEFT_BW_REG     3
#define RIGHT_FW_REG    2
#define RIGHT_BW_REG    1

#define XPOSTHRESH          300
#define XNEGTHRESH          -300
#define YPOSTHRESH          300
#define YNEGTHRESH          -300



void Motors_Init(void);

void Motor_Stop(uint8_t compareRegister);

void Motor_Restart(uint8_t compareRegister);

void Motor_Change_Speed( uint16_t speed, uint8_t reg);

void Motor_Update(packet_t cont_state);

void Motor_Update_Thresh(packet_t cont_state);

#endif /* MOTOR_DRIVER_H_ */