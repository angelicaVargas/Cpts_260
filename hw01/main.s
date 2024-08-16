.option pic0

# Set read-only data section
.rdata
.align 2

# Output format for single row of matrix.    
outputFormat:
    .asciz "[%d,%d,%d]\n"

# The first matrix
matrixa:
    .align 2
    # first row
    .word 1
    .word 2
    .word 3
    # second row
    .word 4
    .word 5
    .word 6
    # third row
    .word 7
    .word 8
    .word 9

# The second matrix
matrixb:    
    .align 2
    # The first row
    .word 1
    .word 2
    .word 3
    # The second row
    .word 4
    .word 5
    .word 6
    # The third row
    .word 7
    .word 8
    .word 9


# Set writable data section
.data
.align 2

# The third (result) matrix
matrixc:
    .align 2
    # The first row
    .word 1
    .word 2
    .word 3
    # The second row
    .word 4
    .word 5
    .word 6
    # The third row
    .word 7
    .word 8
    .word 9

# Set the text section (code)    
.text
.align 2

# This is so that the operating system will "see" the "main" label
# as the name of the first function to call.
.global main


# Print Matrix
#
# $a2 the matrix to print
printmatrix:
    # Function prologue used in calling conventions

    addiu   $sp, $sp, -24   # Allocate some space on the stack
    sw      $s0, 0($sp)     # Save the $s0 register
    sw      $a0, 4($sp)     # Save the $a0 register
    sw      $a1, 8($sp)     # Save the $a1 register
    sw      $a2, 12($sp)    # Save the $a2 register
    sw      $a3, 16($sp)    # Save the $a3 register
    sw      $ra, 20($sp)    # Save the return address

    #####################################################
    # Put your printmatrix code here
    #
    # Feel free to use $s0 and $a0-$a3 they are saved
    # and restored on the stack. If you need more you'll
    # need to add the appropriate `sw` and `lw` in the
    # prologue and epilogue.

    move $s0, $a2           # save the first argument to $s0

    la $a0, outputFormat    # load address of outputFormat into a0
                            # a0 has matrixc (mentioned on main) and s0 has address to matrixc 
    lw $a1, 0($s0)          # load word 1 in s0 to a1
    lw $a2, 4($s0)          # load word 2 in s0 to a2
    lw $a3, 8($s0)          # load word 3 in s0 to a3

    jal printf              # jump and link instruction -> saves return adress

    la $a0, outputFormat    # loading address of outputFormat again or -> segmentation fault
    lw $a1, 12($s0)         # argument a1, gets overwritten (re-use)
    lw $a2, 16($s0)
    lw $a3, 20($s0)

    jal printf

    la $a0, outputFormat 
    lw $a1, 24($s0)
    lw $a2, 28($s0)
    lw $a3, 32($s0)

    jal printf
    #####################################################

    # Function epilogue used in calling conventions
    # This is very much unwinding the prolog but in reverse
    lw      $ra, 20($sp)  # Restore the return address from the stack
    lw      $a3, 16($sp)  # Restore the $a3 register
    lw      $a2, 12($sp)  # Restore the $a2 register
    lw      $a1, 8($sp)   # Restore the $a1 register
    lw      $a0, 4($sp)   # Restore the $a0 register
    lw      $s0, 0($sp)   # Restore the $s0 register
    addiu   $sp, $sp, 24  # Restore the origin stack pointer
    jr      $ra           # Jump to the return address

dotproduct:
    # Function prolog used in calling conventions
    # Don't mess with this ...
    addiu   $sp, $sp, -4   # Allocate some space on the stack
    sw      $ra, ($sp)     # Save the return address

    ################################################
    # Put your dotproduct code here
    #
    # This function does not call other functions so
    # nothing on the stack is saved. 
   
    move $t0, $a0    # save argument in row (matrixa) to $t0
    move $t1, $a1    # save argument in column (matrixb) to $t1
 
    lw $t2, 0($t0)   # load first value of matrixa t0 into t2
    lw $t3, 0($t1)   # load first value of column t1 into t3
    lw $t4, 12($t1)  # load the second value of column t1 into t4
    lw $t5, 24($t1)  # load the third value of column t1 into t5
    mul $t3, $t2, $t3    # multiplying t3 and t2, value in now in t3
    mul $t4, $t2, $t4    
    mul $t5, $t2, $t5    
    add $t6, $t3, $t4    # adding the values t3 and t4, storing into t6
    add $t7, $t6, $t5    # adding values t5 and t6, storing into t7
    # found the first value of matrixc of row1 
    sw $t7, 0($a2)       # storing the value from register t7 into memory
                         # save value into argument of matrixc

    lw $t2, 4($t0)   # load second value of matrixa t0 into t2
    lw $t3, 0($t1)
    lw $t4, 12($t1)
    lw $t5, 24($t1)
    mul $t3, $t2, $t3    
    mul $t4, $t2, $t4
    mul $t5, $t2, $t5
    add $t6, $t3, $t4 
    add $t7, $t6, $t5    
    # found the second value of matrixc of row1
    sw $t7, 4($a2)       # storing the value from register t7 into memory

    lw $t2, 8($t0)   # load third value of matrixa t0 into t2
    lw $t3, 0($t1)   
    lw $t4, 12($t1) 
    lw $t5, 24($t1)  
    mul $t3, $t2, $t3   
    mul $t4, $t2, $t4
    mul $t5, $t2, $t5
    add $t6, $t3, $t4   
    add $t7, $t6, $t5   
    # found the third value of matrixc of row1
    sw $t7, 8($a2)       # storing the value from register t7 into memory

    ################################################

    # Function epilog used in calling conventions
    # This is very much unwinding the prolog but in reverse
    lw      $ra, ($sp)    # Restore the return address from the stack
    addiu   $sp, $sp, 4   # Restore the origin stack pointer
    jr      $ra           # Jump to the return address

main:
    # use return registers as iterators
    move  $s0, $zero # row iterator

    ################################################
    # Put your matrix multiply code here
    #
    # This is main so feel free to use whatever
    # registers you see fit here.
    ################################################
    # s0 is the pointer/row iterator -> use to point to digits in matrix

# create loop that passes argument and increments by 1, to pass to dotproduct
loop: 
    # addi $t0, $t0, 1     # i ++
    # slti $t1, $t0, 3     # t1  = 1 if i < 3
    # li $v0, 0     #initialize result value 
    # pass a row and column as argument to dot product
    la $a0, matrixa        # load first value of row  matrixa 
    la $a1, matrixb        # load first value of column matrixb
    jal     dotproduct     
    
    # loop three times for each row & column (3x3)
    # exit the loop

    la      $a2,  matrixc  # call the first argument of matrixc
    jal     printmatrix    # call printmatrix and print out the new matrix

    jal   exit
