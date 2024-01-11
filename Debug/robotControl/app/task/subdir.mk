################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../robotControl/app/task/TaskStarter.cpp 

OBJS += \
./robotControl/app/task/TaskStarter.o 

CPP_DEPS += \
./robotControl/app/task/TaskStarter.d 


# Each subdirectory must supply rules for building sources it contributes
robotControl/app/task/%.o robotControl/app/task/%.su robotControl/app/task/%.cyclo: ../robotControl/app/task/%.cpp robotControl/app/task/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/app" -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-robotControl-2f-app-2f-task

clean-robotControl-2f-app-2f-task:
	-$(RM) ./robotControl/app/task/TaskStarter.cyclo ./robotControl/app/task/TaskStarter.d ./robotControl/app/task/TaskStarter.o ./robotControl/app/task/TaskStarter.su

.PHONY: clean-robotControl-2f-app-2f-task

