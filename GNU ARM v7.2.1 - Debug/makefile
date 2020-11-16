################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/SiliconLabs/subdir.mk
-include gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/MemMang/subdir.mk
-include gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/subdir.mk
-include gecko_sdk_3.0.0/util/third_party/freertos/Source/subdir.mk
-include gecko_sdk_3.0.0/platform/service/system/src/subdir.mk
-include gecko_sdk_3.0.0/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_3.0.0/platform/service/power_manager/src/subdir.mk
-include gecko_sdk_3.0.0/platform/service/device_init/src/subdir.mk
-include gecko_sdk_3.0.0/platform/emlib/src/subdir.mk
-include gecko_sdk_3.0.0/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_3.0.0/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_3.0.0/platform/common/src/subdir.mk
-include gecko_sdk_3.0.0/platform/Device/SiliconLabs/EFR32BG22/Source/GCC/subdir.mk
-include gecko_sdk_3.0.0/platform/Device/SiliconLabs/EFR32BG22/Source/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: empty.axf

# Tool invocations
empty.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "/home/krzysztof/SimplicityStudio/v5_workspace/empty/autogen/linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="empty.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o empty.axf -Wl,--start-group "./app.o" "./main.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_simple_led_instances.o" "./gecko_sdk_3.0.0/platform/Device/SiliconLabs/EFR32BG22/Source/GCC/startup_efr32bg22.o" "./gecko_sdk_3.0.0/platform/Device/SiliconLabs/EFR32BG22/Source/system_efr32bg22.o" "./gecko_sdk_3.0.0/platform/common/src/sl_slist.o" "./gecko_sdk_3.0.0/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_3.0.0/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_3.0.0/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_assert.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_burtc.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_cmu.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_core.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_emu.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_gpio.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_rtcc.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_system.o" "./gecko_sdk_3.0.0/platform/emlib/src/em_timer.o" "./gecko_sdk_3.0.0/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_3.0.0/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_3.0.0/platform/service/power_manager/src/sl_power_manager.o" "./gecko_sdk_3.0.0/platform/service/power_manager/src/sl_power_manager_debug.o" "./gecko_sdk_3.0.0/platform/service/power_manager/src/sl_power_manager_hal_s2.o" "./gecko_sdk_3.0.0/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_3.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o" "./gecko_sdk_3.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_prortc.o" "./gecko_sdk_3.0.0/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.o" "./gecko_sdk_3.0.0/platform/service/system/src/sl_system_init.o" "./gecko_sdk_3.0.0/platform/service/system/src/sl_system_kernel.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/croutine.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/event_groups.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/list.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/queue.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/tasks.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/timers.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/MemMang/heap_1.o" "./gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/SiliconLabs/tick_power_manager.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: empty.hex'
	arm-none-eabi-objcopy -O ihex "empty.axf" "empty.hex"
	@echo ' '

	@echo 'Building bin file: empty.bin'
	arm-none-eabi-objcopy -O binary "empty.axf" "empty.bin"
	@echo ' '

	@echo 'Building s37 file: empty.s37'
	arm-none-eabi-objcopy -O srec "empty.axf" "empty.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "empty.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) empty.axf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
