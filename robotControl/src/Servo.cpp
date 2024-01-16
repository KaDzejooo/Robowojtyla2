/*
 * Servo.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#include <Servo.hpp>
#include "pca9685.h"

Servo::Servo(uint8_t channel)
{
	_channel = channel;

}

void Servo::setAngle(uint16_t angle)
{
//	calcPWM(angle);
//
//	uint8_t data[] = {
//			_tOnLow,
//			_tOnHigh,
//			_tOffLow,
//			_tOffHigh
//	};
//
//
//	HAL_I2C_Mem_Write(&hi2c1, _iicAddress, _channel, 1, data, 4, 100);


	PCA9685_SetServoAngle(_channel, angle);

}

void Servo::calcPWM(uint8_t angle)
{
	const uint16_t counterVal = 4095;
	uint16_t onPerc,offPerc;
	uint16_t onTime,offTime;

	onPerc = angle/180 * 100;
	offPerc = 100 - onPerc;


	onTime = counterVal * onPerc / 100;
	offTime = counterVal - onTime;

	// calculate and assignment of lo/hi bytes of address
	 _tOnHigh = (onTime>>8) & 0xFF;
	 _tOnLow = (onTime) & 0xFF;

	 _tOffHigh = (offTime>>8) & 0xFF;
	 _tOffLow = (offTime) & 0xFF;

}
