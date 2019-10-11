################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clientes.c \
../src/informes.c \
../src/parcialLaboratorio.c \
../src/pedidos.c \
../src/utn_gets.c 

OBJS += \
./src/clientes.o \
./src/informes.o \
./src/parcialLaboratorio.o \
./src/pedidos.o \
./src/utn_gets.o 

C_DEPS += \
./src/clientes.d \
./src/informes.d \
./src/parcialLaboratorio.d \
./src/pedidos.d \
./src/utn_gets.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


