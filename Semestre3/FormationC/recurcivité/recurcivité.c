#include "recurcivité.h"

unsigned int factorielle(int nb){

    if(nb<0)
    {
        exit(EXIT_FAILURE);
    }
    if(nb == 0 || nb == 1){
        return 1 ;
    }
    return nb *= factorielle(nb-1) ;    
}


unsigned int factorielleTerminal(int nb, int res){

    if(nb<0)
    {
        exit(EXIT_FAILURE);
    }
    if(nb == 0){
        return 1 ;
    }
    if(nb==1){
        return res;
    }
    return factorielleTerminal(nb-1, nb *res);
}

int Fibonnaci(int nb){
    if(nb<0)
    {
        exit(EXIT_FAILURE);
    }
    if(nb<2){
        return 1 ;
    }
    return (Fibonnaci(nb-1)+ Fibonnaci(nb-2));
}

int FibonnaciBis(int nb){

    int i = 1, numb0 = 1, numb1 = 1, tmp;

    while (i<nb)
    {
        tmp = numb0 + numb1;
        numb0 = numb1 ;
        numb1 = tmp ;
        i++;
    }
    

    return (numb1) ;
}