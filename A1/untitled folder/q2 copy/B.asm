section .data
	text1 db 10, "You are in B()", 10, 0
	text2 db "ASCII string: ", 0

section .bss
    string resb 10

extern C

section .text
	global B

B:
	pop rcx 	;	pop return addr
	push C		;	push new return addr

	; mov qword [rbp+4], C

	; save rdi
	mov rcx, string
    mov [rcx], rdi

	call print_welcome
    
	; mov rax, 1
	; mov rdi, 1
	; mov rsi, string
	; mov rdx, 10
	; syscall

	mov rbx, 7	;	loop index
	mov r10, string+7	;	string char index
	call print_loop

    ret

print_welcome:
	mov rax, 1
	mov rdi, 1
	mov rsi, text1
	mov rdx, 17
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, text2
	mov rdx, 15
	syscall

	ret

print_loop:
	mov rax, 1
	mov rdi, 1
	mov rsi, r10
	mov rdx, 1
	syscall
	dec r10
	
	dec rbx
	cmp rbx, 0
	jge print_loop

	ret
