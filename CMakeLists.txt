cmake_minimum_required (VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain/generic-msp430-gcc.cmake")

# Project :
project (FreeStyleHello)

#device dependent config, here for launchpad
set(MSP430_MCU ${CMAKE_SOURCE_DIR}/toolchain/rf430frl152h_freestylelibre)
set(MSP430_MCU_FREQ 1000000UL)

# Configure FTDI port for pypn2232:
set(FTDI_2232_PORT "PORT_A")


msp430_add_executable (FreeStyleHello
            src/patchtable.c
            src/nfctable.c
            src/nfc_functions.c
            src/main.c
            )

include_directories(
    ${CMAKE_SOURCE_DIR}/api
    ${CMAKE_SOURCE_DIR}/inc)

# Command called by 'make upload' to get a FRAM copy, then upload the new FRAM to sensor
add_custom_target(upload
    COMMAND python3  ${CMAKE_SOURCE_DIR}/toolchain/nfc_loader.py -e ${CMAKE_PROJECT_NAME}.elf -d ../FRAM-dump.bin -o ../New-FRAM.bin -l ${MSP430_MCU}.ld -f ${FTDI_2232_PORT}
    DEPENDS ${CMAKE_PROJECT_NAME}
)
