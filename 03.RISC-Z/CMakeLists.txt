cmake_minimum_required(VERSION 3.16)
project(RISCV_Project)

# Specify the RISC-V cross-compiler
set(CMAKE_C_COMPILER riscv64-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv64-unknown-elf-as)
set(CMAKE_C_FLAGS "-march=rv64imac -mabi=lp64 -O2")
set(CMAKE_EXE_LINKER_FLAGS "-nostartfiles")

# Define the source directory
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}")

# List of source files
set(SOURCES
    ${SOURCE_DIR}/factorial.S
    ${SOURCE_DIR}/fibonacci.S
    ${SOURCE_DIR}/unit_test.c
)

# Specify ASM files explicitly
enable_language(ASM)

# Debug Output: Print source files
message(STATUS "Source files: ${SOURCES}")

# Add the executable target
add_executable(tests ${SOURCES})
