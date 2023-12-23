#include "arbre.h"

Tree *newTree(int x){
    Tree *tr = malloc(sizeof(Tree));

    if(tr == NULL){
        perror("Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    tr->value = x ;
    tr->tleft = NULL ;
    tr->tright = NULL ;
    tr->parent = NULL ;

    printf("Creation de %d\n", tr->value);

    return tr ;
}

void clean_tree(Tree *tr){
    
    if(tr == NULL){
        return;
    }

    printf("Suppression de %d\n", tr->value);

    clean_tree(tr->tleft);
    clean_tree(tr->tright);

    free(tr);
}



Tree *joinTree(Tree *left, Tree *right, int node){

    Tree *tr = newTree(node);
    tr->tleft = left ;
    tr->tright = right ; 

    if(left != NULL){
        left->parent = tr ;
    }
    if(right != NULL){
        right->parent = tr ;
    }

    return tr;
}

//pref gauche et post droite en premier 
void print_tree_prefix(Tree *tr){

    if(tr == NULL){
        return;
    }
    if(tr->parent != NULL){
        printf("(%d)=>(%d)\n", tr->parent->value, tr->value);
    }
    else{
        printf("(%d)\n", tr->value);
    }

    if(tr->tleft != NULL){
        print_tree_prefix(tr->tleft); 
    }
    if(tr->tright != NULL){
        print_tree_prefix(tr->tright);
    }
}

int count_tree_node(Tree *tr){
    if(tr ==NULL){
        return 0;
    }
    else{
        return(count_tree_node(tr->tleft) + count_tree_node(tr->tright) +1);
    }
    
}