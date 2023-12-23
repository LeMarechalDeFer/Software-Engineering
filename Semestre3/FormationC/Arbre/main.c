#include "arbre.h"

int main(){
    Tree *arbre = joinTree(joinTree(newTree(8), newTree(3), 2), newTree(4), 6);

    print_tree_prefix(arbre);

    printf("Nombre de noeuds : %d\n", count_tree_node(arbre));

    clean_tree(arbre);

    return 0;
}