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
#include <time.h>
#include <errno.h>
#include "sannalisteint.h"

maillon_int *init_elt() {
    maillon_int *p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt) {
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}

void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt) {
    p_nv_elt->p_suiv = *p_p_tete;
    *p_p_tete = p_nv_elt;
}

int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt) {
    int errorCode = -1;
    if (p_nv_elt != NULL) {
        p_nv_elt->p_suiv = *p_p_tete;
        *p_p_tete = p_nv_elt;
        errorCode = 0;
    }
    return errorCode;
}

void parcourir(maillon_int *p_tete) {
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL) {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt) {
    maillon_int *n, *prec;

    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    } else {
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}

void inserer2(maillon_int **prem, maillon_int *e) {
    maillon_int *n, *prec;
    if (*prem == NULL || e->val <= (*prem)->val) {
        e->p_suiv = *prem;
        *prem = e;
    } else {
        n = prec = *prem;
        while (n != NULL && e->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}

void supprimer_debut(maillon_int **prem) {
    maillon_int *n;
    if (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

void supprime_elt(maillon_int **prem, int nb) {
    maillon_int *n = *prem;
    maillon_int *prec = NULL;

    while (n != NULL) {
        if (n->val == nb) {
            if (prec == NULL) {
                *prem = n->p_suiv;
            } else {
                prec->p_suiv = n->p_suiv;
            }
            maillon_int *temp = n;
            n = n->p_suiv;
            free(temp);
        } else {
            prec = n;
            n = n->p_suiv;
        }
    }
}

void detruire_liste(maillon_int **prem) {
    maillon_int *n;
    while (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

void detruire_liste2(maillon_int **prem) {
    while (*prem != NULL)
        supprimer_debut(prem);
}

void sauver_liste(maillon_int *prem) {
    FILE *f = fopen("saveliste.bin", "wb");
    if (prem != NULL) {
        if (f == NULL)
            fprintf(stderr, "erreur création fichier :%i\n", errno);
        else
            while (prem != NULL) {
                if (1 != fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr, "Erreur d'écriture du maillon %p\n", prem);
                else
                    prem = prem->p_suiv;
            }
        fclose(f);
    } else
        fprintf(stderr, "pas de sauvegarde pour une liste vide\n");
}

maillon_int *load_liste() {
    FILE *f;
    maillon_int *prem = NULL, *p, e;
    if ((f = fopen("saveliste.bin", "rb")) != NULL) {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f)) {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    } else
        printf("erreur ou fichier inexistant");
    return prem;
}