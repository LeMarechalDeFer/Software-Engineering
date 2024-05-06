//#ifndef __EXERCICE1__H__
#define __EXERCICE1__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct graph {
    int nombre_de_sommet ;
    char** matrice_adjacence;
}graph ;

graph saisiegraphe();
void enregistrement_graph(graph G);
int nbchemin2(graph G);
void affichematrice(graph G);
void nettoyage_memoire(graph G);

//#endif