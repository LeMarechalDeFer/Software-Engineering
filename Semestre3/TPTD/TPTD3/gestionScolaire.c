#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEVES 2000

typedef struct Eleve{
    char nom[20] ;
    char prenom[20] ;
    double moyenne_generale ;
} Eleve ;

void lireGestionScolaire(Eleve *T, int *nb_eleve) ;
void afficher(Eleve *T, int *nb_eleves);
void ajouter(Eleve *T, int *nb) ; 
int rechercher(Eleve *T, int *nb_eleves, int i, char nm[20]) ; 
void supprimer(Eleve *T, int *nb_eleves, double moy);

void ajouter(Eleve *T, int *nb_eleves){
    printf("Entrez le prénom :\n");
    scanf("%s", T[*nb_eleves].nom) ;
    printf("Entrez le nom :\n");
    scanf("%s", T[*nb_eleves].prenom);
    printf("Entrez la moyenne :\n");
    scanf("%lf", &T[*nb_eleves].moyenne_generale);
    *nb_eleves += 1; 

}

void lireGestionScolaire(Eleve *T, int *nb_eleve){
    int i = 0;
    FILE *fil = fopen("listeEleves.txt", "r+") ;
    if(fil == NULL)
    {
        perror("Impossible d'ouvrir le fichier") ;
        exit(EXIT_FAILURE);
    }
    fscanf(fil, "%d", nb_eleve);
    for(i=0; i<*nb_eleve; i++){
        fscanf(fil, "%20s %20s %lf", T[i].nom, T[i].prenom, &T[i].moyenne_generale);
    }
    fclose(fil);
}

void afficher(Eleve *T, int *nbeleves){
    int i;
    for(i=0; i<*nbeleves; i++){
        printf("Nom : %s\n", T[i].nom);
        printf("Prénom : %s\n", T[i].prenom);
        printf("Moyenne générale : %lf\n\n", T[i].moyenne_generale);
    }
}

int rechercher(Eleve *T, int *nb_eleves, int i, char nm[20]) {
    if(i>=*nb_eleves){
        return 0;
    }
    if(strcmp(T[i].nom, nm)==0){
        return 1;
    }
    else{
        return rechercher(T, nb_eleves, i+1, nm);
    }
}

void supprimer(Eleve *T, int *nb_eleves, double moy){
    int i = 0;
    while (i < *nb_eleves) {
        if (T[i].moyenne_generale == moy) {
            // Décalage des éléments vers la gauche pour combler l'espace
            for (int j = i; j < *nb_eleves - 1; j++) {
                T[j] = T[j + 1];
            }
            *nb_eleves -= 1; // Réduire la taille du tableau
            // Ne pas incrémenter i car le nouvel élément à l'index i n'a pas encore été vérifié
        } else {
            // Incrémenter i seulement si aucun élève n'est supprimé à cet index
            i++;
        }
    }
}


int main(){
    
    Eleve *tab = (Eleve*)malloc(sizeof(Eleve)*MAX_ELEVES) ;
    int *nb_eleves = (int*)malloc(sizeof(int));
    if(tab == NULL || nb_eleves ==NULL){
        perror("Impossible d'allouer la mémoire");
        exit(EXIT_FAILURE);
    }

    lireGestionScolaire(tab, nb_eleves);
    afficher(tab, nb_eleves);
    printf("Le nombre d'élève est : %d\n", *nb_eleves); 

    int choix = 0;
    
    do{
        printf("\nMenue\n");
        printf("0. Quitter le programme\n");
        printf("1. Afficher les élèves\n");
        printf("2. Ajouter un élève\n");
        printf("3. Rechercher un élève\n");
        printf("4. Supprimer des élèves\n");
        printf("Votre choix :\n");
        scanf("%d", &choix);
        switch (choix){
            case 1:
                afficher(tab, nb_eleves);
                break;
            case 2:
                ajouter(tab, nb_eleves);
                break;
            case 3:
                char nm[20] ;
                printf("Entrez un nom :\n");
                scanf("%s", nm);
                printf("Le prénom a été trouvé : %d", rechercher(tab, nb_eleves, 0, nm));
                break;
            case 4:
                double moyenne_generale ;
                printf("Entrez la moyenne à supprimer :\n");
                scanf("%lf", &moyenne_generale);
                supprimer(tab, nb_eleves, moyenne_generale);
                break;
            default:
               break;
        }
    }while(choix !=0);


    free(tab) ;
    free(nb_eleves);
    
}