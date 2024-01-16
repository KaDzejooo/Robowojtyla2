################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../robotControl/app/app.c 

C_DEPS += \
./robotControl/app/app.d 

OBJS += \
./robotControl/app/app.o 


# Each subdirectory must supply rules for building sources it contributes
robotControl/app/%.o robotControl/app/%.su robotControl/app/%.cyclo: ../robotControl/app/%.c robotControl/app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/Drivers/pca9685" -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/app" -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-robotControl-2f-app

clean-robotControl-2f-app:
	-$(RM) ./robotControl/app/app.cyclo ./robotControl/app/app.d ./robotControl/app/app.o ./robotControl/app/app.su

.PHONY: clean-robotControl-2f-app

