################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BBB_ROV_V1.cpp \
../src/GPIO.cpp \
../src/HardwareDevice.cpp \
../src/PWM.cpp 

OBJS += \
./src/BBB_ROV_V1.o \
./src/GPIO.o \
./src/HardwareDevice.o \
./src/PWM.o 

CPP_DEPS += \
./src/BBB_ROV_V1.d \
./src/GPIO.d \
./src/HardwareDevice.d \
./src/PWM.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


