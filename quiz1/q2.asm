extern printf

section .data
	format db "%llx",10, 0

section .text
    global main

main:
	; push rbp
    mov rax, 0x1234567812345678
    xor rax, 0x11
	mov rdi,format
    mov rsi, rax
	push rax
    call printf
	pop rax
    xor rax, 0x11
	mov rdi,format
    mov rsi, rax
	push rax
    call printf
	pop rax
	; pop rbp