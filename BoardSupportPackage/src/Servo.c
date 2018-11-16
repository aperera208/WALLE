/*
 * Servo.c
 *
 *  Created on: Oct 17, 2018
 *      Author: Alex Perera
 */

#include "Servo.h"
/*
 * Delay x ms
 */
static void Delay(unsigned long interval)
{
    while(interval > 0)
    {
        __delay_cycles(48000);
        interval--;
    }
}

void Servo_Init()
{
    PWM_INIT_SERVO(TIMER_A1_BASE, 0, 20000, TIMER_A_CAPTURECOMPARE_REGISTER_4, GPIO_PORT_P7, GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);
    PWM_INIT_SERVO(TIMER_A1_BASE, 0, 20000, TIMER_A_CAPTURECOMPARE_REGISTER_3, GPIO_PORT_P7, GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
    PWM_INIT_SERVO(TIMER_A1_BASE, 0, 20000, TIMER_A_CAPTURECOMPARE_REGISTER_2, GPIO_PORT_P7, GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
}

void Servo_Stop(uint8_t compareRegister)
{
    Stop_Timer(SERVO_TIMER, compareRegister);
}


void Servo_Restart(uint8_t compareRegister)
{
    Restart_Timer(SERVO_TIMER, compareRegister);
}

void Servo_Change_Position(Timer_A_Type * servo_timer, uint16_t pos, uint8_t compareRegister)
{
    if(pos < 2500)
    {
        servo_timer->CCR[compareRegister] = pos;
    }
}

void Servo_Up_Down(uint8_t iterations)
{
    for(int j = 0; j < iterations; j++)
    {
        for(int i = 0; i < 82; i++)
        {
            Servo_Change_Position(SERVO_TIMER, 400 + (i*25), RIGHT_ARM);
            Delay(50);
        }

        for(int i = 0; i < 82; i++)
        {
            Servo_Change_Position(SERVO_TIMER, 2450 - (i*25), RIGHT_ARM);
            Delay(50);
        }
    }
}

void Servo_Up()
{
    for(int i = 0; i < 82; i++)
    {
        Servo_Change_Position(SERVO_TIMER, 400 + (i*25), RIGHT_ARM);
        Delay(50);
    }
}
