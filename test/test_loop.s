	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0"
	.file	"main"
	.globl	main                            # -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -32
	.cfi_def_cfa_offset 32
	sw	ra, 28(sp)                      # 4-byte Folded Spill
	sw	s0, 24(sp)                      # 4-byte Folded Spill
	sw	s1, 20(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	.cfi_offset s1, -12
	sw	zero, 12(sp)
	li	s1, 4
	lui	a0, %hi(.L_Const_String_)
	addi	s0, a0, %lo(.L_Const_String_)
	lw	a0, 12(sp)
	blt	s1, a0, .LBB0_2
.LBB0_1:                                # %ForLoop
                                        # =>This Inner Loop Header: Depth=1
	lw	a1, 12(sp)
	mv	a0, s0
	call	printf@plt
	lw	a0, 12(sp)
	addi	a0, a0, 1
	sw	a0, 12(sp)
	lw	a0, 12(sp)
	bge	s1, a0, .LBB0_1
.LBB0_2:                                # %ForEnd
	sw	zero, 16(sp)
	li	s1, 4
	lui	a0, %hi(.L_Const_String_.1)
	addi	s0, a0, %lo(.L_Const_String_.1)
	lw	a0, 16(sp)
	blt	s1, a0, .LBB0_4
.LBB0_3:                                # %WhileLoop
                                        # =>This Inner Loop Header: Depth=1
	lw	a1, 16(sp)
	mv	a0, s0
	call	printf@plt
	lw	a0, 16(sp)
	addi	a0, a0, 1
	sw	a0, 16(sp)
	lw	a0, 16(sp)
	bge	s1, a0, .LBB0_3
.LBB0_4:                                # %WhileEnd
	li	a0, 0
	lw	ra, 28(sp)                      # 4-byte Folded Reload
	lw	s0, 24(sp)                      # 4-byte Folded Reload
	lw	s1, 20(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
	.p2align	4
.L_Const_String_:
	.asciz	"For loop iteration: %d\n"
	.size	.L_Const_String_, 24

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
	.p2align	4
.L_Const_String_.1:
	.asciz	"While loop iteration: %d\n"
	.size	.L_Const_String_.1, 26

	.section	".note.GNU-stack","",@progbits
