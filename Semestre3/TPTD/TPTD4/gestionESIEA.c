#include "gestionESIEA.h"

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

List new_list(){
    return NULL;
}

bool is_empty_list(List li){
    if(li == NULL){
        return true ;
    }
    else{
        return false;
    }
}

void print_list(List li){
    if(li == NULL){
        printf("La liste est vide.\n");
    }
    else{
        int i =1;
        while(li != NULL){
            
            printf("Salarié n°%d : %s - %s - %d - %s - %0.2f€ \n", i, li->nom, li->prenom, li->id, li->service, li->salaire);
            i++;
            li = li->nextNodes ;
        }
        printf("\n");
    }
}

void print_list_service(List li, char service[20]){
    if(li == NULL){
        printf("La liste est vide.\n");
    }
    else{
        bool trouver =false;
        int i =1;
        while(li != NULL){
            if (strcmp(li->service, service) == 0) {
                printf("Salarié n°%d : %s - %s - %d - %s - %0.2f€ \n", i, li->nom, li->prenom, li->id, li->service, li->salaire);
                trouver = true ;
            }
            i++;
            li = li->nextNodes ;
        }
        if (!trouver) {
        printf("Aucun employé trouvé dans le service %s.\n", service);
        }   
        printf("\n");

    }
}

List push_front_list(List li, char nom[20], char prenom[20], int id, char service[20], float salaire){
    
    List nouveau = malloc(sizeof(Salarie));
    if(nouveau == NULL){
        perror("Erreur allocation mémoire");
        exit(EXIT_FAILURE);
    }
    else{
        strncpy(nouveau->nom, nom, sizeof(nouveau->nom)-1);
        nouveau->nom[sizeof(nouveau->nom)-1] = '\0'; // Assurez-vous que la chaîne est terminée par '\0'
        strncpy(nouveau->prenom, prenom, sizeof(nouveau->prenom)-1);
        nouveau->prenom[sizeof(nouveau->prenom)-1] = '\0';
        strncpy(nouveau->service, service, sizeof(nouveau->service)-1);
        nouveau->service[sizeof(nouveau->service)-1] = '\0';
        nouveau->id = id;
        nouveau->salaire = salaire;
    }
    nouveau->nextNodes = li ;
    return nouveau ;

    
}

List push_back_list(List li, char nom[20], char prenom[20], int id, char service[20], float salaire){
    List nouveau = malloc(sizeof(Salarie));
    if(nouveau == NULL){
        perror("Erreur allocation mémoire");
        exit(EXIT_FAILURE);
    }

    strncpy(nouveau->nom, nom, sizeof(nouveau->nom)-1);
    nouveau->nom[sizeof(nouveau->nom)-1] = '\0'; // Assurez-vous que la chaîne est terminée par '\0'
    strncpy(nouveau->prenom, prenom, sizeof(nouveau->prenom)-1);
    nouveau->prenom[sizeof(nouveau->prenom)-1] = '\0';
    strncpy(nouveau->service, service, sizeof(nouveau->service)-1);
    nouveau->service[sizeof(nouveau->service)-1] = '\0';
    nouveau->id = id;
    nouveau->salaire = salaire;
    nouveau->nextNodes = NULL;

    if(is_empty_list(li)){
        return nouveau;
    }
    else{
        List temp = li;
        while(temp->nextNodes != NULL){
            temp = temp->nextNodes;
        }
        temp->nextNodes = nouveau;
        return li;
    }
}

List pop_front_list(List li){
    List nouveau = malloc(sizeof(Salarie));
    if(nouveau == NULL){
        perror("Erreur allocation mémoire");
        exit(EXIT_FAILURE);
    }
    nouveau = li ;

    nouveau = nouveau->nextNodes ;
    free(li);
    li = NULL;
    return nouveau ;
}

List pop_back_list(List li){

    if(is_empty_list(li)){
        return new_list();
    }
    else if(li->nextNodes == NULL){
        free(li);
        li = NULL ;
        return new_list();
    }
    else{
        List temp = li;
        if(temp == NULL){
            perror("Erreur aloocation mémoire\n");
            exit(EXIT_FAILURE);
        }
        List before = li ;
        while(temp->nextNodes != NULL){
            before = temp ; 
            temp = temp->nextNodes ;
        }
        before->nextNodes = NULL ;
        free(temp);
        temp = NULL;
    }

    return li;
}

List update_salarie(List li, int id, float nouveau_salaire){
    if(is_empty_list(li)){
        return new_list();
    }
    List temp = li ;
    while(temp != NULL && temp->id != id){
        temp = temp->nextNodes ;
    }
    if(temp != NULL){
        temp->salaire = nouveau_salaire ;
    }
    else{
        perror("L'id n'a pas été trouvé !\n");
    }
    return li;
}

// Fonction auxiliaire pour diviser la liste en deux moitiés
List frontBackSplit(List source) {
    List fast;
    List slow;
    slow = source;
    fast = source->nextNodes;

    // Avancer 'fast' de deux noeuds, et avancer 'slow' de un noeud
    while (fast != NULL) {
        fast = fast->nextNodes;
        if (fast != NULL) {
            slow = slow->nextNodes;
            fast = fast->nextNodes;
        }
    }

    // 'slow' est maintenant avant le point milieu dans la liste, donc divisez-la en deux à ce niveau
    List back = slow->nextNodes;
    slow->nextNodes = NULL;
    return back;
}

// Fonction auxiliaire pour fusionner deux listes triées
List sortedMerge(List a, List b) {
    List result = NULL;

    // Cas de base : si l'une des listes est vide
    if (a == NULL) 
         return b;
    else if (b == NULL) 
         return a;

    // Choisissez a ou b, et récursivement continuez avec la liste restante
    if (a->salaire <= b->salaire) {
        result = a;
        result->nextNodes = sortedMerge(a->nextNodes, b);
    } 
    else {
        result = b;
        result->nextNodes = sortedMerge(a, b->nextNodes);
    }
    return result;
}

// Fonction principale pour trier la liste liée
List croissantSort_salary_list(List li) {
    // Cas de base : si la liste est vide ou contient un seul élément
    if (li == NULL || li->nextNodes == NULL) {
        return li;
    }

    List back = frontBackSplit(li);

    // Recursivement trier les deux sous-listes
    li = croissantSort_salary_list(li);
    back = croissantSort_salary_list(back);

    // Fusionner les deux listes triées
    return sortedMerge(li, back);
}

float Salary_mass_liste(List li){
    // Cas de base: si la liste est vide
    if (li == NULL) {
        return 0;
    }

    // Ajouter le salaire du salarié actuel au total des salaires des salariés restants
    return li->salaire + Salary_mass_liste(li->nextNodes);
}

List mirror_list(List li) {
    List mirrored = NULL;
    List temp;

    while (li != NULL) {
        // Allouer un nouvel espace mémoire pour le nouvel élément
        temp = malloc(sizeof(Salarie));
        if (temp == NULL) {
            perror("Erreur allocation mémoire");
            exit(EXIT_FAILURE);
        }

        // Copier les données du noeud actuel
        *temp = *li;

        // Insérer le nouvel élément au début de la liste miroir
        temp->nextNodes = mirrored;
        mirrored = temp;

        // Passer au noeud suivant dans la liste originale
        li = li->nextNodes;
    }

    return mirrored;
}

