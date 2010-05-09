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
   return table->entries_size = 0;
}

/* Libera a área de memória reservada para a tabela hash */
void free_table(symbol_t* table) {
   int i;
   struct list_entry *p, *p2;

   for (i = 0; i < SYMBOL_T_SIZE; i++) { /* Percorre a tabela imprimindo no arquivo o índice e o conteudo de cada posição ocupada */
      for (p = table->entries[i]; p != NULL; p = p2) { /* apontamos o p2 para o next do p, porque se formos refernciar o p depois de fazer o free, vamos acessar uma posição de memória inválida. Por isso, p2 guarda a posição, e p aponta para o mesmo lugar que p2, que será o próximo a ser excluido */
         p2 = p->next;
	 free(p->entry.name);
	 if(p->entry.array != NULL) {
	   free(p->entry.array->linf);
	   free(p->entry.array->lsup);
	   free(p->entry.array);
	 }
         free(p);
      }
      table->entries[i] = NULL;
   }
}

/* Retorna um ponteiro para uma dada estrutura, a partir de um nome (consulta) */
entry_t* lookup(symbol_t table, char* name) {
   int index;
   struct list_entry *p;

   index = hash_function(name);
   if (table.entries[index] == NULL)
      return NULL;
   for (p = table.entries[index]; p != NULL; p = p->next)
      if (strcmp(p->entry.name, name) == 0)
         return &(p->entry);
   return NULL;
}

/* Função insere um elemento na tabela hash */
int insert(symbol_t* table, entry_t* entry) {
   int index;

   index = hash_function(entry->name); /* Função hash */
   if (table->entries[index] == NULL)
      table->entries[index] = table->last[index] = (struct list_entry*)malloc(sizeof(struct list_entry));
   else {
      table->last[index]->next = (struct list_entry*)malloc(sizeof(struct list_entry));
      table->last[index] = table->last[index]->next;
   }
   table->last[index]->entry = *entry;
   table->last[index]->next = NULL;

   table->entries_size++; /* Guarda o tamanho total da tabela */
   return 0;
}

/*Imprime o conteuo da tabela na saída padrão */
int print_table(symbol_t table) {
   return print_file_table(stdout, table);
}

int print_file_table(FILE* out, symbol_t table) {
   int i;
   struct list_entry *p;

   for (i = 0; i < SYMBOL_T_SIZE; i++) { /* Percorre a tabela imprimindo no arquivo o índice e o conteudo de cada posição ocupada */
      for (p = table.entries[i]; p != NULL; p = p->next) {
         fprintf(out, "%4d %s s=%d d=%d\n", i, p->entry.name, p->entry.size, p->entry.desloc);
      }
   }

   return table.entries_size; /*retorna o tamanho da tabela */
}

