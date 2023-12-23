
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Salarie {
    char nom[20];
    char prenom[20];
    int id;
    char service[20];
    float salaire;
    struct Salarie *nextNodes;
} Salarie, *List ;

List new_list();
bool is_empty_list(List li);
void print_list(List li);
void print_list_service(List li, char service[20]);
List push_front_list(List li, char nom[20], char prenom[20], int id, char service[20], float salaire);
List push_back_list(List li, char nom[20], char prenom[20], int id, char service[20], float salaire);
List pop_front_list(List li);
List pop_back_list(List li);
List update_salarie(List li, int id, float nouveau_salaire);
List frontBackSplit(List source);
List sortedMerge(List a, List b) ;
List croissantSort_salary_list(List li);
float Salary_mass_liste(List li);
List mirror_list(List li);

/*
- Creer la liste
- Inserer en tête
- Inserer en queue
- Supprimer la tête
- Supprimer la queue
- Afficher 
- Miroire de la liste
- Mettre à jour salaire
- Trier la liste selon salaire croissant
- Afficher les salarie d'un service
- Fonction recurcive, calcule masse salariale totale
- Tester main
*/
