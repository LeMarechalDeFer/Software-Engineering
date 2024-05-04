#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


Graph new_graph(int vertices, Bool is_oriented)
{
    GraphElement *element;

    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation Graphe.\n");
        exit(EXIT_FAILURE);
    }

    element->is_oriented = is_oriented;
    element->nb_vertices = vertices;

    element->tab_neighbours = malloc(vertices * sizeof(AdjencyListElement));

    if(element->tab_neighbours == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation Graphe.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 1 ; i < element->nb_vertices + 1 ; i++)
        element->tab_neighbours[i-1].begin = NULL;

    return element;
}

/*----------------------------------------------------------------------------*/

Bool is_empty_graph(Graph g)
{
    if(g == NULL)
        return true;

    return false;
}

/*----------------------------------------------------------------------------*/

NodeList add_node(int x)
{
    NodeList n = malloc(sizeof(NodeListElement));

    if(n == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation Node.\n");
        exit(EXIT_FAILURE);
    }

    n->value = x;
    n->next = NULL;

    return n;
}

/*----------------------------------------------------------------------------*/

void add_edge(Graph g, int src, int dest)
{
    NodeList n = add_node(dest);
    n->next = g->tab_neighbours[src-1].begin;
    g->tab_neighbours[src-1].begin = n;

    if(!g->is_oriented)
    {
        n = add_node(src);
        n->next = g->tab_neighbours[dest-1].begin;
        g->tab_neighbours[dest-1].begin = n;
    }
}

/*----------------------------------------------------------------------------*/

void print_graph(Graph g)
{
    // if(g->nb_vertices == 0)
    // {
    //     fprintf(stderr, "Rien a effacer, le Graphe n'existe pas.\n");
    //     return;
    // }

    for(int i = 1 ; i < g->nb_vertices + 1 ; i++)
    {
        NodeList n = g->tab_neighbours[i-1].begin;
        printf("(%d) : ", i);

        while(n != NULL)
        {
            printf("%d, ", n->value);
            n = n->next;
        }

        printf("NULL\n");
    }
}

/*----------------------------------------------------------------------------*/

void erase_graph(Graph g)
{
    if(is_empty_graph(g))
    {
        fprintf(stderr, "Rien a effacer, le Graphe n'existe pas.\n");
        return;
    }

    //Si sommets adjacents
    if(g->tab_neighbours)
    {
        for(int i = 1 ; i < g->nb_vertices + 1 ; i++)
        {
            NodeList n = g->tab_neighbours[i-1].begin;

            while(n != NULL)
            {
                NodeList tmp = n;
                n = n->next;
                free(tmp);
            }
        }

        //Libération de la liste d'adjacence
        free(g->tab_neighbours);
    }

    //Libération du Graphe
    free(g);
}