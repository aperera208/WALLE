/*
 * camera.h
 *
 *  Created on: Sep 19, 2018
 *      Author: Alex Perera
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#define GET_IMAGE           {0x56, 0x00, 0x36, 0x01, 0x00}
#define GET_IMAGE_SIZE      5
#define READ_LENGTH         {0x56, 0x00, 0x34, 0x01, 0x00}
#define READ_LENGTH_SIZE    5
#define READ_DATA           {0x56, 0x00, 0x32, 0x0C, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x64, 0x00, 0x0A}
#define READ_DATA_SIZE      16
#define STOP_CAPTURE        {0x56, 0x00, 0x36, 0x01, 0x03}
#define STOP_CAPTURE_SIZE   5
#define IMG_160x120         {0x56, 0x00, 0x54, 0x01, 0x22}
#define IMG_160x120_SIZE    5
#define CMP_RATIO           {0x56,  0x00, 0x31, 0x05, 0x01, 0x01, 0x12, 0x04, 0x99}
#define CMP_RATIO_SIZE      9

void Take_Picture();

void SPI_SendtoCamera(char * data, int bytecount);

uint8_t SPI_RecfromCamera();

bool SPI_initforcamera();

bool UART_initforcamera();

void UART_SendtoCamera(char * data, int bytecount);

void UART_ReceivefromCamera(char * data, int bytecount);

void I2C_initforcamera(void);

void I2C_writeforcamera(int slaveaddr, unsigned char memaddr, int bytecount, unsigned char* data );

uint8_t I2C_readforcamera(int slaveaddr, uint8_t reg);
#endif /* CAMERA_H_ */
