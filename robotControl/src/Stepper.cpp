/*
 * Stepper.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#include <Stepper.hpp>
Stepper::Stepper(uint8_t stepPin, uint8_5 stepPort, uint8_t dirPin,
		uint8_t dirPort) {
	float currentAngle = 0;

}


Stepper::setAngle(uint16_t angle) {
	calcDegNStep(angle);
	if (realDegNStep.deg > 0)
		Hal_GPIO_WritePin(dirPort, dirPin, 1);
	else
		Hal_GPIO_WritePin(dirPort, dirPin, 0);

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
