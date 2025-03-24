/*
    Documentation section
    @Project TD2 Exercice B.5.tri
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to demonstrate sorting using function pointers
*/

#include <stdio.h>
#include <stdlib.h>

/*
Vérifie si a est supérieur à b
Input :
  - int a : un entier
  - int b : un entier
Output :
  - int : 1 si a > b, 0 si a == b, -1 si a < b
*/
int superieur(int a, int b) {
    if (a > b) {
        return 1;
    } else if (a == b) {
        return 0;
    } else {
        return -1;
    }
}

/*
Vérifie si a est inférieur à b
Input :
  - int a : un entier
  - int b : un entier
Output :
  - int : 1 si a < b, 0 si a == b, -1 si a > b
*/
int inferieur(int a, int b) {
    if (a < b) {
        return 1;
    } else if (a == b) {
        return 0;
    } else {
        return -1;
    }
}

/*
Tri un tableau d'entiers en utilisant une fonction de comparaison
Input :
  - int* t : un tableau d'entiers
  - int n : la taille du tableau
  - int (*compare)(int, int) : une fonction de comparaison qui prend deux entiers en paramètre et retourne un entier
Output :
  - void : le tableau est trié en place
*/
void tri(int* t, int n, int compare(int, int)) {
    int i, iMin, j, tmp;
    for (i = 0; i < n - 1; i++) {
        iMin = i;
        for (j = i + 1; j < n; j++) {
            if (compare(t[j], t[iMin]) > 0) {
                iMin = j;
            }
        }
        if (iMin != i) {
            tmp = t[i];
            t[i] = t[iMin];
            t[iMin] = tmp;
        }
    }
}