/*
    Documentation section
    @Project TD2 Exercice B.2-3
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to search for an element in an array
*/

#include <stdio.h>
#include <stdlib.h>
#include "search_array.h"

/*
Recherche un élément dans un tableau d'entiers.
Input : 
    - int* array : tableau d'entiers
    - int size : taille du tableau
    - int element : élément à rechercher
Output :
    - int : indice de l'élément trouvé, ou -1 si l'élément n'est pas trouvé
*/
int searchArray(int* array, int size, int element) {
    if (array == NULL) {
        return -1;  // Code d'erreur si le tableau n'existe pas
    }

    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;  // Retourne l'indice de l'élément trouvé
        }
    }

    return -1;  // Retourne -1 si l'élément n'est pas trouvé
}