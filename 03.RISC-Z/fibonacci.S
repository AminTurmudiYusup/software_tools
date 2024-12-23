    .section .text
    .global fibonacci

fibonacci:
    addi sp, sp, -16          # Allocate stack space
    sw ra, 12(sp)             # Save return address

    li t1, 0                  # F(0) = 0
    li t2, 1                  # F(1) = 1
    ble a0, t2, base_case     # If n <= 1, go to base_case

fibonacci_loop:
    add t4, t1, t2            # t4 = t1 + t2
    mv t1, t2                 # t1 = t2
    mv t2, t4                 # t2 = t4
    addi a0, a0, -1           # n -= 1
    bgt a0, t2, fibonacci_loop # Continue loop if n > 1

    mv a0, t2                 # result = t2
    lw ra, 12(sp)             # Restore return address
    addi sp, sp, 16           # Deallocate stack space
    ret                       # Return result

base_case:
    mv a0, t1                 # If n == 0, result = 0
    lw ra, 12(sp)             # Restore return address
    addi sp, sp, 16           # Deallocate stack space
    ret
