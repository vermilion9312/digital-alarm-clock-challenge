################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CLCD/Src/CLCD.c 

OBJS += \
./Drivers/CLCD/Src/CLCD.o 

C_DEPS += \
./Drivers/CLCD/Src/CLCD.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CLCD/Src/%.o Drivers/CLCD/Src/%.su Drivers/CLCD/Src/%.cyclo: ../Drivers/CLCD/Src/%.c Drivers/CLCD/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/CLCD/Inc -I../Drivers/Seven_segment/Inc -I../User/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CLCD-2f-Src

clean-Drivers-2f-CLCD-2f-Src:
	-$(RM) ./Drivers/CLCD/Src/CLCD.cyclo ./Drivers/CLCD/Src/CLCD.d ./Drivers/CLCD/Src/CLCD.o ./Drivers/CLCD/Src/CLCD.su

.PHONY: clean-Drivers-2f-CLCD-2f-Src

