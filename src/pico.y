%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
%}

%token IDF
%token INT
%token DOUBLE
%token FLOAT
%token CHAR
%token QUOTE
%token DQUOTE
%token LE
%token GE
%token EQ
%token NE
%token AND
%token OR
%token NOT
%token IF
%token THEN
%token ELSE
%token WHILE
%token INT_LIT
%token F_LIT
%token END
%token TRUE
%token FALSE
%token REAL
%token FOR
%token NEXT
%token REPEAT
%token UNTIL
%start code

%union {
   char expr[4000]; /* redefinimos a union YYSTYPE, que é o tipo da variável yylval, que conterá uma string */
}

%left '+' '-'
%left '*' '/'
%right '='

%%
code: declaracoes acoes
    | acoes
    ;

declaracoes: declaracao ';'
           | declaracoes declaracao ';'
           ;

declaracao: listadeclaracao ':' tipo

listadeclaracao: IDF
               | IDF ',' listadeclaracao
               ;

tipo: tipounico 
    | tipolista
    ;

tipounico: INT
         | DOUBLE
         | FLOAT
         | CHAR
         ;

tipolista: INT '[' listadupla ']'
         | DOUBLE '[' listadupla ']'
         | FLOAT '[' listadupla ']'
         | CHAR '[' listadupla ']'
         ;

listadupla: INT_LIT ':' INT_LIT
          | INT_LIT ':' INT_LIT ',' listadupla
          ;

acoes: comando ';'
    | comando ';' acoes
    ;

comando: lvalue '=' expr             { printf("%s\n", $3.expr); } /* imprimimos a expressão quando ela já está inteiramente composta "expr" */
       | enunciado
       ;

lvalue: IDF
      | IDF '[' listaexpr ']'
      ;

listaexpr: expr                      { printf("%s\n", $1.expr); }
	   | expr ',' listaexpr      { printf("%s\n", $1.expr); }
	   ;

                    /* inicialmente, colocamos o primeiro operador na string (vazia), depois vamos concatenando os outros
                       operadores e por último acrescentamos o sinal, forma pós-fixada (definição) */
expr: expr '+' expr { sprintf($$.expr, "%s%s+ ", $1.expr, $3.expr); }
    | expr '-' expr { sprintf($$.expr, "%s%s- ", $1.expr, $3.expr); }
    | expr '*' expr { sprintf($$.expr, "%s%s* ", $1.expr, $3.expr); }
    | expr '/' expr { sprintf($$.expr, "%s%s/ ", $1.expr, $3.expr); }
    | '(' expr ')'  { $$ = $2; }
    | INT_LIT       { $$ = $1; }
    | F_LIT    
    | lvalue
    | chamaproc
    ;

chamaproc: IDF '(' listaexpr ')'
         ;

enunciado: expr                                             { printf("%s\n", $1.expr); }
         | IF '(' expbool ')' THEN acoes fiminstcontrole
         | WHILE '(' expbool ')' '{' acoes '}'
         ;

fiminstcontrole: END
               | ELSE acoes END
               ;

expbool: TRUE 
       | FALSE
       | '(' expbool ')'
       | expbool AND expbool
       | expbool OR expbool
       | NOT expbool
       | expr '>' expr        { printf("%s\n%s\n", $1.expr, $3.expr); }
       | expr '<' expr        { printf("%s\n%s\n", $1.expr, $3.expr); }
       | expr LE expr         { printf("%s\n%s\n", $1.expr, $3.expr); }
       | expr GE expr         { printf("%s\n%s\n", $1.expr, $3.expr); }
       | expr EQ expr         { printf("%s\n%s\n", $1.expr, $3.expr); }
       | expr NE expr         { printf("%s\n%s\n", $1.expr, $3.expr); }
       ;
%%
 /* A partir daqui, insere-se qlqer codigo C necessario.
  */

char* progname;
int lineno;
extern FILE* yyin;


int main(int argc, char* argv[]) 
{
   if (argc != 2) {
     printf("uso: %s <input_file>. Try again!\n", argv[0]);
     exit(-1);
   }
   yyin = fopen(argv[1], "r");
   if (!yyin) {
     printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
         argv[0], argv[1]);
     exit(-1);
   }

   progname = argv[0];

   if (!yyparse()) 
      printf("OKAY.\n");
   else 
      printf("ERROR.\n");

   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}
