/*
 * Wifi.c
 *
 *  Created on: Nov 1, 2018
 *      Author: Alex Perera
 */

#include "Wifi.h"

//extern  int length;

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


bool Wifi_Init_UART()
{
    const eUSCI_UART_Config config =
    {

         EUSCI_A_UART_CLOCKSOURCE_SMCLK,                            //         uint_fast8_t selectClockSource;
         6,        // 6,                                                //         uint_fast16_t clockPrescalar;
         8,                                                         //         uint_fast8_t firstModReg;
         0x20,        // 0x20,                                             //         uint_fast8_t secondModReg;
         EUSCI_A_UART_NO_PARITY,                                    //         uint_fast8_t parity;
         EUSCI_A_UART_LSB_FIRST,                                    //         uint_fast16_t msborLsbFirst;
         EUSCI_A_UART_ONE_STOP_BIT,                                 //         uint_fast16_t numberofStopBits;
         EUSCI_A_UART_MODE,                                         //         uint_fast16_t uartMode;
         EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION             //         uint_fast8_t overSampling;
    };

    if(UART_initModule(EUSCI_A3_BASE, &config) == false)
    {
        return false;
    }

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P9, GPIO_PIN6 | GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);     // For Backchannel UART

    UART_enableModule(EUSCI_A3_BASE);
    //UART_enableInterrupt(EUSCI_A3_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
    //Interrupt_enableMaster();
    //Interrupt_enableInterrupt(INT_EUSCIA3);

    return true;
}


void Wifi_SendtoWifi(char * data, int bytecount)
{
    while(bytecount > 0)
    {
        EUSCI_A3->TXBUF = *data++;
        while(!(EUSCI_A3->IFG & EUSCI_A_IFG_TXIFG));
        bytecount--;
    }
}

void Wifi_ReceivefromWifi(char * data, int bytecount)
{
    for(int i = 0; i < bytecount; i++)
     {
        while(!(EUSCI_A3->IFG & EUSCI_A_IFG_RXIFG));
        data[i] = EUSCI_A3->RXBUF;
     }
}


void Wifi_Send_Pic(char * data, char * length_h, char * length_l, int bytecount)
{
    char image_cmd[1] = {0xA1};
    //char rec[1];
    Wifi_SendtoWifi(image_cmd, 1);
    //Wifi_ReceivefromWifi(rec, 1);

    Delay(5);

    Wifi_SendtoWifi(length_h, 1);

    Wifi_SendtoWifi(length_l-10, 1);

    Wifi_SendtoWifi(data+5, (bytecount-10));

    Delay(5);

    //Wifi_SendtoWifi(data, bytecount);

//    int length_4 = (bytecount-10)/4;
//    char length_4_h[1] = {length_4>>8};
//    char length_4_l[1] = {length_4};
//
//    Wifi_SendtoWifi(length_4_h, 1);
//    Delay(50);
//
//    Wifi_SendtoWifi(length_4_l, 1);
//    Delay(50);
//
//    Wifi_SendtoWifi(data+5, length_4);
//    Delay(50);
//    Wifi_SendtoWifi(data+5+length_4, length_4);
//    Delay(50);
//    Wifi_SendtoWifi(data+5+length_4+length_4, length_4);
//    Delay(50);
//    Wifi_SendtoWifi(data+5+length_4+length_4+length_4, length_4);
//    Delay(50);


}

void EUSCIA3_IRQHandler()
{
    uint32_t status = UART_getEnabledInterruptStatus(EUSCI_A3_BASE);


    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        char rec = EUSCI_A3->RXBUF;

    }



    UART_clearInterruptFlag(EUSCI_A3_BASE, status);
}


