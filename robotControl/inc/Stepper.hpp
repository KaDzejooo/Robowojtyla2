/*
 * Stepper.hpp
 *
 *  Created on: Jan 9, 2024
 *      Author: KaDzejoo
 */

#ifndef STEPPER_HPP_
#define STEPPER_HPP_

#include "main.h"
#include "cmsis_os2.h"
#include "math.h"
/*
 *
 */
#define STEPPER_FULL_STEP 1
#define STEPPER_HALF_STEP 2
#define STEPPER_QUATER_STEP 4
#define STEPPER_EIGHT_STEP 8

class Stepper
{
	public:
		Stepper(uint8_t stepPin,uint8_t stepPort, uint8_t dirPin, uint8_t dirPort);
		/*void setMicrostepping(uint8_t microstepping);*/
		/*void setStepsPerRev(uint8_t stepsPerRev);*/

		void setAngle(uint16_t angle);


	private:
		typedef struct {
			float deg;
			int step;}degNStep;
		degNStep calcDegNStep(float angle);
		float currentAngle;
		uint16_t  stepPin, dirPin;
		GPIO_TypeDef*  stepPort, dirPort;
};

#endif /* STEPPER_HPP_ */
