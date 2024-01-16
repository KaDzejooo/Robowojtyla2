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
#define DIRECT_MODE 0
#define LINEAR_MODE 1


class RobotControl
{
	public:
		RobotControl();
		void taskEntry();
		void setMoveMode(uint8_t mode);

		Robot robotOne = Robot(155,149,149,0);
		MotionSolver solve;

		void moveRobotTo(position3D pos);
	private:
		bool moveMode =0;
		std::vector<position3D> moveSequence;
		//jointAngles_t actualAngles;
		//jointAngles_t targetAngles;

};

#endif /* ROBOTCONTROL_HPP_ */
