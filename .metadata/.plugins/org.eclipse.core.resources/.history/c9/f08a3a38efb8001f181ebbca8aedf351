################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Challenge 2. Stopwatch_Time display on 7Segment_controlled by buttons
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.elf \

MAP_FILES += \
Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.list \


# All Target
all: main-build

# Main-build Target
main-build: Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.elf secondary-outputs

# Tool invocations
Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.elf Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.map: $(OBJS) $(USER_OBJS) C:\Github\digital-alarm-clock-challenge\Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons\STM32F407VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Challenge 2. Stopwatch_Time display on 7Segment_controlled by buttons.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Github\digital-alarm-clock-challenge\Challenge 2. Stopwatch_Time display on 7Segment_controlled by buttons\STM32F407VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Challenge 2. Stopwatch_Time display on 7Segment_controlled by buttons.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Challenge 2. Stopwatch_Time display on 7Segment_controlled by buttons.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.elf Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.list Challenge\ 2.\ Stopwatch_Time\ display\ on\ 7Segment_controlled\ by\ buttons.map Challenge\\ 2.\\ Stopwatch_Time\\ display\\ on\\ 7Segment_controlled\\ by\\ buttons.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
