#include "exercice.h"

char **lecturegraphe(int *ordre) {
    FILE *f = fopen("graphe.txt", "r");
    if (!f) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    fscanf(f, "%d", ordre);
    char **adjacence = (char **)malloc(*ordre * sizeof(char *));
    for (int i = 0; i < *ordre; i++) {
        adjacence[i] = (char *)calloc(*ordre, sizeof(char));
    }

    int i, j;
    while (fscanf(f, "%d %d", &i, &j) != EOF) {
        adjacence[i][j] = 1;
    }

    fclose(f);
    return adjacence;
}

void affichematrice(int ordre, char **adjacence) {
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            printf("%d ", adjacence[i][j]);
        }
        printf("\n");
    }
}

void affichesuccesseurs(int ordre, char **adjacence) {
    for (int i = 0; i < ordre; i++) {
        printf("Successeurs de %d : ", i);
        for (int j = 0; j < ordre; j++) {
            if (adjacence[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void affichepredecesseurs(int ordre, char **adjacence) {
    for (int i = 0; i < ordre; i++) {
        printf("Prédécesseurs de %d : ", i);
        for (int j = 0; j < ordre; j++) {
            if (adjacence[j][i]) { // Inversion de j et i pour trouver les prédécesseurs
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void affichesarcs(int ordre, char **adjacence) {
    printf("Arcs du graphe :\n");
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (adjacence[i][j]) {
                printf("(%d, %d) ", i, j);
            }
        }
    }
    printf("\n");
}

void saisiegraphe() {
    printf("Saisie d'un nouveau graphe.\n");
    int ordre;
    printf("Nombre de sommets : ");
    scanf("%d", &ordre);
    
    char **adjacence = (char **)malloc(ordre * sizeof(char *));
    for (int i = 0; i < ordre; i++) {
        adjacence[i] = (char *)calloc(ordre, sizeof(char));
    }
    
    int i, j;
    while (1) {
        printf("Entrer un arc sous la forme i j (entrer -1 -1 pour terminer) : ");
        scanf("%d %d", &i, &j);
        if (i == -1 && j == -1) {
            break;
        }
        if (i >= 0 && i < ordre && j >= 0 && j < ordre) {
            adjacence[i][j] = 1;
        } else {
            printf("Arc invalide.\n");
        }
    }

    FILE *f = fopen("graphe_saisi.txt", "w");
    fprintf(f, "%d\n", ordre);
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (adjacence[i][j]) {
                fprintf(f, "%d %d\n", i, j);
            }
        }
    }
    fclose(f);
    
    // Libération de la mémoire
    for (int i = 0; i < ordre; i++) {
        free(adjacence[i]);
    }
    free(adjacence);
    
    printf("Graphe sauvegardé dans 'graphe_saisi.txt'.\n");
}

int nbchemin2(int ordre, char **adjacence) {
    int count = 0;
    for (int i = 0; i < ordre; i++) {
        for (int j = 0; j < ordre; j++) {
            if (i != j) {
                for (int k = 0; k < ordre; k++) {
                    if (adjacence[i][k] && adjacence[k][j]) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}


