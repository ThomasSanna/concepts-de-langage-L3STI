/*
    Documentation section
    @Project TD2 Exercice C.1
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to calculate the product of the first n integers using both classical and tail recursion
*/

#include <stdio.h>

/*
Fonction de récursivité classique qui calcule le produit des n premiers entiers.
Input : 
  - int n (nombre d'entiers à multiplier)
Output : 
  - int (produit des n premiers entiers)
*/
int produitClassique(int n) {
    if (n == 1) {
        return 1;
    }
    return n * produitClassique(n - 1);
}

/*
Fonction de récursivité terminale qui calcule le produit des n premiers entiers.
Est utilisée avec produitTerminale(n) pour éviter de passer l'accumulateur.
Input : 
  - int n (nombre d'entiers à multiplier)
  - int accumulateur (accumulateur pour la récursivité terminale)
Output : 
  - int (produit des n premiers entiers)
*/
int produitTerminaleH(int n, int accumulateur) {
    if (n == 1) {
        return accumulateur;
    }
    return produitTerminaleH(n - 1, n * accumulateur);
}

/*
Fonction d'interface pour la récursivité terminale.
Cette fonction appelle la fonction produitTerminale avec un accumulateur initialisé à 1.
Input : 
  - int n (nombre d'entiers à multiplier)
Output : 
  - int (produit des n premiers entiers)
*/
int produitTerminale(int n) {
    return produitTerminaleH(n, 1);
}

// Fonction de test principale 
int main() {
    int n = 3;

    int resultatClassique = produitClassique(n);
    int resultatTerminale = produitTerminale(n);

    printf("Produit des %d premiers entiers (récursivité classique) : %d\n", n, resultatClassique);
    printf("Produit des %d premiers entiers (récursivité terminale) : %d\n", n, resultatTerminale);

    return 0;
}