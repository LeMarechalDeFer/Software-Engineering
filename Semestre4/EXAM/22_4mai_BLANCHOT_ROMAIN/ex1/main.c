#include "exercice1.h"



int main(){
    graph G ;
    G = saisiegraphe();
    int x ;
    x= nbchemin2(G) ;
    printf("Le nombre de chemain de deux est : %d\n", x);
    affichematrice(G);
    enregistrement_graph(G);
    nettoyage_memoire(G);
    return 0;
}


