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

void print_tac(FILE* out, struct node_tac * code) {
   struct node_tac * p;

   for (p = code; p != NULL; p = p->next) {
      print_inst_tac(out, *(p->inst));
   }
}

void append_inst_tac(struct node_tac ** code_ref, struct tac * inst) {
   if (inst == NULL) 
      return;
   if (*code_ref == NULL) {
      *code_ref = (struct node_tac*)malloc(sizeof(struct node_tac));
      (*code_ref)->inst = (struct tac*)malloc(sizeof(struct tac));
      memcpy((*code_ref)->inst, inst, sizeof(struct tac));
      (*code_ref)->next = NULL;
      (*code_ref)->prev = NULL;
   } else {
      struct node_tac * p;

      for (p = *code_ref; p->next != NULL; p = p->next);
      p->next = (struct node_tac*)malloc(sizeof(struct node_tac));
      p->next->inst = (struct tac*)malloc(sizeof(struct tac));
      memcpy(p->next->inst, inst, sizeof(struct tac));
      p->next->next = NULL;
      p->next->prev = p;
   }
}

void cat_tac(struct node_tac ** code_a, struct node_tac ** code_b) {
   if (*code_b != NULL) {
      if (*code_a == NULL)
         *code_a = *code_b;
      else {
         struct node_tac * p;

         for (p = *code_a; p->next != NULL; p = p->next);
         p->next = *code_b;
         (*code_b)->prev = p;
      }
   }
}

#endif
