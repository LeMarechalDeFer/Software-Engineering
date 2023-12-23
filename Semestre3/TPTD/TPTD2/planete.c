//Gestion des planètes d'un système stellaire
#include "planete.h"

// void init(void){
//     int planeteNumber ;
//     printf("Selectionner le nombre de plannette") ; 
//     scanf("%d", planeteNumber);
//     Planete *tab = malloc(sizeof(Planete)*planeteNumber);
// }


int readPlanetData(Planete tab[], int tailleMax) {
    FILE *fic = fopen("planete_data.txt", "r");
    if (fic == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int nbPlanetes = 0;
    while (nbPlanetes < tailleMax && !feof(fic)) {
        if (fscanf(fic, "%25s %f %f %u", tab[nbPlanetes].nom, &tab[nbPlanetes].diametre, &tab[nbPlanetes].dTerre, &tab[nbPlanetes].nbSatellites) == 4) {
            nbPlanetes++;
        }
    }

    fclose(fic);
    return nbPlanetes;
}



void inputPlanet(Planete *T, int *nb) {
    int nbNewPlanets;
    printf("Entrez le nombre de nouvelles planètes à ajouter : ");
    scanf("%d", &nbNewPlanets);

    if (*nb + nbNewPlanets > MAX_PLANETES) {
        printf("Espace insuffisant pour ajouter autant de planètes.\n");
        return;
    }

    for (int i = *nb; i < *nb + nbNewPlanets; i++) {
        printf("Planète %d:\n", i + 1);
        printf("Nom : ");
        scanf("%25s", T[i].nom);
        printf("Diamètre (km) : ");
        scanf("%f", &T[i].diametre);
        printf("Distance à la Terre (km) : ");
        scanf("%f", &T[i].dTerre);
        printf("Nombre de satellites : ");
        scanf("%u", &T[i].nbSatellites);
    }

    *nb += nbNewPlanets;
}


void displayPlanet(Planete *T, int NbPlanet){
    int i;
    for(i=0; i<NbPlanet; i++){
        printf("Nom : %25s\n", T[i].nom);
        printf("Diametre : %f\n", T[i].diametre) ;
        printf("Distance à la terre (km) : %f\n", T[i].dTerre);
        printf("Nombre de satellites : %u\n\n", T[i].nbSatellites);
    }
}

void addPlanet(Planete *T, int *nb) {
    if (*nb >= 100) {  
        printf("Capacité maximale atteinte. Impossible d'ajouter une nouvelle planète.\n");
        return;
    }

    printf("Ajout d'une nouvelle planète:\n");
    printf("Nom de la planète : ");
    scanf("%25s", T[*nb].nom);
    printf("Diamètre (km) : ");
    scanf("%f", &T[*nb].diametre);
    printf("Distance à la Terre (km) : ");
    scanf("%f", &T[*nb].dTerre);
    printf("Nombre de satellites : ");
    scanf("%u", &T[*nb].nbSatellites);

    (*nb)++;
}


int searchPlanet(Planete *T, int nb, int i, char *planetName) {
    // Cas de base : si on a parcouru tout le tableau sans trouver la planète
    if (i >= nb) {
        return 0;
    }

    // Si le nom de la planète à l'indice actuel correspond au nom recherché
    if (strcmp(T[i].nom, planetName) == 0) {
        return 1;
    }

    // Appel récursif pour vérifier le reste du tableau
    return searchPlanet(T, nb, i + 1, planetName);
}


void deletePlanetByMoon(Planete *T, int *nb, int bMoon) {
    int i = 0;
    int found = 0;

    while (i < *nb) {
        if (T[i].nbSatellites == bMoon) {
            found = 1;
            // Décaler les éléments suivants d'une position vers la gauche
            for (int j = i; j < *nb - 1; j++) {
                T[j] = T[j + 1];
            }
            (*nb)--; // Diminuer le nombre total de planètes
            // Ne pas augmenter i car nous devons vérifier le nouvel élément à la position i
        } else {
            i++; // Passer à l'élément suivant seulement si aucune suppression n'a eu lieu
        }
    }

    if (!found) {
        printf("Aucune planète avec %d lunes trouvée.\n", bMoon);
    }
}


Planete findClosestPlanet(Planete *T, int nb) {
    if (nb <= 0) {
        fprintf(stderr, "Erreur : Le tableau est vide.\n");
        exit(EXIT_FAILURE);
    }

    // On suppose que la première planète est la plus proche
    Planete closest = T[0];
    for (int i = 1; i < nb; i++) {
        if (T[i].dTerre < closest.dTerre) {
            closest = T[i];
        }
    }
    return closest;
}

Planete findSmallestDiameterPlanet(Planete *T, int nb) {
    if (nb <= 0) {
        fprintf(stderr, "Erreur : Le tableau est vide.\n");
        exit(EXIT_FAILURE);
    }

    // On suppose que la première planète a le plus petit diamètre
    Planete smallest = T[0];
    for (int i = 1; i < nb; i++) {
        if (T[i].diametre < smallest.diametre) {
            smallest = T[i];
        }
    }
    return smallest;
}

