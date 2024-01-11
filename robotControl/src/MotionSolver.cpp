/*
 * MotionSolver.cpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#include "MotionSolver.hpp"

MotionSolver::MotionSolver()
{
	moves.clear( );
}

void MotionSolver::solveLinear(jointAngles_t accAnglesIN, jointAngles_t targetAnglesIN)
{
	int diffA = abs(accAnglesIN.angleA - targetAnglesIN.angleA);
	int diffB = abs(accAnglesIN.angleB - targetAnglesIN.angleB);
	int diffC = abs(accAnglesIN.angleC - targetAnglesIN.angleC);
	int diffBase = abs(accAnglesIN.angleBase - targetAnglesIN.angleBase);

	int maxSteps = std::max(std::max(diffA, diffB), std::max(diffC, diffBase));

	moves.reserve(maxSteps);
	jointAngles_t result;

	for (int i = 0; i < maxSteps; i++)
	{

		//TODO check for negative values
		//TODO check for maxAngles
		//TODO this shit won't work at all YET


		if (result.angleA != targetAnglesIN.angleA)
		{
			result.angleA++;
		}
		if (result.angleB != targetAnglesIN.angleB)
		{
			result.angleB++;
		}
		if (result.angleC != targetAnglesIN.angleC)
		{
			result.angleC++;
		}
		if (result.angleBase != targetAnglesIN.angleBase)
		{
			result.angleBase++;
		}


		//moves.emplace(moves.end( ), result);
		moves.push_back(result);
	}


}

void MotionSolver::setRobot(Robot robotObj)
{
	robotData = robotObj;
}

jointAngles_t MotionSolver::inverseKinematics(position3D targetPos, Robot robot, uint16_t phi)
{
	jointAngles_t retVal;
	//PLANAR PART
	uint16_t q1, q2, q0; //tool orientation

	uint16_t l0 = robot.getOffsetB( );
	uint16_t l1 = robot.getOffsetJointC( );
	uint16_t l2 = robot.getToolOffset( );

	uint16_t P2x = targetPos.getX( ) - l2 * cos(phi);
	uint16_t P2y = targetPos.getZ( ) - l2 * sin(phi);



	q1 = acos(((P2x*P2x)+(P2x*P2x)-(l0*l0)-(l1*l1))/
							2*l0*l1);
	q0=atan(P2x/P2y)-atan((l1*sin(q1))/
				 	 	  (l0+cos(q1)));

	q2 =phi - q1 - q0;

	//PLANAR PART END
	retVal.angleA = q0;
	retVal.angleB = q1;
	retVal.angleC = q2;
	retVal.angleBase = atan(targetPos.getX( ) / targetPos.getY( ));

	return retVal;
}
