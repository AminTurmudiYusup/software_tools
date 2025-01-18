#!/bin/bash

# Step 1: Run make to compile the program
echo "Compiling the program using make..."
make

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"

    # Step 2: Run the compiled program (fractal_program)
    echo "Running the compiled program..."
    ./fractal_program
else
    echo "Compilation failed. Please check the errors above."
    exit 1
fi
