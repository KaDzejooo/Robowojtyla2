/*
 * RobotControl.cpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#include "RobotControl.hpp"

RobotControl::RobotControl()
{
	

}

void RobotControl::moveRobotTo(int x, int y, int z)
{
//iic 0x40
	
	

}

Servo::Servo(uint8_t channel, uint8_t iicAdress)
{
	_channel = channel;
	_iicAdress =iicAdress;
}

void Servo::setSevroAngle(uint16_t angle)
{
	uint8_t data[] = {
			_tOnLow,
			_tOnHigh,
			_tOffLow,
			_tOffHigh
	};


	HAL_I2C_Mem_Write(&hi2c1, _iicAdress, _channel, 1, data, 4, 100);
}

void Servo::calcPWM(uint8_t angle)
{


}
