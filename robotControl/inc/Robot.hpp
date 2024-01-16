/*
 * Robot.hpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "position3D.hpp"
#include "main.h"
#include "i2c.h"
#include "Servo.hpp"
#include "Types.hpp"
/*
 *
 */

class Robot
{
	public:
		Robot( );
		Robot(int off1, int off2, int off3, int off4);
		// parts
		Servo s1 = Servo(0);//TODO check iic address
		Servo s2 = Servo(1);//TODO check iic address
		Servo s3 = Servo(2);//TODO check iic address
		//set/get



		const int getMaxRange( ) const;
		const int getOffsetA( ) const;
		const int getOffsetB( ) const;
		const int getOffsetJointC( ) const;
		const int getToolOffset( ) const;
		const jointAngles_t& getMaxAngles( ) const;
		void setMaxAngles(const jointAngles_t &maxAngles);
		const jointAngles_t& getMinAngles( ) const;
		void setMinAngles(const jointAngles_t &minAngles);



		jointAngles_t maxAngles;
		jointAngles_t minAngles;

	private:

		int offsetA, offsetB, offsetJointC;
		int toolOffset;

		int maxRange = 690;

};

#endif /* ROBOT_HPP_ */
