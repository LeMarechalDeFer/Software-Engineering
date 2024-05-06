#include "exercice1.h"


graph saisiegraphe() {
    printf("Saisie d'un nouveau graphe.\n");
    int ordre;
    printf("Nombre de sommets : ");
    scanf("%d", &ordre);
    
    graph G;
    G.nombre_de_sommet = ordre;
    G.matrice_adjacence = (char **)malloc(G.nombre_de_sommet * sizeof(char *));
    if (!G.matrice_adjacence) {
    perror("Echec de l'allocation de la mémoire pour la matrice d'adjacence");
    exit(EXIT_FAILURE);
}
    for (int i = 0; i < G.nombre_de_sommet; i++) {
        G.matrice_adjacence[i] = (char *)calloc(G.nombre_de_sommet, sizeof(char));
        if (!G.matrice_adjacence[i]) {
        perror("Echec de l'allocation de la mémoire pour la ligne de la matrice d'adjacence");
        for (int j = 0; j < i; j++) {
            free(G.matrice_adjacence[j]);
        }
        free(G.matrice_adjacence);
        exit(EXIT_FAILURE);
    }
    }

    int i, j;
    while (1) {
        printf("Entrer un arc sous la forme i j (entrer -1 -1 pour terminer) : ");
        scanf("%d %d", &i, &j);
        if (i == -1 && j == -1) {
            break;
        }
        if (i >= 0 && i < G.nombre_de_sommet && j >= 0 && j < G.nombre_de_sommet) {
            G.matrice_adjacence[i][j] = 1;
        } else {
            printf("Arc invalide.\n");
        }
    }

    return G;
}


void enregistrement_graph(graph G){
    FILE *f = fopen("graphe_saisi.txt", "w");
    fprintf(f, "%d\n", G.nombre_de_sommet);
    for (int i = 0; i < G.nombre_de_sommet; i++) {
        for (int j = 0; j < G.nombre_de_sommet; j++) {
            if (G.matrice_adjacence[i][j]) {
                fprintf(f, "%d %d\n", i, j);
            }
        }
    }
    fclose(f);
    
    
    printf("Graphe sauvegardé dans 'graphe_saisi.txt'.\n");
}



int nbchemin2(graph G) {
    int count = 0;
    for (int i = 0; i < G.nombre_de_sommet; i++) {
        for (int j = 0; j < G.nombre_de_sommet; j++) {
            if (i != j) {
                for (int k = 0; k < G.nombre_de_sommet; k++) {
                    if (G.matrice_adjacence[i][k] && G.matrice_adjacence[k][j]) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}


void affichematrice(graph G) {
    for (int i = 0; i < G.nombre_de_sommet; i++) {
        for (int j = 0; j < G.nombre_de_sommet; j++) {
            printf("%d ", G.matrice_adjacence[i][j]);
        }
        printf("\n");
    }
}

void nettoyage_memoire(graph G){
    // Libération de la mémoire
    for (int i = 0; i < G.nombre_de_sommet; i++) {
        free(G.matrice_adjacence[i]);
    }
    free(G.matrice_adjacence);
}

