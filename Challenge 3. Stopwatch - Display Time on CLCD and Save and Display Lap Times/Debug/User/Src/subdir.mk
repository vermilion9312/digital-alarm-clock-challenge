################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/button.c \
../User/Src/digital_clock.c \
../User/Src/lcd.c \
../User/Src/led.c \
../User/Src/seven_segment.c \
../User/Src/timer.c \
../User/Src/uart.c 

OBJS += \
./User/Src/button.o \
./User/Src/digital_clock.o \
./User/Src/lcd.o \
./User/Src/led.o \
./User/Src/seven_segment.o \
./User/Src/timer.o \
./User/Src/uart.o 

C_DEPS += \
./User/Src/button.d \
./User/Src/digital_clock.d \
./User/Src/lcd.d \
./User/Src/led.d \
./User/Src/seven_segment.d \
./User/Src/timer.d \
./User/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/CLCD/Inc -I../Drivers/Seven_segment/Inc -I../User/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/button.cyclo ./User/Src/button.d ./User/Src/button.o ./User/Src/button.su ./User/Src/digital_clock.cyclo ./User/Src/digital_clock.d ./User/Src/digital_clock.o ./User/Src/digital_clock.su ./User/Src/lcd.cyclo ./User/Src/lcd.d ./User/Src/lcd.o ./User/Src/lcd.su ./User/Src/led.cyclo ./User/Src/led.d ./User/Src/led.o ./User/Src/led.su ./User/Src/seven_segment.cyclo ./User/Src/seven_segment.d ./User/Src/seven_segment.o ./User/Src/seven_segment.su ./User/Src/timer.cyclo ./User/Src/timer.d ./User/Src/timer.o ./User/Src/timer.su ./User/Src/uart.cyclo ./User/Src/uart.d ./User/Src/uart.o ./User/Src/uart.su

.PHONY: clean-User-2f-Src

