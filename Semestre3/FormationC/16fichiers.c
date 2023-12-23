#include <stdio.h>
#include <stdlib.h>

/* fopen(<fichier>, <mode_ouverture>) : r (lecture seule, doit exister)
                                        w (écriture seule)
                                        a (ajout fin fichier)
                                        r+ (lecture/ecriture, doit exister)
                                        w+ (lecture/écriture, supprime contenue existant)
                                        a+ (ajout lecture/écriture, de fichier)
    fclose(<fichier>) : fermer un fichier ouvert                                  
    feof(<fichier>) : tester la fin d'un fichier (mais d'abord tester avec la lecture d'un caractère fgetc()) (ne devient vrai qu'apres echec tentative de lecture )

    [LECTURE]
    fgetc(<fichier>)                                : lire un caractère
    fgets(<chaine>, <taille_chaine>, <fichier>)     : lire une ligne
    fscanf(<fichier>,<format>, ....)                : lire du texte formaté (%d %s ect)

    [ECRITURE]
    fputc(<fichier>)                                : écrit un caractère
    fputs(<chaine>, <fichier>)                      : écrit une ligne de texte
    fprintf(<fichier>, <format>, <valeurs associé>) : écrit du texte formaté

    [POSITION]
    ftell(<fichier>)                                : retourne la position du pointeur
    fseek(<fichier>, <deplacement>, <origine>)      : déplace le curseur
            -> <origine> :  SEEK_SET (début du fichier)
                            SEEK_CUR (position courante)
                            SEEK_END (fin du fichier)  

    [DIVERS]
    rename(<ancien_nom>, <nouveau_nom>)             : renommer un fichier (il ne doit pas être ouvert)
    remove(<fichier>)                               : supprimer un fichier (sans passer par la corbeille)


    [A VOIR]
    fread
    fwrite
                                        
*/

int main(){

    FILE *fic = fopen("test.txt", "r") ;
    int lettre = 0 ;


    if(fic == NULL){
        perror("Erreur chargement fichier");
        return 1;
    }

    // //Lire un caractère
    // lettre= fgetc(fic) ; 
    // printf("%c\n", lettre) ;


    // //Lire tout un fichier avec while
    // while (1)
    // {
    //     lettre = fgetc(fic) ;
    //     if(feof(fic)){
    //         break;
    //     }
    //     printf("%c", lettre) ;

    // }

    // while((lettre = fgetc(fic)) != EOF)
    // {
    //     printf("%c", lettre) ;
    // }
    
    // //Lire une ligne 

    // signed char texte[256] ;

    // fgets(texte, 255, fic) ;
    // printf("%s", texte) ;

    // while (fgets(texte, 255, fic) != NULL)
    // {
    //     printf("%s", texte) ;
    // }
    
    // //Lire un fichier formater 
    // signed char texte[256] ;
    // int age = 0;
    // int nombre_abonné  = 0;

    // fscanf(fic, "%s" "%d" "%d", texte, &age, &nombre_abonné);

    // printf("Nom : %s, ", texte) ;
    // printf("Age : %d, ", age) ;
    // printf("Abonnés : %d\n", nombre_abonné) ;

    // fscanf(fic, "%s" "%d" "%d", texte, &age, &nombre_abonné);

    // printf("Nom : %s, ", texte) ;
    // printf("Age : %d, ", age) ;
    // printf("Abonnés : %d\n", nombre_abonné) ;

    int position_curseur = -1;

    printf("Position : %d\n", ftell(fic)) ;
    
    fseek(fic, 5, SEEK_SET) ;
    printf("Position : %d\n", ftell(fic)) ;
    
    rewind(fic) ;
    printf("Position : %d\n", ftell(fic)) ;
    


    fclose(fic) ;
}