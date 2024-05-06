//#include "exercice2.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// // Fonction pour créer un nœud
// Node* createNode(int v) {
//     Node* newNode = malloc(sizeof(Node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// // Fonction pour ajouter une arête au graphe (non dirigé)
// void addEdge(Graph* graph, int src, int dest) {
//     // Ajouter une arête de src à dest
//     Node* newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;

//     // Ajouter une arête de dest à src (car le graphe est non dirigé)
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }

// // Fonction pour créer un graphe
// Graph* createGraph(int vertices) {
//     Graph* graph = malloc(sizeof(Graph));
//     graph->numVertices = vertices;

//     graph->adjLists = malloc(vertices * sizeof(Node*));

//     for (int i = 0; i < vertices; i++) {
//         graph->adjLists[i] = NULL;
//         visited[i] = 0;
//     }
//     return graph;
// }



// void explorerProfondeur(ListeSuccesseurs* liste, int taille) {
//     int* visite = (int*)calloc(taille, sizeof(int));
//     for (int i = 0; i < taille; i++) {
//         if (!visite[i]) {
//             DFS(liste, i, visite);
//         }
//     }
//     free(visite);
// }


// // Fonction DFS récursive
// void DFS(Graph* graph, int vertex) {
//     Node* adjList = graph->adjLists[vertex];
//     Node* temp = adjList;

//     visited[vertex] = 1;
//     printf("Visited %d \n", vertex);

//     while (temp != NULL) {
//         int connectedVertex = temp->vertex;

//         if (visited[connectedVertex] == 0) {
//             DFS(graph, connectedVertex);
//         }
//         temp = temp->next;
//     }
// }


typedef struct graph {
    int nombre_de_sommet ;
    bool** matrice_adjacence;
}graph ;

int n =500;

void parcours_prof(graph G){
    int i;
    bool M[n] ;

    for(i=1; i<n; i++){
        M[i]= false;
    }
    for(i=1; i<n; i++){
        if(M[i]=false){
            prof(i, G, M);
        }
    }
}



void prof(int i, graph G, bool M[n]){
    int j;
    M[i] = true ;
    for(j=1; j<n;j++){
        if(G.matrice_adjacence[i][j]= true && M[j]= false){
            prof(j, G, M);
        }
    }
}