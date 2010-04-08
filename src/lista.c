#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _LISTA_C_
#define _LISTA_C_

struct tac* create_inst_tac(const char* res, const char* arg1, 
                 const char* op, const char* arg2) {
   struct tac * t = (struct tac *)malloc(sizeof(struct tac));
   t->op = (char*)malloc(sizeof(char)*(1+strlen(op)));
   strcpy(t->op, op);
   t->res = (char*)malloc(sizeof(char)*(1+strlen(res)));
   strcpy(t->res, res);
   t->arg1 = (char*)malloc(sizeof(char)*(1+strlen(arg1)));
   strcpy(t->arg1, arg1);
   t->arg2 = (char*)malloc(sizeof(char)*(1+strlen(arg2)));
   strcpy(t->arg2, arg2);
   return( t );
}

void print_inst_tac(FILE* out, struct tac i) {
   fprintf(out, "%s\t:= %s %s %s\n", i.res, i.arg1, i.op, i.arg2);
}

/* A IMPLEMENTAR */
void print_tac(FILE* out, struct node_tac * code) {
  /* A IMPLEMENTAR */
}

void append_inst_tac(struct node_tac ** code_ref, struct tac * inst) {
  /* A IMPLEMENTAR */
}

void cat_tac(struct node_tac ** code_a, struct node_tac ** code_b) {
  /* A IMPLEMENTAR */
}

#endif
