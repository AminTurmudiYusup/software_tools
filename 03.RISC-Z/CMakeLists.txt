cmake_minimum_required(VERSION 3.16)
project(RISCV_Project)

# Specify the RISC-V cross-compiler
set(CMAKE_C_COMPILER riscv64-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv64-unknown-elf-as)
set(CMAKE_C_FLAGS "-march=rv64imac -mabi=lp64 -msoft-float -O2")
set(CMAKE_EXE_LINKER_FLAGS "-nostartfiles -msoft-float")


# Specify ASM files explicitly
enable_language(ASM)

# List of source files (relative to the current directory)
set(SOURCES
    factorial.S
    fibonacci.S
    unit_tests.c
)

# Debug Output: Print source files
message(STATUS "Source files: ${SOURCES}")

# Add the executable target
add_executable(tests ${SOURCES})
