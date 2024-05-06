#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100  // Nombre maximum de sommets dans le graphe

int visited[MAX_VERTICES]; // Tableau pour suivre les sommets visités

// Structure pour les nœuds dans la liste d'adjacence
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Structure pour le graphe
typedef struct graph {
    int numVertices;
    Node** adjLists;  // Tableau de pointeurs vers des nœuds
} Graph;

// Fonction pour créer un nœud
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour ajouter une arête au graphe (non dirigé)
void addEdge(Graph* graph, int src, int dest) {
    // Ajouter une arête de src à dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Ajouter une arête de dest à src (car le graphe est non dirigé)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Fonction pour créer un graphe
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        visited[i] = 0;
    }
    return graph;
}

// Fonction DFS récursive
void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}


int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    DFS(graph, 0);

    return 0;
}
