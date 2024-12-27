#!/bin/bash

# Name of the C file and output executable
C_FILE="io-flush/first_io.c"
OUTPUT_FILE="program"

# Compile the program
echo "Compiling $C_FILE..."
gcc "$C_FILE" -o "$OUTPUT_FILE"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful."

# Run the program with parameter 'a'
echo -e "\nRunning with parameter 'a':"
./"$OUTPUT_FILE" a

# Run the program with parameter 'b'
echo -e "\nRunning with parameter 'b':"
./"$OUTPUT_FILE" b

# Run the program with parameter 'c'
echo -e "\nRunning with parameter 'c':"
./"$OUTPUT_FILE" c
