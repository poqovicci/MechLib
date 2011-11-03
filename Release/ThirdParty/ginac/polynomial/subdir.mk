################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThirdParty/ginac/polynomial/chinrem_gcd.cpp \
../ThirdParty/ginac/polynomial/collect_vargs.cpp \
../ThirdParty/ginac/polynomial/cra_garner.cpp \
../ThirdParty/ginac/polynomial/divide_in_z_p.cpp \
../ThirdParty/ginac/polynomial/gcd_uvar.cpp \
../ThirdParty/ginac/polynomial/mgcd.cpp \
../ThirdParty/ginac/polynomial/mod_gcd.cpp \
../ThirdParty/ginac/polynomial/optimal_vars_finder.cpp \
../ThirdParty/ginac/polynomial/pgcd.cpp \
../ThirdParty/ginac/polynomial/primpart_content.cpp \
../ThirdParty/ginac/polynomial/upoly_io.cpp 

OBJS += \
./ThirdParty/ginac/polynomial/chinrem_gcd.o \
./ThirdParty/ginac/polynomial/collect_vargs.o \
./ThirdParty/ginac/polynomial/cra_garner.o \
./ThirdParty/ginac/polynomial/divide_in_z_p.o \
./ThirdParty/ginac/polynomial/gcd_uvar.o \
./ThirdParty/ginac/polynomial/mgcd.o \
./ThirdParty/ginac/polynomial/mod_gcd.o \
./ThirdParty/ginac/polynomial/optimal_vars_finder.o \
./ThirdParty/ginac/polynomial/pgcd.o \
./ThirdParty/ginac/polynomial/primpart_content.o \
./ThirdParty/ginac/polynomial/upoly_io.o 

CPP_DEPS += \
./ThirdParty/ginac/polynomial/chinrem_gcd.d \
./ThirdParty/ginac/polynomial/collect_vargs.d \
./ThirdParty/ginac/polynomial/cra_garner.d \
./ThirdParty/ginac/polynomial/divide_in_z_p.d \
./ThirdParty/ginac/polynomial/gcd_uvar.d \
./ThirdParty/ginac/polynomial/mgcd.d \
./ThirdParty/ginac/polynomial/mod_gcd.d \
./ThirdParty/ginac/polynomial/optimal_vars_finder.d \
./ThirdParty/ginac/polynomial/pgcd.d \
./ThirdParty/ginac/polynomial/primpart_content.d \
./ThirdParty/ginac/polynomial/upoly_io.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/ginac/polynomial/%.o: ../ThirdParty/ginac/polynomial/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


