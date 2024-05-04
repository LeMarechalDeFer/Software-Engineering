#include "cfc.h"

Graphe* lireGraphe(char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    int nombreSommets;
    fscanf(fichier, "%d", &nombreSommets);

    Graphe* graphe = (Graphe*)malloc(sizeof(Graphe));
    graphe->taille = nombreSommets;
    graphe->matrice = (int**)malloc(nombreSommets * sizeof(int*));
    for (int i = 0; i < nombreSommets; i++) {
        graphe->matrice[i] = (int*)calloc(nombreSommets, sizeof(int));
    }

    int i, j;
    while (fscanf(fichier, "%d %d", &i, &j) != EOF) {
        graphe->matrice[i][j] = 1;
    }

    fclose(fichier);
    return graphe;
}

void DFS(ListeSuccesseurs* liste, int sommet, int* visite) {
    visite[sommet] = 1; // Marquer le sommet comme visité
    printf("%d ", sommet); // Afficher le sommet visité (facultatif)

    Noeud* courant = liste[sommet];
    while (courant != NULL) {
        if (!visite[courant->sommet]) {
            DFS(liste, courant->sommet, visite);
        }
        courant = courant->suivant;
    }
}

ListeSuccesseurs* matriceToListe(Graphe* graphe) {
    ListeSuccesseurs* liste = (ListeSuccesseurs*)malloc(graphe->taille * sizeof(Noeud*));
    for (int i = 0; i < graphe->taille; i++) {
        liste[i] = NULL;
        for (int j = 0; j < graphe->taille; j++) {
            if (graphe->matrice[i][j] == 1) {
                Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
                nouveauNoeud->sommet = j;
                nouveauNoeud->suivant = liste[i];
                liste[i] = nouveauNoeud;
            }
        }
    }
    return liste;
}

void explorerProfondeur(ListeSuccesseurs* liste, int taille) {
    int* visite = (int*)calloc(taille, sizeof(int));
    for (int i = 0; i < taille; i++) {
        if (!visite[i]) {
            DFS(liste, i, visite);
        }
    }
    free(visite);
}

void DFS_ordreSuffixe(ListeSuccesseurs* liste, int sommet, int* visite, int* ordreSuffixe, int* index) {
    visite[sommet] = 1;
    for (Noeud* n = liste[sommet]; n != NULL; n = n->suivant) {
        if (!visite[n->sommet]) {
            DFS_ordreSuffixe(liste, n->sommet, visite, ordreSuffixe, index);
        }
    }
    ordreSuffixe[(*index)++] = sommet;
}

void afficherOrdreSuffixe(ListeSuccesseurs* liste, int taille) {
    int* visite = (int*)calloc(taille, sizeof(int));
    int* ordreSuffixe = (int*)malloc(taille * sizeof(int));
    int index = 0;

    for (int i = 0; i < taille; i++) {
        if (!visite[i]) {
            DFS_ordreSuffixe(liste, i, visite, ordreSuffixe, &index);
        }
    }

    for (int i = taille - 1; i >= 0; i--) {
        printf("%d ", ordreSuffixe[i]);
    }

    free(visite);
    free(ordreSuffixe);
}

ListeSuccesseurs* inverserGraphe(ListeSuccesseurs* liste, int taille) {
    ListeSuccesseurs* listeInverse = (ListeSuccesseurs*)malloc(taille * sizeof(Noeud*));
    for (int i = 0; i < taille; i++) {
        listeInverse[i] = NULL;
        Noeud* courant = liste[i];
        while (courant != NULL) {
            Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
            nouveauNoeud->sommet = i;
            nouveauNoeud->suivant = listeInverse[courant->sommet];
            listeInverse[courant->sommet] = nouveauNoeud;
            courant = courant->suivant;
        }
    }
    return listeInverse;
}

// Supposant l'existence d'une version modifiée de DFS qui marque les composantes
void DFS_composantes(ListeSuccesseurs* listeInverse, int sommet, int* visite, int composanteActuelle) {
    visite[sommet] = 1;
    for (Noeud* n = listeInverse[sommet]; n != NULL; n = n->suivant) {
        if (!visite[n->sommet]) {
            DFS_composantes(listeInverse, n->sommet, visite, composanteActuelle);
        }
    }
}

void determinerComposantesFortementConnexes(ListeSuccesseurs* liste, int taille, int* nombreComposantes) {
    int* visite = (int*)calloc(taille, sizeof(int));
    int* ordreSuffixe = (int*)malloc(taille * sizeof(int));
    int index = 0;
    *nombreComposantes = 0;
    
    for (int i = 0; i < taille; i++) {
        if (!visite[i]) {
            DFS_ordreSuffixe(liste, i, visite, ordreSuffixe, &index);
        }
    }

    ListeSuccesseurs* listeInverse = inverserGraphe(liste, taille);
    memset(visite, 0, taille * sizeof(int));

    for (int i = taille - 1; i >= 0; i--) {
        int sommet = ordreSuffixe[i];
        if (!visite[sommet]) {
            DFS_composantes(listeInverse, sommet, visite, *nombreComposantes);
            (*nombreComposantes)++;
        }
    }

    free(visite);
    free(ordreSuffixe);
}

GrapheReduit* construireGrapheReduit(ListeSuccesseurs* liste, int taille, int* composanteDe, int nombreComposantes) {
    GrapheReduit* grapheReduit = malloc(sizeof(GrapheReduit));
    grapheReduit->taille = nombreComposantes;
    grapheReduit->listes = calloc(nombreComposantes, sizeof(Noeud*));

    for (int i = 0; i < taille; i++) {
        int compOrigine = composanteDe[i];
        Noeud* courant = liste[i];
        while (courant) {
            int compDestination = composanteDe[courant->sommet];
            if (compOrigine != compDestination) {
                Noeud* tmp = grapheReduit->listes[compOrigine];
                int trouve = 0;
                while (tmp) {
                    if (tmp->sommet == compDestination) {
                        trouve = 1;
                        break;
                    }
                    tmp = tmp->suivant;
                }
                if (!trouve) {
                    Noeud* nouveauNoeud = malloc(sizeof(Noeud));
                    nouveauNoeud->sommet = compDestination;
                    nouveauNoeud->suivant = grapheReduit->listes[compOrigine];
                    grapheReduit->listes[compOrigine] = nouveauNoeud;
                }
            }
            courant = courant->suivant;
        }
    }

    return grapheReduit;
}

int estAcceptable(GrapheReduit* graphe) {
    int* visite = calloc(graphe->taille, sizeof(int));
    int* pile = calloc(graphe->taille, sizeof(int));

    for (int i = 0; i < graphe->taille; i++) {
        if (!visite[i]) {
            if (detecterCycleDFS(graphe->listes, i, visite, pile)) {
                free(visite);
                free(pile);
                return 0; // Non acceptable si un cycle est détecté
            }
        }
    }

    free(visite);
    free(pile);
    return 1; // Acceptable si aucun cycle n'est détecté
}

int detecterCycleDFS(ListeSuccesseurs* liste, int sommet, int* visite, int* pile) {
    if (visite[sommet] == 0) {
        visite[sommet] = 1; // Marquer comme visité
        pile[sommet] = 1; // Marquer comme en exploration

        Noeud* courant = liste[sommet];
        while (courant != NULL) {
            if (visite[courant->sommet] == 0 && detecterCycleDFS(liste, courant->sommet, visite, pile)) {
                return 1; // Cycle détecté
            } else if (pile[courant->sommet] == 1) {
                return 1; // Retour sur un sommet en exploration
            }
            courant = courant->suivant;
        }
    }
    pile[sommet] = 0; // Fin de l'exploration de ce sommet
    return 0; // Aucun cycle détecté à partir de ce sommet
}
