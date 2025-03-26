/*
    Documentation section
    @Project TD2 Exercice B.4
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to apply a function to an array of integers
*/



#include <stdio.h>
#include <stdlib.h>

/* Question (a)
La fonction appliquerATableau prend en paramètre un tableau d'entiers et une fonction qui prend un entier en paramètre et retourne un entier. 
Elle applique la fonction à chaque élément du tableau. Une sorte de map.
*/

int fois_deux(int i){
    return i * 2;
}

/* Question (b)
Applique la fonction f à chaque élément du tableau t de taille n.
Input :
  - int f(int) : une fonction qui prend un entier en paramètre et retourne un entier
  - int* t : un tableau d'entiers
  - int n : la taille du tableau
Output :
  - void : la fonction ne retourne rien, elle modifie le tableau en place
*/
void appliquerATableauPurPointeurs(int f(int), int* t, int n){
    int* end = t + n; // ie l'adresse du dernier element de t
    for (int* p = t; p < end; p++) {
        *p = f(*p);
    }
}

// Question (c)
int f1(int i, int j) {
  return i + j;
}

/*
Applique la fonction f à chaque élément du tableau t de taille n, en lui passant val comme second argument.
Input :
  - int f(int, int) : une fonction qui prend deux entiers en paramètre et retourne un entier
  - int* t : un tableau d'entiers
  - int n : la taille du tableau
  - int val : la valeur à passer en second argument à la fonction f
*/
void appliquerATableau(int f(int, int), int* t, int n, int val) {
  for (int i = 0; i < n; i++) {
    t[i] = f(t[i], val);
  }
}

// Question (d)
int addition(int a, int b) {
  return a + b;
}

int soustraction(int a, int b) {
  return a - b;
}

int multiplication(int a, int b) {
  return a * b;
}

int division(int a, int b) {
  if (b == 0) {
    return 0;
  }
  return a / b;
}


int main(void){
    int tab[] = {1, 2, 3, 4};
    int (*f)(int) = &fois_deux;
    printf("Avant : \n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    printf("Apres utilisation de *2 : \n");
    appliquerATableauPurPointeurs(*f, tab, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    printf("Apres utilisation de +2 : \n");
    int (*f2)(int, int) = &f1;
    appliquerATableau(*f2, tab, 4, 2);
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    printf("Apres utilisation de -2 : \n");
    int (*f3)(int, int) = &soustraction;
    appliquerATableau(*f3, tab, 4, 2);
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    printf("Apres utilisation de *2 : \n");
    int (*f4)(int, int) = &multiplication;
    appliquerATableau(*f4, tab, 4, 2);
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    printf("Apres utilisation de /2 : \n");
    int (*f5)(int, int) = &division;
    appliquerATableau(*f5, tab, 4, 2);
    for (int i = 0; i < 4; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}