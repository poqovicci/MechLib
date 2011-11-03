################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThirdParty/ginac/parser/default_reader.cpp \
../ThirdParty/ginac/parser/lexer.cpp \
../ThirdParty/ginac/parser/parse_binop_rhs.cpp \
../ThirdParty/ginac/parser/parse_context.cpp \
../ThirdParty/ginac/parser/parser.cpp \
../ThirdParty/ginac/parser/parser_compat.cpp 

OBJS += \
./ThirdParty/ginac/parser/default_reader.o \
./ThirdParty/ginac/parser/lexer.o \
./ThirdParty/ginac/parser/parse_binop_rhs.o \
./ThirdParty/ginac/parser/parse_context.o \
./ThirdParty/ginac/parser/parser.o \
./ThirdParty/ginac/parser/parser_compat.o 

CPP_DEPS += \
./ThirdParty/ginac/parser/default_reader.d \
./ThirdParty/ginac/parser/lexer.d \
./ThirdParty/ginac/parser/parse_binop_rhs.d \
./ThirdParty/ginac/parser/parse_context.d \
./ThirdParty/ginac/parser/parser.d \
./ThirdParty/ginac/parser/parser_compat.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/ginac/parser/%.o: ../ThirdParty/ginac/parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


