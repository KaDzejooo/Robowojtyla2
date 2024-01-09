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
