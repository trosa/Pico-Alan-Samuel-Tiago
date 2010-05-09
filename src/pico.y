%{
  /* Aqui, pode-se inserir qualquer codigo C necessario ah compilacao
   * final do parser. Sera copiado tal como esta no inicio do y.tab.c
   * gerado por Yacc.
   */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #include "node.h"
  #include "symbol_table.h"

  #define UNDEFINED_SYMBOL_ERROR -21

  Node *syntax_tree = NULL;
  symbol_t s_table;
  int __desloc__ = 0;
  extern int noline;
%}

%token <node> IDF
%token <node> INT
%token <node> DOUBLE
%token <node> REAL
%token <node> CHAR
%token <node> QUOTE
%token <node> DQUOTE
%token <node> LE
%token <node> GE
%token <node> EQ
%token <node> NE
%token <node> AND
%token <node> OR
%token <node> NOT
%token <node> IF
%token <node> THEN
%token <node> ELSE
%token <node> WHILE
%token <node> INT_LIT
%token <node> F_LIT
%token <node> END
%token <node> TRUE
%token <node> FALSE
%token <node> FOR
%token <node> NEXT
%token <node> REPEAT
%token <node> UNTIL
%start code

%union {
   struct _node *node;
}

%type <node> code
%type <node> declaracoes
%type <node> declaracao
%type <node> listadeclaracao
%type <node> tipo
%type <node> tipounico
%type <node> tipolista
%type <node> listadupla
%type <node> acoes
%type <node> comando
%type <node> lvalue
%type <node> listaexpr
%type <node> expr
%type <node> chamaproc
%type <node> enunciado
%type <node> fiminstcontrole
%type <node> expbool

%left '+' '-'
%left '*' '/'
%right '='

%left OR
%left AND
%right NOT

%%
code: declaracoes acoes  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $2); syntax_tree = $$ = create_node(noline, program_node, NULL, NULL, 2, c); }
    | acoes              { Node **c; pack_nodes(&c, 0, $1); syntax_tree = $$ = create_node(noline, program_node, NULL, NULL, 1, c); }
    ;

declaracoes: declaracao ';'              { Node **c; pack_nodes(&c, 0, $1); $$ = create_node(noline, decls_node, NULL, NULL, 1, c); }
           | declaracoes declaracao ';'  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $2); $$ = create_node(noline, decls_node, NULL, NULL, 2, c); }
           ;

declaracao: listadeclaracao ':' tipo      { 
                                             Node *n, *n_arr;
                                             int i;
                                             
                                             n = $1;
                                             while (1)
                                             {
                                                /* Antes de inserir um elemento na tabela de simbolos, verifica se esse elemento nao está na tabela */
                                                if (lookup(s_table, n->children[0]->lexeme) == NULL)
                                                { 
                                                   entry_t e;

                                                   e.name = (char *)malloc(strlen(n->children[0]->lexeme) + 1);
                                                   strcpy(e.name, n->children[0]->lexeme);
                                                   switch ($3->type)
                                                   {
                                                   case char_node:
                                                      e.type = 0;
                                                      e.size = 1;
                                                      e.array = NULL;
                                                      break;
                                                   case int_node:
                                                      e.type = 1;
                                                      e.size = 4;
                                                      e.array = NULL;
                                                      break;
                                                   case real_node:
                                                      e.type = 2;
                                                      e.size = 4;
                                                      e.array = NULL;
                                                      break;
                                                   case double_node:
                                                      e.type = 3;
                                                      e.size = 8;
                                                      e.array = NULL;
                                                      break;

                                                   case char_array_node:
                                                   case int_array_node:
                                                   case real_array_node:
                                                   case double_array_node:
                                                      i = 0;
                                                      n_arr = $3->children[0];
                                                      e.size = 1;
                                                      /*Inicialização das estruturas */
                                                      e.array = (array_t *)malloc(sizeof(array_t));
                                                      e.array->dim = height(n_arr) - 1;
                                                      e.array->linf = (int *)malloc(sizeof(int) * e.array->dim);
                                                      e.array->lsup = (int *)malloc(sizeof(int) * e.array->dim);
                                                      e.array->c = 0;
                                                      while(1)
                                                      {
							 /* Percorre a arvore e coloca os limites inferiores e superiores nos seus respectivos arrays */
                                                         sscanf(n_arr->children[0]->lexeme, "%d", &(e.array->linf[i]));
                                                         sscanf(n_arr->children[1]->lexeme, "%d", &(e.array->lsup[i]));
							 /* Calculo da Constante C */
                                                         e.size *= e.array->lsup[i] - e.array->linf[i] + 1;
                                                         e.array->c += e.array->linf[i];
                                                         e.array->c *= e.array->lsup[i] - e.array->linf[i] + 1;
                                                         if (n_arr->children_number == 2)
                                                            break;
                                                         n_arr = n_arr->children[2];
                                                         i++;
                                                      }
                                                      switch ($3->type)
                                                      {
                                                      case char_array_node:
                                                         e.type = 4;
                                                         e.size *= 1;
                                                         break;
                                                      case int_array_node:
                                                         e.type = 5;
                                                         e.size *= 4;
                                                         break;
                                                      case real_array_node:
                                                         e.type = 6;
                                                         e.size *= 4;
                                                         break;
                                                      case double_array_node:
                                                         e.type = 7;
                                                         e.size *= 8;
                                                         break;
                                                      }
                                                      break;
                                                   }
                                                   e.desloc = __desloc__;
                                                   __desloc__ += e.size;
                                                   insert(&s_table, &e);
                                                }
                                                else
                                                {
                                                   // ERRO: identificador já declarado;
                                                }

                                                if (n->children_number == 1)
                                                   break;
                                                n = n->children[1];
                                             }

                                             Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, decl_node, NULL, NULL, 2, c);
                                          }

listadeclaracao: IDF                      { Node **c; pack_nodes(&c, 0, $1); $$ = create_node(noline, decl_list_node, NULL, NULL, 1, c); }
               | IDF ',' listadeclaracao  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, decl_list_node, NULL, NULL, 2, c); }
               ;

tipo: tipounico  { $$ = $1; }
    | tipolista  { $$ = $1; }
    ;

tipounico: INT                       { $$ = create_leaf(noline, int_node, NULL, NULL); }
         | DOUBLE                    { $$ = create_leaf(noline, double_node, NULL, NULL); }
         | REAL                      { $$ = create_leaf(noline, real_node, NULL, NULL); }
         | CHAR                      { $$ = create_leaf(noline, char_node, NULL, NULL); }
         ;

tipolista: INT '[' listadupla ']'    { Node **c; pack_nodes(&c, 0, $3); $$ = create_node(noline, int_array_node, NULL, NULL, 1, c); }
         | DOUBLE '[' listadupla ']' { Node **c; pack_nodes(&c, 0, $3); $$ = create_node(noline, double_array_node, NULL, NULL, 1, c); }
         | REAL '[' listadupla ']'   { Node **c; pack_nodes(&c, 0, $3); $$ = create_node(noline, real_array_node, NULL, NULL, 1, c); }
         | CHAR '[' listadupla ']'   { Node **c; pack_nodes(&c, 0, $3); $$ = create_node(noline, char_array_node, NULL, NULL, 1, c); }
         ;

listadupla: INT_LIT ':' INT_LIT                 { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, array_list_node, NULL, NULL, 2, c); }
          | INT_LIT ':' INT_LIT ',' listadupla  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); pack_nodes(&c, 2, $5); $$ = create_node(noline, array_list_node, NULL, NULL, 3, c); }
          ;

acoes: comando ';'       { Node **c; pack_nodes(&c, 0, $1); $$ = create_node(noline, action_node, NULL, NULL, 1, c); }
    | comando ';' acoes  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, action_node, NULL, NULL, 2, c); }
    ;

comando: lvalue '=' expr  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, assig_node, NULL, NULL, 2, c); }
       | enunciado        { Node **c; pack_nodes(&c, 0, $1); $$ = create_node(noline, enun_node, NULL, NULL, 1, c); }
       ;

lvalue: IDF                   {
                                 if (lookup(s_table, $1->lexeme) == NULL)
                                 {
                                    printf("UNDEFINED SYMBOL. A variavel %s nao foi declarada.\n", $1->lexeme);
                                    $$ = create_leaf(noline, error_node, NULL, NULL);
                                    return(UNDEFINED_SYMBOL_ERROR);
                                 }
                                 Node **c; pack_nodes(&c, 0, $1); $$ = create_node(noline, lvalue_node, NULL, NULL, 1, c);
                              }
      | IDF '[' listaexpr ']' {
                                 if (lookup(s_table, $1->lexeme) == NULL)
                                 {
                                    printf("UNDEFINED SYMBOL. A variavel %s nao foi declarada.\n", $1->lexeme);
                                    $$ = create_leaf(noline, error_node, NULL, NULL);
                                    return(UNDEFINED_SYMBOL_ERROR);
                                 }
                                 Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, lvalue_node, NULL, NULL, 2, c);
                              }
      ;

listaexpr: expr                 { Node **c; pack_nodes(&c, 0, $1); $$ = create_node(noline, expr_list_node,  NULL, NULL, 1, c); }
	   | expr ',' listaexpr { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, expr_list_node,  NULL, NULL, 2, c); }
	   ;

expr: expr '+' expr  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, plus_node,  NULL, NULL, 2, c); }
    | expr '-' expr  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, minus_node, NULL, NULL, 2, c); }
    | expr '*' expr  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, mult_node,  NULL, NULL, 2, c); }
    | expr '/' expr  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, div_node,   NULL, NULL, 2, c); }
    | '(' expr ')'   { $$ = $2; }
    | INT_LIT        { $$ = $1; }
    | F_LIT          { $$ = $1; }
    | lvalue         { $$ = $1; }
    | chamaproc      { $$ = $1; }
    ;

chamaproc: IDF '(' listaexpr ')'  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, proc_node,  NULL, NULL, 2, c); }
         ;

enunciado: expr                                           { $$ = $1; }
         | IF '(' expbool ')' THEN acoes fiminstcontrole  { Node **c; pack_nodes(&c, 0, $3); pack_nodes(&c, 1, $6); pack_nodes(&c, 2, $7); $$ = create_node(noline, if_node,  NULL, NULL, 3, c); }
         | WHILE '(' expbool ')' '{' acoes '}'            { Node **c; pack_nodes(&c, 0, $3); pack_nodes(&c, 1, $6); $$ = create_node(noline, while_node,  NULL, NULL, 2, c); }
         ;

fiminstcontrole: END             { $$ = create_leaf(noline, end_node, NULL, NULL); }
               | ELSE acoes END  { Node **c; pack_nodes(&c, 0, $2); $$ = create_node(noline, else_node,  NULL, NULL, 1, c); }
               ;

expbool: TRUE                 { $$ = create_leaf(noline, true_node, NULL, NULL); }
       | FALSE                { $$ = create_leaf(noline, false_node, NULL, NULL); }
       | '(' expbool ')'      { $$ = $2; }
       | expbool AND expbool  { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, and_node,  NULL, NULL, 2, c); }
       | expbool OR expbool   { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, or_node,  NULL, NULL, 2, c); }
       | NOT expbool          { Node **c; pack_nodes(&c, 0, $2);  $$ = create_node(noline, not_node,  NULL, NULL, 1, c); }
       | expr '>' expr        { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, sup_node,  NULL, NULL, 2, c); }
       | expr '<' expr        { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, inf_node,  NULL, NULL, 2, c); }
       | expr LE expr         { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, inf_eq_node,  NULL, NULL, 2, c); }
       | expr GE expr         { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, sup_eq_node,  NULL, NULL, 2, c); }
       | expr EQ expr         { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, eq_node,  NULL, NULL, 2, c); }
       | expr NE expr         { Node **c; pack_nodes(&c, 0, $1); pack_nodes(&c, 1, $3); $$ = create_node(noline, neq_node,  NULL, NULL, 2, c); }
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
   init_table(&s_table);

   if (!yyparse()) 
      printf("OKAY.\n");
   else 
      printf("ERROR.\n");

   deep_free_node(syntax_tree);
   free_table(&s_table);
   return(0);
}

yyerror(char* s) {
  fprintf(stderr, "%s: %s", progname, s);
  fprintf(stderr, "line %d\n", lineno);
}
