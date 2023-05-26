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
	.cfi_offset ra, -4
	li	a0, 10
	sw	a0, 8(sp)
	li	a0, 97
	sb	a0, 15(sp)
	lui	a0, 262290
	addi	a0, a0, -328
	sw	a0, 20(sp)
	lui	a0, 335544
	addi	a0, a0, 1311
	sw	a0, 16(sp)
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	li	a1, 10
	call	printf@plt
	lb	a1, 15(sp)
	lui	a0, %hi(.L_Const_String_.1)
	addi	a0, a0, %lo(.L_Const_String_.1)
	call	printf@plt
	lw	a3, 20(sp)
	lw	a2, 16(sp)
	lui	a0, %hi(.L_Const_String_.2)
	addi	a0, a0, %lo(.L_Const_String_.2)
	call	printf@plt
	li	a0, 0
	lw	ra, 28(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 32
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"Integer: %d\n"
	.size	.L_Const_String_, 13

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"Char: %c\n"
	.size	.L_Const_String_.1, 10

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"Double: %lf\n"
	.size	.L_Const_String_.2, 13

	.section	".note.GNU-stack","",@progbits
