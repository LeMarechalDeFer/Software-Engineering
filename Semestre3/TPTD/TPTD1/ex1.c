#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOMBRE_MAX 10
#define TAILLE_TAB 999

int OCCU(int *tab, int x, int taille){
    if(taille == 0){
        return 0;
    }
    if(*tab == x){
        return 1 + OCCU(tab+1, x, taille-1);
    }
    else{
        return OCCU(tab+1, x, taille-1) ;
    }
}


int main(){
    int i ;
    int x = 3 ;
    srand(time(NULL));
    int *tab = (int*)malloc(sizeof(int)*TAILLE_TAB);

    for(i=0; i<TAILLE_TAB; i++){
        tab[i] = rand()%NOMBRE_MAX ;
    }
    // for(i=0; i<TAILLE_TAB; i++){
    //     printf("Numéro %d :%d\n", i+1, tab[i]);
    // }


    printf("Le nombre d'occurence est %d", OCCU(tab, x, TAILLE_TAB));

    free(tab);
}