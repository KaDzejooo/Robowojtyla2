################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/pca9685/pca9685.c 

C_DEPS += \
./Drivers/pca9685/pca9685.d 

OBJS += \
./Drivers/pca9685/pca9685.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/pca9685/%.o Drivers/pca9685/%.su Drivers/pca9685/%.cyclo: ../Drivers/pca9685/%.c Drivers/pca9685/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/Drivers/pca9685" -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/app" -I"C:/Users/oem/Desktop/repositories/Robowojtyla2/robotControl/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-pca9685

clean-Drivers-2f-pca9685:
	-$(RM) ./Drivers/pca9685/pca9685.cyclo ./Drivers/pca9685/pca9685.d ./Drivers/pca9685/pca9685.o ./Drivers/pca9685/pca9685.su

.PHONY: clean-Drivers-2f-pca9685

