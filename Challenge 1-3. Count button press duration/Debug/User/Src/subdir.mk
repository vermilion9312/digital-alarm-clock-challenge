################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/7SEG.c \
../User/Src/button.c \
../User/Src/led.c \
../User/Src/seven_segment.c \
../User/Src/uart.c 

OBJS += \
./User/Src/7SEG.o \
./User/Src/button.o \
./User/Src/led.o \
./User/Src/seven_segment.o \
./User/Src/uart.o 

C_DEPS += \
./User/Src/7SEG.d \
./User/Src/button.d \
./User/Src/led.d \
./User/Src/seven_segment.d \
./User/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../User/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/7SEG.cyclo ./User/Src/7SEG.d ./User/Src/7SEG.o ./User/Src/7SEG.su ./User/Src/button.cyclo ./User/Src/button.d ./User/Src/button.o ./User/Src/button.su ./User/Src/led.cyclo ./User/Src/led.d ./User/Src/led.o ./User/Src/led.su ./User/Src/seven_segment.cyclo ./User/Src/seven_segment.d ./User/Src/seven_segment.o ./User/Src/seven_segment.su ./User/Src/uart.cyclo ./User/Src/uart.d ./User/Src/uart.o ./User/Src/uart.su

.PHONY: clean-User-2f-Src

