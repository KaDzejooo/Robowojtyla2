/*
 * RobotControl.cpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#include "RobotControl.hpp"
#include "cmsis_os2.h"

//TODO DON'T FORGET TO ADD LOOPS INTO OTHER RTOS TASKS !!!!
// defined in freeertos.c


RobotControl::RobotControl()
{

}

void RobotControl::taskEntry( )
{
	for(;;)
	{
		osDelay(50);
	}
}


void RobotControl::moveRobotTo(position3D pos)
{
// start and end positions defined
// Inverse Kinematics model
// transpose Cartesian coordinates into joint angles
// sending data of next joint angles to solver
// solver returns vector of moves (angles)
// this func moves servos for that amount
// and updates accAngle in motionSolver (i guess)

	jointAngles_t targetAnglesIN = solve.inverseKinematics(pos);
	jointAngles_t accAnglesIN = solve.inverseKinematics(pos);

	solve.solveLinear(accAnglesIN, targetAnglesIN);
	std::vector<jointAngles_t> moves = solve.getMoves();

	for (int i = 0; i<moves.size();i++)
	{
		robotOne.s1.setAngle(moves.at(i).angleA);
		robotOne.s2.setAngle(moves.at(i).angleB);
		robotOne.s3.setAngle(moves.at(i).angleC);
		robotOne.stepper.setAngle(moves.at(i).angleBase);
	}
	robotOne.s1.setAngle(moves.at(1).angleA);
	robotOne.s2.setAngle(moves.at(1).angleB);
	robotOne.s3.setAngle(moves.at(1).angleC);
	robotOne.stepper.setAngle(45);
	

}


