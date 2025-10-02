#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insertion en tête
Node* insererTete(Node* dernier, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    
    if (dernier == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    nouveau->next = dernier->next;
    dernier->next = nouveau;
    return dernier;
}

// Insertion en queue
Node* insererQueue(Node* dernier, int valeur) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    
    if (dernier == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    nouveau->next = dernier->next;
    dernier->next = nouveau;
    return nouveau;
}

// Affichage
void afficher(Node* dernier) {
    if (dernier == NULL) return;
    
    Node* actuel = dernier->next;
    do {
        printf("%d -> ", actuel->data);
        actuel = actuel->next;
    } while (actuel != dernier->next);
    printf("(début)\n");
}

int main() {
    Node* dernier = NULL;
    int nbr, i,v;
    printf("Donner le nombre des éléments :" );
    scanf("%d", &nbr);
    for (i=0; i<nbr; i++){ 
    printf("Donner la valeur de l'élément %d: ",i);
    scanf("%d", &v);
    dernier=insererTete(dernier,v);
    }
    afficher(dernier);
    return 0;
}
