
#ifndef __ARBRE__H
#define __ARBRE__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Tree
{
    int value ;
    struct Tree *tleft ;
    struct Tree *tright ;
    struct Tree *parent ;
} Tree;

Tree *newTree(int x);
void clean_tree(Tree *tr);
Tree *joinTree(Tree *left, Tree *right, int node);
void print_tree_prefix(Tree *tr); //pref gauche et post droite en premier 
int count_tree_node(Tree *tr);


#endif
//compare
//trie
//reverse

//inserer
//hauteur