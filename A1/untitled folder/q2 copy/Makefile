default: A C asm


asm:
	nasm -f elf64 B.asm -o B.o
	gcc -no-pie A.c B.o C.c -o A
	./A

A: A.c
	${CC} -S -o $@.s $<
	${CC} -c -o $@.o $<

C: C.c
	${CC} -S -o $@.s $<
	${CC} -c -o $@.o $<
