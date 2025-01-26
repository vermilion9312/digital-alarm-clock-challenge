################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/_001_mode.c \
../User/Src/_002_timer.c \
../User/Src/_003_uart.c \
../User/Src/_101_digital_clock.c \
../User/Src/_102_lcd.c \
../User/Src/_103_seven_segment.c \
../User/Src/_104_led.c \
../User/Src/_105_button.c 

OBJS += \
./User/Src/_001_mode.o \
./User/Src/_002_timer.o \
./User/Src/_003_uart.o \
./User/Src/_101_digital_clock.o \
./User/Src/_102_lcd.o \
./User/Src/_103_seven_segment.o \
./User/Src/_104_led.o \
./User/Src/_105_button.o 

C_DEPS += \
./User/Src/_001_mode.d \
./User/Src/_002_timer.d \
./User/Src/_003_uart.d \
./User/Src/_101_digital_clock.d \
./User/Src/_102_lcd.d \
./User/Src/_103_seven_segment.d \
./User/Src/_104_led.d \
./User/Src/_105_button.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/CLCD/Inc -I../Drivers/Seven_segment/Inc -I../User/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/_001_mode.cyclo ./User/Src/_001_mode.d ./User/Src/_001_mode.o ./User/Src/_001_mode.su ./User/Src/_002_timer.cyclo ./User/Src/_002_timer.d ./User/Src/_002_timer.o ./User/Src/_002_timer.su ./User/Src/_003_uart.cyclo ./User/Src/_003_uart.d ./User/Src/_003_uart.o ./User/Src/_003_uart.su ./User/Src/_101_digital_clock.cyclo ./User/Src/_101_digital_clock.d ./User/Src/_101_digital_clock.o ./User/Src/_101_digital_clock.su ./User/Src/_102_lcd.cyclo ./User/Src/_102_lcd.d ./User/Src/_102_lcd.o ./User/Src/_102_lcd.su ./User/Src/_103_seven_segment.cyclo ./User/Src/_103_seven_segment.d ./User/Src/_103_seven_segment.o ./User/Src/_103_seven_segment.su ./User/Src/_104_led.cyclo ./User/Src/_104_led.d ./User/Src/_104_led.o ./User/Src/_104_led.su ./User/Src/_105_button.cyclo ./User/Src/_105_button.d ./User/Src/_105_button.o ./User/Src/_105_button.su

.PHONY: clean-User-2f-Src

