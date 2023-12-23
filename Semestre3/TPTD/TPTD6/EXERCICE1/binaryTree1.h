#ifndef __BINARY_TREE1__H__
#define __BINARY_TREE1__H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAB 12

typedef struct Tree
{
    unsigned int value ;
    struct Tree *tleft ;
    struct Tree *tright ;
    struct Tree *parent ;
} Tree;


typedef struct Node {
    Tree *node;
    struct Node *next;
} Node, *QueueNode;

Tree *newTree(unsigned int e);
Tree *joinTree(Tree *G, Tree *D, unsigned int r);
void clean_tree(Tree *tr);
Tree *createTreeWithTab(unsigned int T[]);
void print_tree_prefix(Tree *tr);
bool equals_trees(Tree *tr1, Tree *tr2);
unsigned int depth_tree(Tree *tr);

unsigned int sum_tree_leftBranch(Tree *tr);
unsigned int sum_of_left_leaves(Tree *A);

void enqueue(QueueNode *head, Tree *node) ;
Tree* dequeue(QueueNode *head);
bool isEmpty(QueueNode head);
void tree_width_course(Tree *A);

#endif

