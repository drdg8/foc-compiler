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
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movabsq	$4607632778762754458, %rax      # imm = 0x3FF199999999999A
	movq	%rax, 16(%rsp)
	movl	$1, 12(%rsp)
	movl	$3, %edi
	movl	$4, %esi
	callq	add@PLT
	movl	%eax, 12(%rsp)
	movl	$1, 8(%rsp)
	cmpl	$3, %eax
	jne	.LBB1_2
# %bb.1:                                # %Then
	incl	8(%rsp)
	jmp	.LBB1_3
.LBB1_2:                                # %Else
	decl	8(%rsp)
.LBB1_3:                                # %Merge
	movl	8(%rsp), %esi
	movl	$.L_Const_String_, %edi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$24, %rsp
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

	.section	".note.GNU-stack","",@progbits
