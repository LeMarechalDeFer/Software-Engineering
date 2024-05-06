#ifndef __EXERCICE2__H__
#define __EXERCICE2__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTICES 100  

int visited[MAX_VERTICES]; 

typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Structure pour le graphe
typedef struct graph {
    int numVertices;
    Node** adjLists;  
} Graph;

Node* createNode(int v);
void addEdge(Graph* graph, int src, int dest);
Graph* createGraph(int vertices);
void DFS(Graph* graph, int vertex) ;

#endif
