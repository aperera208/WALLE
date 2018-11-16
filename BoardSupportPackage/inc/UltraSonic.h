/*
 * UltraSonic.h
 *
 *  Created on: Sep 17, 2018
 *      Author: Alex Perera
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <stdint.h>


void InitSensor(uint_fast8_t echoPort, uint_fast16_t echoPin, uint_fast8_t trigPort, uint_fast16_t trigPin);

uint16_t GetSensorReading(uint_fast8_t echoPort, uint_fast16_t echoPin, uint_fast8_t trigPort, uint_fast16_t trigPin, uint16_t count);


#endif /* ULTRASONIC_H_ */
