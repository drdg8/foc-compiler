	.text
	.attribute	4, 16
	.attribute	5, "rv32i2p0"
	.file	"main"
	.globl	quicksort                       # -- Begin function quicksort
	.p2align	2
	.type	quicksort,@function
quicksort:                              # @quicksort
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -32
	.cfi_def_cfa_offset 32
	sw	ra, 28(sp)                      # 4-byte Folded Spill
	.cfi_offset ra, -4
	sw	a0, 0(sp)
	sw	a1, 4(sp)
	sw	a2, 8(sp)
	sw	a1, 12(sp)
	sw	a2, 16(sp)
	add	a1, a1, a2
	srli	a2, a1, 31
	add	a1, a1, a2
	slli	a1, a1, 1
	andi	a1, a1, -4
	add	a0, a0, a1
	lw	a0, 0(a0)
	sw	a0, 20(sp)
.LBB0_1:                                # %WhileCond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_2 Depth 2
                                        #     Child Loop BB0_5 Depth 2
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	blt	a1, a0, .LBB0_8
.LBB0_2:                                # %WhileCond6
                                        #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, 12(sp)
	lw	a1, 0(sp)
	slli	a0, a0, 2
	add	a0, a1, a0
	lw	a0, 0(a0)
	lw	a1, 20(sp)
	bge	a0, a1, .LBB0_5
# %bb.3:                                # %WhileLoop12
                                        #   in Loop: Header=BB0_2 Depth=2
	lw	a0, 12(sp)
	addi	a0, a0, 1
	sw	a0, 12(sp)
	j	.LBB0_2
.LBB0_4:                                # %WhileLoop20
                                        #   in Loop: Header=BB0_5 Depth=2
	lw	a0, 16(sp)
	addi	a0, a0, -1
	sw	a0, 16(sp)
.LBB0_5:                                # %WhileCond14
                                        #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	lw	a0, 16(sp)
	lw	a1, 0(sp)
	lw	a2, 20(sp)
	slli	a0, a0, 2
	add	a0, a1, a0
	lw	a0, 0(a0)
	blt	a2, a0, .LBB0_4
# %bb.6:                                # %WhileEnd22
                                        #   in Loop: Header=BB0_1 Depth=1
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	blt	a1, a0, .LBB0_1
# %bb.7:                                # %Then
                                        #   in Loop: Header=BB0_1 Depth=1
	lw	a0, 12(sp)
	lw	a1, 0(sp)
	slli	a0, a0, 2
	add	a0, a1, a0
	lw	a2, 0(a0)
	lw	a3, 16(sp)
	sw	a2, 24(sp)
	slli	a2, a3, 2
	add	a1, a1, a2
	lw	a1, 0(a1)
	sw	a1, 0(a0)
	lw	a0, 16(sp)
	lw	a1, 0(sp)
	lw	a2, 24(sp)
	slli	a0, a0, 2
	add	a0, a1, a0
	sw	a2, 0(a0)
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	addi	a0, a0, 1
	sw	a0, 12(sp)
	addi	a0, a1, -1
	sw	a0, 16(sp)
	j	.LBB0_1
.LBB0_8:                                # %WhileEnd39
	lw	a0, 4(sp)
	lw	a1, 16(sp)
	bge	a0, a1, .LBB0_10
# %bb.9:                                # %Then43
	lw	a0, 0(sp)
	lw	a1, 4(sp)
	lw	a2, 16(sp)
	call	quicksort@plt
.LBB0_10:                               # %Merge48
	lw	a0, 12(sp)
	lw	a1, 8(sp)
	bge	a0, a1, .LBB0_12
# %bb.11:                               # %Then52
	lw	a0, 0(sp)
	lw	a1, 12(sp)
	lw	a2, 8(sp)
	call	quicksort@plt
.LBB0_12:                               # %Merge57
	lw	ra, 28(sp)                      # 4-byte Folded Reload
	addi	sp, sp, 32
	ret
.Lfunc_end0:
	.size	quicksort, .Lfunc_end0-quicksort
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	addi	sp, sp, -2032
	.cfi_def_cfa_offset 2032
	sw	ra, 2028(sp)                    # 4-byte Folded Spill
	sw	s0, 2024(sp)                    # 4-byte Folded Spill
	sw	s1, 2020(sp)                    # 4-byte Folded Spill
	.cfi_offset ra, -4
	.cfi_offset s0, -8
	.cfi_offset s1, -12
	lui	a0, 976
	addi	a0, a0, 304
	sub	sp, sp, a0
	.cfi_def_cfa_offset 4000032
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	lui	a1, 977
	addi	a1, a1, -1788
	add	a1, sp, a1
	call	scanf@plt
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	sw	zero, 0(a0)
	addi	s1, sp, 4
	lui	a0, %hi(.L_Const_String_.1)
	addi	s0, a0, %lo(.L_Const_String_.1)
.LBB1_1:                                # %WhileCond
                                        # =>This Inner Loop Header: Depth=1
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	lw	a0, 0(a0)
	lui	a1, 977
	addi	a1, a1, -1788
	add	a1, sp, a1
	lw	a1, 0(a1)
	bge	a0, a1, .LBB1_3
# %bb.2:                                # %WhileLoop
                                        #   in Loop: Header=BB1_1 Depth=1
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	lw	a0, 0(a0)
	slli	a0, a0, 2
	add	a1, s1, a0
	mv	a0, s0
	call	scanf@plt
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	lw	a0, 0(a0)
	addi	a0, a0, 1
	lui	a1, 977
	addi	a1, a1, -1784
	add	a1, sp, a1
	sw	a0, 0(a1)
	j	.LBB1_1
.LBB1_3:                                # %WhileEnd
	lui	a0, 977
	addi	a0, a0, -1788
	add	a0, sp, a0
	lw	a0, 0(a0)
	lui	a1, 977
	addi	a1, a1, -1780
	add	a1, sp, a1
	sw	zero, 0(a1)
	addi	a2, a0, -1
	lui	a0, 977
	addi	a0, a0, -1776
	add	a0, sp, a0
	sw	a2, 0(a0)
	addi	a0, sp, 4
	addi	s1, sp, 4
	li	a1, 0
	call	quicksort@plt
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	sw	zero, 0(a0)
	lui	a0, %hi(.L_Const_String_.2)
	addi	s0, a0, %lo(.L_Const_String_.2)
.LBB1_4:                                # %WhileCond8
                                        # =>This Inner Loop Header: Depth=1
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	lw	a0, 0(a0)
	lui	a1, 977
	addi	a1, a1, -1788
	add	a1, sp, a1
	lw	a1, 0(a1)
	bge	a0, a1, .LBB1_6
# %bb.5:                                # %WhileLoop12
                                        #   in Loop: Header=BB1_4 Depth=1
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	lw	a0, 0(a0)
	slli	a0, a0, 2
	add	a0, s1, a0
	lw	a1, 0(a0)
	mv	a0, s0
	call	printf@plt
	lui	a0, 977
	addi	a0, a0, -1784
	add	a0, sp, a0
	lw	a0, 0(a0)
	addi	a0, a0, 1
	lui	a1, 977
	addi	a1, a1, -1784
	add	a1, sp, a1
	sw	a0, 0(a1)
	j	.LBB1_4
.LBB1_6:                                # %WhileEnd15
	li	a0, 0
	lui	a1, 976
	addi	a1, a1, 304
	add	sp, sp, a1
	lw	ra, 2028(sp)                    # 4-byte Folded Reload
	lw	s0, 2024(sp)                    # 4-byte Folded Reload
	lw	s1, 2020(sp)                    # 4-byte Folded Reload
	addi	sp, sp, 2032
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%d"
	.size	.L_Const_String_, 3

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%d"
	.size	.L_Const_String_.1, 3

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"%d\n"
	.size	.L_Const_String_.2, 4

	.section	".note.GNU-stack","",@progbits
