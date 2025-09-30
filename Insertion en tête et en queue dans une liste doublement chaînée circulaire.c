#include <stdio.h>
#include <stdlib.h>

// Structure d'un élément de la liste doublement chaînée circulaire
typedef struct Liste
{
    int valeur;
    struct Liste *previous;
    struct Liste *next;
} Liste;

// Fonction pour créer un élément de la liste
Liste *creer_liste(int v)
{
    Liste *l = (Liste *)malloc(sizeof(Liste));
    if (!l)
    {
        perror("Erreur d'allocation de la memoire...");
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

// Insertion en tête
void inserer_tete(Liste *S, int x)
{
    Liste *premier = S->next;
    Liste *l = creer_liste(x);
    l->next = premier;
    l->previous = S;
    premier->previous = l;
    S->next = l;
}

// Insertion en queue
void inserer_queue(Liste *S, int x)
{
    Liste *dernier = S->previous;
    Liste *l = creer_liste(x);
    l->previous = dernier;
    l->next = S;
    dernier->next = l;
    S->previous = l;
}

// Affichage de la liste
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

int main()
{
    printf("\n\nBienvenue dans le programme d'insertion dans une liste doublement chaînée circulaire !\n");

    int taille;
    do
    {
        printf("\n\tEntrez la taille de la liste (>3) : ");
        scanf("%d", &taille);
        if (taille <= 3)
            printf("\tLa taille doit être supérieure à 3.\n");
    } while (taille <= 3);

    Liste sentinelle;
    initialiser_sentinelle(&sentinelle);

    printf("\n\tRemplissage de la liste avec %d entiers relatifs :\n", taille);
    for (int i = 0; i < taille; i++)
    {
        int valeur;
        printf("Entrez la valeur N° %d : ", i + 1);
        scanf("%d", &valeur);
        inserer_queue(&sentinelle, valeur);
    }

    printf("\n\tLa liste actuelle : ");
    afficher_liste(&sentinelle);

    int valeur_tete, valeur_queue;
    printf("\n\tEntrez un nombre à insérer en tête : ");
    scanf("%d", &valeur_tete);
    inserer_tete(&sentinelle, valeur_tete);

    printf("\tEntrez un nombre à insérer en queue : ");
    scanf("%d", &valeur_queue);
    inserer_queue(&sentinelle, valeur_queue);

    printf("\n\tLa liste après insertion en tête et en queue : ");
    afficher_liste(&sentinelle);

    return 0;
}