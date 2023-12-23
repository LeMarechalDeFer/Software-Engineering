#include <stdio.h>
#include <stdlib.h>

#define TVA 20
#define Coucou printf("Coucou!\n")
#define AIRE (LONGUEUR * LARGEUR)

#ifndef __BIBLI_H__ 
#define __BIBLI_H__

//habitude a prendre lors de la creation d'un fichier.h
//define remplace au moment du processeur, la constante par le morceau de code

/*
    Constante prédéfinie du langage C :

        __FILE__ (nom du fichier)
        __LINE__ (ligne du fichier)
        __DATE__ (date de compilation)
        __TIME__ (heure de compilation)

*/

int main(){

    int prixHT = 15 ;
    int prixTTC = 0 ;

    prixTTC = prixHT + (prixHT * TVA /100);
    return 0 ;    
}

//habitude a prendre lors de la creation d'un fichier.h
#endif