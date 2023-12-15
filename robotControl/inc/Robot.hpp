/*
 * Robot.hpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "position3D.hpp"
/*
 *
 */
class Robot
{
	public:
		Robot( );
		void setAngles(const int angles[3]);
		const position3D& getBasePos( ) const;
		void setBasePos(const position3D &basePos);
		const int getMaxAngleA( ) const;
		const int getMaxAngleB( ) const;
		const int getMaxAngleC( ) const;
		const int getMaxRange( ) const;
		const int getOffsetA( ) const;
		const int getOffsetB( ) const;
		const int getOffsetJointC( ) const;
		const int getToolOffset( ) const;
		const position3D& getToolPos( ) const;
		void setToolPos(const position3D &toolPos);

	private:
		position3D basePos, toolPos;

		int offsetA, offsetB, offsetJointC;
		int toolOffset;

		int maxAngleA;
		int maxAngleB;
		int maxAngleC;
		int maxRange = 69;

};

#endif /* ROBOT_HPP_ */
