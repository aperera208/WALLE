################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/AsciiLib.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/AsciiLib.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/AsciiLib.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/BSP.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/BSP.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/BSP.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/BackChannelUart.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/BackChannelUart.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/BackChannelUart.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/ClockSys.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/ClockSys.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/ClockSys.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/Joystick.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/Joystick.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/Joystick.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/LCD.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/LCD.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/LCD.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/LED.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/LED.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/LED.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/bme280.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/bme280.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/bme280.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/bme280_support.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/bme280_support.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/bme280_support.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/bmi160.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/bmi160.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/bmi160.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/bmi160_support.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/bmi160_support.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/bmi160_support.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/demo_sysctl.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/demo_sysctl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/demo_sysctl.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/i2c_driver.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/i2c_driver.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/i2c_driver.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/opt3001.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/opt3001.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/opt3001.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/tmp007.obj: C:/Users/Alex\ Perera/Desktop/Senior/CCS/BoardSupportPackage/src/tmp007.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/DriverLib" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/src" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/BoardSupportPackage/inc" --include_path="C:/ti/ccsv7/ccs_base/arm/include" --include_path="C:/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="C:/Users/Alex Perera/Desktop/Senior/CCS/Test" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.8.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/tmp007.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


