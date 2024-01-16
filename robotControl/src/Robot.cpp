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
	toolOffset = 90;
	maxAngles = {180,180,180,360};
	minAngles = {0,0,0,0};
}
Robot::Robot(int off1, int off2, int off3, int off4):
offsetA(off1), offsetB(off2), offsetJointC(off3),toolOffset(off4)
{
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

const jointAngles_t& Robot::getMaxAngles( ) const
{
	return maxAngles;
}

void Robot::setMaxAngles(const jointAngles_t &maxAngles)
{
	this->maxAngles = maxAngles;
}

const jointAngles_t& Robot::getMinAngles( ) const
{
	return minAngles;
}

void Robot::setMinAngles(const jointAngles_t &minAngles)
{
	this->minAngles = minAngles;
}
