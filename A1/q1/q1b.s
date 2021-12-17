	.file	"q1b.c"
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
	addq	$-128, %rsp
	movl	%edi, %eax
	movq	%rsi, -128(%rbp)
	movb	%al, -116(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -72(%rbp)
	cmpl	$0, -72(%rbp)
	jns	.L2
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	jmp	.L1
.L2:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -64(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -56(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -48(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -40(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	$0, -96(%rbp)
	movb	$48, -97(%rbp)
.L6:
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movzbl	-97(%rbp), %eax
	cmpb	$10, %al
	je	.L30
	jmp	.L6
.L30:
	nop
	movl	$1, -88(%rbp)
	jmp	.L7
.L22:
	movl	$0, -68(%rbp)
.L12:
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movzbl	-97(%rbp), %eax
	cmpb	$10, %al
	jne	.L8
	movl	$0, -88(%rbp)
	jmp	.L9
.L8:
	movzbl	-97(%rbp), %eax
	cmpb	$44, %al
	jne	.L12
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movzbl	-97(%rbp), %eax
	cmpb	%al, -116(%rbp)
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -92(%rbp)
	cmpl	$0, -92(%rbp)
	je	.L11
	addl	$1, -96(%rbp)
.L11:
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
.L9:
	cmpl	$0, -88(%rbp)
	je	.L31
	movl	$0, -84(%rbp)
	jmp	.L15
.L21:
	movl	$0, -80(%rbp)
.L19:
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	testq	%rax, %rax
	jle	.L32
	movzbl	-97(%rbp), %eax
	cmpb	$44, %al
	je	.L17
	movzbl	-97(%rbp), %eax
	cmpb	$10, %al
	je	.L17
	movzbl	-97(%rbp), %eax
	cmpb	$13, %al
	jne	.L18
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	jmp	.L17
.L18:
	movl	-80(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, -80(%rbp)
	movzbl	-97(%rbp), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	addl	%eax, -80(%rbp)
	jmp	.L19
.L32:
	nop
.L17:
	cmpl	$0, -92(%rbp)
	je	.L20
	movl	-84(%rbp), %eax
	cltq
	movsd	-64(%rbp,%rax,8), %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-80(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movl	-84(%rbp), %eax
	cltq
	movsd	%xmm0, -64(%rbp,%rax,8)
.L20:
	addl	$1, -84(%rbp)
.L15:
	cmpl	$5, -84(%rbp)
	jle	.L21
.L7:
	leaq	-97(%rbp), %rcx
	movl	-72(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	testq	%rax, %rax
	jg	.L22
	jmp	.L14
.L31:
	nop
.L14:
	movsbl	-116(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -76(%rbp)
	jmp	.L23
.L26:
	movl	-76(%rbp), %eax
	cltq
	movsd	-64(%rbp,%rax,8), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-96(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.L24
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L25
.L24:
	movl	-76(%rbp), %eax
	cltq
	movsd	-64(%rbp,%rax,8), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-96(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
.L25:
	movl	-76(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-128(%rbp), %rax
	addq	%rdx, %rax
	movsd	(%rax), %xmm1
	movl	-76(%rbp), %eax
	cltq
	movsd	-64(%rbp,%rax,8), %xmm0
	movl	-76(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-128(%rbp), %rax
	addq	%rdx, %rax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	addl	$1, -76(%rbp)
.L23:
	cmpl	$5, -76(%rbp)
	jle	.L26
	movq	-128(%rbp), %rax
	addq	$48, %rax
	movsd	(%rax), %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-96(%rbp), %xmm0
	movq	-128(%rbp), %rax
	addq	$48, %rax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
.L1:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L28
	call	__stack_chk_fail@PLT
.L28:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	readcsv, .-readcsv
	.globl	func
	.type	func, @function
func:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$65, %edi
	call	readcsv
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE7:
	.size	func, .-func
	.section	.rodata
.LC8:
	.string	"pthread_create"
.LC9:
	.string	"pthread_join"
.LC10:
	.string	"Section: A & B"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
	leaq	-64(%rbp), %rdx
	leaq	-72(%rbp), %rax
	movq	%rdx, %rcx
	leaq	func(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	movl	%eax, -76(%rbp)
	cmpl	$0, -76(%rbp)
	je	.L35
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L42
.L35:
	movl	$100000, %edi
	call	usleep@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$66, %edi
	call	readcsv
	movq	-72(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	movl	%eax, -76(%rbp)
	cmpl	$0, -76(%rbp)
	je	.L37
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L42
.L37:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -80(%rbp)
	jmp	.L38
.L41:
	movl	-80(%rbp), %eax
	cltq
	movsd	-64(%rbp,%rax,8), %xmm0
	movsd	-16(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jnp	.L39
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L40
.L39:
	movl	-80(%rbp), %eax
	cltq
	movsd	-64(%rbp,%rax,8), %xmm0
	movsd	-16(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
.L40:
	addl	$1, -80(%rbp)
.L38:
	cmpl	$5, -80(%rbp)
	jle	.L41
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
.L42:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L43
	call	__stack_chk_fail@PLT
.L43:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
