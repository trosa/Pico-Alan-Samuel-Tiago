#include "symbol_table.h"

#include <stdlib.h>
#include <string.h>

/* Função Hash, calcula um int dado um string */
int hash_function(char* name) {
   unsigned int l, r; /*Utilizamos unisgned para que, no caso de overflow, o retorno não seja negativo */
   char* p;

   l = strlen(name);
   r = 5377;
   for (p = name; *p != '\0'; p++) {
      r = (~r) << 2 + 5377 + *p;
   }
   return r % SYMBOL_T_SIZE;
}

/* Inicializa a tabela com os valores NULL em todas as entradas da tabela hash 
   Armazenamento de espaço para a tabela que será implementada */
int init_table(symbol_t* table) {
   /* table = (symbol_t*)malloc(sizeof(symbol_t)); */
   memset(table->entries, (int)NULL, sizeof(*(table->entries)) * SYMBOL_T_SIZE);
   table->entries_size = 0;
}

/* Libera a área de memória reservada para a tabela hash */
void free_table(symbol_t* table) {
   int i;

   for (i = 0; i < SYMBOL_T_SIZE; i++) { /* Percorre a tabela imprimindo no arquivo o índice e o conteudo de cada posição ocupada */
      if (table->entries[i] != NULL) {
         free(table->entries[i]);
      }
   }
}

/* Retorna um ponteiro para uma dada estrutura, a partir de um nome (consulta) */
entry_t* lookup(symbol_t table, char* name) {
   int index, i0;

   index = i0 = hash_function(name);
   while (table.entries[index] == NULL || strcmp(table.entries[index]->name, name) != 0) { /* Se a posição estiver vazia, ou o nome não for o procurado, procuramos na próxima estrutura da tabela */
      index++;
      if (index >= SYMBOL_T_SIZE) /*Caso chegue ao final da tabela, começamos a busca por seu início */
         index = 0;
      if (index == i0) /* Se retornar  posição inicial, é porque não encontrou o nome procurado */
         return NULL;
   }

   return table.entries[index];
}

/* Função insere um elemento na tabela hash */
int insert(symbol_t* table, entry_t* entry) {
   int index;

   if (table->entries_size == SYMBOL_T_SIZE) /* Se a tabela estiver cheia, retorna ERRO */
      return -1;
   index = hash_function(entry->name); /* Função hash */
   while (table->entries[index] != NULL) { /* Caso a posição apontada pela função já esteja ocupada, procura a próxima posição vazia */
      index++;
      if (index >= SYMBOL_T_SIZE) /*Caso chegue ao final da tabela, retorna para o seu início */
         index = 0;
   }
   table->entries[index] = (entry_t*)malloc(sizeof(entry_t));
   memcpy(table->entries[index], entry, sizeof(entry_t));

   /* entry; /* Coloca o elemento na posição indicada pelo index */
   table->entries_size++; /* Guarda o tamanho total da tabela */
   return 0;
}

/*Imprime o conteuo da tabela na saída padrão */
int print_table(symbol_t table) {
   return print_file_table(stdout, table);
}

int print_file_table(FILE* out, symbol_t table) {
   int i;

   for (i = 0; i < SYMBOL_T_SIZE; i++) { /* Percorre a tabela imprimindo no arquivo o índice e o conteudo de cada posição ocupada */
      if (table.entries[i] != NULL) {
         fprintf(out, "%4d %s\n", i, table.entries[i]->name);
      }
   }

   return table.entries_size; /*retorna o tamanho da tabela */
}

