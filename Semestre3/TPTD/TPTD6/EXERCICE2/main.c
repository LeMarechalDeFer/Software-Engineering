#include "binaryTree2.h"

int main() {
    Tree *tr = newTree('+', 0);

    tr->tleft = newTree('*', 0);
    tr->tleft->tleft = newTree('\0', 2);
    tr->tleft->tright = newTree('-', 0);
    tr->tleft->tright->tleft = newTree('\0', 15);
    tr->tleft->tright->tright = newTree('\0', 1);

    tr->tright = newTree('/', 0);
    tr->tright->tleft = newTree('+', 0);
    tr->tright->tleft->tleft = newTree('\0', 6);
    tr->tright->tleft->tright = newTree('\0', 8);
    tr->tright->tright = newTree('\0', 2);


    printf("La valeur de l'expression est : %d\n", evaluate(tr));


    return 0;
}