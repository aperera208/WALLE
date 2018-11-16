/*
 * pwn.h
 *
 *  Created on: Sep 7, 2018
 *      Author: Alex Perera
 */

#ifndef _PWM_H_
#define _PWM_H_

#include <stdint.h>
#include "timer_a.h"


void PWM_INIT_MOTOR( uint32_t timerBase, uint_fast16_t dutyCycle, uint_fast16_t timerPeriod, uint_fast16_t compareRegister,
              uint_fast8_t selectedPort, uint_fast16_t selectedPins, uint8_t GPIO_function);

void PWM_INIT_SERVO(uint32_t timerBase, uint_fast16_t dutyCycle, uint_fast16_t timerPeriod, uint_fast16_t compareRegister,
                    uint_fast8_t selectedPort, uint_fast16_t selectedPins, uint8_t GPIO_function);

void Stop_Timer(Timer_A_Type * timer, uint_fast16_t compareRegister);

void Restart_Timer(Timer_A_Type * timer, uint_fast16_t compareRegister);

#endif /* _PWM_H_ */
