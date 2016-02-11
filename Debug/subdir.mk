################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cliente.cpp \
../Evento.cpp \
../main.cpp \
../singleton_client.cpp \
../singleton_server.cpp 

OBJS += \
./Cliente.o \
./Evento.o \
./main.o \
./singleton_client.o \
./singleton_server.o 

CPP_DEPS += \
./Cliente.d \
./Evento.d \
./main.d \
./singleton_client.d \
./singleton_server.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


