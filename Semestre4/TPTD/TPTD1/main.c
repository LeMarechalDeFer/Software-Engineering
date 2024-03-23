#include "exercice.h"

int main() {
    int ordre;
    char **adjacence = lecturegraphe(&ordre);

    printf("Matrice d'adjacence :\n");
    affichematrice(ordre, adjacence);
    printf("\n");

    printf("Successeurs de chaque sommet :\n");
    affichesuccesseurs(ordre, adjacence);
    printf("\n");

    printf("Prédécesseurs de chaque sommet :\n");
    affichepredecesseurs(ordre, adjacence);
    printf("\n");

    printf("Tous les arcs du graphe :\n");
    affichesarcs(ordre, adjacence);
    printf("\n");

    int chemin2 = nbchemin2(ordre, adjacence);
    printf("Nombre de chemins de longueur 2 : %d\n", chemin2);
    printf("\n");

    // Saisie d'un nouveau graphe 
    // saisiegraphe();

    // Libération de la mémoire
    for (int i = 0; i < ordre; i++) {
        free(adjacence[i]);
    }
    free(adjacence);

    return 0;
}