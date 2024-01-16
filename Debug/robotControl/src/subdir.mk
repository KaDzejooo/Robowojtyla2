################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../robotControl/src/Matrix4x4.cpp \
../robotControl/src/MotionSolver.cpp \
../robotControl/src/Robot.cpp \
../robotControl/src/RobotControl.cpp \
../robotControl/src/Servo.cpp \
../robotControl/src/Stepper.cpp \
../robotControl/src/position3D.cpp 

OBJS += \
./robotControl/src/Matrix4x4.o \
./robotControl/src/MotionSolver.o \
./robotControl/src/Robot.o \
./robotControl/src/RobotControl.o \
./robotControl/src/Servo.o \
./robotControl/src/Stepper.o \
./robotControl/src/position3D.o 

CPP_DEPS += \
./robotControl/src/Matrix4x4.d \
./robotControl/src/MotionSolver.d \
./robotControl/src/Robot.d \
./robotControl/src/RobotControl.d \
./robotControl/src/Servo.d \
./robotControl/src/Stepper.d \
./robotControl/src/position3D.d 


# Each subdirectory must supply rules for building sources it contributes
robotControl/src/%.o robotControl/src/%.su robotControl/src/%.cyclo: ../robotControl/src/%.cpp robotControl/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/inc" -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/app" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/Drivers/pca9685" -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-robotControl-2f-src

clean-robotControl-2f-src:
	-$(RM) ./robotControl/src/Matrix4x4.cyclo ./robotControl/src/Matrix4x4.d ./robotControl/src/Matrix4x4.o ./robotControl/src/Matrix4x4.su ./robotControl/src/MotionSolver.cyclo ./robotControl/src/MotionSolver.d ./robotControl/src/MotionSolver.o ./robotControl/src/MotionSolver.su ./robotControl/src/Robot.cyclo ./robotControl/src/Robot.d ./robotControl/src/Robot.o ./robotControl/src/Robot.su ./robotControl/src/RobotControl.cyclo ./robotControl/src/RobotControl.d ./robotControl/src/RobotControl.o ./robotControl/src/RobotControl.su ./robotControl/src/Servo.cyclo ./robotControl/src/Servo.d ./robotControl/src/Servo.o ./robotControl/src/Servo.su ./robotControl/src/Stepper.cyclo ./robotControl/src/Stepper.d ./robotControl/src/Stepper.o ./robotControl/src/Stepper.su ./robotControl/src/position3D.cyclo ./robotControl/src/position3D.d ./robotControl/src/position3D.o ./robotControl/src/position3D.su

.PHONY: clean-robotControl-2f-src

