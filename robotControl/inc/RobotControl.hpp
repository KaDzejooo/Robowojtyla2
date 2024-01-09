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



class RobotControl
{
	public:
		RobotControl();
		void taskEntry();

		Robot robotOne;
		MotionSolver solve;

		void moveRobotTo(position3D pos);
	private:

		jointAngles_t actualAngles;
		jointAngles_t targetAngles;

};

#endif /* ROBOTCONTROL_HPP_ */
