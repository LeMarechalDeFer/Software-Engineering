#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int NBM(char *phrase, int taille){
    if(taille == 0){
        return 0;
    }
    if(*phrase >= 'A' && *phrase <='Z'){
        return 1 + NBM(phrase+1, taille-1) ;
    }
    else{
        return NBM(phrase+1, taille-1);
    }
}


int main(){
    char *phrase = (char*)malloc(sizeof(*phrase)*200) ;
    strcpy(phrase, "Qu'est ce qui est jaune et qui attend ? Jonathan");
    int taille = strlen(phrase) ;
    printf("La phrase est : %s\n", phrase);
    printf("Le nombre de majuscule est %d", NBM(phrase, taille));

    free(phrase);

}