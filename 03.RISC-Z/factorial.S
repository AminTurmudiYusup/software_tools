    .section .text
    .global factorial

factorial:
    addi sp, sp, -16          # Allocate stack space
    sw ra, 12(sp)             # Save return address
    sw a0, 0(sp)              # Save n

    beq a0, x0, done          # Base case: if n == 0, return 1
    addi a0, a0, -1           # Recursive case: n = n - 1
    jal ra, factorial         # Call factorial(n-1)

    lw t0, 0(sp)              # Restore n into t0
    lw ra, 12(sp)             # Restore return address
    addi sp, sp, 16           # Deallocate stack space
    mul a0, a0, t0            # result = n * factorial(n-1)
    ret                       # Return result

done:
    li a0, 1                  # Return 1
    lw ra, 12(sp)             # Restore return address
    addi sp, sp, 16           # Deallocate stack space
    ret
