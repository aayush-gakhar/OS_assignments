section .data
	text db "Hello World!", 10

section .bss
        string resb 100

section .text
	global B


B:
	;to print
        mov rcx, string
        mov [rcx], rdi
	mov rax, 1
	mov rdi, 1
	mov rsi, string
	mov rdx, 100
	syscall

	;to exit code
	mov rax, 60
	mov rdi, 0
	syscall
        ret
