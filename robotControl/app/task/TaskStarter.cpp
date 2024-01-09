/*
 * TaskStarter.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#include "RobotControl.hpp"


extern "C" void taskEntry_robotOne( );


static RobotControl robotController;


void taskEntry_robotOne( ){

	robotController.taskEntry();
}
