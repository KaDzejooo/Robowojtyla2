/*
 * MotionSolver.hpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#ifndef MOTIONSOLVER_HPP_
#define MOTIONSOLVER_HPP_

#include <vector>
#include "Robot.hpp"
#include "math.h"
/*
 *
 */

typedef struct{
		int angleA;
		int angleB;
		int angleC;
		int angleBase;

}jointAngles_t;
class MotionSolver
{
	public:
		MotionSolver() ;

		void setRobot(Robot robotObj);
		/*
		 * Solves robot trajectory according to start and end angles
		 *
		 */
		void solveLinear(jointAngles_t accAnglesIN, jointAngles_t targetAnglesIN);


		jointAngles_t inverseKinematics(position3D targetPos);


		/*
		 *  Returns vector of joint angles in order of succesion
		 */
		const std::vector<jointAngles_t>& getMoves( ) const
		{
			return moves;
		}



	private:

		jointAngles_t accAngles;
		jointAngles_t targetAngles;
		Robot robotData;
		std::vector<jointAngles_t> moves;
};

#endif /* MOTIONSOLVER_HPP_ */
