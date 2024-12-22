    .data
result: .word 0          # Memory location to store the result

    .text
    .globl fibonacci      # Export the function name for C

fibonacci:
    # Input: n in a0
    # Output: Fibonacci(n) in a0
    li t1, 0             # F(0) = 0
    li t2, 1             # F(1) = 1
    li t3, 2             # Counter for the loop (starts at 2)

    beq a0, 0, fib_zero  # If n == 0, go to fib_zero
    beq a0, 1, fib_one   # If n == 1, go to fib_one

fibonacci_loop:
    add t4, t1, t2       # t4 = t1 + t2 (next Fibonacci number)
    mv t1, t2            # t1 = t2 (shift values)
    mv t2, t4            # t2 = t4
    addi t3, t3, 1       # Counter += 1
    bge t3, a0, done     # If counter >= n, exit the loop
    j fibonacci_loop     # Repeat

fib_zero:
    li a0, 0             # Result = 0
    ret                  # Return to caller

fib_one:
    li a0, 1             # Result = 1
    ret                  # Return to caller

done:
    mv a0, t2            # Return the result in a0
    ret                  # Return to caller
