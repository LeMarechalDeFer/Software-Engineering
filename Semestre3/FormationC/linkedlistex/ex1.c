#include <stdio.h>
#include <stdlib.h>

//Création de la structure d'un noeuds
typedef struct Node {
    int data ;
    Node *nextNode ;
} Node ;

Node* createNodes(int data){
    Node* newNode = (Node*)malloc(sizeof(Node)) ;
    if(newNode == NULL){
        exit(0);
    }
    
    newNode->data = data ;
    newNode->nextNode = NULL ;
    return newNode ;
}

Node* insertAtBeginning(Node** head, int data){
    Node* newNode = createNodes(data) ;
    newNode->nextNode = *head ;

}









