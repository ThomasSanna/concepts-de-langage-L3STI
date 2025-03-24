/*
    Documentation section
    @Project TD2 Exercice B.2-3
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to calculate the sum of an array of integers
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sum_array.h"

/*
Fait la somme des éléments d'un tableau d'entiers.
Input : 
    - int *array : tableau d'entiers
    - size_t size : taille du tableau
    - int *computedSum : pointeur vers la somme calculée
Output :
    - int : 0 si la somme a été calculée avec succès, -1 en cas d'erreur
*/
int sumArray(int *array, size_t size, int *computedSum) {
    if (array == NULL || computedSum == NULL) {
        return -1;
    }

    *computedSum = 0;
    for (int *ptr = array; ptr < array + size; ++ptr) {
        *computedSum += *ptr;
    }

    return 0;
}