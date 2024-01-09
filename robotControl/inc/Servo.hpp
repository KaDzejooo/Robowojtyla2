/*
 * Servo.hpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#ifndef SERVO_HPP_
#define SERVO_HPP_
#include "main.h"
#include "i2c.h"
/*
 *
 */
class Servo
{
	public:
		Servo(uint8_t channel,uint8_t iicAddress);
		void setAngle(uint16_t angle);
	private:
		void calcPWM(uint8_t angle);

		uint8_t _tOnLow, _tOnHigh, _tOffLow, _tOffHigh;
		uint8_t _channel;
		uint8_t _iicAddress;
};

#endif /* SERVO_HPP_ */
