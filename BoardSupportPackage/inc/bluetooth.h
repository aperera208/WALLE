/*
 * bluetooth.h
 *
 *  Created on: Oct 16, 2018
 *      Author: Alex Perera
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "gpio.h"
#include "uart.h"
#include "string.h"
#include <stdbool.h>

#define AUDIO_STREAM    "S%,0007\r\n"
#define FACT_SETTINGS   "SF,1\r\n"
#define DEV_NAME        "SN,PARTE BT\r\n"
#define REBOOT          "R,1\r\n"
#define MAX_GAIN        "SS,0F\r\n"

bool bluetooth_init();

void bluetooth_uart_send(char * data);

uint8_t bluetooth_uart_receive();

#endif /* BLUETOOTH_H_ */
