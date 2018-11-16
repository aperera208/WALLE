/*
 * xbee.h
 *
 *  Created on: Oct 20, 2018
 *      Author: Alex Perera
 */

#ifndef XBEE_H_
#define XBEE_H_

#include "controller.h"
#include "uart.h"
#include "gpio.h"
#include "interrupt.h"

#define START       'S'
#define END         'N'
#define ACK         'A'

void XBEE_UART_INIT();
bool XBEE_SEND_BASIC_CONTROLLER_PACKET(basic_packet_t data);
bool XBEE_SEND_CONTROLLER_STATE(packet_t data);



#endif /* XBEE_H_ */
