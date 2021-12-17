	.file	"q1a.c"
	.text
	.section	.rodata
.LC0:
	.string	"student_record.csv"
.LC1:
	.string	"File open"
.LC3:
	.string	"Section: %c\n"
	.align 8
.LC4:
	.string	"Assignment 1|Assignment 2|Assignment 3|Assignment 4|Assignment 5|Assignment 6"
.LC5:
	.string	"  00.000000  "
.LC6:
	.string	"  %f  "
.LC7:
	.string	"\n"
	.text
	.globl	readcsv
	.type	readcsv, @function
readcsv:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, %eax
	movb	%al, -84(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -40(%rbp)
	cmpl	$0, -40(%rbp)
	jns	.L2
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	jmp	.L1
.L2:
	pxor	%xmm0, %xmm0
	movss	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -28(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -24(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -20(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -12(%rbp)
	movl	$0, -64(%rbp)
	movb	$48, -65(%rbp)
.L6:
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movzbl	-65(%rbp), %eax
	cmpb	$10, %al
	je	.L29
	jmp	.L6
.L29:
	nop
	movl	$1, -56(%rbp)
	jmp	.L7
.L22:
	movl	$0, -36(%rbp)
.L12:
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movzbl	-65(%rbp), %eax
	cmpb	$10, %al
	jne	.L8
	movl	$0, -56(%rbp)
	jmp	.L9
.L8:
	movzbl	-65(%rbp), %eax
	cmpb	$44, %al
	jne	.L12
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movzbl	-65(%rbp), %eax
	cmpb	%al, -84(%rbp)
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -60(%rbp)
	cmpl	$0, -60(%rbp)
	je	.L11
	addl	$1, -64(%rbp)
.L11:
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
.L9:
	cmpl	$0, -56(%rbp)
	je	.L30
	movl	$0, -52(%rbp)
	jmp	.L15
.L21:
	movl	$0, -48(%rbp)
.L19:
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	testq	%rax, %rax
	jle	.L31
	movzbl	-65(%rbp), %eax
	cmpb	$44, %al
	je	.L17
	movzbl	-65(%rbp), %eax
	cmpb	$10, %al
	je	.L17
	movzbl	-65(%rbp), %eax
	cmpb	$13, %al
	jne	.L18
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	jmp	.L17
.L18:
	movl	-48(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, -48(%rbp)
	movzbl	-65(%rbp), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	addl	%eax, -48(%rbp)
	jmp	.L19
.L31:
	nop
.L17:
	cmpl	$0, -60(%rbp)
	je	.L20
	movl	-52(%rbp), %eax
	cltq
	movss	-32(%rbp,%rax,4), %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-48(%rbp), %xmm0
	addss	%xmm1, %xmm0
	movl	-52(%rbp), %eax
	cltq
	movss	%xmm0, -32(%rbp,%rax,4)
.L20:
	addl	$1, -52(%rbp)
.L15:
	cmpl	$5, -52(%rbp)
	jle	.L21
.L7:
	leaq	-65(%rbp), %rcx
	movl	-40(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	testq	%rax, %rax
	jg	.L22
	jmp	.L14
.L30:
	nop
.L14:
	movsbl	-84(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -44(%rbp)
	jmp	.L23
.L26:
	movl	-44(%rbp), %eax
	cltq
	movss	-32(%rbp,%rax,4), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2ssl	-64(%rbp), %xmm1
	divss	%xmm1, %xmm0
	ucomiss	%xmm0, %xmm0
	jnp	.L24
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L25
.L24:
	movl	-44(%rbp), %eax
	cltq
	movss	-32(%rbp,%rax,4), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2ssl	-64(%rbp), %xmm1
	divss	%xmm1, %xmm0
	pxor	%xmm2, %xmm2
	cvtss2sd	%xmm0, %xmm2
	movq	%xmm2, %rax
	movq	%rax, %xmm0
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
.L25:
	addl	$1, -44(%rbp)
.L23:
	cmpl	$5, -44(%rbp)
	jle	.L26
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L1:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L27
	call	__stack_chk_fail@PLT
.L27:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	readcsv, .-readcsv
	.section	.rodata
.LC8:
	.string	"pid"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	call	fork@PLT
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jns	.L33
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L34
.L33:
	cmpl	$0, -12(%rbp)
	jne	.L35
	movl	$65, %edi
	call	readcsv
	movl	$0, %edi
	call	exit@PLT
.L35:
	leaq	-16(%rbp), %rcx
	movl	-12(%rbp), %eax
	movl	$0, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	waitpid@PLT
	movl	$66, %edi
	call	readcsv
	movl	$0, %eax
.L34:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L36
	call	__stack_chk_fail@PLT
.L36:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
