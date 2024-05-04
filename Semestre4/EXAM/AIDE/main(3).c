#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* ordre_suffixe;
int index_suffixe = 0;
int* composanteId;
int idCFC = 0;

// Structure pour représenter un graphe
typedef struct {
    int nb_sommets;    // Nombre de sommets
    int **adj;         // Matrice d'adjacence
} Graphe;

typedef struct noeud {
    int sommet;
    struct noeud* suivant;
} Noeud;

typedef struct {
    int nb_sommets;
    Noeud** listes; // successeurs
} ListeSucc;

ListeSucc* inverser_graphe(ListeSucc* g);
    
Graphe* init_graphe(int nb_sommets) {
    Graphe* g = (Graphe*)malloc(sizeof(Graphe));
    g->nb_sommets = nb_sommets;
    g->adj = (int**)malloc(nb_sommets * sizeof(int*));
    for(int i = 0; i < nb_sommets; i++) {
        g->adj[i] = (int*)calloc(nb_sommets, sizeof(int)); // Initialise à 0
    }
    return g;
}

Graphe* lire_TD(char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }else {
    printf("Fichier %s ouvert avec succès.\n", nom_fichier);
    }
    
    int nb_sommets;
    fscanf(fichier, "%d", &nb_sommets);
    Graphe* g = init_graphe(nb_sommets);
    
    int u, v;
    while (fscanf(fichier, "%d %d", &u, &v) != EOF) {
        g->adj[u-1][v-1] = 1; // Arc de u à v changer pour le fichier Pennsylvanie car le début est a 0 et non a 1
        printf("Ajout de l'arc %d -> %d\n", u, v);
    }
    
    fclose(fichier);
    return g;
}

Graphe* lire_Penn(char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }else {
    printf("Fichier %s ouvert avec succès.\n", nom_fichier);
    }
    
    int nb_sommets;
    fscanf(fichier, "%d", &nb_sommets);
    Graphe* g = init_graphe(nb_sommets);
    
    int u, v;
    while (fscanf(fichier, "%d %d", &u, &v) != EOF) {
        g->adj[u][v] = 1; // Arc de u à v changer pour le fichier Pennsylvanie car le début est a 0 et non a 1
        printf("Ajout de l'arc %d -> %d\n", u, v);
    }
    
    fclose(fichier);
    return g;
}

void ajouter_arc(Noeud** liste, int sommet) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->sommet = sommet;
    nouveau->suivant = *liste;
    *liste = nouveau;
}

ListeSucc* matrice_vers_liste(Graphe* g) {
    ListeSucc* ls = (ListeSucc*)malloc(sizeof(ListeSucc));
    ls->nb_sommets = g->nb_sommets;
    ls->listes = (Noeud**)malloc(g->nb_sommets * sizeof(Noeud*));
    
    for(int i = 0; i < g->nb_sommets; i++) {
        ls->listes[i] = NULL;
        for(int j = 0; j < g->nb_sommets; j++) {
            if (g->adj[i][j] == 1) {
                printf("Ajout de l'arc %d -> %d\n", i, j);
                ajouter_arc(&(ls->listes[i]), j);
            }
        }
    }
    return ls;
}

void dfs(ListeSucc* g, int sommet, int visite[]) {
    visite[sommet] = 1; // Marque le sommet comme visité
    printf("%d ", sommet + 1); // Affiche le sommet visité

    Noeud* temp = g->listes[sommet];
    while(temp != NULL) {
        if(!visite[temp->sommet]) {
            dfs(g, temp->sommet, visite);
        }
        temp = temp->suivant;
    }
    ordre_suffixe[index_suffixe++] = sommet + 1;
}

ListeSucc* inverser_graphe(ListeSucc* g) {
    ListeSucc* g_inverse = (ListeSucc*)malloc(sizeof(ListeSucc));
    g_inverse->nb_sommets = g->nb_sommets;
    g_inverse->listes = (Noeud**)malloc(g->nb_sommets * sizeof(Noeud*));
    
    for (int i = 0; i < g->nb_sommets; i++) {
        g_inverse->listes[i] = NULL;
    }
    
    for (int i = 0; i < g->nb_sommets; i++) {
        Noeud* temp = g->listes[i];
        while (temp != NULL) {
            ajouter_arc(&(g_inverse->listes[temp->sommet]), i);
            temp = temp->suivant;
        }
    }
    
    return g_inverse;
}

void dfs_composante(ListeSucc* g, int sommet, int* visite, int idCFC) {
    visite[sommet] = 1;
    composanteId[sommet] = idCFC; // Marquer le sommet avec l'ID de la Compo fort connexe

    Noeud* temp = g->listes[sommet];
    while(temp != NULL) {
        if(!visite[temp->sommet]) {
            dfs_composante(g, temp->sommet, visite, idCFC);
        }
        temp = temp->suivant;
    }
}


int main() {
    Graphe* g = lire_TD("TD.txt");
    if (g == NULL) {
        printf("Erreur lors de la lecture du fichier.\n");
        return 1;
    }

    ListeSucc* ls = matrice_vers_liste(g);

    // Initialise tab de visite pour le parcours prof
    int* visite = (int*)calloc(ls->nb_sommets, sizeof(int));
    ordre_suffixe = (int*)malloc(ls->nb_sommets * sizeof(int));
    
    // Lancer le parcours en prof à partir du sommet 0 
    printf("\nParcours DFS du graphe :\n");
    dfs(ls, 0, visite); // modif si 1 est un sommet du graph
    printf("\n");
    
    printf("\nOrdre suffixe du parcours DFS :\n");
    for(int i = 0; i < ls->nb_sommets; i++) {
        printf("%d ", ordre_suffixe[i]);
    }
    printf("\n");
    
    ListeSucc* g_inverse = inverser_graphe(ls);
    // reset tab de visite 2e explo prof
    memset(visite, 0, ls->nb_sommets * sizeof(int));

    printf("\nComposantes fortement connexes :\n");
    for (int i = ls->nb_sommets - 1; i >= 0; i--) {
    int sommet = ordre_suffixe[i] - 1; // modif
        if (!visite[sommet]) {
            dfs(g_inverse, sommet, visite);
            printf("\n"); 
        }
    }

    for(int i = index_suffixe - 1; i >= 0; i--) {
        int sommet = ordre_suffixe[i] - 1; // modif
        if (!visite[sommet]) {
            dfs_composante(g_inverse, sommet, visite, idCFC++);
        }
    }

// PAs fini
    Graphe* grapheReduit = init_graphe(idCFC); 
    for(int i = 0; i < ls->nb_sommets; i++) {
        for(Noeud* temp = ls->listes[i]; temp; temp = temp->suivant) {
            int u = composanteId[i];
            int v = composanteId[temp->sommet];
            if(u != v) {
                grapheReduit->adj[u][v] = 1; 
            }
        }
    }

    // Affichage du graphe réduit...
    printf("\nGraphe réduit :\n");
    for(int i = 0; i < idCFC; i++) {
        for(int j = 0; j < idCFC; j++) {
            printf("%d ", grapheReduit->adj[i][j]);
        }
        printf("\n");
    }
    
    // Libération de la mémoire allouée pour la matrice d'adjacence
    for (int i = 0; i < g->nb_sommets; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);

    // Libération de la mémoire allouée pour la liste de successeurs
    for (int i = 0; i < ls->nb_sommets; i++) {
        Noeud* actuel = ls->listes[i];
        while (actuel != NULL) {
            Noeud* aSupprimer = actuel;
            actuel = actuel->suivant;
            free(aSupprimer);
        }
    }
    free(ls->listes);
    free(ls);

    // Libération du tableau visite
    free(visite);

    return 0;
}