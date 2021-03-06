/*
 * camera.c
 *
 *  Created on: Sep 19, 2018
 *      Author: Alex Perera
 */
#include <stdbool.h>
#include "msp.h"
#include "camera.h"
#include "gpio.h"
#include "i2c.h"
#include "uart.h"
#include "driverlib.h"
#include "i2c_driver.h"

char jpg[3000];
int length;
char length_h[1];
char length_l[1];


void Take_Picture()
{
    char cmp_ratio[CMP_RATIO_SIZE] = CMP_RATIO;
    char cmp_ratio_ret[5];

    char img_size[IMG_160x120_SIZE] = IMG_160x120;
    char img_size_ret[5];

    char read_length[READ_LENGTH_SIZE] = READ_LENGTH;
    char read_length_ret[9];

    char stop_capture[STOP_CAPTURE_SIZE] = STOP_CAPTURE;
    char stop_capture_ret[5];

    char get_image[GET_IMAGE_SIZE] = GET_IMAGE;
    char get_image_ret[5];

    UART_SendtoCamera(img_size, IMG_160x120_SIZE);
    UART_ReceivefromCamera(img_size_ret, 5);

    UART_SendtoCamera(cmp_ratio, CMP_RATIO_SIZE);
    UART_ReceivefromCamera(cmp_ratio_ret, 5);

    UART_SendtoCamera(get_image, GET_IMAGE_SIZE);
    UART_ReceivefromCamera(get_image_ret, 5);

    UART_SendtoCamera(read_length, READ_LENGTH_SIZE);
    UART_ReceivefromCamera(read_length_ret, 9);

    length = ((read_length_ret[7]<<8) | read_length_ret[8]) + 10;
//    if(length > 3500 || length < 0)
//    {
//        length = 0;
//        return;
//    }
    length_l[0] = length;
    length_h[0] = length>>8;

    char read_data[READ_DATA_SIZE] = {0x56, 0x00, 0x32, 0x0C, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, read_length_ret[7],  read_length_ret[8], 0x00, 0x0A};

    UART_SendtoCamera(read_data, READ_DATA_SIZE);
    UART_ReceivefromCamera(jpg, length);

    UART_SendtoCamera(stop_capture, STOP_CAPTURE_SIZE);
    UART_ReceivefromCamera(stop_capture_ret, 5);
}

bool UART_initforcamera()
{
    const eUSCI_UART_Config config =
    {

         EUSCI_A_UART_CLOCKSOURCE_SMCLK,                            //         uint_fast8_t selectClockSource;
         19,        // 6,                                                //         uint_fast16_t clockPrescalar;
         8,                                                         //         uint_fast8_t firstModReg;
         0x65,        // 0x20,                                             //         uint_fast8_t secondModReg;
         EUSCI_A_UART_NO_PARITY,                                    //         uint_fast8_t parity;
         EUSCI_A_UART_LSB_FIRST,                                    //         uint_fast16_t msborLsbFirst;
         EUSCI_A_UART_ONE_STOP_BIT,                                 //         uint_fast16_t numberofStopBits;
         EUSCI_A_UART_MODE,                                         //         uint_fast16_t uartMode;
         EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION             //         uint_fast8_t overSampling;
    };

    if(UART_initModule(EUSCI_A0_BASE, &config) == false)
    {
        return false;
    }

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);     // For Backchannel UART

    UART_enableModule(EUSCI_A0_BASE);

    return true;
}

void UART_SendtoCamera(char * data, int bytecount)
{
    while(bytecount > 0)
    {
        EUSCI_A0->TXBUF = *data++;
        while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
        bytecount--;
    }
}

void UART_ReceivefromCamera( char * data, int bytecount)
{
    for(int i = 0; i < bytecount; i++)
     {
        while(!(EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG));
        data[i] = EUSCI_A0->RXBUF;
     }
}




bool SPI_initforcamera()
{
//    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);
//
//    const eUSCI_SPI_MasterConfig config =
//    {
//         EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
//         MAP_CS_getSMCLK(),
//         12000000,
//         EUSCI_B_SPI_MSB_FIRST,
//         EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,
//         EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH,
//         EUSCI_B_SPI_3PIN
//    };
//
//    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, (GPIO_PIN2|GPIO_PIN5|GPIO_PIN7|GPIO_PIN7), GPIO_PRIMARY_MODULE_FUNCTION);
//    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN2);
//    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN2);
//
//    SPI_initMaster(EUSCI_B2_BASE, &config);
//    SPI_enableModule(EUSCI_B2_BASE);
//
//    return true;

    EUSCI_B2->CTLW0 |= EUSCI_B_CTLW0_SWRST;                                 // Set UCSWRST for configuration

    EUSCI_B2->CTLW0 |= EUSCI_B_CTLW0_MSB    | EUSCI_B_CTLW0_MST  |          // MSB first, Master mode, Synchronous mode,
                       EUSCI_B_CTLW0_MODE_0 | EUSCI_B_CTLW0_SYNC |          // Inactive state is high, 3-pin SPI, 8-bit data
                       EUSCI_B_CTLW0_SSEL_3 | EUSCI_B_CTLW0_CKPL;           // Standard clock,

    EUSCI_B2->BRW = 0;                                                      // Maximum clock speed

    P3->SEL0 |= (BIT5 | BIT6 | BIT7) ;                                     // Set CLK, MOSI, MISO to primary function (EUSCI_B3 SPI)
    P3->SEL1 &= ~(BIT5 | BIT6 | BIT7) ;
    P3->DIR |= (BIT5 | BIT6 | BIT7);                                       // Set to outputs

    P3->SEL0 &= ~(BIT2);                                            // Set LCD CS, TP CS to GPIO outputs
    P3->SEL1 &= ~(BIT2) ;
    P3->DIR |= (BIT2);                                              // Set to outputs

    EUSCI_B2->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;                                // Clear UCSWRST, ready to transmit/receive

    return true;
}


void SPI_SendtoCamera(char * data, int bytecount)
{
    while(bytecount > 0)
    {
        GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN2);
        SPI_transmitData(EUSCI_B2_BASE, *data++);
        while(EUSCI_B2->STATW & EUSCI_B_STATW_SPI_BUSY);
        bytecount--;
        GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN2);
    }


}


uint8_t SPI_RecfromCamera()
{
    return SPI_receiveData(EUSCI_B2_BASE);
}





//                    I2C Write Function                    //
/*
 * Write data to a slave with I2C
 * Param "slaveaddr": Location of slave address to write to
 * Param "memaddr": location to write to within the slave
 * Param "bytecount": number of bytes of data to send
 * Param "data": pointer to array of 8 bit values to send
 */
void I2C_writeforcamera(int slaveaddr, unsigned char memaddr, int bytecount, unsigned char* data )
{

    EUSCI_B1->I2CSA = slaveaddr;                                                // Send slave address to I2C Slave Addr Register

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TR;                                        // Transmit mode

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTT;                                     // Generate start condition, bit1 set
    while(I2C_masterIsStartSent(EUSCI_B1_BASE));
    while(!(EUSCI_B1->CTLW0 & EUSCI_B_CTLW0_TXSTT));                              // Wait for complete address to send

    EUSCI_B1->TXBUF = memaddr;                                                  // Send memory address to slave

    while(!(EUSCI_B1->IFG & EUSCI_B_IFG_TXIFG));                               // EUSCI_B Transmit Interrupt Flag. set when TXBUF is empty

    while(bytecount > 0)                                                          // Keep sending while there's data to send
    {
        EUSCI_B1->TXBUF = *data++;                                              // Send data to slave, increment pointer for next value
        while(!(EUSCI_B1->IFG & EUSCI_B_IFG_TXIFG));                           // EUSCI_B Transmit Interrupt Flag 0. set when TXBUF is empty
        bytecount--;                                                              // Decrement byte counter for while loop
    }

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTP;                                     // Generate stop condition, bit2 set

    while((EUSCI_B1->CTLW0 & EUSCI_B_CTLW0_TXSTP ));                              // Wait for Stop condition to send

    //EUSCI_B2->IFG = 0;                                                           // Clear flags
}



uint8_t I2C_readforcamera(int slaveaddr, uint8_t reg)
{
    EUSCI_B1->I2CSA = (slaveaddr)<<1;                                                // Send slave address to I2C Slave Addr Register

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TR;                                        // Transmit mode

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTT;                                     // Generate start condition, bit1 set
    //while(I2C_masterIsStartSent(EUSCI_B1_BASE));
    while(!(EUSCI_B1->CTLW0 & EUSCI_B_CTLW0_TXSTT));                              // Wait for complete address to send

    EUSCI_B1->TXBUF = reg;                                               // Send register address to slave

    while(!(EUSCI_B1->IFG & EUSCI_B_IFG_TXIFG));                               // EUSCI_B Transmit Interrupt Flag. set when TXBUF is empty

    EUSCI_B1->I2CSA = (slaveaddr+1)<<1;                                                // Send slave address to I2C Slave Addr Register
    EUSCI_B1->CTLW0 &= ~EUSCI_B_CTLW0_TR;                                        // Receive mode

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTT;                                     // Generate start condition, bit1 set
    //while(I2C_masterIsStartSent(EUSCI_B1_BASE));
    while(EUSCI_B1->CTLW0 & EUSCI_B_CTLW0_TXSTT);                              // Wait for complete address to send

    while(!(EUSCI_B1->IFG & EUSCI_B_IFG_RXIFG));
    uint8_t rec_data = EUSCI_B1->RXBUF;

    EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTP;                                     // Generate stop condition, bit2 set

    while((EUSCI_B1->CTLW0 & EUSCI_B_CTLW0_TXSTP ));                              // Wait for Stop condition to send

    return rec_data;
}

/*
 * Initialize EUSCI_B2 for I2C communication with camera
 * No parameters
 */
void I2C_initforcamera(void)
{
    /*
    EUSCI_B1 -> CTLW0 |= EUSCI_B_CTLW0_SWRST;                                     // Set UCSWRST for configuration (avoid unpredictable behavior), Software reset enable
    EUSCI_B1 -> CTLW0 |= EUSCI_B_CTLW0_SSEL__SMCLK |  EUSCI_B_CTLW0_SYNC |  EUSCI_B_CTLW0_MODE_3 | EUSCI_B_CTLW0_MST|EUSCI_B_CTLW0_TR;      // Standard Mode Clock | Synchronous Mode
                                                                                 // I2C Mode | Master Mode
                                                                                  // 7-bit slave address (UCSLA10,Bit 14 = 0), Single Master Environment (UCMM,Bit 13 = 0)
    EUSCI_B1 -> BRW = 40;                                                         // 12 MHz / 40 = 300 kHz

    EUSCI_B1 -> CTLW0 &= ~1;                                                      // CTLW0 & 0xFFFE, Released for Operation
*/
    /* I2C Clock Source Speed */
    //i2cConfig.i2cClk = MAP_CS_getSMCLK();

    /* Select I2C function for I2C_SCL(P6.5) & I2C_SDA(P6.4) */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN5 | GPIO_PIN4,
            GPIO_PRIMARY_MODULE_FUNCTION);

   const eUSCI_I2C_MasterConfig i2cConfig =
   {
           EUSCI_B_I2C_CLOCKSOURCE_SMCLK,                                           // SMCLK Clock Source
           MAP_CS_getSMCLK(),
           EUSCI_B_I2C_SET_DATA_RATE_400KBPS,                                       // Desired I2C Clock of 100khz
           0,                                                                       // No byte counter threshold
           EUSCI_B_I2C_SEND_STOP_AUTOMATICALLY_ON_BYTECOUNT_THRESHOLD               // Autostop
   };

   I2C_initMaster(EUSCI_B1_BASE, &i2cConfig);

   I2C_setSlaveAddress(EUSCI_B1_BASE, 0x60);

   I2C_enableModule(EUSCI_B1_BASE);
}
