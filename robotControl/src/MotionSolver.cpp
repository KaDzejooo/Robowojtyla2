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
	accAngles = result;

}

void MotionSolver::setRobot(Robot robotObj)
{
	robotData = robotObj;
}

jointAngles_t MotionSolver::inverseKinematics(position3D targetPos, Robot robot)
{
	jointAngles_t retVal;
	uint16_t q1, q2, q0;
	uint16_t l0 = robot.getOffsetB( );
	uint16_t l1 = robot.getOffsetJointC( );
	uint16_t l2 = robot.getToolOffset( );
	uint16_t baseOffset = robot.getOffsetA();

	uint16_t P2x = targetPos.getX( ) - l2 * cos(targetPos.getPhi());
	uint16_t P2y = targetPos.getZ( ) - (l2 * sin(targetPos.getPhi())) - baseOffset;

	q1 = acos(((P2x*P2x)+(P2x*P2x)-(l0*l0)-(l1*l1))/
							2*l0*l1);
	q0=atan(P2x/P2y)-atan((l1*sin(q1))/
				 	 	  (l0+cos(q1)));

	q2 =targetPos.getPhi() - q1 - q0;

	retVal.angleA = MotionSolver::limitAngle(robot.maxAngles.angleA,robot.minAngles.angleA,q0);
	retVal.angleB = MotionSolver::limitAngle(robot.maxAngles.angleB,robot.minAngles.angleB,q1);
	retVal.angleC = MotionSolver::limitAngle(robot.maxAngles.angleC,robot.minAngles.angleC,q2);
	retVal.angleBase = atan(targetPos.getX( ) / targetPos.getY( ));

	return retVal;
}

int MotionSolver::limitAngle(int max, int min, int angle)
{
	if (angle > max)
	{
		return max;
	}
	if (angle < min)
	{
		return min;
	}
	return angle;

	
}

jointAngles_t MotionSolver::differentialDrive(jointAngles_t ang)
{
	jointAngles_t temp;

	// some weird shit



	return temp;
}
