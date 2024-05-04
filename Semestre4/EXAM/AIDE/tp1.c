//----------------------
// TPTD Graph 1 - 2A
//----------------------

//----------------------
// Includes
//----------------------
#include <stdio.h>
#include <stdlib.h>

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

//----------------------
// Next
//----------------------
void displayNext(int ordre, int** adjacence) 
{
    printf("Liste des successeurs de chaque sommet :\n");
    for (int i = 0; i < ordre; i++) 
    {
        printf("Successeurs de %d : ", i);
        for (int j = 0; j < ordre; j++) 
        {
            if (adjacence[i][j] == 1) 
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

//----------------------
// Prev
//----------------------
void displayPrev(int ordre, int** adjacence) 
{
    printf("Liste des prédécesseurs de chaque sommet :\n");
    for (int i = 0; i < ordre; i++) 
    {
        printf("Prédécesseurs de %d : ", i);
        for (int j = 0; j < ordre; j++) 
        {
            if (adjacence[j][i] == 1) 
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

//----------------------
// Arcs
//----------------------
void displayArc(int ordre, int** adjacence) 
{
    printf("Liste des arcs du graphe :\n");
    for (int i = 0; i < ordre; i++) 
    {
        for (int j = 0; j < ordre; j++) 
        {
            if (adjacence[i][j] == 1) 
            {
                printf("(%d, %d) ", i, j);
            }
        }
    }
    printf("\n");
}

//----------------------
// WayOfTwo
//----------------------
int nbWayOfTwo(int ordre, int** adjacence) 
{
    int iWays = 0;
    for (int i = 0; i < ordre; i++) 
    {
        for (int j = 0; j < ordre; j++) 
        {
            if (adjacence[i][j] == 1) 
            {
                for (int k = 0; k < ordre; k++) 
                {
                    if (adjacence[j][k] == 1) 
                    {
                        iWays++;
                    }
                }
            }
        }
    }
    return iWays;
}

//---------------------------------
// Read graph and buid adj matrix
//---------------------------------
int** readGraph(int* ordre) 
{
    FILE *fichier;
    fichier = fopen("graph.txt", "r"); 

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
        matrice[i][j] = 1; // 1 = arc(i,j)
    }

    fclose(fichier);
    return matrice;
}

char** readGraphCHAR(int* ordre) 
{
    FILE *fichier;
    fichier = fopen("graph.txt", "r"); 

    if (fichier == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    // Lecture du nombre de sommets
    fscanf(fichier, "%d", ordre); 

    char** matrice = (char**)malloc(*ordre * sizeof(char*));
    for (int i = 0; i < *ordre; i++) 
    {
        matrice[i] = (char*)malloc(*ordre * sizeof(char));
    }

    // Lecture des arcs
    int i, j;
    while (fscanf(fichier, "%d %d", &i, &j) == 2) 
    {
        matrice[i][j] = '1'; // 1 = arc(i,j)
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

//---------------------
// Input Graph
//---------------------
void inputGraph() 
{
    int ordre, arcs;
    printf("Entrez le nombre de sommets : ");
    scanf("%d", &ordre);
    printf("Entrez le nombre d'arcs : ");
    scanf("%d", &arcs);

    FILE *fichier;
    fichier = fopen("graphInput.txt", "w"); 

    if (fichier == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    // Écriture du nombre de sommets dans le fichier
    fprintf(fichier, "%d\n", ordre); 
    
    for (int i = 0; i < arcs; i++) 
    {
        int firstVertex, lastVertex;
        printf("Arc %d : Entrez le sommet de départ et le sommet d'arrivée (séparés par un espace) : ", i+1);
        scanf("%d %d", &firstVertex, &lastVertex);
        
        // Écriture des arcs dans le fichier
        fprintf(fichier, "%d %d\n", firstVertex, lastVertex);
    }

    fclose(fichier);
}

//---------------------
// Main
//---------------------
int main(void) 
{
    int ordre;
    int** matrice = readGraph(&ordre);

    int
    char** matriceCHAR = readGraphCHAR(&ordreChar);

    displayMatrix(ordre, matrice);

    displayNext(ordre, matrice);

    displayPrev(ordre, matrice);

    displayArc(ordre, matrice);

    int iNbWays = nbWayOfTwo(ordre, matrice);
    printf("Nombre de chemins de longueur 2 dans le graphe : %d\n", iNbWays);

 //   inputGraph();

    freeMemory(ordre, matrice);
    return 0;
}