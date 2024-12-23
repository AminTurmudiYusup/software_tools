    .data
result: .word 0          # Memory location to store the result (if needed)

    .text
    .globl fibonacci      # Export the function name for C

fibonacci:
    # Input: n in a0
    # Output: Fibonacci(n) in a0

    # Handle base cases directly
    li t1, 0             # F(0) = 0
    li t2, 1             # F(1) = 1
    ble a0, 1, base_case # If n <= 1, go to base_case

    # Loop for n > 1
fibonacci_loop:
    add t4, t1, t2       # t4 = t1 + t2 (next Fibonacci number)
    mv t1, t2            # t1 = t2 (shift values)
    mv t2, t4            # t2 = t4
    addi a0, a0, -1      # Decrement n (a0)
    bgt a0, 1, fibonacci_loop # Repeat until n <= 1

    # Store result in a0
    mv a0, t2            # Result = t2
    ret                  # Return to caller

base_case:
    mv a0, t1            # If n == 0, result = t1 (0)
    beq a0, 0, ret_label # If n == 1, result = t2 (1)
    mv a0, t2
ret_label:
    ret                  # Return to caller
