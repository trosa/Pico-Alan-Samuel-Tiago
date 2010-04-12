#include <stdio.h>
#include "../src/lista.h"

int main(){
   struct node_tac* l = NULL, *l2 = NULL;
   struct tac* n;
   
   
   n = create_inst_tac("eu", "tu", "!=", "nos");
   append_inst_tac(&l, n);
   n = create_inst_tac("a", "b", "+", "c");
   append_inst_tac(&l2, n);

   cat_tac(&l, &l2);
   print_tac(stdout, l);

   return(0);
}
