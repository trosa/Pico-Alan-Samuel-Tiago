/** @file lista.h
 */

#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>

/** 
 * Estrutura de dados (que implementa uma intrucao TAC, ver Etapa 4), a ser
 * encadeada na lista. Por enquanto, o que representa é irrelevante.
 */
struct tac {
   char* op;   /* "+", "-", ":=", "if", etc... */
   char* res;  /* "TMP100" */
   char* arg1; /* "TMP0"   */
   char* arg2; /* "TMP1"   */
};

/** \brief  Construtor de Instrucao TAC 
 *
 * Para testes, pode-se usar qualquer string em argumentos.
 * @param res um char*.
 * @param arg1 um char*.
 * @param op um char*.
 * @param arg2 um char*.
 * @return um ponteiro sobre uma 'struct tac'.
 */
struct tac* create_inst_tac(const char* res, const char* arg1, 
                 const char* op, const char* arg2);

/** \brief Funcao que imprime o conteudo de uma instrucao TAC 
 *
 * @param out um ponteiro sobre um arquivo (aberto) aonde ira ser escrita a instrucao.
 * @param i a instrucao a ser impressa.
 */
void print_inst_tac(FILE* out, struct tac i);

/** Um elemento basico da lista. O campo 'inst' aponta para a informacao a ser
 * armazenada em um elemento da lista. O resto serve para implementar a lista
 * e seus metodos.
 */
struct node_tac {
   struct tac * inst;
   struct node_tac* next;
   struct node_tac* prev;
};

/** \brief Imprime no arquivo apontado por 'out' o conteudo da lista apontada
 * por 'code'.
 *
 * @param out um ponteiro sobre um arquivo (aberto) aonde ira ser escrita a lista (uma linha por elemento).
 * @param code o ponteiro para a lista a ser impressa.
 */
void print_tac(FILE* out, struct node_tac * code);

/** Insere no fim da lista 'code' o elemento 'inst'. 
 * @param code lista (possivelmente vazia) inicial, em entrada. Na saida, contem *         a mesma lista, com mais um elemento inserido no fim.
 * @param inst o elemento inserido no fim da lista.
 */
void append_inst_tac(struct node_tac ** code, struct tac * inst);

/** Concatena a lista 'code_a' com a lista 'code_b'.
 * @param code_a lista (possivelmente vazia) inicial, em entrada. Na saida, contem 
 *         a mesma lista concatenada com 'code_b'.
 * @param code_b a lista concatenada com 'code_a'.
 */
void cat_tac(struct node_tac ** code_a, struct node_tac ** code_b);

/** Cria um novo temporário
 * @param type tipo do valor a ser armazenado no temporário
 *         (0 = char, 1 = int, 2 = real, 3 = double)
 * @return o deslocamento do temporário em relação a Rx
 */
int novo_tmp(int type);

/** Cria um novo rótulo
  * @return inteiro ainda não utilizado em um rótulo gerado pela função
  */
int novo_rot();

#endif
