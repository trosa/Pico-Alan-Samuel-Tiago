#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Pode ser util...*/
static int __nodes_ids__ = 0;

Node* create_node(int nl, Node_type t, char* lex, 
                  void* att, int nbc, Node** children) {
   /* A IMPLEMENTAR */
}

Node* create_leaf(int nl, Node_type t, char* lex, void* att) {
   /* A IMPLEMENTAR */
}

int nb_of_children(Node* n) {
   /* A IMPLEMENTAR */
}


Node* child(Node* n, int i) {
   /* A IMPLEMENTAR */
}

int deep_free_node(Node* n) {
   /* A IMPLEMENTAR */
}

int height(Node *n) {
   /* A IMPLEMENTAR */
}

int pack_nodes(Node*** array_of_nodes, const int cur_size, Node* n) {
   /* A IMPLEMENTAR */
}

