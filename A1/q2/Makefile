default:
	nasm -f elf64 B.asm -o B.o
	gcc -no-pie A.c B.o C.c -o A
	./A
