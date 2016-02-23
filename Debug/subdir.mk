################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Address.cpp \
../Cliente.cpp \
../Evento.cpp \
../Socket.cpp \
../main.cpp \
../singleton_client.cpp 

OBJS += \
./Address.o \
./Cliente.o \
./Evento.o \
./Socket.o \
./main.o \
./singleton_client.o 

CPP_DEPS += \
./Address.d \
./Cliente.d \
./Evento.d \
./Socket.d \
./main.d \
./singleton_client.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


