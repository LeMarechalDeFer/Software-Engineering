#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void DFSUtil(int v, bool visited[], Node** adjacencyList, int* suffixOrder, int* index) {
    // Marquer le sommet courant comme visité
    visited[v] = true;
    printf("Début de visite du sommet %d\n", v);  // Debug: début de visite du sommet

    // Recur pour tous les sommets adjacents à ce sommet
    Node* temp = adjacencyList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            printf("Aller vers le sommet non visité %d à partir du sommet %d\n", adjVertex, v);  // Debug: tracer le parcours vers un sommet non visité
            DFSUtil(adjVertex, visited, adjacencyList, suffixOrder, index);
        } else {
            printf("Le sommet %d a déjà été visité, pas de récursion vers %d\n", v, adjVertex);  // Debug: cas déjà visité
        }
        temp = temp->next;
    }

    // Ajouter le sommet à l'ordre suffixe après avoir exploré tous ses voisins
    suffixOrder[*index] = v;
    printf("Ajout du sommet %d à l'ordre suffixe à l'index %d\n", v, *index);  // Debug: afficher l'ajout à l'ordre suffixe
    (*index)--;
}


void DFS(Node** adjacencyList, int num_vertices, int* suffixOrder) {
    bool *visited = (bool *)malloc(num_vertices * sizeof(bool));
    int index = num_vertices - 1;  // Dernier indice pour l'ordre suffixe
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }

    printf("Démarrage de l'exploration en profondeur du graphe avec %d sommets\n", num_vertices);  // Debug: début de DFS avec compte de sommets
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            printf("Démarrage du DFS à partir du sommet %d\n", i);  // Debug: sommet de départ du DFS
            DFSUtil(i, visited, adjacencyList, suffixOrder, &index);
        } else {
            printf("Le sommet %d a déjà été exploré, pas de démarrage de DFS ici\n", i);  // Debug: sommet déjà exploré
        }
    }

    printf("Fin de l'exploration DFS\n");  // Debug: fin de l'exploration DFS
    free(visited);
}


Node** createAdjacencyList(int **matrix, int num_vertices) {
    Node** adjacencyList = (Node**) malloc(num_vertices * sizeof(Node*));
    for (int i = 0; i < num_vertices; i++) {
        adjacencyList[i] = NULL;
        for (int j = 0; j < num_vertices; j++) {
            if (matrix[i][j] == 1) {
                // Ajouter le sommet j à la liste des successeurs de i
                Node* newNode = (Node*) malloc(sizeof(Node));
                newNode->vertex = j;
                newNode->next = adjacencyList[i];
                adjacencyList[i] = newNode; // Ajout en tête pour simplifier l'insertion
            }
        }
    }
    return adjacencyList;
}

void printAdjacencyList(Node** adjacencyList, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        Node* temp = adjacencyList[i];
        printf("Liste de successeurs pour le sommet %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeAdjacencyList(Node** adjacencyList, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        Node* temp = adjacencyList[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(adjacencyList);
}

int readNumVertices(FILE *file) {
    int num_vertices;
    fscanf(file, "%d", &num_vertices);
    return num_vertices;
}

int** initializeMatrix(int num_vertices) {
    int **matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void fillAdjacencyMatrix(FILE *file, int **matrix, int num_vertices) {
    int from, to;
    while (fscanf(file, "%d %d", &from, &to) == 2) {
        matrix[from - 1][to - 1] = 1;  
    }
}

void printMatrix(int **matrix, int num_vertices) {
    printf("Matrice d'adjacence :\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    FILE *file = fopen("TD.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    int num_vertices = readNumVertices(file);
    int **adj_matrix = initializeMatrix(num_vertices);
    fillAdjacencyMatrix(file, adj_matrix, num_vertices);
    fclose(file);

    printMatrix(adj_matrix, num_vertices);
    
    // Transformer la matrice en liste de successeurs
    Node** adjacencyList = createAdjacencyList(adj_matrix, num_vertices);
    printAdjacencyList(adjacencyList, num_vertices);
    

    // Créer un tableau pour stocker l'ordre suffixe
    int* suffixOrder = (int*)malloc(num_vertices * sizeof(int));

    printf("Exploration en profondeur du graphe (DFS) et ordre suffixe:\n");
    DFS(adjacencyList, num_vertices, suffixOrder);

    // Affichage de l'ordre suffixe
    printf("Ordre suffixe: ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", suffixOrder[i]);
    }
    printf("\n");

    // Nettoyage
    freeMatrix(adj_matrix, num_vertices);
    freeAdjacencyList(adjacencyList, num_vertices);
    free(suffixOrder);



    return 0;
}
