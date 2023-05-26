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
	li	a0, 10
	sw	a0, 12(sp)
	li	a0, 5
	sw	a0, 16(sp)
	lui	a0, %hi(.L_Const_String_)
	addi	a0, a0, %lo(.L_Const_String_)
	li	a1, 10
	li	a2, 5
	li	a3, 15
	call	printf@plt
	lw	a1, 12(sp)
	lw	a2, 16(sp)
	sub	a3, a1, a2
	lui	a0, %hi(.L_Const_String_.1)
	addi	a0, a0, %lo(.L_Const_String_.1)
	call	printf@plt
	lw	s0, 12(sp)
	lw	s1, 16(sp)
	mv	a0, s0
	mv	a1, s1
	call	__mulsi3@plt
	mv	a3, a0
	lui	a0, %hi(.L_Const_String_.2)
	addi	a0, a0, %lo(.L_Const_String_.2)
	mv	a1, s0
	mv	a2, s1
	call	printf@plt
	lw	s0, 12(sp)
	lw	s1, 16(sp)
	mv	a0, s0
	mv	a1, s1
	call	__divsi3@plt
	mv	a3, a0
	lui	a0, %hi(.L_Const_String_.3)
	addi	a0, a0, %lo(.L_Const_String_.3)
	mv	a1, s0
	mv	a2, s1
	call	printf@plt
	lui	a0, %hi(.L_Const_String_.4)
	addi	a0, a0, %lo(.L_Const_String_.4)
	li	a1, 0
	call	printf@plt
	lui	a0, %hi(.L_Const_String_.5)
	addi	a0, a0, %lo(.L_Const_String_.5)
	li	a1, 1
	call	printf@plt
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	xor	a0, a0, a1
	seqz	a1, a0
	lui	a0, %hi(.L_Const_String_.6)
	addi	a0, a0, %lo(.L_Const_String_.6)
	call	printf@plt
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	xor	a0, a0, a1
	snez	a1, a0
	lui	a0, %hi(.L_Const_String_.7)
	addi	a0, a0, %lo(.L_Const_String_.7)
	call	printf@plt
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	slt	a1, a0, a1
	lui	a0, %hi(.L_Const_String_.8)
	addi	a0, a0, %lo(.L_Const_String_.8)
	call	printf@plt
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	slt	a1, a1, a0
	lui	a0, %hi(.L_Const_String_.9)
	addi	a0, a0, %lo(.L_Const_String_.9)
	call	printf@plt
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	slt	a0, a1, a0
	xori	a1, a0, 1
	lui	a0, %hi(.L_Const_String_.10)
	addi	a0, a0, %lo(.L_Const_String_.10)
	call	printf@plt
	lw	a0, 12(sp)
	lw	a1, 16(sp)
	slt	a0, a0, a1
	xori	a1, a0, 1
	lui	a0, %hi(.L_Const_String_.11)
	addi	a0, a0, %lo(.L_Const_String_.11)
	call	printf@plt
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
	.asciz	"Addition: %d + %d = %d\n"
	.size	.L_Const_String_, 24

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
	.p2align	4
.L_Const_String_.1:
	.asciz	"Subtraction: %d - %d = %d\n"
	.size	.L_Const_String_.1, 27

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
	.p2align	4
.L_Const_String_.2:
	.asciz	"Multiplication: %d * %d = %d\n"
	.size	.L_Const_String_.2, 30

	.type	.L_Const_String_.3,@object      # @_Const_String_.3
	.p2align	4
.L_Const_String_.3:
	.asciz	"Division: %d / %d = %d\n"
	.size	.L_Const_String_.3, 24

	.type	.L_Const_String_.4,@object      # @_Const_String_.4
	.p2align	4
.L_Const_String_.4:
	.asciz	"Logical AND: (a == b) && (a != b) = %d\n"
	.size	.L_Const_String_.4, 40

	.type	.L_Const_String_.5,@object      # @_Const_String_.5
	.p2align	4
.L_Const_String_.5:
	.asciz	"Logical OR: (a == b) || (a != b) = %d\n"
	.size	.L_Const_String_.5, 39

	.type	.L_Const_String_.6,@object      # @_Const_String_.6
	.p2align	4
.L_Const_String_.6:
	.asciz	"Equals: a == b -> %d\n"
	.size	.L_Const_String_.6, 22

	.type	.L_Const_String_.7,@object      # @_Const_String_.7
	.p2align	4
.L_Const_String_.7:
	.asciz	"Not Equals: a != b -> %d\n"
	.size	.L_Const_String_.7, 26

	.type	.L_Const_String_.8,@object      # @_Const_String_.8
	.p2align	4
.L_Const_String_.8:
	.asciz	"Less Than: a < b -> %d\n"
	.size	.L_Const_String_.8, 24

	.type	.L_Const_String_.9,@object      # @_Const_String_.9
	.p2align	4
.L_Const_String_.9:
	.asciz	"Greater Than: a > b -> %d\n"
	.size	.L_Const_String_.9, 27

	.type	.L_Const_String_.10,@object     # @_Const_String_.10
	.p2align	4
.L_Const_String_.10:
	.asciz	"Less Than or Equals: a <= b -> %d\n"
	.size	.L_Const_String_.10, 35

	.type	.L_Const_String_.11,@object     # @_Const_String_.11
	.p2align	4
.L_Const_String_.11:
	.asciz	"Greater Than or Equals: a >= b -> %d\n"
	.size	.L_Const_String_.11, 38

	.section	".note.GNU-stack","",@progbits
