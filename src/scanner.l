 /* Secao das declaracoes */

%option noyywrap
  /* Sera copiado no .c final */
%{
    #include <stdlib.h>
    #include <string.h>
   
    /* este include eh importante... */
    #include "tokens.h"
    #include "node.h"

    /* Essa macro define a criação do nodo da arvore, atribui o lexema e retorna o token */
    #define CREATE_NODE(type, token) yylval.node = create_leaf(noline, type, yytext, NULL); return(token);

    extern YYSTYPE yylval; /* Declaramos essa variável como externa, para que o compilador possa encontrar essa variável no y.tab.c, para poder usar no lex.yy.c. */
    long unsigned int noline = 1;
%}
 
  /* Definicoes regulares (A COMPLETAR conforme a especificacao) */
digito     [0-9]
minusculo  [a-z]
maiusculo  [A-Z]
letra      {minusculo}|{maiusculo}

%%

 /* Secao das Regras de traducao */
 /* O que consta aqui eh puramente ilustrativo... A COMPLETAR ! 
  * Ver tambem "tokens.h".
  */

int    { return(INT); }
double { return(DOUBLE); }
real   { return(REAL); }
float  { return(REAL); }
char   { return(CHAR); }
"*"    { return('*'); }
"+"    { return('+'); }
"-"    { return('-'); }
"/"    { return('/'); }
","    { return(','); }
";"    { return(';'); }
":"    { return(':'); }
"'"    { return(QUOTE); }
"\""   { return(DQUOTE); }
"("    { return('('); }
")"    { return(')'); }
"["    { return('['); }
"]"    { return(']'); }
"{"    { return('{'); }
"}"    { return('}'); }
"<"    { return('<'); }
">"    { return('>'); }
"="    { return('='); }
"<="   { return(LE); }
">="   { return(GE); }
"=="   { return(EQ); }
"!="   { return(NE); }
"&"    { return(AND); }
"|"    { return(OR); }
"!"    { return(NOT); }
if     { return(IF); }
then   { return(THEN); }
else   { return(ELSE); }
for    { return(FOR); }
next   { return(NEXT); }
while  { return(WHILE); }
repeat { return(REPEAT); }
until  { return(UNTIL); }
end    { return(END); }
true   { return(TRUE); }
false  { return(FALSE); }

[ \t]+ { ; } 
\n     { noline++; } /* Guardamos o numero da linha atual */
({letra}|_)({letra}|{digito}|_)*          { CREATE_NODE(idf_node, IDF); }
{digito}+                                 { CREATE_NODE(int_lit_node, INT_LIT); }
{digito}+\.{digito}+([eE][+-]?{digito}+)? { CREATE_NODE(f_lit_node, F_LIT); }

  /* Tratamento dos erros lexicais: a regra seguinte pega tudo o que nao
   * fechou com uma Regexp anterior.
   */
. { printf("Erro lexical - caractere nao reconhecido: %c.\n", yytext[0]);
    exit(-1); }
%%
 /* Secao dos  Procedimentos auxiliares  */

 /* Para redefinir a entrada padrao do LEX. 
  * Redefinir a variavel 'yyin' para ler de um arquivo. Por exemplo:
     yyin = fopen("Meu_programa.c", "r");
  * ira mandar ler o programa a ser compilado pelo analisador lexical
  * em 'Meu_programa.c'.
  * O default eh ler da entrada standard (o teclado).
  */

// extern FILE *yyin;
// int main(int argc, char* argv[]) {
//    int token;
//    if (argc != 2) {
//      printf("uso: %s <input_file>. Try again!\n", argv[0]);
//      exit(-1);
//    }
//    yyin = fopen(argv[1], "r");
//    if (!yyin) {
//      printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
//          argv[0], argv[1]);
//      exit(-1);
//    }
//   /* agora a entrada padrao eh o arquivo especificado como 1o argumento ao
//    * executavel (argv[1]).
//    * Soh chama o analisador lexical default fornecido pelo output do Flex:
//    */
//   while (token=yylex()) { 
//      /* neste laco, obtem-se "palavra por palavra" os tokens reconhecidos
//       * pelo scanner fornecido pelo Lex. Poderia ser feita a analise
//       * sintatica... Sera feito depois!
//       */
//      printf("Meu analisador lexical reconheceu o token %d\n", token);
//   }
//   return(0);
// }
