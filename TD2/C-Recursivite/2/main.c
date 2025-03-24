/*
    Documentation section
    @Project TD2 Exercice C.2
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to calculate the power of a number using both classical and tail recursion
*/

#include <stdio.h>

/*
Fonction de récursivité classique qui calcule la puissance d'un nombre n à la puissance p.
Input : 
  - int n (base)
  - int p (exposant)
Output :
  - int (n^p)
*/

int puissanceClassique(int n, int p) {
    if (p == 0) {
        return 1;
    }
    return n * puissanceClassique(n, p - 1);
}

/*
Fonction de récursivité terminale qui calcule la puissance d'un nombre n à la puissance p.
Est utilisée avec puissanceTerminale(n, p) pour éviter de passer l'accumulateur.
Input : 
  - int n (base)
  - int p (exposant)
  - int accumulateur (accumulateur pour la récursivité terminale)
Output :
  - int (n^p)
*/
int puissanceTerminaleH(int n, int p, int accumulateur) {
    if (p == 0) {
        return accumulateur;
    }
    return puissanceTerminaleH(n, p - 1, n * accumulateur);
}

/*
Fonction d'interface pour la récursivité terminale.
Cette fonction appelle la fonction puissanceTerminale avec un accumulateur initialisé à 1.
Input : 
  - int n (base)
  - int p (exposant)
Output :
  - int (n^p)
*/
int puissanceTerminale(int n, int p) {
    return puissanceTerminaleH(n, p, 1);
}

int main() {
    int n = 2;
    int p = 3;

    int resultatClassique = puissanceClassique(n, p);
    int resultatTerminale = puissanceTerminale(n, p);

    printf("Puissance de %d à la puissance %d (récursivité classique) : %d\n", n, p, resultatClassique);
    printf("Puissance de %d à la puissance %d (récursivité terminale) : %d\n", n, p, resultatTerminale);

    return 0;
}