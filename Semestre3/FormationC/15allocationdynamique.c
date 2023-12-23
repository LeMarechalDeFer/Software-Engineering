#include <stdio.h>
#include <stdlib.h>

/*
        sizeof(<type_de_donnée>)                        : retourne la taille en octets d'une donnée

        malloc(<taille_en_octets)                       : allouer dynamiquement une zone mémoire
        calloc(<type_de_donnée>, <taille_en_octets>)    : allouer dynamiquement une zone mémoire initialisé à 0
        realloc(<type_de_donnée>, <nouvelle_taille>)    : réalloue un espace mémoire

        free(<type_de_donnée>)                          : libère la mémoire alloué dynamiquement 
        
*/


// typedef struct Player {
//     char username[25] ;
//     int hp ;
//     int mp ;
// } Player ;


// int main(){
//     int playerNumber = 0 ;
//     Player *playerList = NULL ;
//     int i = 0 ;

//     printf("Combien de joueur ?") ;
//     scanf("%d", &playerNumber) ;

//     //playerList = malloc(sizeof(Player)*playerNumber) ;
//     playerList = calloc(playerNumber, sizeof(Player)) ;

//     if(playerList == NULL)
//     {
//         exit(1);
//     }


//     for(i = 0; i< playerNumber; i++){
//         printf("Joueur %d :\n", i + 1);
//         printf("Nom d'utilisateur : %s\n", playerList[i].username);
//         printf("HP : %d\n", playerList[i].hp);
//         printf("MP : %d\n", playerList[i].mp);
//     }

//     return 0 ;

// }


typedef struct Player {
    char *username ;
    int hp ;
    int mp ;
} Player ;


int main(){
    int playerNumber = 0 ;
    Player *playerList = NULL ;
    int i = 0 ;

    printf("Combien de joueur ?") ;
    scanf("%d", &playerNumber) ;

    //playerList = malloc(sizeof(Player)*playerNumber) ;
    playerList = calloc(playerNumber, sizeof(Player)) ;

    if(playerList == NULL)
    {
        exit(1);
    }

    for (i = 0; i < playerNumber; i++) {
        // Allouer de la mémoire pour username
        playerList[i].username = malloc(25 * sizeof(char));
        if (playerList[i].username == NULL) {
            exit(1); // Gérer l'échec d'allocation ici
        }

        // Lire le nom d'utilisateur, limiter à 24 caractères
        printf("Nom d'utilisateur pour le joueur %d : ", i + 1);
        scanf("%24s", playerList[i].username); // Notez le '%24s'

        // Vous pouvez également ajouter une saisie pour hp et mp ici
    }

    for(i = 0; i< playerNumber; i++){
        printf("Joueur %d :\n", i + 1);
        printf("Nom d'utilisateur : %s\n", playerList[i].username);
        printf("HP : %d\n", playerList[i].hp);
        printf("MP : %d\n", playerList[i].mp);
    }

    printf("\n\n") ;

    //attention realloc demande test supplementaire pour faire attentions au potentielles perte de mémoire
    //admettons on change le nombre de joueur à deux
    playerNumber = 2 ;
    playerList = realloc(playerList, sizeof(Player)*playerNumber) ;

    for(i = 0; i< playerNumber; i++){
        printf("Joueur %d :\n", i + 1);
        printf("Nom d'utilisateur : %s\n", playerList[i].username);
        printf("HP : %d\n", playerList[i].hp);
        printf("MP : %d\n", playerList[i].mp);
    }

    free(playerList) ;

    return 0 ;

}