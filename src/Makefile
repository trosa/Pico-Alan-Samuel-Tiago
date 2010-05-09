#
# Digita 'make' ou 'make pico' para compilar tudo.
#
# Compilacao do parser+scanner para obter um executavel. O main se encontra
# na 3a secao de 'pico.y'. A compilacao depende dos codigos C resultantes
# das compilacoes com o flex e o yacc (regras abaixo), e de symbol_table.c
# que eh usado no scanner.
pico: lex.yy.c y.tab.c symbol_table.c node.c lista.c
	gcc -o pico y.tab.c lex.yy.c symbol_table.c node.c lista.c -ll

# Compilacao com o (f)lex do analisador lexical. Le os tokens a serem
# retornados em 'tokens.h'
lex.yy.c: scanner.l
	flex scanner.l

# Compilacao com o Yacc da gramatica.
# O codigo fonte (em C) do parser se encontra depois em y.tab.c.
# Observar o uso de '-d' para gerar o arquivo que contem os #define associados
# aos tokens (ver %token em pico.y). Este arquivo 'y.tab.h' eh depois 
# renomeado em 'tokens.h' para manter a compatibilidade com o scanner da Etapa1.
y.tab.c: pico.y
	yacc -d pico.y ; mv y.tab.h tokens.h

# Digita 'make clean' para limpar tudo.
clean:
	rm -f lex.yy.c y.tab.c pico

debug: lex.yy.c y.tab.c symbol_table.c node.c
	gcc -g -O0 -D DEBUG -o pico y.tab.c lex.yy.c symbol_table.c node.c -ll
	
