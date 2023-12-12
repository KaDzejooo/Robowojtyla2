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
/*
 *
 */
class MotionSolver
{
	public:
		MotionSolver(Robot robot);
		void solve(std::vector<int> accAnglesIN, std::vector<int> targetAnglesIN);

		const std::vector <std::vector <int> >& getMoves( ) const
		{
			return moves;
		}

	private:
		std::vector<int> accAngles;
		std::vector<int> targetAngles;

		std::vector<std::vector<int>> moves;
};

#endif /* MOTIONSOLVER_HPP_ */
