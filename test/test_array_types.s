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
	addi	sp, sp, -96
	.cfi_def_cfa_offset 96
	sw	ra, 92(sp)                      # 4-byte Folded Spill
	sw	s0, 88(sp)                      # 4-byte Folded Spill
	sw	s1, 84(sp)                      # 4-byte Folded Spill
	sw	s2, 80(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	.cfi_offset s1, -12
	.cfi_offset s2, -16
	sw	zero, 8(sp)
	li	a0, 4
	addi	a1, sp, 12
	lw	a2, 8(sp)
	blt	a0, a2, .LBB0_2
.LBB0_1:                                # %ForLoop
                                        # =>This Inner Loop Header: Depth=1
	lw	a2, 8(sp)
	slli	a3, a2, 2
	add	a3, a1, a3
	addi	a2, a2, 1
	sw	a2, 0(a3)
	sw	a2, 8(sp)
	lw	a2, 8(sp)
	bge	a0, a2, .LBB0_1
.LBB0_2:                                # %ForEnd
	li	a0, 97
	sb	a0, 35(sp)
	li	a0, 98
	sb	a0, 36(sp)
	li	a0, 99
	sb	a0, 37(sp)
	li	a0, 100
	sb	a0, 38(sp)
	li	a0, 101
	sb	a0, 39(sp)
	lui	a0, 261914
	addi	a0, a0, -1639
	sw	a0, 44(sp)
	lui	a0, 629146
	addi	a0, a0, -1638
	sw	a0, 40(sp)
	lui	a1, 262170
	addi	a1, a1, -1639
	sw	a1, 52(sp)
	sw	a0, 48(sp)
	lui	a1, 262310
	addi	a1, a1, 1638
	sw	a1, 60(sp)
	lui	a1, 419430
	addi	a1, a1, 1638
	sw	a1, 56(sp)
	lui	a1, 262426
	addi	a1, a1, -1639
	sw	a1, 68(sp)
	sw	a0, 64(sp)
	lui	a0, 262496
	sw	a0, 76(sp)
	sw	zero, 72(sp)
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	call	printf@plt
	sw	zero, 8(sp)
	li	s1, 4
	addi	s2, sp, 12
	lui	a0, %hi(.L_Const_String_.1)
	addi	s0, a0, %lo(.L_Const_String_.1)
	lw	a0, 8(sp)
	blt	s1, a0, .LBB0_4
.LBB0_3:                                # %ForLoop17
                                        # =>This Inner Loop Header: Depth=1
	lw	a0, 8(sp)
	slli	a0, a0, 2
	add	a0, s2, a0
	lw	a1, 0(a0)
	mv	a0, s0
	call	printf@plt
	lw	a0, 8(sp)
	addi	a0, a0, 1
	sw	a0, 8(sp)
	lw	a0, 8(sp)
	bge	s1, a0, .LBB0_3
.LBB0_4:                                # %ForEnd23
	lui	a0, %hi(.L_Const_String_.2)
	addi	a0, a0, %lo(.L_Const_String_.2)
	call	printf@plt
	lui	a0, %hi(.L_Const_String_.3)
	addi	a0, a0, %lo(.L_Const_String_.3)
	call	printf@plt
	sw	zero, 8(sp)
	li	s1, 4
	addi	s2, sp, 35
	lui	a0, %hi(.L_Const_String_.4)
	addi	s0, a0, %lo(.L_Const_String_.4)
	lw	a0, 8(sp)
	blt	s1, a0, .LBB0_6
.LBB0_5:                                # %ForLoop29
                                        # =>This Inner Loop Header: Depth=1
	lw	a0, 8(sp)
	add	a0, s2, a0
	lb	a1, 0(a0)
	mv	a0, s0
	call	printf@plt
	lw	a0, 8(sp)
	addi	a0, a0, 1
	sw	a0, 8(sp)
	lw	a0, 8(sp)
	bge	s1, a0, .LBB0_5
.LBB0_6:                                # %ForEnd36
	lui	a0, %hi(.L_Const_String_.5)
	addi	a0, a0, %lo(.L_Const_String_.5)
	call	printf@plt
	lui	a0, %hi(.L_Const_String_.6)
	addi	a0, a0, %lo(.L_Const_String_.6)
	call	printf@plt
	sw	zero, 8(sp)
	li	s1, 4
	addi	s2, sp, 40
	lui	a0, %hi(.L_Const_String_.7)
	addi	s0, a0, %lo(.L_Const_String_.7)
	lw	a0, 8(sp)
	blt	s1, a0, .LBB0_8
.LBB0_7:                                # %ForLoop42
                                        # =>This Inner Loop Header: Depth=1
	lw	a0, 8(sp)
	slli	a0, a0, 3
	add	a0, s2, a0
	lw	a2, 0(a0)
	ori	a0, a0, 4
	lw	a3, 0(a0)
	mv	a0, s0
	call	printf@plt
	lw	a0, 8(sp)
	addi	a0, a0, 1
	sw	a0, 8(sp)
	lw	a0, 8(sp)
	bge	s1, a0, .LBB0_7
.LBB0_8:                                # %ForEnd49
	lui	a0, %hi(.L_Const_String_.8)
	addi	a0, a0, %lo(.L_Const_String_.8)
	call	printf@plt
	li	a0, 0
	lw	ra, 92(sp)                      # 4-byte Folded Reload
	lw	s0, 88(sp)                      # 4-byte Folded Reload
	lw	s1, 84(sp)                      # 4-byte Folded Reload
	lw	s2, 80(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 96
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"Integer array:\n"
	.size	.L_Const_String_, 16

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%d "
	.size	.L_Const_String_.1, 4

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"\n"
	.size	.L_Const_String_.2, 2

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
	.p2align	4
.L_Const_String_.3:
	.asciz	"Character array:\n"
	.size	.L_Const_String_.3, 18

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
.L_Const_String_.4:
	.asciz	"%c "
	.size	.L_Const_String_.4, 4

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
.L_Const_String_.5:
	.asciz	"\n"
	.size	.L_Const_String_.5, 2

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
.L_Const_String_.6:
	.asciz	"Double array:\n"
	.size	.L_Const_String_.6, 15

	.type	.L_Const_String_.7,@object      # @_Const_String_.7
.L_Const_String_.7:
	.asciz	"%lf "
	.size	.L_Const_String_.7, 5

	.type	.L_Const_String_.8,@object      # @_Const_String_.8
.L_Const_String_.8:
	.asciz	"\n"
	.size	.L_Const_String_.8, 2

	.section	".note.GNU-stack","",@progbits
