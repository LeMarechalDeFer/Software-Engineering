
typedef struct Noeud {
    void* donnee; 
    struct Noeud *suivant;
    struct Noeud *precedent;
} Noeud;

typedef struct EntreeTableHachage {
    int cle;   
    Noeud* noeud;
} EntreeTableHachage;

EntreeTableHachage tableHachage[TABLE_HACHAGE_TAILLE]; 


void ajouterEnTete(Noeud** tete, void* donnee) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->donnee = donnee;
    nouveauNoeud->suivant = (*tete);
    nouveauNoeud->precedent = NULL;

    if ((*tete) != NULL) {
        (*tete)->precedent = nouveauNoeud;
    }

    *tete = nouveauNoeud;
}

void supprimerNoeud(Noeud** tete, Noeud* aSupprimer) {
    if (*tete == NULL || aSupprimer == NULL) return;

    if (*tete == aSupprimer) {
        *tete = aSupprimer->suivant;
    }

    if (aSupprimer->suivant != NULL) {
        aSupprimer->suivant->precedent = aSupprimer->precedent;
    }

    if (aSupprimer->precedent != NULL) {
        aSupprimer->precedent->suivant = aSupprimer->suivant;
    }

    free(aSupprimer);  
}


int fonctionHachage(int cle) {
    return cle % TABLE_HACHAGE_TAILLE;
}

void insererTableHachage(EntreeTableHachage* table, int cle, void* donnee) {
    int index = fonctionHachage(cle);
    ajouterEnTete(&(table[index].noeud), donnee);  
    table[index].cle = cle;  
}

Noeud* rechercherTableHachage(EntreeTableHachage* table, int cle) {
    int index = fonctionHachage(cle);
    Noeud* courant = table[index].noeud;
    while (courant != NULL) {
        
        // Ajouter des conditions de correspondance de clé ou de donnée ici si nécessaire
        if (table[index].cle == cle) {
            return courant;
        }

        courant = courant->suivant;
    }
    return NULL; 
}



insererTableHachage(tableHachage, cleUniqueFauxBourdon, nouveauFauxBourdon);
insererTableHachage(tableHachage, cleUniqueOuvriere, nouvelleOuvriere);