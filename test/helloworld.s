	.text
	.file	"main"
	.globl	add                             # -- Begin function add
	.p2align	4, 0x90
	.type	add,@function
add:                                    # @add
	.cfi_startproc
# %bb.0:                                # %entry
                                        # kill: def $esi killed $esi def $rsi
                                        # kill: def $edi killed $edi def $rdi
	movl	%edi, -12(%rsp)
	movl	%esi, -8(%rsp)
	leal	(%rdi,%rsi), %eax
	movl	%eax, -4(%rsp)
	retq
.Lfunc_end0:
	.size	add, .Lfunc_end0-add
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movabsq	$4607632778762754458, %rax      # imm = 0x3FF199999999999A
	movq	%rax, 24(%rsp)
	movl	$1, 16(%rsp)
	movl	$3, %edi
	movl	$4, %esi
	callq	add@PLT
	movl	%eax, 16(%rsp)
	movl	$.L_Const_String_, %edi
	movl	%eax, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$1, 20(%rsp)
	movl	$5, 12(%rsp)
	cmpl	$5, 12(%rsp)
	jg	.LBB1_4
	.p2align	4, 0x90
.LBB1_2:                                # %WhileLoop
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$5, 12(%rsp)
	je	.LBB1_4
# %bb.3:                                # %Else
                                        #   in Loop: Header=BB1_2 Depth=1
	incl	12(%rsp)
	cmpl	$5, 12(%rsp)
	jle	.LBB1_2
.LBB1_4:                                # %WhileEnd
	movl	20(%rsp), %esi
	movl	$.L_Const_String_.1, %edi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	12(%rsp), %esi
	movl	$.L_Const_String_.2, %edi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.L_Const_String_,@object        # @_Const_String_
	.section	.rodata,"a",@progbits
.L_Const_String_:
	.asciz	"%d\n"
	.size	.L_Const_String_, 4

	.type	.L_Const_String_.1,@object      # @_Const_String_.1
.L_Const_String_.1:
	.asciz	"%d\n"
	.size	.L_Const_String_.1, 4

	.type	.L_Const_String_.2,@object      # @_Const_String_.2
.L_Const_String_.2:
	.asciz	"%d\n"
	.size	.L_Const_String_.2, 4

	.section	".note.GNU-stack","",@progbits
