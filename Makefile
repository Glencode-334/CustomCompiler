CC = gcc
CFLAGS = -Wall -lm
FLEX = flex

all: equation_compiler

equation_compiler: main.o compute.o lex.yy.o
	$(CC) -o equation_compiler main.o compute.o lex.yy.o -ll $(CFLAGS)

lex.yy.c: compute.l
	$(FLEX) compute.l

lex.yy.o: lex.yy.c compute.h
	$(CC) -c lex.yy.c

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

compute.o: compute.c compute.h
	$(CC) -c compute.c $(CFLAGS)

clean:
	rm -f equation_compiler *.o lex.yy.c