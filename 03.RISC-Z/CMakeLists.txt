cmake_minimum_required(VERSION 3.16)
project(RISCV_Project)

# Specify the RISC-V cross-compiler
set(CMAKE_C_COMPILER riscv64-unknown-elf-gcc)
set(CMAKE_ASM_COMPILER riscv64-unknown-elf-as)

# Compiler and assembler flags
set(CMAKE_C_FLAGS "-march=rv64imac -mabi=lp64 -msoft-float -O2 -g")
set(CMAKE_ASM_FLAGS "-march=rv64imac -mabi=lp64 -msoft-float -O2 -g")
set(CMAKE_EXE_LINKER_FLAGS "-nostartfiles -msoft-float -e main")

# Enable ASM language support
enable_language(ASM)

# List of source files
set(SOURCES
    factorial.S
    fibonacci.S
    unit_tests.c
)

# Debug Output: Print source files
message(STATUS "Source files: ${SOURCES}")

# Add the executable target
add_executable(tests ${SOURCES})

# Ensure compilers are found
if (NOT CMAKE_C_COMPILER)
    message(FATAL_ERROR "RISC-V C compiler not found!")
endif()
if (NOT CMAKE_ASM_COMPILER)
    message(FATAL_ERROR "RISC-V assembler not found!")
endif()

# Enable verbose build output (optional)
set(CMAKE_VERBOSE_MAKEFILE ON)
