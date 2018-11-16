/*
 * UART.c
 *
 *  Created on: Oct 24, 2018
 *      Author: Alex Perera
 */

#include "UARTs.h"

bool init_UART(void)
{
    const eUSCI_UART_Config config =
    {

         EUSCI_A_UART_CLOCKSOURCE_SMCLK,                            //         uint_fast8_t selectClockSource;
         19,        // 6,                                                //         uint_fast16_t clockPrescalar;
         0x08,                                                         //         uint_fast8_t firstModReg;
         0x65,        // 0x20,                                             //         uint_fast8_t secondModReg;
         EUSCI_A_UART_NO_PARITY,                                    //         uint_fast8_t parity;
         EUSCI_A_UART_LSB_FIRST,                                    //         uint_fast16_t msborLsbFirst;
         EUSCI_A_UART_ONE_STOP_BIT,                                 //         uint_fast16_t numberofStopBits;
         EUSCI_A_UART_MODE,                                         //         uint_fast16_t uartMode;
         EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION             //         uint_fast8_t overSampling;
    };

    if(UART_initModule(EUSCI_A2_BASE, &config) == false)
    {
        return false;
    }

    if(UART_initModule(EUSCI_A0_BASE, &config) == false)
    {
        return false;
    }

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);     // For Backchannel UART
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);      //TX - Pin 3.3 RX - Pin 3.2


    UART_enableModule(EUSCI_A2_BASE);
    UART_enableModule(EUSCI_A0_BASE);

    return true;
}
