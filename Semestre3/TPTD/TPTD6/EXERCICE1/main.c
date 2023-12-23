#include "binaryTree1.h"


int main() {

    Tree *A = newTree(1);
    A->tleft = newTree(2);
    A->tright = newTree(3);

    A->tleft->tleft = newTree(4);
    A->tleft->tright = newTree(5);

    printf("Parcours préfixe de l'arbre :\n");
    print_tree_prefix(A);
    printf("\n");

    unsigned int height = depth_tree(A);
    printf("Hauteur de l'arbre : %u\n", height);

    printf("Parcours en largeur de l'arbre :\n");
    tree_width_course(A);
    printf("\n");

    bool are_equal = equals_trees(A, A);
    printf("L'arbre est-il égal à lui-même ? %s\n", are_equal ? "Oui" : "Non");

    clean_tree(A);

    return 0;
}
