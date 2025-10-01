#include <stdio.h>
#include <stdlib.h>

// Définition du nœud
typedef struct noeud {
    int n;              
    struct noeud* suiv; //ça c'est le pointeur vers le suivant
} noeud;

// Définition de la liste
typedef struct {
    noeud* tete;
} liste;

// Fonction pour insérer en tête de la liste
void inserer(liste* l, int val) {
    noeud* nouv = (noeud*)malloc(sizeof(noeud));
    nouv->n = val;
    nouv->suiv = l->tete;
    l->tete = nouv;
}

// Fonction pour afficher la liste
void afficher(liste* l) {
    noeud* p = l->tete;
    while (p != NULL) {
        printf("%d -> ", p->n);
        p = p->suiv;
    }
    printf("NULL\n");
}

// Fonction pour supprimer toutes les occurrences
void supprimer(liste* l, int val) {
    noeud* p = l->tete;
    noeud* prec = NULL;

    while (p != NULL) {
        if (p->n == val) {
            noeud* tmp = p;
            if (prec == NULL) { // suppression en tête
                l->tete = p->suiv;
                p = l->tete;
            } else {
                prec->suiv = p->suiv;
                p = p->suiv;
            }
            free(tmp);
        } else {
            prec = p;
            p = p->suiv;
        }
    }
}

int main() {
    liste L;
    L.tete = NULL;
    printf("suppression des occurences \n");
    //juste un Exemple d’insertion après tu peux changer les chiffres 
    inserer(&L, 5);
    inserer(&L, 3);
    inserer(&L, 5);
    inserer(&L, 2);
    inserer(&L, 5);

    printf("Liste avant suppression :\n");
    afficher(&L);

    int x;
    printf("Entrez la valeur a supprimer : ");
    scanf("%d", &x);

    supprimer(&L, x);

    printf("Liste apres suppression :\n");
    afficher(&L);

    return 0;
}