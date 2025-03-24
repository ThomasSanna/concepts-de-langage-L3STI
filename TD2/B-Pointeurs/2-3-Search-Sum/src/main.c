/*
    Documentation section
    @Project TD2 Exercice B.2-3
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to test the sum and search functions on static and dynamic arrays
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sum_array.h"
#include "search_array.h"

int main() {
	// Init Tableau statique
	int staticArray[5] = {1, 2, 3, 4, 5};

	// Init Tableau dynamique
	size_t dynamicSize = 5;
	int *dynamicArray = (int *)malloc(dynamicSize * sizeof(int));
	for (size_t i = 0; i < dynamicSize; ++i) {
		dynamicArray[i] = i + 1; // Remplir le tableau avec des valeurs de 1 à 5
	}

	// Test sumArray ---------
	// Tableau statique
	int sumStatic = 0;
	if (sumArray(staticArray, 5, &sumStatic) == 0) {
		printf("La somme du tableau statique est : %d\n", sumStatic);
	} else {
		printf("Erreur lors du calcul de la somme du tableau statique.\n");
	}
	// Tableau dynamique
	int sumDynamic = 0;
	if (sumArray(dynamicArray, dynamicSize, &sumDynamic) == 0) {
		printf("La somme du tableau dynamique est : %d\n", sumDynamic);
	} else {
		printf("Erreur lors du calcul de la somme du tableau dynamique.\n");
	}

	// Test searchArray ---------
	// Tableau statique
	int searchStatic = 3;
	int indexStatic = searchArray(staticArray, 5, searchStatic);
	if (indexStatic != -1) {
		printf("L'élément %d a été trouvé à l'indice %d dans le tableau statique.\n", searchStatic, indexStatic);
	} else {
		printf("L'élément %d n'a pas été trouvé dans le tableau statique.\n", searchStatic);
	}
	// Tableau dynamique
	int searchDynamic = 4;
	int indexDynamic = searchArray(dynamicArray, dynamicSize, searchDynamic);
	if (indexDynamic != -1) {
		printf("L'élément %d a été trouvé à l'indice %d dans le tableau dynamique.\n", searchDynamic, indexDynamic);
	} else {
		printf("L'élément %d n'a pas été trouvé dans le tableau dynamique.\n", searchDynamic);
	}


	// Libérer la mémoire allouée dynamiquement
	free(dynamicArray);

	return 0;
}