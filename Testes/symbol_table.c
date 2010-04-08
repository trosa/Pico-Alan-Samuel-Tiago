#include "../src/symbol_table.h"

int main(int argc, char* argv[]) {
   symbol_t tabela;
   entry_t e1, e2, e3;

   init_table(&tabela);
   printf("%p\n", lookup(tabela, "teste"));

   e1.name = "e1";
   e2.name = "e2";
   e3.name = "ee1";

   insert(&tabela, &e1);
   insert(&tabela, &e2);
   insert(&tabela, &e3);

   printf("e1 = %s\n", lookup(tabela, "e1")->name);
   printf("e2 = %s\n", lookup(tabela, "e2")->name);
   printf("e3 = %s\n", lookup(tabela, "ee1")->name);

   print_table(tabela);
   free_table(&tabela);
}
