#include <stdio.h>
#include <stdlib.h>
#include "recurcivité.h"

//gcc main.c recurcivité.c -o main -Wall -Werror -g

int main(){

    //printf("%d", factorielle(6));
    //printf("%d", factorielleTerminal(6, 1));
    printf("%d", FibonnaciBis(35));
    return 0;
}