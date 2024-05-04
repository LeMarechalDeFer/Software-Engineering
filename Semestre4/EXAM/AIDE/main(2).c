#include "cfc.h"

int main() {

    printf("Traitement du fichier TD.txt (graphe orienté):\n");

    // Étape 1: Lecture du graphe et création de la structure de données appropriée
    Graphe* grapheTD = lireGraphe("TD.txt");
    if (!grapheTD) {
        printf("Erreur lors de la lecture du fichier TD.txt\n");
        return 1;
    }

    // Étape 2: Identifier les composantes fortement connexes
    int* composanteDe = NULL;
    int nombreComposantes;
    determinerComposantesFortementConnexes(grapheTD->listes, grapheTD->taille, &nombreComposantes);
    
    // Étape 3: Construire le graphe réduit
    GrapheReduit* grapheReduitTD = construireGrapheReduit(grapheTD->listes, grapheTD->taille, composanteDe, nombreComposantes);
    
    // Étape 4: Vérifier l'acceptabilité du plan de sens uniques
    if (estAcceptable(grapheReduitTD)) {
        printf("Le plan de sens uniques est acceptable pour TD.txt.\n");
    } else {
        printf("Le plan de sens uniques n'est pas acceptable pour TD.txt.\n");
    }
    
    return 0;
}
