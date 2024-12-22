    .data
result: .word 0          # Memory location to store the result

    .text
    .globl factorial      # Export the function name for C

factorial:
    # Input: n in a0
    # Output: Factorial(n) in a0
    li t1, 1             # Initialize result in t1

factorial_loop:
    beq a0, 0, done      # If n == 0, go to done
    mul t1, t1, a0       # t1 = t1 * a0
    addi a0, a0, -1      # Decrement a0
    j factorial_loop     # Repeat

done:
    mv a0, t1            # Return the result in a0
    ret                  # Return to caller
