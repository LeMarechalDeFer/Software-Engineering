//----------------------
// TPTD Graph 2 - 2A
//----------------------

//----------------------
// Includes
//----------------------
#include <stdio.h>
#include <stdlib.h>

//----------------------
// Defines
//----------------------
#define MAx_VERTEX  100
//----------------------
// Struct
//----------------------
typedef struct NextVertex NextVertex;
typedef struct NextVertexList NextVertexList;

// Structure d'un élément de la liste chaînée représentant les NextVertexs d'un sommet
struct NextVertex 
{
    int vertex;
    NextVertex* next;
};

// Structure d'une liste de NextVertexs
struct NextVertexList 
{
    NextVertex* head;
};

// Fonction pour créer une nouvelle liste de NextVertexs
NextVertexList* createNextVertexList() 
{
    NextVertexList* list = (NextVertexList*)malloc(sizeof(NextVertexList));
    if (list != NULL) 
    {
        list->head = NULL;
    }
    return list;
}

// Fonction pour ajouter un NextVertex à une liste de NextVertexs
void addNextVertex(NextVertexList* list, int vertex) 
{
    NextVertex* vertexTmp = (NextVertex*)malloc(sizeof(NextVertex));
    if (vertexTmp != NULL) 
    {
        vertexTmp->vertex = vertex;
        vertexTmp->next = list->head;
        list->head = vertexTmp;
    }
}

// Fonction pour détruire une liste de NextVertexs
void destroyListeNextVertexs(NextVertexList* list) 
{
    NextVertex* current = list->head;
    while (current != NULL) 
    {
        NextVertex* vertextTemp = current;
        current = current->next;
        free(vertextTemp);
    }
    free(list);
}

// Fonction pour afficher les NextVertexs de chaque sommet
void displayNextVertexList(NextVertexList** list, int ordre) 
{
    for (int i = 0; i < ordre; i++) 
    {
        printf("NextVertex of %d : ", i);
        NextVertex* current = list[i]->head;
        while (current != NULL) 
        {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

//---------------------------------------
// Build and fill MasterNextVertext list
//---------------------------------------
NextVertexList** buildAndFillMasterNextVertextList(int ordre, int** adjMatrix)
{
    // Création d'un tableau de listes de successeurs
    NextVertexList** list = (NextVertexList**)malloc(ordre * sizeof(NextVertexList*));
    if (list == NULL) 
    {
        printf("Error on allocating memory.\n");
        exit(-1);
    }

    // Initialisation de chaque liste de successeurs
    for (int i = 0; i < ordre; i++) 
    {
        list[i] = createNextVertexList();
        if (list[i] == NULL) 
        {
            printf("Error on allocating memory.\n");
            return NULL;
        }
    }

    // Remplissage des listes de successeurs à partir de la matrice d'adjacence
    for (int i = 0; i < ordre; i++) 
    {
        for (int j = 0; j < ordre; j++) 
        {
            if (adjMatrix[i][j] == 1) 
            {
                addNextVertex(list[i], j);
            }
        }
    }

    return list;
}

//---------------------------------
// DFS
//---------------------------------
// Fonction pour explorer en profondeur un graphe orienté à partir d'un sommet donné
void dfs(int startVortex, int** adjMatrix, int* visite, int ordre) 
{
    visite[startVortex] = 1; // Marquer le sommet comme visité
    printf("%d ", startVortex); // Afficher le sommet visité

    // Explorer les sommets adjacents non visités
    for (int i = 0; i < ordre; i++) 
    {
        if (adjMatrix[startVortex][i] == 1 && visite[i] == 0) {
            dfs(i, adjMatrix, visite, ordre);
        }
    }
}

//---------------------------------
// Suffix order of the graph
//---------------------------------
void displaySuffixOrder(int** adjMatrix, int ordre) 
{
    int visite[MAx_VERTEX] = {0}; // Tableau de marquage des sommets visités

    printf("Ordre suffixe sur la foret couvrante associee au parcours en profondeur du graphe : ");
    for (int i = 0; i < ordre; i++) 
    {
        if (visite[i] == 0) 
        {
            dfs(i, adjMatrix, visite, ordre);
        }
    }
    printf("\n");
}



//---------------------------------
// Read graph and buid adj matrix
//---------------------------------
int** readGraph(int* ordre) 
{
    FILE *fichier;
    fichier = fopen("GraphTD2.txt", "r"); 

    if (fichier == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    // Lecture du nombre de sommets
    fscanf(fichier, "%d", ordre); 

    int** matrice = (int**)malloc(*ordre * sizeof(int*));
    if (matrice == NULL) 
    {
        printf("Erreur lors de la création de la matrice.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *ordre; i++) 
    {
        matrice[i] = (int*)malloc(*ordre * sizeof(int));
    }

    // Lecture des arcs
    int i, j;
    while (fscanf(fichier, "%d %d", &i, &j) == 2) 
    {
        matrice[i-1][j-1] = 1; // 1 = arc(i,j)
    }

    fclose(fichier);
    return matrice;
}

//---------------------
// Memory
//---------------------
void freeMemory(int ordre, int** matrice)
{
    // Libération de la mémoire
    for (int i = 0; i < ordre; i++) 
    {
        free(matrice[i]);
    }
    free(matrice);
}

//----------------------
// displayMatrix
//----------------------
void displayMatrix(int ordre, int** adjacence)
{
    printf("Matrice d'adjacence du graphe :\n");
    for (int i = 0; i < ordre; i++)
    {
        for (int j = 0; j < ordre; j++) 
        {
            printf("%d ", adjacence[i][j]);
        }
        printf("\n");
    }
}

//---------------------------
// Main
//---------------------------
int main (void)
{
    int ordre;
    int** adjMatrix = readGraph(&ordre);
    
    displayMatrix(ordre,adjMatrix);

    NextVertexList** masterList = buildAndFillMasterNextVertextList(ordre,adjMatrix);
     // Affichage des successeurs de chaque sommet
    displayNextVertexList(masterList, ordre);

    // Initialisation du tableau de visite
    int* visite = (int*)malloc(ordre * sizeof(int));
    for (int i = 0; i < ordre; i++) 
    {
        visite[i] = 0; // Initialisation à 0 (non visité)
    }

    // Parcours en profondeur du graphe orienté à partir du sommet 0
    printf("Parcours en profondeur du graphe oriente a partir du sommet 0 : ");
    dfs(0, adjMatrix, visite, ordre);
    printf("\n");

    // Affichage de l'ordre suffixe du graphe
    displaySuffixOrder(adjMatrix, ordre);

    // Libération de la mémoire
    for (int i = 0; i < ordre; i++) 
    {
        destroyListeNextVertexs(masterList[i]);
    }
    free(masterList);

    return 0;
}