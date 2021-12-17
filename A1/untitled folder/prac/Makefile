def: 
	nasm -f elf64 B.asm -o B.o
	gcc -no-pie f1.c B.o -o comb
	./comb

hello:
	nasm -f elf64 hello.asm -o hello.o
	ld hello.o -o hello
	./hello
