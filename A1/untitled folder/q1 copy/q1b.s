	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_readcsv                        ## -- Begin function readcsv
	.p2align	4, 0x90
_readcsv:                               ## @readcsv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rsi, %rax
	movb	%dil, %cl
	xorl	%esi, %esi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -8(%rbp)
	movb	%cl, -33(%rbp)
	movq	%rax, -48(%rbp)
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_open
	movl	%eax, -52(%rbp)
	cmpl	$0, -52(%rbp)
	jge	LBB0_2
## %bb.1:
	leaq	L_.str.1(%rip), %rdi
	callq	_perror
	jmp	LBB0_41
LBB0_2:
	xorl	%esi, %esi
	leaq	-32(%rbp), %rdi
	movl	$24, %edx
	callq	_memset
	movl	$0, -56(%rbp)
	movb	$48, -57(%rbp)
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	movsbl	-57(%rbp), %eax
	cmpl	$10, %eax
	jne	LBB0_5
## %bb.4:
	jmp	LBB0_6
LBB0_5:                                 ##   in Loop: Header=BB0_3 Depth=1
	jmp	LBB0_3
LBB0_6:
	movl	$1, -72(%rbp)
LBB0_7:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_9 Depth 2
                                        ##     Child Loop BB0_19 Depth 2
                                        ##       Child Loop BB0_21 Depth 3
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	cmpq	$0, %rax
	jle	LBB0_36
## %bb.8:                               ##   in Loop: Header=BB0_7 Depth=1
	movl	$0, -68(%rbp)
LBB0_9:                                 ##   Parent Loop BB0_7 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	movsbl	-57(%rbp), %eax
	cmpl	$10, %eax
	jne	LBB0_11
## %bb.10:                              ##   in Loop: Header=BB0_7 Depth=1
	movl	$0, -72(%rbp)
	jmp	LBB0_16
LBB0_11:                                ##   in Loop: Header=BB0_9 Depth=2
	movsbl	-57(%rbp), %eax
	cmpl	$44, %eax
	jne	LBB0_15
## %bb.12:                              ##   in Loop: Header=BB0_7 Depth=1
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	movsbl	-33(%rbp), %eax
	movsbl	-57(%rbp), %ecx
	cmpl	%ecx, %eax
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, -64(%rbp)
	cmpl	$0, -64(%rbp)
	je	LBB0_14
## %bb.13:                              ##   in Loop: Header=BB0_7 Depth=1
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -56(%rbp)
LBB0_14:                                ##   in Loop: Header=BB0_7 Depth=1
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	jmp	LBB0_16
LBB0_15:                                ##   in Loop: Header=BB0_9 Depth=2
	jmp	LBB0_9
LBB0_16:                                ##   in Loop: Header=BB0_7 Depth=1
	cmpl	$0, -72(%rbp)
	jne	LBB0_18
## %bb.17:
	jmp	LBB0_36
LBB0_18:                                ##   in Loop: Header=BB0_7 Depth=1
	movl	$0, -76(%rbp)
LBB0_19:                                ##   Parent Loop BB0_7 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB0_21 Depth 3
	cmpl	$6, -76(%rbp)
	jge	LBB0_35
## %bb.20:                              ##   in Loop: Header=BB0_19 Depth=2
	movl	$0, -80(%rbp)
LBB0_21:                                ##   Parent Loop BB0_7 Depth=1
                                        ##     Parent Loop BB0_19 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	cmpq	$0, %rax
	jg	LBB0_23
## %bb.22:                              ##   in Loop: Header=BB0_19 Depth=2
	jmp	LBB0_31
LBB0_23:                                ##   in Loop: Header=BB0_21 Depth=3
	movsbl	-57(%rbp), %eax
	cmpl	$44, %eax
	je	LBB0_25
## %bb.24:                              ##   in Loop: Header=BB0_21 Depth=3
	movsbl	-57(%rbp), %eax
	cmpl	$10, %eax
	jne	LBB0_26
LBB0_25:                                ##   in Loop: Header=BB0_19 Depth=2
	jmp	LBB0_31
LBB0_26:                                ##   in Loop: Header=BB0_21 Depth=3
	movsbl	-57(%rbp), %eax
	cmpl	$13, %eax
	jne	LBB0_28
## %bb.27:                              ##   in Loop: Header=BB0_19 Depth=2
	movl	-52(%rbp), %edi
	leaq	-57(%rbp), %rsi
	movl	$1, %edx
	callq	_read
	jmp	LBB0_31
LBB0_28:                                ##   in Loop: Header=BB0_21 Depth=3
	imull	$10, -80(%rbp), %eax
	movl	%eax, -80(%rbp)
	movsbl	-57(%rbp), %eax
	subl	$48, %eax
	addl	-80(%rbp), %eax
	movl	%eax, -80(%rbp)
## %bb.29:                              ##   in Loop: Header=BB0_21 Depth=3
	jmp	LBB0_30
LBB0_30:                                ##   in Loop: Header=BB0_21 Depth=3
	jmp	LBB0_21
LBB0_31:                                ##   in Loop: Header=BB0_19 Depth=2
	cmpl	$0, -64(%rbp)
	je	LBB0_33
## %bb.32:                              ##   in Loop: Header=BB0_19 Depth=2
	cvtsi2ssl	-80(%rbp), %xmm0
	movslq	-76(%rbp), %rax
	addss	-32(%rbp,%rax,4), %xmm0
	movss	%xmm0, -32(%rbp,%rax,4)
LBB0_33:                                ##   in Loop: Header=BB0_19 Depth=2
	jmp	LBB0_34
LBB0_34:                                ##   in Loop: Header=BB0_19 Depth=2
	movl	-76(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -76(%rbp)
	jmp	LBB0_19
LBB0_35:                                ##   in Loop: Header=BB0_7 Depth=1
	jmp	LBB0_7
LBB0_36:
	movsbl	-33(%rbp), %esi
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -84(%rbp)
LBB0_37:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$6, -84(%rbp)
	jge	LBB0_40
## %bb.38:                              ##   in Loop: Header=BB0_37 Depth=1
	movslq	-84(%rbp), %rax
	movss	-32(%rbp,%rax,4), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	cvtsi2ssl	-56(%rbp), %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str.4(%rip), %rdi
	movb	$1, %al
	callq	_printf
	movslq	-84(%rbp), %rax
	movss	-32(%rbp,%rax,4), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movq	-48(%rbp), %rax
	movslq	-84(%rbp), %rcx
	addss	(%rax,%rcx,4), %xmm0
	movss	%xmm0, (%rax,%rcx,4)
## %bb.39:                              ##   in Loop: Header=BB0_37 Depth=1
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -84(%rbp)
	jmp	LBB0_37
LBB0_40:
	cvtsi2ssl	-56(%rbp), %xmm0
	movq	-48(%rbp), %rax
	addss	24(%rax), %xmm0
	movss	%xmm0, 24(%rax)
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_41:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_43
## %bb.42:
	addq	$96, %rsp
	popq	%rbp
	retq
LBB0_43:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_func                           ## -- Begin function func
	.p2align	4, 0x90
_func:                                  ## @func
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rsi
	movl	$65, %edi
	callq	_readcsv
	xorl	%eax, %eax
	movl	%eax, %edi
	callq	_pthread_exit
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rsi, %rax
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	leaq	-48(%rbp), %rcx
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -8(%rbp)
	movl	$0, -52(%rbp)
	movl	%edi, -56(%rbp)
	movq	%rax, -64(%rbp)
	leaq	-72(%rbp), %rdi
	leaq	_func(%rip), %rdx
	callq	_pthread_create
	movl	%eax, -76(%rbp)
	cmpl	$0, -76(%rbp)
	je	LBB2_2
## %bb.1:
	leaq	L_.str.6(%rip), %rdi
	callq	_perror
	movl	$1, -52(%rbp)
	jmp	LBB2_9
LBB2_2:
	movl	$100000, %edi                   ## imm = 0x186A0
	callq	_usleep
	leaq	-48(%rbp), %rsi
	movl	$66, %edi
	callq	_readcsv
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-72(%rbp), %rdi
	callq	_pthread_join
	movl	%eax, -76(%rbp)
	cmpl	$0, -76(%rbp)
	je	LBB2_4
## %bb.3:
	leaq	L_.str.7(%rip), %rdi
	callq	_perror
	movl	$1, -52(%rbp)
	jmp	LBB2_9
LBB2_4:
	leaq	L_.str.8(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -80(%rbp)
LBB2_5:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$6, -80(%rbp)
	jge	LBB2_8
## %bb.6:                               ##   in Loop: Header=BB2_5 Depth=1
	movslq	-80(%rbp), %rax
	movss	-48(%rbp,%rax,4), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	divss	-24(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str.4(%rip), %rdi
	movb	$1, %al
	callq	_printf
## %bb.7:                               ##   in Loop: Header=BB2_5 Depth=1
	movl	-80(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -80(%rbp)
	jmp	LBB2_5
LBB2_8:
	movl	$0, -52(%rbp)
LBB2_9:
	movl	-52(%rbp), %eax
	movl	%eax, -84(%rbp)                 ## 4-byte Spill
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB2_11
## %bb.10:
	movl	-84(%rbp), %eax                 ## 4-byte Reload
	addq	$96, %rsp
	popq	%rbp
	retq
LBB2_11:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"student_record.csv"

L_.str.1:                               ## @.str.1
	.asciz	"File open"

L_.str.2:                               ## @.str.2
	.asciz	"Section: %c\n"

L_.str.3:                               ## @.str.3
	.asciz	"Assignment 1 | Assignment 2 | Assignment 3 | Assignment 4 | Assignment 5 | Assignment 6\n"

L_.str.4:                               ## @.str.4
	.asciz	"%f      "

L_.str.5:                               ## @.str.5
	.asciz	"\n\n"

L_.str.6:                               ## @.str.6
	.asciz	"pthread_create"

L_.str.7:                               ## @.str.7
	.asciz	"pthread_join"

L_.str.8:                               ## @.str.8
	.asciz	"Section: A & B\n"

.subsections_via_symbols
