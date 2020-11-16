################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.o: ../gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG_EFM=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DEFR32BG22C224F512IM40=1' -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/common/toolchain/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/service/system/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/driver/leddrv/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/service/power_manager/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/emlib/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/common/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/service/device_init/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/util/third_party/freertos/Source/include" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/util/third_party/freertos/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/CMSIS/Include" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/service/sleeptimer/inc" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/gecko_sdk_3.0.0/platform/Device/SiliconLabs/EFR32BG22/Include" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/config" -I"/home/krzysztof/SimplicityStudio/v5_workspace/empty/autogen" -Os -Wall -Wextra -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.d" -MT"gecko_sdk_3.0.0/util/third_party/freertos/Source/portable/GCC/ARM_CM4F/port.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


