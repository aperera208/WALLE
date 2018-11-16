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

packet_t cont_state;
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

    XBEE_UART_INIT();
    init_controller();

    while(1)
    {
        cont_state = get_controller_state();
        XBEE_SEND_CONTROLLER_STATE(cont_state);

        switch(cont_state.buttons)
        {
            case 0x07:
                if(mode == manual)
                {
                    break;
                }
                prevmode = mode;
                mode = manual;
                LCD_Menu_UnselBottom();
                LCD_Menu_UnselRight();
                LCD_Menu_UnselTop();
                LCD_Menu_SelLeft();
                break;

            case 0x0B:
                if(mode == parte)
                {
                    break;
                }
                prevmode = mode;
                mode = parte;
                LCD_Menu_UnselLeft();
                LCD_Menu_UnselRight();
                LCD_Menu_UnselTop();
                LCD_Menu_SelBottom();
                break;

            case 0x0E:
                if(mode == picture)
                {
                    break;
                }
                prevmode = mode;
                mode = picture;
                LCD_Menu_UnselBottom();
                LCD_Menu_UnselLeft();
                LCD_Menu_UnselTop();
                LCD_Menu_SelRight();
                break;

            case 0x0D:
                if(mode == automatic)
                {
                    break;
                }
                prevmode = mode;
                mode = automatic;
                LCD_Menu_UnselBottom();
                LCD_Menu_UnselLeft();
                LCD_Menu_UnselRight();
                LCD_Menu_SelTop();
                break;

            case 0x06:
                if(mode == picture)
                {
                    mode = prevmode;
                    prevmode = picture;
                    cont_state.buttons = (uint8_t)mode;
                }

            default:
                break;
        }
    }
}



