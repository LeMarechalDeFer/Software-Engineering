#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PLANETES 100

typedef struct Planete {
    char nom[26];
    float diametre;
    float dTerre;
    int nbSatellites;
} Planete;

//max 100 planetes

// void init(void);
int readPlanetData(Planete tab[], int tailleMax);
void inputPlanet(Planete *T, int *nb) ;
void displayPlanet(Planete *T, int NbPlanet);
void addPlanet(Planete *T, int *nb) ;
int searchPlanet(Planete *T, int nb, int i, char *planetName);
void deletePlanetByMoon(Planete *T, int *nb, int bMoon) ;
Planete findClosestPlanet(Planete *T, int nb) ;
Planete findSmallestDiameterPlanet(Planete *T, int nb);

