################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --opt_for_speed=2 --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/inc" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/DriverLib" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/WALLE_Robot" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power="1,3,4,5.3,7,9,10,12" --define=ccs --define=__MSP432P401R__ -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_msp432p401r_ccs.obj: ../startup_msp432p401r_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --opt_for_speed=2 --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/inc" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/DriverLib" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/WALLE_Robot" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power="1,3,4,5.3,7,9,10,12" --define=ccs --define=__MSP432P401R__ -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="startup_msp432p401r_ccs.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

system_msp432p401r.obj: ../system_msp432p401r.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --opt_for_speed=2 --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/inc" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/BoardSupportPackage/DriverLib" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/GITHUB/WALLE_Robot" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power="1,3,4,5.3,7,9,10,12" --define=ccs --define=__MSP432P401R__ -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="system_msp432p401r.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


