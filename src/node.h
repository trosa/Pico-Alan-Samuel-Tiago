/** @file node.h
 *  @version 1.1
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <stdio.h> 

typedef int Node_type;

/* Seria de constantes que servirao para definir tipos de nos (na arvore),
 * a partir da etapa 4 - irrelevante por enquanto. */
#define program_node   299
#define idf_node       300
#define int_node       301
#define float_node     302
#define str_node       303
#define empty_node     304
#define proc_node      305
#define param_node     306
#define decl_node      307
#define decl_list_node 308
#define op_node        309
#define nop_node       310
#define return_node    311
#define if_node        312
#define while_node     313
#define print_node     314
#define cond_node      315
#define affect_node    316
#define or_node        317
#define and_node       318
#define eq_node        319
#define neq_node       320
#define inf_node       321
#define sup_node       322
#define inf_eq_node    323
#define sup_eq_node    324
#define plus_node      325
#define minus_node     326
#define mult_node      327
#define div_node       328
#define mod_node       329
#define umenos_node    330
#define not_node       331
#define char_node      332
#define bloc_node      333
#define true_node      335
#define false_node     336

/** Estrutura de dados parcial para o no da arvore.
 *  Trata-se de uma arvore generalizada: qualquer no pode ter de 0 ateh
 *  MAX_CHILDREN_NUMBER filhos. */

#define MAX_CHILDREN_NUMBER 10

typedef struct _node {
   int num_line;   /**< numero de linha (irrelevante por enquanto).*/
   int id;         /**< rótulo do nó. Cada nó deve ter um 'id' distinto. */
   char* lexeme;   /**< irrelevante por enquanto. */
   Node_type type; /**< Um dos valores definidos acima pelos # defines. */
   void* attribute;/**< Qualquer coisa por enquanto. */
   /* Fim das informacoes armazenadas em cada no.
    * A seguir, completar essa estrutura de dados com o necessário para
    * a implementacao dos metodos especificados.
    */

} Node;

/** Constructor of a Node.
 *
 * @param nl : line number of the instruction that originates the node.
 * @param t  : node type (one of the values # define'd above). Must return an
 *             error if the type in not correct.
 * @param lexema : whatever string you want to associate to the node.
 * @param att : a semantical attribute.
 * @param nbc : number of children nodes (<= MAX_CHILDREN_NUMBER and >= 0). Must
 *      return an error if nbc it not correct.
 * @param children : array of children nodes (of size 'nbc').
 * @return a (pointer on a) new Node.
 */
Node* create_node(int nl, Node_type t, char* lexema, 
                  void* att, int nbc, Node** children) ;

/** Constructor of a leaf Node (without any child).
 * @param nl : line number of the instruction that originates the node.
 * @param t  : node type (one of the values # define'd above).  Must return an
 *             error if the type in not correct.
 * @param lexema : whatever string you want to associate to the node.
 * @param att : a semantica attribute (can be NULL for now).
 * @return a (pointer) on a new Node.
 */
Node* create_leaf(int nl, Node_type t, char* lexema, void* att) ;

/** accessor to the number of children of a Node.
 *  Must return en error if 'n' is NULL.
 */
int nb_of_children(Node* n);

/** accessor to the i'th child of a Node.
 * @param n : the node to be consulted. Must return en error if 'n' is NULL.
 * @param i : the number of the child that one wants. Must be strictly lower 
 *       than n->num_children and larger than 0. Must return an error if i is
 *       not correct.
 * @return a pointer on a Node.
 */
Node* child(Node* n, int i) ;

/** Pushes 'n' Nodes on bottom of an array of Node* which contains originally
 * 'cur_size' entries. Returns the new number of entries (ie 'cur_size+1') in
 * the array 'array_of_nodes'.
 * This function is convenient to be used with create_node (see its last
 * argument).
 * On the first call, 'array_of_nodes' should not be allocated, and 'cur_size'
 * should be zero.
 * Implementation limit: since these Node* structures are meant to be used
 * in a compiler, one expects an upper limit of MAX_CHILDREN_NUMBER nodes
 * to be packed. Trying to pack more than this limit must raise an error.
 * Typical use: Node** children; pf1 = create_leaf(1, int_node, "1", NULL);
 * pf3 = create_leaf(1, int_node, "2", NULL); pack_nodes(&children, 0, pf1);
 *  pack_nodes(&children, 1, pf3);
 */

int pack_nodes(Node*** array_of_nodes, int cur_size, Node* n);

/** Destructor of a Node. Desallocates (recursively) all the tree rooted at
 * 'n'.
 */
int deep_free_node(Node* n) ;

/** returns the height of the tree rooted by 'n'.
 *  The height of a leaf is 1. 
 */
int height(Node *n) ;


#endif
