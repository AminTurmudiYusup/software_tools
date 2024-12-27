# Compiler and flags
CC = riscv64-unknown-elf-gcc
CFLAGS = -march=rv64imac -mabi=lp64 -O0 -g

# Source files
ASM_SOURCES = factorial.S fibonacci.S
C_SOURCES = unit_tests.c
OBJECTS = $(ASM_SOURCES:.S=.o) $(C_SOURCES:.c=.o)

# Target executable
TARGET = tests

# Default rule to build everything
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile assembly and C files into object files
%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)
