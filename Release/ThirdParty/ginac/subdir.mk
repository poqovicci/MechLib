################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThirdParty/ginac/add.cpp \
../ThirdParty/ginac/archive.cpp \
../ThirdParty/ginac/basic.cpp \
../ThirdParty/ginac/clifford.cpp \
../ThirdParty/ginac/color.cpp \
../ThirdParty/ginac/constant.cpp \
../ThirdParty/ginac/ex.cpp \
../ThirdParty/ginac/excompiler.cpp \
../ThirdParty/ginac/expair.cpp \
../ThirdParty/ginac/expairseq.cpp \
../ThirdParty/ginac/exprseq.cpp \
../ThirdParty/ginac/factor.cpp \
../ThirdParty/ginac/fail.cpp \
../ThirdParty/ginac/fderivative.cpp \
../ThirdParty/ginac/function.cpp \
../ThirdParty/ginac/idx.cpp \
../ThirdParty/ginac/indexed.cpp \
../ThirdParty/ginac/inifcns.cpp \
../ThirdParty/ginac/inifcns_gamma.cpp \
../ThirdParty/ginac/inifcns_nstdsums.cpp \
../ThirdParty/ginac/inifcns_trans.cpp \
../ThirdParty/ginac/integral.cpp \
../ThirdParty/ginac/lst.cpp \
../ThirdParty/ginac/matrix.cpp \
../ThirdParty/ginac/mul.cpp \
../ThirdParty/ginac/ncmul.cpp \
../ThirdParty/ginac/normal.cpp \
../ThirdParty/ginac/numeric.cpp \
../ThirdParty/ginac/operators.cpp \
../ThirdParty/ginac/power.cpp \
../ThirdParty/ginac/print.cpp \
../ThirdParty/ginac/pseries.cpp \
../ThirdParty/ginac/registrar.cpp \
../ThirdParty/ginac/relational.cpp \
../ThirdParty/ginac/remember.cpp \
../ThirdParty/ginac/symbol.cpp \
../ThirdParty/ginac/symmetry.cpp \
../ThirdParty/ginac/tensor.cpp \
../ThirdParty/ginac/utils.cpp \
../ThirdParty/ginac/wildcard.cpp 

OBJS += \
./ThirdParty/ginac/add.o \
./ThirdParty/ginac/archive.o \
./ThirdParty/ginac/basic.o \
./ThirdParty/ginac/clifford.o \
./ThirdParty/ginac/color.o \
./ThirdParty/ginac/constant.o \
./ThirdParty/ginac/ex.o \
./ThirdParty/ginac/excompiler.o \
./ThirdParty/ginac/expair.o \
./ThirdParty/ginac/expairseq.o \
./ThirdParty/ginac/exprseq.o \
./ThirdParty/ginac/factor.o \
./ThirdParty/ginac/fail.o \
./ThirdParty/ginac/fderivative.o \
./ThirdParty/ginac/function.o \
./ThirdParty/ginac/idx.o \
./ThirdParty/ginac/indexed.o \
./ThirdParty/ginac/inifcns.o \
./ThirdParty/ginac/inifcns_gamma.o \
./ThirdParty/ginac/inifcns_nstdsums.o \
./ThirdParty/ginac/inifcns_trans.o \
./ThirdParty/ginac/integral.o \
./ThirdParty/ginac/lst.o \
./ThirdParty/ginac/matrix.o \
./ThirdParty/ginac/mul.o \
./ThirdParty/ginac/ncmul.o \
./ThirdParty/ginac/normal.o \
./ThirdParty/ginac/numeric.o \
./ThirdParty/ginac/operators.o \
./ThirdParty/ginac/power.o \
./ThirdParty/ginac/print.o \
./ThirdParty/ginac/pseries.o \
./ThirdParty/ginac/registrar.o \
./ThirdParty/ginac/relational.o \
./ThirdParty/ginac/remember.o \
./ThirdParty/ginac/symbol.o \
./ThirdParty/ginac/symmetry.o \
./ThirdParty/ginac/tensor.o \
./ThirdParty/ginac/utils.o \
./ThirdParty/ginac/wildcard.o 

CPP_DEPS += \
./ThirdParty/ginac/add.d \
./ThirdParty/ginac/archive.d \
./ThirdParty/ginac/basic.d \
./ThirdParty/ginac/clifford.d \
./ThirdParty/ginac/color.d \
./ThirdParty/ginac/constant.d \
./ThirdParty/ginac/ex.d \
./ThirdParty/ginac/excompiler.d \
./ThirdParty/ginac/expair.d \
./ThirdParty/ginac/expairseq.d \
./ThirdParty/ginac/exprseq.d \
./ThirdParty/ginac/factor.d \
./ThirdParty/ginac/fail.d \
./ThirdParty/ginac/fderivative.d \
./ThirdParty/ginac/function.d \
./ThirdParty/ginac/idx.d \
./ThirdParty/ginac/indexed.d \
./ThirdParty/ginac/inifcns.d \
./ThirdParty/ginac/inifcns_gamma.d \
./ThirdParty/ginac/inifcns_nstdsums.d \
./ThirdParty/ginac/inifcns_trans.d \
./ThirdParty/ginac/integral.d \
./ThirdParty/ginac/lst.d \
./ThirdParty/ginac/matrix.d \
./ThirdParty/ginac/mul.d \
./ThirdParty/ginac/ncmul.d \
./ThirdParty/ginac/normal.d \
./ThirdParty/ginac/numeric.d \
./ThirdParty/ginac/operators.d \
./ThirdParty/ginac/power.d \
./ThirdParty/ginac/print.d \
./ThirdParty/ginac/pseries.d \
./ThirdParty/ginac/registrar.d \
./ThirdParty/ginac/relational.d \
./ThirdParty/ginac/remember.d \
./ThirdParty/ginac/symbol.d \
./ThirdParty/ginac/symmetry.d \
./ThirdParty/ginac/tensor.d \
./ThirdParty/ginac/utils.d \
./ThirdParty/ginac/wildcard.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/ginac/%.o: ../ThirdParty/ginac/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


