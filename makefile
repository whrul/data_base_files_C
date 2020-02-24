a.out: *.h *.c
	gcc *.c

run: a.out
	./a.out
