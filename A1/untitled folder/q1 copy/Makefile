default: q1a q1b

q1a: q1a.c
	${CC} -S -o $@.s $<
	${CC} -c -o $@.o $<
	${CC} -o $@ $<

q1b: q1b.c
	${CC} -S -o $@.s $<
	${CC} -c -o $@.o $<
	${CC} -o $@ $<

