/*
 * Wifi.h
 *
 *  Created on: Nov 1, 2018
 *      Author: Alex Perera
 */

#ifndef WIFI_H_
#define WIFI_H_

#include <stdbool.h>
#include "uart.h"
#include "gpio.h"
#include "interrupt.h"

bool Wifi_Init_UART();

void Wifi_Send_Pic(char * data, char * length_h, char * length_l, int bytecount);

void Wifi_SendtoWifi(char * data, int bytecount);

void Wifi_ReceivefromWifi(char * data, int bytecount);



#endif /* BOARDSUPPORTPACKAGE_INC_WIFI_H_ */
