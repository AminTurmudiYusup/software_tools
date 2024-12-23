.section .text
.global factorial

factorial:
    # Base case: if (n == 0), return 1
    beq a0, x0, done
    
    # Recursive case: return n * factorial(n-1)
    addi sp, sp, -8         # Allocate stack space
    sw a0, 0(sp)            # Save a0 (n) on the stack
    addi a0, a0, -1         # n = n - 1
    jal ra, factorial       # Call factorial(n-1)
    lw t0, 0(sp)            # Restore a0 (n) into t0
    addi sp, sp, 8          # Deallocate stack space
    mul a0, a0, t0          # result = n * result_of_factorial(n-1)
    ret                     # Return result

done:
    li a0, 1                # Return 1
    ret
