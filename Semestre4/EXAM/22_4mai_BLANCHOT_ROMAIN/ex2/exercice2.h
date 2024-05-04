#ifndef __EXERCICE2__H__
#define __EXERCICE2__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


    /* Définition d'un Noeud (sommet) */
    typedef struct NodeListElement
    {
        int value;
        struct NodeListElement *next;
    }NodeListElement, *NodeList;
 
    /* Définition d'une liste d'adjacence */
    typedef struct AdjencyListElement
    {
        NodeListElement *begin;
    }AdjencyListElement, *AdjencyList;

    /* Définition d'un Graphe */
    typedef struct GraphElement
    {
        bool is_oriented;
        int nb_vertices;
        AdjencyList tab_neighbours;
    }GraphElement, *Graph;

#endif
