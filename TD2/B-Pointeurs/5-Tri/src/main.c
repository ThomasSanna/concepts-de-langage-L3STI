/*
    Documentation section
    @Project TD2 Exercice B.5.main
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to demonstrate sorting using function pointers
*/

#include <stdio.h>

int superieur(int a, int b);
int inferieur(int a, int b);
void tri(int* t, int n, int (*compare)(int, int));

int main() {
    int t1[] = {5, 3, 8, 4, 2};
    int t2[] = {5, 3, 8, 4, 2};
    int n = 5;
    int i;

    // Tri croissant
    tri(t1, n, inferieur);
    printf("Tri croissant : ");
    for (i = 0; i < n; i++) {
        printf("%d ", t1[i]);
    }
    printf("\n");

    // Tri décroissant
    tri(t2, n, superieur);
    printf("Tri décroissant : ");
    for (i = 0; i < n; i++) {
        printf("%d ", t2[i]);
    }
    printf("\n");

    return 0;
}