################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../robotControl/src/robotControl.c 

C_DEPS += \
./robotControl/src/robotControl.d 

OBJS += \
./robotControl/src/robotControl.o 


# Each subdirectory must supply rules for building sources it contributes
robotControl/src/%.o robotControl/src/%.su robotControl/src/%.cyclo: ../robotControl/src/%.c robotControl/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/Users/oem/STM32CubeIDE/workspace_GFX/robowojtyla/robotControl/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-robotControl-2f-src

clean-robotControl-2f-src:
	-$(RM) ./robotControl/src/robotControl.cyclo ./robotControl/src/robotControl.d ./robotControl/src/robotControl.o ./robotControl/src/robotControl.su

.PHONY: clean-robotControl-2f-src

