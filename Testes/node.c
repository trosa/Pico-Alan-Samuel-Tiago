#include <stdio.h>
#include <stdlib.h>
#include "../src/node.h"

int main ()
{
   Node *pf1, *pf3, *pf0;
   Node **children;

   pf1 = create_leaf(1, int_node, "1", NULL);
   pf3 = create_leaf(1, int_node, "2", NULL);
   pack_nodes(&children, 0, pf1);
   pack_nodes(&children, 1, pf3);
   printf("h = %d\n", height(pf1)); /* deve imprimir 1 */
   pf0 = create_node(1, int_node, "0", NULL, 2, children); /* pf0 é o pai de pf1 e pf3 */
   printf("h = %d\n", height(pf0)); /* deve imiprimir 2 */
   printf("n = %d\n", nb_of_children(pf0)); /* deve imprimir 2 */
   printf("n = %d\n", nb_of_children(child(pf0, 0))); /* deve imprimir 0, porque o retorno de child é o filho de pf0, que é uma folha. */
   deep_free_node(pf0);
}
