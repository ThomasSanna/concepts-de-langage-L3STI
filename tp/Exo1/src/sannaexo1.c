/*
    Documentation section
    @Project TP1 Exercice 1
    @Author Sanna Thomas
    @Author Nivet Marie-Laure
    @Created 20250319
    @Program Description, Program to create a linked list of integers and to manipulate it
*/


#include <stdio.h>
#include <stdlib.h>
#include "sannalisteint.h"

/*
    Permet d'afficher le menu des choix possibles
    @input : void
    @output : int, choix de l'utilisateur
*/
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
           "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
           "4 Supprimer l'élément de tête\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"saveliste.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin); 

    return choix;
}


// point d'entrée de l'application
int main()
{
    maillon_int *premier = NULL;
    maillon_int *nouveau; 
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin)
    {
        i = menu();
        switch (i)
        {
        case 1: // Creer une liste de taille aleatoire
            nb = rand() % 20 + 1;
            for (int j = 0; j < nb; j++)
            {
                nouveau = init_elt();
                ajout_tete_v3(&premier, nouveau);
            }
            parcourir(premier);
            break;

        case 2: // Ajouter un élément entier aléatoire en tête de liste
            nouveau = init_elt();
            if (ajout_tete_v3(&premier, nouveau) == 0)
                parcourir(premier);
            else
                printf("Erreur lors de l'ajout en tête de liste\n");
            break;

        case 3: // Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant
            nouveau = init_elt();
            inserer2(&premier, nouveau);
            parcourir(premier);
            break;

        case 4: // Supprimer l'élément de tête
            supprimer_debut(&premier);
            parcourir(premier);
            break;

        case 5: // Supprimer un maillon d'une valeur donnee
            printf("Valeur à supprimer : ");
            scanf("%d", &nb);
            supprime_elt(&premier, nb);
            parcourir(premier);
            break;

        case 6: // Detruire liste
            detruire_liste(&premier);
            parcourir(premier);
            break;

        case 7: // Sauver liste
            sauver_liste(premier);
            break;

        case 8: // Charger liste
            premier = load_liste();
            parcourir(premier);
            break;

        default:
            fin = 1;
            break;
        }
    }

    return 0;
}