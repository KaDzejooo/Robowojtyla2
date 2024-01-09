/*
 * app.c
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */
#include "app.h"

void taskEntry_robotOne();

void startRobotOne(void *argument)
{
	taskEntry_robotOne();
}
