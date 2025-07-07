################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/motor_driver/motor_driver.c 

OBJS += \
./Drivers/motor_driver/motor_driver.o 

C_DEPS += \
./Drivers/motor_driver/motor_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/motor_driver/%.o Drivers/motor_driver/%.su Drivers/motor_driver/%.cyclo: ../Drivers/motor_driver/%.c Drivers/motor_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/wande/STM32CubeIDE/workspace_1.18.1/V2_Detran_Project/Drivers/motor_driver" -I"C:/Users/wande/STM32CubeIDE/workspace_1.18.1/V2_Detran_Project/Drivers/UART_CMD" -I"C:/Users/wande/STM32CubeIDE/workspace_1.18.1/V2_Detran_Project/Drivers/VOLTAGE_READER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-motor_driver

clean-Drivers-2f-motor_driver:
	-$(RM) ./Drivers/motor_driver/motor_driver.cyclo ./Drivers/motor_driver/motor_driver.d ./Drivers/motor_driver/motor_driver.o ./Drivers/motor_driver/motor_driver.su

.PHONY: clean-Drivers-2f-motor_driver

