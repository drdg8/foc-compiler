	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0"
	.file	"main"
	.globl	factorial                       # -- Begin function factorial
	.p2align	2
	.type	factorial,@function
factorial:                              # @factorial
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -16
	.cfi_def_cfa_offset 16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	sw	s0, 8(sp)                       # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	sw	a0, 4(sp)
	beqz	a0, .LBB0_2
# %bb.1:                                # %Else
	lw	s0, 4(sp)
	addi	a0, s0, -1
	call	factorial@plt
	mv	a1, a0
	mv	a0, s0
	call	__mulsi3@plt
	j	.LBB0_3
.LBB0_2:                                # %Then
	li	a0, 1
.LBB0_3:                                # %Then
	lw	ra, 12(sp)                      # 4-byte Folded Reload
	lw	s0, 8(sp)                       # 4-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	factorial, .Lfunc_end0-factorial
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -16
	.cfi_def_cfa_offset 16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	li	a0, 5
	sw	a0, 8(sp)
	li	a0, 5
	call	factorial@plt
	mv	a2, a0
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	li	a1, 5
	call	printf@plt
	li	a0, 0
	lw	ra, 12(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
	.p2align	4
.L_Const_String_:
	.asciz	"Factorial of %d: %d\n"
	.size	.L_Const_String_, 21

	.section	".note.GNU-stack","",@progbits
