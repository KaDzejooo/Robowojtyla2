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


	moveSequence.emplace_back(40,50,30,66);
	moveSequence.emplace_back(80,70,10,42);
	moveSequence.emplace_back(21,37,42,0);
	moveSequence.emplace_back(90,90,90,55);

	setMoveMode(DIRECT_MODE);

	for(;;)
	{
		for(uint8_t i = 0;i<moveSequence.size();i++)
		{
			moveRobotTo(moveSequence.at(i));
			osDelay(100);
		}
		osDelay(5000);
	}
}

void RobotControl::setMoveMode(uint8_t mode)
{
	moveMode = mode;
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

	jointAngles_t targetAngles = solve.inverseKinematics(pos,robotOne);
	jointAngles_t accAngles = solve.getAccAngles( );

	if (moveMode == 0)// direct drive
	{
		robotOne.s1.setAngle(targetAngles.angleA);
		robotOne.s2.setAngle(targetAngles.angleB);
		robotOne.s3.setAngle(targetAngles.angleC);
		//robotOne.stepper.setAngle(targetAnglesIN.angleBase);
	}
	if(moveMode == 1)//linear interpolation
	{
		solve.solveLinear(accAngles, targetAngles);

		std::vector<jointAngles_t> moves = solve.getMoves();

		for (uint16_t i = 0; i<moves.size();i++)
		{
			robotOne.s1.setAngle(moves.at(i).angleA);
			robotOne.s2.setAngle(moves.at(i).angleB);
			robotOne.s3.setAngle(moves.at(i).angleC);
			//robotOne.stepper.setAngle(moves.at(i).angleBase);
		}
	}





	

}


