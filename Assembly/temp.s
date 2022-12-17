main:
                                                # s0 = a[]
                                                # s1 = num
    add     $a0,        $s1,        $s0
    jal     set

set:
    addi    $sp,        $sp,        -16         # $sp = $sp + -16
    sw      $t0,        12($s1)
    sw      $t1,        8($s1)
    sw      $ra,        4($s1)

# int i = 0
    add     $t0,        $0,         $0
loop:
    slt     $t1,        $t0,        10
    beq     $t1,        $0,         endloop     # if $t1 == $0 then goto endloop
    add     $a0,        $t0,        $0          # $a0 = $t0 + $0
    lw      $t1,        0($sp)
    jal     compare                             # jump to compare and save position to $ra
    sll     $t1,        $t0,        2           # $t1 = $t0 << 2
    add     $t1,        $t1,        $v0         # $t1 = $t1 + $v0
    sw      $v0,        0($t1)
    addi    $t0,        $t0,        1           # $t0 = $t0 + 1
    lw      $a0,        0($sp)
    addi    $a0,        $a1,        -1          # $a0 = $a1 + -1
    j       loop                                # jump to loop
endloop:

compare:
    addi    $sp,        $sp,        -16         # $sp = $sp + -12
    sw      $t0,        12($sp)
    sw      $ra,        8($sp)
    sw      $a1,        4($sp)                  # a
    sw      $a2,        0($sp)                  # b
    lw      $a0,        0($sp)                  # b
    lw      $a1,        4($sp)                  # a
    jal     subtract                            # jump to sub and save position to $ra
    slt     $t0,        $v0,        $0          # $t0 = ($v0 < $0) ? 1 : 0
    beq     $t0,        $0,         returnB     # if $t0 == $0 then goto returnB
    lw      $a0,        0($sp)
    add     $v0,        $a1,        $0          # $v0 = $a1 + 0
    j       end                                 # jump to end

returnB:
    lw      $a1,        4($sp)
    add     $v0,        $a1,        $0          # $v0 = $a1 + $0


subtract:
    sub     $v0,        $a0,        $a1         # $t0 = $a0 - $a1
    jr      $ra                                 # jump to $ra

end:
    lw      $t0,        12($t0)
    lw      $ra,        8($sp)
    addi    $sp,        $sp,        1           # $sp = $sp + 1
    jr      $ra                                 # jump to $ra
