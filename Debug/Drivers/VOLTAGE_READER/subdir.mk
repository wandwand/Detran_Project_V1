################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/VOLTAGE_READER/VOLTAGE_READER.c 

OBJS += \
./Drivers/VOLTAGE_READER/VOLTAGE_READER.o 

C_DEPS += \
./Drivers/VOLTAGE_READER/VOLTAGE_READER.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/VOLTAGE_READER/%.o Drivers/VOLTAGE_READER/%.su Drivers/VOLTAGE_READER/%.cyclo: ../Drivers/VOLTAGE_READER/%.c Drivers/VOLTAGE_READER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/wande/STM32CubeIDE/workspace_1.18.1/V2_Detran_Project/Drivers/motor_driver" -I"C:/Users/wande/STM32CubeIDE/workspace_1.18.1/V2_Detran_Project/Drivers/UART_CMD" -I"C:/Users/wande/STM32CubeIDE/workspace_1.18.1/V2_Detran_Project/Drivers/VOLTAGE_READER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-VOLTAGE_READER

clean-Drivers-2f-VOLTAGE_READER:
	-$(RM) ./Drivers/VOLTAGE_READER/VOLTAGE_READER.cyclo ./Drivers/VOLTAGE_READER/VOLTAGE_READER.d ./Drivers/VOLTAGE_READER/VOLTAGE_READER.o ./Drivers/VOLTAGE_READER/VOLTAGE_READER.su

.PHONY: clean-Drivers-2f-VOLTAGE_READER

