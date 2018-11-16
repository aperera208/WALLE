/*
 * controller.h
 *
 *  Created on: Oct 24, 2018
 *      Author: Alex Perera
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "Joystick.h"

typedef enum
{
    left = 0,
    left_center = 1,
    center_x = 2,
    right_center = 3,
    right = 4
}x_dir_t;

typedef enum
{
    down = 0,
    down_center = 1,
    center_y = 2,
    up_center = 3,
    up = 4
}y_dir_t;

typedef enum{
    picture = 0x0E,
    parte = 0x0B,
    manual = 0x07,
    automatic = 0x0D,
    sleeping = 0x00
}mode_t;

struct basic_packet{
    x_dir_t xdir;
    y_dir_t ydir;
    uint8_t buttons;
};
typedef struct basic_packet basic_packet_t;

struct packet{
    int16_t xadc;
    int16_t yadc;
    uint8_t buttons;
};
typedef struct packet packet_t;

void init_controller(void);
basic_packet_t get_basic_controller_state(void);
packet_t get_controller_state(void);




#endif /* BOARDSUPPORTPACKAGE_INC_CONTROLLER_H_ */