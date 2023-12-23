#ifndef __LIST__H__
#define __LIST__H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Définir la liste
typedef struct ListElement{
    int value ;
    struct ListElement *next ;

}ListElement, *List ;


// Protype
List new_list(void);
bool is_empty_list(List li);
int list_length(List li);
void print_list(List li);
List push_back_list(List li, int x);
List push_front_list(List li, int x);
List pop_back_list(List li);
List pop_front_list(List li);
List clear_list(List li) ;


#endif