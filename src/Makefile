CC      = gcc
LDFLAGS = -g

all: etapa1 

## Etapa 1
etapa1: pico

doc: Doxyfile $(HEAD1)
	doxygen Doxyfile

pico: lex.yy.c
	gcc -o pico lex.yy.c -lfl

lex.yy.c: scanner.l tokens.h
	flex scanner.l;

clean:
	rm -f *.o lex.yy.?
