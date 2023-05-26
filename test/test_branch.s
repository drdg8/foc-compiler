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
	addi	sp, sp, -16
	.cfi_def_cfa_offset 16
	sw	ra, 12(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	li	a0, 10
	sw	a0, 4(sp)
	li	a0, 5
	sw	a0, 8(sp)
	bnez	zero, .LBB0_2
# %bb.1:                                # %Then
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	j	.LBB0_3
.LBB0_2:                                # %Else
	lui	a0, %hi(.L_Const_String_.1)
	addi	a0, a0, %lo(.L_Const_String_.1)
.LBB0_3:                                # %Merge4
	call	printf@plt
	lw	a0, 4(sp)
	li	a1, 10
	bne	a0, a1, .LBB0_5
# %bb.4:                                # %Case0
	lui	a0, %hi(.L_Const_String_.2)
	addi	a0, a0, %lo(.L_Const_String_.2)
	j	.LBB0_7
.LBB0_5:                                # %Comparison1
	li	a1, 5
	bne	a0, a1, .LBB0_8
# %bb.6:                                # %Case1
	lui	a0, %hi(.L_Const_String_.3)
	addi	a0, a0, %lo(.L_Const_String_.3)
.LBB0_7:                                # %SwitchEnd
	call	printf@plt
.LBB0_8:                                # %SwitchEnd
	li	a0, 0
	lw	ra, 12(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
	.p2align	4
.L_Const_String_:
	.asciz	"a is greater than b\n"
	.size	.L_Const_String_, 21

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
	.p2align	4
.L_Const_String_.1:
	.asciz	"b is greater than a\n"
	.size	.L_Const_String_.1, 21

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"a is 10\n"
	.size	.L_Const_String_.2, 9

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
.L_Const_String_.3:
	.asciz	"a is 5\n"
	.size	.L_Const_String_.3, 8

	.section	".note.GNU-stack","",@progbits
