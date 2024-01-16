/*
 * Stepper.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#include <Stepper.hpp>
Stepper::Stepper() {
	float currentAngle = 0;
}


void Stepper::setAngle(uint16_t angle) {
	degNStep realDegNStep=calcDegNStep(angle);
	if (realDegNStep.deg > 0){
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PinState(1));}

	else{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PinState(0));}

	for (int i = 0; i < realDegNStep.step; i++) {

		HAL_GPIO_WritePin(STEP_GPIO_Port, STEP_Pin, GPIO_PinState(1));
		osDelay(10);
		HAL_GPIO_WritePin(STEP_GPIO_Port, STEP_Pin, GPIO_PinState(0));
	}

}

degNStep Stepper::calcDegNStep(float angle) {
	float toDoAngle = currentAngle - angle;
	degNStep realDegNStep;
	int stepF = toDoAngle / 1.8;
	realDegNStep.deg = stepF * 1.8;
	realDegNStep.step = abs(stepF);
	return realDegNStep;
}
