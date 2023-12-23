#include "gestionESIEA.h"

int main() {
    // Création d'une nouvelle liste
    List listEmploye = new_list();
    printf("Liste initialisée.\n");
    print_list(listEmploye);

    // Ajout d'employés à la liste
    printf("\nAjout d'employés à la liste...\n");
    listEmploye = push_back_list(listEmploye, "Dupont", "Jean", 1, "Comptabilité", 3000.00);
    listEmploye = push_front_list(listEmploye, "Martin", "Alice", 2, "RH", 3200.00);
    listEmploye = push_back_list(listEmploye, "Leroy", "Marc", 3, "IT", 3500.00);
    print_list(listEmploye);

    // Mise à jour du salaire d'un employé
    printf("\nMise à jour du salaire de Jean Dupont...\n");
    listEmploye = update_salarie(listEmploye, 1, 3300.00);
    print_list(listEmploye);

    // Calcul de la masse salariale totale
    float totalSalaire = Salary_mass_liste(listEmploye);
    printf("\nMasse salariale totale: %0.2f€\n", totalSalaire);

    // Tri de la liste par salaire croissant
    printf("\nTri de la liste par salaire croissant...\n");
    listEmploye = croissantSort_salary_list(listEmploye);
    print_list(listEmploye);

    // Suppression d'employés
    printf("\nSuppression de l'employé en tête de liste...\n");
    listEmploye = pop_front_list(listEmploye);
    print_list(listEmploye);

    printf("\nSuppression de l'employé en fin de liste...\n");
    listEmploye = pop_back_list(listEmploye);
    print_list(listEmploye);

    // Affichage des employés d'un service spécifique
    printf("\nAffichage des employés du service RH...\n");
    print_list_service(listEmploye, "RH");

    // Création d'une liste miroir
    printf("\nCréation d'une liste miroir...\n");
    List mirroredList = mirror_list(listEmploye);
    print_list(mirroredList);

    // Libération de la mémoire
    // Ajoutez ici du code pour libérer correctement toute la mémoire allouée aux listes

    return 0;
}