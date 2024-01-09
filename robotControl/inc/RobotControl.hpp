/*
 * RobotControl.hpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#ifndef ROBOTCONTROL_HPP_
#define ROBOTCONTROL_HPP_
#include "main.h"
#include "i2c.h"
#include "MotionSolver.hpp"
#include "Robot.hpp"
/*
 *
 */
class Servo
{
	public:
		Servo(uint8_t channel,uint8_t iicAdress);
		void setSevroAngle(uint16_t angle);
	private:
		void calcPWM(uint8_t angle);

		uint8_t _tOnLow, _tOnHigh, _tOffLow, _tOffHigh;
		uint8_t _channel;
		uint8_t _iicAdress;


};


class RobotControl
{
	public:
		RobotControl();
		Robot robotData;
		MotionSolver solve;

		void moveRobotTo(int x , int y ,int z);
	private:

		jointAngles_t actualAngles;
		jointAngles_t targetAngles;

};

#endif /* ROBOTCONTROL_HPP_ */
