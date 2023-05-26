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
	addi	sp, sp, -80
	.cfi_def_cfa_offset 80
	sw	ra, 76(sp)                      # 4-byte Folded Spill
	sw	s0, 72(sp)                      # 4-byte Folded Spill
	sw	s1, 68(sp)                      # 4-byte Folded Spill
	sw	s2, 64(sp)                      # 4-byte Folded Spill
	sw	s3, 60(sp)                      # 4-byte Folded Spill
	sw	s4, 56(sp)                      # 4-byte Folded Spill
	sw	s5, 52(sp)                      # 4-byte Folded Spill
	sw	s6, 48(sp)                      # 4-byte Folded Spill
	sw	s7, 44(sp)                      # 4-byte Folded Spill
	sw	s8, 40(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	.cfi_offset s1, -12
	.cfi_offset s2, -16
	.cfi_offset s3, -20
	.cfi_offset s4, -24
	.cfi_offset s5, -28
	.cfi_offset s6, -32
	.cfi_offset s7, -36
	.cfi_offset s8, -40
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	addi	a1, sp, 12
	addi	a2, sp, 16
	call	scanf@plt
	sw	zero, 28(sp)
	sw	zero, 32(sp)
	lui	a0, %hi(A)
	addi	s1, a0, %lo(A)
	lui	a0, %hi(.L_Const_String_.1)
	addi	s0, a0, %lo(.L_Const_String_.1)
	j	.LBB0_2
.LBB0_1:                                # %WhileEnd
                                        #   in Loop: Header=BB0_2 Depth=1
	lw	a0, 28(sp)
	addi	a0, a0, 1
	sw	a0, 28(sp)
.LBB0_2:                                # %WhileCond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_4 Depth 2
	lw	a0, 28(sp)
	lw	a1, 12(sp)
	bge	a0, a1, .LBB0_6
# %bb.3:                                # %WhileLoop
                                        #   in Loop: Header=BB0_2 Depth=1
	sw	zero, 32(sp)
.LBB0_4:                                # %WhileCond2
                                        #   Parent Loop BB0_2 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, 32(sp)
	lw	a1, 16(sp)
	bge	a0, a1, .LBB0_1
# %bb.5:                                # %WhileLoop6
                                        #   in Loop: Header=BB0_4 Depth=2
	lw	a0, 28(sp)
	lw	a1, 16(sp)
	call	__mulsi3@plt
	lw	a1, 32(sp)
	add	a0, a0, a1
	slli	a0, a0, 2
	add	a1, s1, a0
	mv	a0, s0
	call	scanf@plt
	lw	a0, 32(sp)
	addi	a0, a0, 1
	sw	a0, 32(sp)
	j	.LBB0_4
.LBB0_6:                                # %WhileEnd13
	lui	a0, %hi(.L_Const_String_.2)
	addi	a0, a0, %lo(.L_Const_String_.2)
	addi	a1, sp, 20
	addi	a2, sp, 24
	call	scanf@plt
	sw	zero, 28(sp)
	sw	zero, 32(sp)
	lui	a0, %hi(B)
	addi	s1, a0, %lo(B)
	lui	a0, %hi(.L_Const_String_.3)
	addi	s0, a0, %lo(.L_Const_String_.3)
	j	.LBB0_8
.LBB0_7:                                # %WhileEnd31
                                        #   in Loop: Header=BB0_8 Depth=1
	lw	a0, 28(sp)
	addi	a0, a0, 1
	sw	a0, 28(sp)
.LBB0_8:                                # %WhileCond15
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_10 Depth 2
	lw	a0, 28(sp)
	lw	a1, 20(sp)
	bge	a0, a1, .LBB0_12
# %bb.9:                                # %WhileLoop19
                                        #   in Loop: Header=BB0_8 Depth=1
	sw	zero, 32(sp)
.LBB0_10:                               # %WhileCond20
                                        #   Parent Loop BB0_8 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, 32(sp)
	lw	a1, 24(sp)
	bge	a0, a1, .LBB0_7
# %bb.11:                               # %WhileLoop24
                                        #   in Loop: Header=BB0_10 Depth=2
	lw	a0, 28(sp)
	lw	a1, 24(sp)
	call	__mulsi3@plt
	lw	a1, 32(sp)
	add	a0, a0, a1
	slli	a0, a0, 2
	add	a1, s1, a0
	mv	a0, s0
	call	scanf@plt
	lw	a0, 32(sp)
	addi	a0, a0, 1
	sw	a0, 32(sp)
	j	.LBB0_10
.LBB0_12:                               # %WhileEnd33
	lw	a0, 16(sp)
	lw	a1, 20(sp)
	beq	a0, a1, .LBB0_15
# %bb.13:                               # %Then
	lui	a0, %hi(.L_Const_String_.4)
	addi	a0, a0, %lo(.L_Const_String_.4)
	call	printf@plt
.LBB0_14:                               # %WhileEnd99
	li	a0, 0
	lw	ra, 76(sp)                      # 4-byte Folded Reload
	lw	s0, 72(sp)                      # 4-byte Folded Reload
	lw	s1, 68(sp)                      # 4-byte Folded Reload
	lw	s2, 64(sp)                      # 4-byte Folded Reload
	lw	s3, 60(sp)                      # 4-byte Folded Reload
	lw	s4, 56(sp)                      # 4-byte Folded Reload
	lw	s5, 52(sp)                      # 4-byte Folded Reload
	lw	s6, 48(sp)                      # 4-byte Folded Reload
	lw	s7, 44(sp)                      # 4-byte Folded Reload
	lw	s8, 40(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 80
	ret
.LBB0_15:                               # %Else
	sw	zero, 28(sp)
	sw	zero, 32(sp)
	lui	a0, %hi(C)
	addi	s3, a0, %lo(C)
	lui	a0, %hi(A)
	addi	s4, a0, %lo(A)
	lui	a0, %hi(B)
	addi	s5, a0, %lo(B)
	j	.LBB0_17
.LBB0_16:                               # %WhileEnd76
                                        #   in Loop: Header=BB0_17 Depth=1
	lw	a0, 28(sp)
	addi	a0, a0, 1
	sw	a0, 28(sp)
.LBB0_17:                               # %WhileCond37
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_20 Depth 2
                                        #       Child Loop BB0_22 Depth 3
	lw	a0, 28(sp)
	lw	a1, 12(sp)
	bge	a0, a1, .LBB0_24
# %bb.18:                               # %WhileLoop41
                                        #   in Loop: Header=BB0_17 Depth=1
	sw	zero, 32(sp)
	j	.LBB0_20
.LBB0_19:                               # %WhileEnd74
                                        #   in Loop: Header=BB0_20 Depth=2
	lw	a0, 32(sp)
	addi	a0, a0, 1
	sw	a0, 32(sp)
.LBB0_20:                               # %WhileCond42
                                        #   Parent Loop BB0_17 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_22 Depth 3
	lw	a0, 32(sp)
	lw	a1, 24(sp)
	bge	a0, a1, .LBB0_16
# %bb.21:                               # %WhileLoop46
                                        #   in Loop: Header=BB0_20 Depth=2
	lw	a0, 28(sp)
	lw	a1, 24(sp)
	call	__mulsi3@plt
	lw	a1, 32(sp)
	add	a0, a0, a1
	slli	a0, a0, 2
	add	a0, s3, a0
	sw	zero, 0(a0)
	sw	zero, 36(sp)
.LBB0_22:                               # %WhileCond50
                                        #   Parent Loop BB0_17 Depth=1
                                        #     Parent Loop BB0_20 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	lw	a0, 36(sp)
	lw	a1, 16(sp)
	bge	a0, a1, .LBB0_19
# %bb.23:                               # %WhileLoop54
                                        #   in Loop: Header=BB0_22 Depth=3
	lw	s0, 28(sp)
	lw	s1, 24(sp)
	mv	a0, s0
	mv	a1, s1
	call	__mulsi3@plt
	lw	s6, 32(sp)
	add	a0, a0, s6
	slli	a0, a0, 2
	add	s7, s3, a0
	lw	s8, 0(s7)
	lw	a1, 16(sp)
	mv	a0, s0
	call	__mulsi3@plt
	lw	s0, 36(sp)
	add	a0, a0, s0
	slli	a0, a0, 2
	add	a0, s4, a0
	lw	s2, 0(a0)
	mv	a0, s0
	mv	a1, s1
	call	__mulsi3@plt
	add	a0, a0, s6
	slli	a0, a0, 2
	add	a0, s5, a0
	lw	a1, 0(a0)
	mv	a0, s2
	call	__mulsi3@plt
	add	a0, s8, a0
	sw	a0, 0(s7)
	addi	a0, s0, 1
	sw	a0, 36(sp)
	j	.LBB0_22
.LBB0_24:                               # %WhileEnd78
	sw	zero, 28(sp)
	lui	a0, %hi(C)
	addi	s2, a0, %lo(C)
	lui	a0, %hi(.L_Const_String_.5)
	addi	s0, a0, %lo(.L_Const_String_.5)
	lui	a0, %hi(.L_Const_String_.6)
	addi	s1, a0, %lo(.L_Const_String_.6)
	j	.LBB0_26
.LBB0_25:                               # %WhileEnd96
                                        #   in Loop: Header=BB0_26 Depth=1
	mv	a0, s1
	call	printf@plt
	lw	a0, 28(sp)
	addi	a0, a0, 1
	sw	a0, 28(sp)
.LBB0_26:                               # %WhileCond79
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_28 Depth 2
	lw	a0, 28(sp)
	lw	a1, 12(sp)
	bge	a0, a1, .LBB0_14
# %bb.27:                               # %WhileLoop83
                                        #   in Loop: Header=BB0_26 Depth=1
	sw	zero, 32(sp)
.LBB0_28:                               # %WhileCond84
                                        #   Parent Loop BB0_26 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, 32(sp)
	lw	a1, 24(sp)
	bge	a0, a1, .LBB0_25
# %bb.29:                               # %WhileLoop88
                                        #   in Loop: Header=BB0_28 Depth=2
	lw	a0, 28(sp)
	lw	a1, 24(sp)
	call	__mulsi3@plt
	lw	a1, 32(sp)
	add	a0, a0, a1
	slli	a0, a0, 2
	add	a0, s2, a0
	lw	a1, 0(a0)
	mv	a0, s0
	call	printf@plt
	lw	a0, 32(sp)
	addi	a0, a0, 1
	sw	a0, 32(sp)
	j	.LBB0_28
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	A,@object                       # @A
	.bss
	.globl	A
	.p2align	4
A:
	.zero	800000
	.size	A, 800000

	.type	B,@object                       # @B
	.globl	B
	.p2align	4
B:
	.zero	800000
	.size	B, 800000

	.type	C,@object                       # @C
	.globl	C
	.p2align	4
C:
	.zero	800000
	.size	C, 800000

	.type	input,@object                   # @input
	.globl	input
	.p2align	4
input:
	.zero	100000
	.size	input, 100000

	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%d %d\n"
	.size	.L_Const_String_, 7

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%d"
	.size	.L_Const_String_.1, 3

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"%d %d"
	.size	.L_Const_String_.2, 6

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
.L_Const_String_.3:
	.asciz	"%d"
	.size	.L_Const_String_.3, 3

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
	.p2align	4
.L_Const_String_.4:
	.asciz	"Incompatible Dimensions\n"
	.size	.L_Const_String_.4, 25

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
.L_Const_String_.5:
	.asciz	"%10d"
	.size	.L_Const_String_.5, 5

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
.L_Const_String_.6:
	.asciz	"\n"
	.size	.L_Const_String_.6, 2

	.section	".note.GNU-stack","",@progbits
