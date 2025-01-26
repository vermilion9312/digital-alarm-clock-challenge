################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Seven_segment/Src/7SEG.c 

OBJS += \
./Drivers/Seven_segment/Src/7SEG.o 

C_DEPS += \
./Drivers/Seven_segment/Src/7SEG.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Seven_segment/Src/%.o Drivers/Seven_segment/Src/%.su Drivers/Seven_segment/Src/%.cyclo: ../Drivers/Seven_segment/Src/%.c Drivers/Seven_segment/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/CLCD/Inc -I../Drivers/Seven_segment/Inc -I../User/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Seven_segment-2f-Src

clean-Drivers-2f-Seven_segment-2f-Src:
	-$(RM) ./Drivers/Seven_segment/Src/7SEG.cyclo ./Drivers/Seven_segment/Src/7SEG.d ./Drivers/Seven_segment/Src/7SEG.o ./Drivers/Seven_segment/Src/7SEG.su

.PHONY: clean-Drivers-2f-Seven_segment-2f-Src

