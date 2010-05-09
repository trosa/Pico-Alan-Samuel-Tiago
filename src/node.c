#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Pode ser util...*/
static int __nodes_ids__ = 0;

Node* create_node(int nl, Node_type t, char* lex, 
                  void* att, int nbc, Node** children) {
   int i;
   Node* n;

/* testamos se o número de filhos e o tipo são válidos, enquanto nós inicializamos um nodo 
					(reutilizamos a função create_leaf para reutilizar codigo) */
   if (nbc < 0 || nbc > MAX_CHILDREN_NUMBER || (n = create_leaf(nl, t, lex, att)) == NULL) 
      return NULL;

   n->children_number = nbc;
   n->children = children;

   return n;
}

Node* create_leaf(int nl, Node_type t, char* lex, void* att) {
   if (t < program_node || t > proc_node)
      return NULL;

   Node* n;

   if ((n = (Node*)malloc(sizeof(Node))) == NULL)
      return NULL;   
   n->num_line = nl;
   n->type = t;
   n->lexeme = NULL;
   if (lex != NULL && (n->lexeme = (char*)malloc(strlen(lex) + 1)) == NULL) {
      free(n);
      return NULL;
   }
   if (lex != NULL)
      strcpy(n->lexeme, lex);
   //n->attribute = att;
   n->attribute = NULL;
   n->children_number = 0;
   n->id = __nodes_ids__++; /* Dessa forma cada nodo vai apresentar um ID diferente */

#ifdef DEBUG
   fprintf(stderr, "id = %d, type = %d, line = %d", n->id, n->type, n->num_line);
   if (lex != NULL)
      fprintf(stderr, " (%s)", n->lexeme);
   fprintf(stderr, "\n");
#endif

   return n;
}

int nb_of_children(Node* n) {
   if (n == NULL)
      return(-1);
   return (n->children_number);
}


Node* child(Node* n, int i) {
   if (n == NULL || i < 0 || i >= n->children_number)
      return(NULL);
   return(n->children[i]);
}

int deep_free_node(Node* n) {
   int i;

   for (i = 0; i < n->children_number; i++)
      deep_free_node(n->children[i]);

   free(n->lexeme);
   free(n->children);
   if (n->attribute != NULL)
     free(n->attribute);
   free(n);

   return 0;
}

/* Função recursiva que retorna a altura da árvore, ela vai até a profundidade e retorna guardando o valor da altura em max */
int height(Node *n) {
   int i, r, max = 0;

   for (i = 0; i < n->children_number; i++) {
      r = height(n->children[i]);
      if (r > max)
         max = r;
   }

   return max + 1;
}

/* Essa função adiciona um nodo a um array de nodos, caso esse array seja vazio (cur_size = 0), ele aloca o array; caso o array esteja cheio, ele retorna erro; caso o array já exista, ele adiciona o elemento no final do array */
int pack_nodes(Node*** array_of_nodes, const int cur_size, Node* n) {
   if (cur_size >= MAX_CHILDREN_NUMBER)
      return -1;

   if (cur_size == 0)
      if ((*array_of_nodes = (Node**)malloc(sizeof(Node*) * MAX_CHILDREN_NUMBER)) == NULL)
         return -1;
   (*array_of_nodes)[cur_size] = n;

   return cur_size + 1;
}

