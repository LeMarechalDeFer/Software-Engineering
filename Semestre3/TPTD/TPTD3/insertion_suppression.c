#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 5
/*
Objectif inserer et supprimer un élément dans les differentes structures:
- tableau statique / dynamique
- liste chainées
-
*/

void affichierTableau(int *tabStatique, int *tabDynamique, int taille){
    int i ;
    printf("Le tableau statique : \n");

    for(i=0; i<TAILLE_MAX; i++){
        printf("Le numéro %d : %d\n", i+1, tabStatique[i]);
    }
    printf("Le tableau dynamique : \n");

    for(i=0; i<taille; i++){
        printf("Le numéro %d : %d\n", i+1, tabDynamique[i]);
    }
}




void inserer1Element(int **tabDynamique, int *taille, int position, int element) {
    *taille += 1;
    int *temp = realloc(*tabDynamique, sizeof(int) * (*taille));
    if (!temp) {
        free(*tabDynamique);
        perror("Réallocation échouée");
        exit(EXIT_FAILURE);
    }
    *tabDynamique = temp;

    for (int i = *taille - 1; i > position; i--) {
        (*tabDynamique)[i] = (*tabDynamique)[i - 1];
    }
    (*tabDynamique)[position] = element;
}


// SI JE DEFINIE TAB MAX
// void inserer1Element(int *tabDynamique, int *taille, int maxTaille, int position, int element) {
//     if (*taille >= maxTaille) {
//         printf("Insertion impossible : tableau plein.\n");
//         return;
//     }

//     // Décalage des éléments pour créer de l'espace pour le nouvel élément
//     for (int i = *taille; i > position; i--) {
//         tabDynamique[i] = tabDynamique[i - 1];
//     }

//     // Insérer le nouvel élément
//     tabDynamique[position] = element;
//     *taille += 1;
// }


void supprimer1Element(int **tabDynamique, int *taille, int position) {
    if (position < 0 || position >= *taille) {
        printf("Position invalide.\n");
        return;
    }

    // Décalage des éléments pour combler l'espace laissé par l'élément supprimé
    for (int i = position; i < *taille - 1; i++) {
        (*tabDynamique)[i] = (*tabDynamique)[i + 1];
    }

    // Mise à jour de la taille
    *taille -= 1;

    // Réduire la taille du tableau alloué
    int *temp = realloc(*tabDynamique, (*taille) * sizeof(int));
    if (temp == NULL && *taille > 0) {
        // Si realloc échoue et la nouvelle taille n'est pas 0
        perror("Reallocation échouée");
        // Note: tabDynamique est toujours valide et pointe vers l'ancienne mémoire
    } else {
        // Si realloc réussit ou si la nouvelle taille est 0
        *tabDynamique = temp;
    }
}



int main(){
    int taille =5 ;
    int tabStatique[TAILLE_MAX] = {1, 2, 3, 4} ;
    int *tabDynamique = (int*)malloc(sizeof(int)*taille);
    
    if(tabDynamique ==NULL){
        perror("Problème d'initialisation tableau\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < taille; i++) {
        tabDynamique[i] = i + 1; 
    }

    affichierTableau(tabStatique, tabDynamique, taille);

    inserer1Element(&tabDynamique, &taille, 3, 6);
    affichierTableau(tabStatique, tabDynamique, taille);      
    supprimer1Element(&tabDynamique, &taille, 3);
    affichierTableau(tabStatique, tabDynamique, taille); 


    free(tabDynamique);
}


//SI ON DONNE TAILLE MAX et que l'on modifie :
// #define TAILLE_MAX 5

// void ajouterElement(int tab[], int *tailleCourante, int element) {
//     if (*tailleCourante < TAILLE_MAX) {
//         tab[*tailleCourante] = element;
//         *tailleCourante += 1;
//     } else {
//         printf("Tableau plein. Impossible d'ajouter l'élément.\n");
//     }
// }

// void supprimerElement(int tab[], int *tailleCourante, int position) {
//     if (position < 0 || position >= *tailleCourante) {
//         printf("Position invalide.\n");
//     } else {
//         for (int i = position; i < *tailleCourante - 1; i++) {
//             tab[i] = tab[i + 1];
//         }
//         *tailleCourante -= 1;
//     }
// }
