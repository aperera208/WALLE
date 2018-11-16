#include "BSP.h"

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

extern volatile packet_t cont_state;
extern char jpg[3000];
extern int length;
extern char length_h[1];
extern char length_l[1];
mode_t prevmode = sleeping;
mode_t mode = sleeping;

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

    Motors_Init();
    XBEE_UART_INIT();
//    UART_initforcamera();
//    Wifi_Init_UART();

    //GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0);

    while(1)
    {
        switch(cont_state.buttons)
        {
            case 0x07:
                if(mode == manual)
                {
                    break;
                }
                prevmode = mode;
                mode = manual;
                break;

            case 0x0B:
                if(mode == parte)
                {
                    break;
                }
                prevmode = mode;
                mode = parte;
                break;

            case 0x0E:
                if(mode == picture)
                {
                    break;
                }
                prevmode = mode;
                mode = picture;
//              Take_Picture();
//              Wifi_Send_Pic(jpg, length_h, length_l, length);
                cont_state.buttons = 0x0E;
                XBEE_SEND_CONTROLLER_STATE(cont_state);
                break;

            case 0x0D:
                if(mode == automatic)
                {
                    break;
                }
                prevmode = mode;
                mode = automatic;
                break;

            default:
                break;
        }

        switch (mode)
        {
            case manual:
                //Motor_Update(cont_state);
                Motor_Update_Thresh(cont_state);
                break;

            case automatic:

                break;

            case parte:

                break;
        }

    }
}




