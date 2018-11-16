#include "BSP.h"


const char data[153600] = {0};

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

/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    ClockSys_SetMaxFreq();

    uint32_t CLK = ClockSys_GetSysFreq();
    uint32_t SMCLK = CS_getSMCLK();
    uint32_t ACLK = CS_getACLK();
    uint32_t DCO = CS_getDCOFrequency();

//    Motors_Init();
    //Servo_Init();
    //Servo_Up_Down(3);
    bluetooth_init();


    //InitSensor(GPIO_PORT_P5, GPIO_PIN1, GPIO_PORT_P5, GPIO_PIN0);

    while(1)
    {


//        count = GetSensorReading(GPIO_PORT_P5, GPIO_PIN1, GPIO_PORT_P5, GPIO_PIN0, count);
//        count = 0;

    }
}



