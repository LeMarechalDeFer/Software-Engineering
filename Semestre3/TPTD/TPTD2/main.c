#include "planete.h"


int main() {
    Planete tab[MAX_PLANETES];
    int nbPlanetes;
    int choix;
    char nomPlanete[26];

    // Lecture des données des planètes depuis un fichier
    nbPlanetes = readPlanetData(tab, MAX_PLANETES);

    // Permettre à l'utilisateur de saisir des planètes
    inputPlanet(tab, &nbPlanetes);

    displayPlanet(tab, nbPlanetes);

    // Boucle du menu
    do {
        printf("\nMenu:\n");
        printf("0. Quitter le programme\n");
        printf("1. Afficher les planètes\n");
        printf("2. Ajouter une planète\n");
        printf("3. Rechercher une planète\n");
        printf("4. Supprimer des planètes\n");
        printf("5. Retourner la planète la plus proche de la Terre\n");
        printf("6. Retourner la planète dont le diamètre est le plus petit\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                displayPlanet(tab, nbPlanetes);
                break;
            case 2:
                addPlanet(tab, &nbPlanetes);
                break;
            case 3:
                printf("Entrez le nom de la planète à rechercher : ");
                scanf("%25s", nomPlanete);
                if (searchPlanet(tab, nbPlanetes, 0, nomPlanete)) {
                    printf("Planète trouvée.\n");
                } else {
                    printf("Planète non trouvée.\n");
                }
                break;
            case 4:
                int nbLunes;
                printf("Entrez le nombre de lunes pour supprimer les planètes correspondantes : ");
                scanf("%d", &nbLunes);
                deletePlanetByMoon(tab, &nbPlanetes, nbLunes);
                break;
            case 5:
                Planete closest = findClosestPlanet(tab, nbPlanetes);
                printf("La planète la plus proche est %s.\n", closest.nom);
                break;
            case 6:
                Planete smallest = findSmallestDiameterPlanet(tab, nbPlanetes);
                printf("La planète avec le plus petit diamètre est %s.\n", smallest.nom);
                break;
            default:
                break;
        }
    } while (choix != 0);

    return 0;
}
