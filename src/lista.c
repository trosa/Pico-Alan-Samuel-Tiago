#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _LISTA_C_
#define _LISTA_C_

/** Posição do próximo temporário a ser gerado pelo novo_tmp */
int next_tmp = 0;
int next_lbl = 0;
int line;

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
   if (i.res[0] == '\0' && i.arg1[0] == '\0' && i.op[0] == '\0') {
      fprintf(out, "%s:\n", i.arg2);
      line--;
      return;
   }

   fprintf(out, "%03d:   ", line);
   if (i.res[0] == '-')
      fprintf(out, "IF %s %s %s GOTO %s", i.arg1, i.op, i.arg2, i.res + 1);
   else if (i.arg1[0] == '\0')
      fprintf(out, "%s(%s) := %s", i.res, i.op, i.arg2);
   else if (i.arg2[0] == '\0')
      if (i.op[0] == '\0')
         fprintf(out, "%s := %s", i.res, i.arg1);
      else
         fprintf(out, "%s %s", i.op, i.arg1);         
   else
      if (i.op[0] == '\0')
         fprintf(out, "%s := %s(%s)", i.res, i.arg1, i.arg2);
      else
         fprintf(out, "%s := %s %s %s", i.res, i.arg1, i.op, i.arg2);
}

void print_tac(FILE* out, struct node_tac * code) {
   struct node_tac * p;

   line = 0;
   for (p = code; p != NULL; p = p->next, line++) {
      fprintf(out, "\n");
      print_inst_tac(out, *(p->inst));
   }
}

void append_inst_tac(struct node_tac ** code_ref, struct tac * inst) {
   if (inst == NULL) 
      return;
   if (*code_ref == NULL) {
      *code_ref = (struct node_tac*)malloc(sizeof(struct node_tac));
      (*code_ref)->inst = inst;
      (*code_ref)->next = NULL;
      (*code_ref)->prev = NULL;
   } else {
      struct node_tac * p;

      for (p = *code_ref; p->next != NULL; p = p->next);
      p->next = (struct node_tac*)malloc(sizeof(struct node_tac));
      p->next->inst = inst;
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

int novo_tmp(int type)
{
   int tmp;

   tmp = next_tmp;
   next_tmp += (type == 0)? 1: (type == 1)? 4: (type == 2)? 4: (type == 3)? 8: 0;
   return tmp;
}

int novo_rot()
{
   return next_lbl++;
}
#endif
