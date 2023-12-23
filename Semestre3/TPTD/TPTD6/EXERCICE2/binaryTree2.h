#ifndef __BINARY_TREE2__H__
#define __BINARY_TREE2__H__


#include <stdio.h>
#include <stdlib.h>


typedef struct Tree
{
    char op;
    unsigned int value ;
    struct Tree *tleft ;
    struct Tree *tright ;
} Tree;


void clean_tree(Tree *tr);
Tree *newTree(char op, int value);
int evaluate(Tree *tr);



#endif