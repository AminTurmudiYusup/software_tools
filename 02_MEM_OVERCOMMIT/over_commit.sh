#!/bin/sh

# Compile the C program
gcc -o overcommit 02_MEM_OVERCOMMIT/over_commit.c

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful."

# Run the program with arguments
# Usage: ./overcommit <number_of_pages> <operation>
echo "Running write operation..."
./overcommit 128 write

echo "Running read operation..."
./overcommit 128 read

echo "Done!"
