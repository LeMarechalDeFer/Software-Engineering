
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


List new_list(void){

    return NULL;
}

bool is_empty_list(List li){

    if(li == NULL){
        return(true);
    }
    else{
        return(false);
    }
}

int list_length(List li){
    int length = 0;

    if(!is_empty_list(li)){
        while(li != NULL){
            length += 1;
            li = li->next ;
        }
    }
    return length ;
}

void print_list(List li){
    if(is_empty_list(li)){
        printf("La liste est vide\n");
    }
    else{
        while(li != NULL){
            printf("[%d]", li->value);
            li = li->next ; 
        }
        printf("\n");
    }
} 

List push_back_list(List li, int x){
    List element = malloc(sizeof(ListElement));
    if(element == NULL){
        perror("Erreur aloocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    element->value = x ;
    element->next = NULL ;

    if(is_empty_list(li)){
        return element ;
    }
    else{   
        List temp = li ;
        if(temp == NULL){
        perror("Erreur aloocation mémoire\n");
        exit(EXIT_FAILURE);
    }
        while(temp->next !=NULL){
            temp = temp->next ;
        }
        temp->next = element;
    }
    return li;
}

List push_front_list(List li, int x){
    List element = malloc(sizeof(ListElement));
    if(element == NULL){
        perror("Erreur aloocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    element->value = x ;
    if(is_empty_list(li)){
        element->next = NULL ;
    }
    else{
        element->next = li ;
    }
    return element ;
}

List pop_front_list(List li){

 
    List element = malloc(sizeof(ListElement));
    if(element == NULL){
        perror("Erreur aloocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    if(is_empty_list(li)){
        return new_list();
    }

    element = li->next ; 
    free(li);
    li = NULL;
    return element ;


}

List pop_back_list(List li){

    if(is_empty_list(li)){
        return new_list();
    }
    else if(li->next == NULL){
        free(li);
        li = NULL ;
        return new_list();
    }
    else{
        List temp = li;
        if(temp == NULL){
            perror("Erreur aloocation mémoire\n");
            exit(EXIT_FAILURE);
        }
        List before = li ;
        while(temp->next != NULL){
            before = temp ; 
            temp = temp->next ;
        }
        before->next = NULL ;
        free(temp);
        temp = NULL;
    }

    return li;
}

List clear_list(List li){
    if(is_empty_list(li)){
        return new_list() ;
    }
    else{
        while(li != NULL){
            li = pop_front_list(li);
        }
        return li;
    }
}

int main(){
    List my_list = new_list();
    print_list(my_list);
    my_list = push_front_list(my_list, 5);
    my_list = push_back_list(my_list, 6);
    print_list(my_list);
    //my_list = pop_back_list(my_list);
    //my_list = pop_front_list(my_list);
    my_list = clear_list(my_list);
    print_list(my_list);

    
}

