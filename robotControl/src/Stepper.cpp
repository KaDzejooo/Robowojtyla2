/*
 * Stepper.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#include <Stepper.hpp>
Stepper::Stepper(uint16_t stepPin, GPIO_TypeDef* stepPort, uint16_t dirPin,GPIO_TypeDef* dirPort) {
	float currentAngle = 0;
}


void Stepper::setAngle(uint16_t angle) {
	degNStep realDegNStep=calcDegNStep(angle);
	if (realDegNStep.deg > 0){
		HAL_GPIO_WritePin(dirPort, dirPin, 1);}

	else{
		HAL_GPIO_WritePin(dirPort, dirPin, 0);}

	for (int i = 0; i < realDegNStep.step; i++) {

		HAL_GPIO_WritePin(stepPort, stepPin, 1);
		osDelay(10);
		HAL_GPIO_WritePin(stepPort, stepPin, 0);
	}

}

degNStep Stepper::calcDegNStep(float angle) {
	float toDoAngle = currentAngle - angle;
	degNStep realDegNStep;
	float stepF = (toDoAngle / 1.8) - ((toDoAngle / 1.8) % 1);
	realDegNStep.deg = stepF * 1.8;
	realDegNStep.step = abs(stepF);
	return realDegNStep;
}
