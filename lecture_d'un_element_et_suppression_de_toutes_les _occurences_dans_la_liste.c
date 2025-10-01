 #include <stdio.h>
#include <stdlib.h>

// Définition de la structure Element
typedef struct Element {
    int donnee;
    struct Element* suivant;
} Element;

// Insertion à la fin
void insererFin(Element** tete, int valeur) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->donnee = valeur;
    nouveau->suivant = NULL;

    if (*tete == NULL) {
        *tete = nouveau;
    } else {
        Element* temp = *tete;
        while (temp->suivant != NULL)
            temp = temp->suivant;
        temp->suivant = nouveau;
    }
}

// Affichage de la liste
void afficherListe(Element* tete) {
    while (tete != NULL) {
        printf("%d -> ", tete->donnee);
        tete = tete->suivant;
    }
    printf("NULL\n");
}

// Suppression de toutes les occurrences d'une valeur
void supprimerOccurrences(Element** tete, int valeur) {
    while (*tete != NULL && (*tete)->donnee == valeur) {
        Element* temp = *tete;
        *tete = (*tete)->suivant;
        free(temp);
    }

    Element* courant = *tete;
    while (courant != NULL && courant->suivant != NULL) {
 if (courant->suivant->donnee == valeur) {
            Element* temp = courant->suivant;
            courant->suivant = courant->suivant->suivant;
            free(temp);
        } else {
            courant = courant->suivant;
        }
    }
}

// Fonction principale
int main() {
    Element* liste = NULL;
    int n, val;

    printf("Combien d'elements ? ");
    scanf("%d", &n);

    printf("Entrez les elements :\n");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insererFin(&liste, x);
    }

    printf("Liste initiale : ");
    afficherListe(liste);

    printf("Entrez la valeur à supprimer : ");
    scanf("%d", &val);

    supprimerOccurrences(&liste, val);

    printf("Liste après suppression : ");
    afficherListe(liste);

    return 0;
}
