#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool PALINDROME(char *mot, int taille){

    if(taille<=1){
        return true;
    }
    if(mot[0]!=mot[taille-1]){
       return false ; 
    }
    else{
        return PALINDROME(mot+1, taille-2);
    }
}

int main(){
    char *mot = (char*)malloc(sizeof(*mot)*200) ;
    strcpy(mot, "radar");
    int taille = strlen(mot);
    printf("Le mot est : %s, sa taille est %d. Est ce un palindrome : %s", mot, taille, (PALINDROME(mot, taille)) ? "Vrai" : "Faux");

    free(mot);
}