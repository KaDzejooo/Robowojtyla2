/*
 * Robot.cpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#include "Robot.hpp"

Robot::Robot( )
{
	offsetA=155; offsetB=149; offsetJointC=149;
	toolOffset = 0;

	maxAngleA = 0;
	maxAngleB = 0;
	maxAngleC =0;


	
}
Robot::Robot(int off1, int off2, int off3, int off4):
offsetA(off1), offsetB(off2), offsetJointC(off3),toolOffset(off4)
{
}



const position3D& Robot::getBasePos( ) const
{
	return basePos;
}

void Robot::setBasePos(const position3D &basePos)
{
	this->basePos = basePos;
}

const int Robot::getMaxAngleA( ) const
{
	return maxAngleA;
}

const int Robot::getMaxAngleB( ) const
{
	return maxAngleB;
}

const int Robot::getMaxAngleC( ) const
{
	return maxAngleC;
}

const int Robot::getMaxRange( ) const
{
	return maxRange;
}

const int Robot::getOffsetA( ) const
{
	return offsetA;
}

const int Robot::getOffsetB( ) const
{
	return offsetB;
}

const int Robot::getOffsetJointC( ) const
{
	return offsetJointC;
}

const int Robot::getToolOffset( ) const
{
	return toolOffset;
}

const position3D& Robot::getToolPos( ) const
{
	return toolPos;
}

void Robot::setToolPos(const position3D &toolPos)
{
	this->toolPos = toolPos;
}


