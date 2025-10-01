#include <stdio.h>
#include <stdlib.h>

// Définition du nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Création d'un nouveau nœud
Node* creerNoeud(int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    nouveau->next = NULL;
    return nouveau;
}

// Insertion triée
void insererTrie(Node** tete, int valeur) {
    Node* nouveau = creerNoeud(valeur);

    // Cas 1 : liste vide ou valeur plus petite que la tête
    if (*tete == NULL || valeur < (*tete)->data) {
        nouveau->next = *tete;
        *tete = nouveau;
        return;
    }

    // Cas 2 : chercher la bonne position
    Node* courant = *tete;
    while (courant->next != NULL && courant->next->data < valeur) {
        courant = courant->next;
    }

    // Insérer entre courant et courant->next
    nouveau->next = courant->next;
    courant->next = nouveau;
}

// Affichage de la liste
void afficherListe(Node* tete) {
    Node* tmp = tete;
    while (tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// Programme principal
int main() {
    Node* tete = NULL;

    // Insérer des éléments
    insererTrie(&tete, 10);
    insererTrie(&tete, 5);
    insererTrie(&tete, 20);
    insererTrie(&tete, 15);

    // Afficher la liste triée
    afficherListe(tete);

    return 0;
}
