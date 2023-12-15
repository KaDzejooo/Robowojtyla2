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
		MotionSolver(Robot robot);

		/*
		 * Solves robot trajectory according to start and end angles
		 *
		 */
		void solveLinear(jointAngles_t accAnglesIN, jointAngles_t targetAnglesIN);




		/*
		 *  Returns vector of joint angles in order of succesion
		 */
		const std::vector <std::vector <int> >& getMoves( ) const
		{
			return moves;
		}



	private:
		Robot robotData;
		std::vector<int> accAngles;
		std::vector<int> targetAngles;

		std::vector<jointAngles_t> moves;
};

#endif /* MOTIONSOLVER_HPP_ */
