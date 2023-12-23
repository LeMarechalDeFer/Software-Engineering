#include "binaryTree2.h"


void clean_tree(Tree *tr){
    
    if(tr == NULL){
        return;
    }

    printf("Suppression de %u\n", tr->value);

    clean_tree(tr->tleft);
    clean_tree(tr->tright);

    free(tr);
}

Tree *newTree(char op, int value){
    Tree *tr = malloc(sizeof(Tree));

    if(tr == NULL){
        perror("Erreur d'allocation d'un noeud\n");
        exit(EXIT_FAILURE);
    }

    tr->op = op;
    tr->value = value ;
    tr->tleft = NULL ;
    tr->tright = NULL ;
    
    //printf("Le noeud %u ou %c à été initialisé\n", tr->value, tr->op);

    return tr ;
}

int evaluate(Tree *tr) {
    
    if (tr->op == '\0') {
        return tr->value;
    }

    unsigned int left_val = evaluate(tr->tleft);
    unsigned int right_val = evaluate(tr->tright);

    switch (tr->op) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val; 
        default: 
            printf("Opérateur invalide");
            exit(EXIT_FAILURE);
    }
}
