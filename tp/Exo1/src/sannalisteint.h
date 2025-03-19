// Header file for linked list of integers
#ifndef SANNALISTEINT_H
#define SANNALISTEINT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the linked list
typedef struct maillon
{
    int val;
    struct maillon *p_suiv;
} maillon_int;

// Function declarations
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt);
maillon_int *init_elt();
void parcourir(maillon_int *p_tete);
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt);
void inserer2(maillon_int **prem, maillon_int *e);
void supprimer_debut(maillon_int **prem);
void supprime_elt(maillon_int **prem, int nb);
void detruire_liste(maillon_int **prem);
void sauver_liste(maillon_int *prem);
maillon_int *load_liste();

#endif // SANNALISTEINT_H