#include <stdio.h>
#include <stdlib.h>

// Structure de la liste doublement chaînée circulaire
typedef struct Liste
{
    int valeur;
    struct Liste *previous;
    struct Liste *next;
} Liste;

// Créer un élément de la liste
Liste *creer_liste(int v)
{
    Liste *l = (Liste *)malloc(sizeof(Liste));
    if (!l)
    {
        perror("Erreur d'allocation memoire");
        exit(1);
    }
    l->valeur = v;
    l->previous = l->next = NULL;
    return l;
}

// Initialiser le sentinelle
void initialiser_sentinelle(Liste *S)
{
    S->next = S;
    S->previous = S;
}

// Insérer un élément trié
void inserer_trie(Liste *S, int x)
{
    Liste *p = S->next;
    while (p != S && p->valeur < x)
        p = p->next;
    Liste *l = creer_liste(x);
    l->next = p;
    l->previous = p->previous;
    p->previous->next = l;
    p->previous = l;
}

// Afficher la liste
void afficher_liste(Liste *S)
{
    Liste *p = S->next;
    if (p == S)
    {
        printf("La liste est vide.\n");
        return;
    }
    while (p != S)
    {
        printf("%d ", p->valeur);
        p = p->next;
    }
    printf("\n");
}

// Trier la liste (j'ai utiliser le tri simple')
void trier_liste(Liste *S)
{
    Liste *tri = (Liste *)malloc(sizeof(Liste)); 
    initialiser_sentinelle(tri);
    Liste *p = S->next;
    while (p != S)
    {
        Liste *suivant = p->next;
        inserer_trie(tri, p->valeur);
        free(p);
        p = suivant;
    }
    // Ici je reconnecte la lites a S
    S->next = tri->next;
    S->previous = tri->previous;
    if (tri->next != tri)
        tri->next->previous = S;
    if (tri->previous != tri)
        tri->previous->next = S;
    free(tri);
}

// Insérer un élément à une position 
void inserer_position(Liste *S, int x, int pos)
{
    Liste *p = S->next;
    int compteur = 1;
    while (p != S && compteur < pos)
    {
        p = p->next;
        compteur++;
    }
    Liste *l = creer_liste(x);
    l->next = p;
    l->previous = p->previous;
    p->previous->next = l;
    p->previous = l;
}

int main()
{
    printf("\n\nBienvenue dans le programme d'insertion dans une  liste doublement chaînée circulaire triée !\n");

    int taille;
    do
    {
        printf("\n\tEntrez la taille de la liste (>5) : ");
        scanf("%d", &taille);
        if (taille <= 5)
            printf("\tLa taille doit être supérieure à 5.\n");
    } while (taille <= 5);

    Liste sentinelle;
    initialiser_sentinelle(&sentinelle);

    printf("\n\tRemplissage de la liste avec %d entiers relatifs :\n", taille);
    for (int i = 0; i < taille; i++)
    {
        int valeur;
        printf("\tEntrez la valeur N°%d : ", i + 1);
        scanf("%d", &valeur);
        inserer_trie(&sentinelle, valeur);
    }

    printf("\n\tLa liste initiale triée : ");
    afficher_liste(&sentinelle);

    int valeur_insertion, position;
    printf("\n\tEntrez le nombre à insérer : ");
    scanf("%d", &valeur_insertion);
    printf("\tEntrez la position à laquelle l'insérer (1 = tête) : ");
    scanf("%d", &position);

    inserer_position(&sentinelle, valeur_insertion, position);

    printf("\n\tLa liste après insertion : ");
    afficher_liste(&sentinelle);

    return 0;
}