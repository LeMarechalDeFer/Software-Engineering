#include <stdio.h>
#include <stdlib.h>

// Structure pour le nœud de l'arbre de Huffman
typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// Structure pour la file de priorité (min-heap)
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;
