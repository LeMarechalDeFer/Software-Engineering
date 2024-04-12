#ifndef CFC_H
#define CFC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclaration anticipée
typedef struct Noeud Noeud;
typedef Noeud* ListeSuccesseurs;
typedef struct {
    int** matrice; // Matrice d'adjacence
    int taille;    // Nombre de sommets
    ListeSuccesseurs* listes;
} Graphe;

struct Noeud {
    int sommet;
    Noeud* suivant;
};



typedef struct {
    ListeSuccesseurs* listes; // Liste de successeurs pour le graphe réduit
    int taille;               // Nombre de sommets dans le graphe réduit
} GrapheReduit;

// Prototypes des fonctions
Graphe* lireGraphe(char* nomFichier);
ListeSuccesseurs* matriceToListe(Graphe* graphe);
void explorerProfondeur(ListeSuccesseurs* liste, int taille);
void afficherOrdreSuffixe(ListeSuccesseurs* liste, int taille);
ListeSuccesseurs* inverserGraphe(ListeSuccesseurs* liste, int taille);
void determinerComposantesFortementConnexes(ListeSuccesseurs* liste, int taille, int* nombreComposantes);
GrapheReduit* construireGrapheReduit(ListeSuccesseurs* liste, int taille, int* composanteDe, int nombreComposantes);
int estAcceptable(GrapheReduit* graphe);
int detecterCycleDFS(ListeSuccesseurs* liste, int sommet, int* visite, int* pile);

#endif // CFC_H