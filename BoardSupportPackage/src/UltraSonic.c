/*
 * UltraSonic.c
 *
 *  Created on: Sep 17, 2018
 *      Author: Alex Perera
 */


#include "UltraSonic.h"
#include "gpio.h"
#include "interrupt.h"

/*
 * Delay x us
 */
static void Delay_US(unsigned long interval)
{
    while(interval > 0)
    {
        __delay_cycles(48);
        interval--;
    }
}


void InitSensor(uint_fast8_t echoPort, uint_fast16_t echoPin, uint_fast8_t trigPort, uint_fast16_t trigPin)
{
    GPIO_setAsInputPin(echoPort, echoPin);
    GPIO_setAsOutputPin(trigPort, trigPin);
    GPIO_setOutputLowOnPin(trigPort, trigPin);
}

uint16_t GetSensorReading(uint_fast8_t echoPort, uint_fast16_t echoPin, uint_fast8_t trigPort, uint_fast16_t trigPin, uint16_t count)
{
    GPIO_setOutputHighOnPin(trigPort, trigPin);
    Delay_US(10);
    GPIO_setOutputLowOnPin(trigPort, trigPin);

    while(GPIO_getInputPinValue(echoPort, echoPin) == 0);

    while(GPIO_getInputPinValue(echoPort, echoPin) == 1)
    {
        count++;
        if(count > 65000)
        {
            count = 0;
            break;
        }
    }

    return count;
}


