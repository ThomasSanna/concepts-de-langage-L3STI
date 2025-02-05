#include <stdio.h>

/*

Pointeur : variable contenant l'adresse d'une autre variable

[VARIABLES]
    maVariable : valeur de la variable
    &maVariable : adresse de la variable
  
[POINTEURS]
    monPointeur : adresse de la variable pointée
    *monPointeur : valeur de la variable pointée
    &monPointeur : adresse du pointeur

printf % list :
%d : int
%f : float
%c : char
%s : string
%p : pointer
%x : hexadecimal
%o : octal
%u : unsigned int
%ld : long int
%lu : unsigned long int

*/

// Fonction pour échanger les valeurs de deux entiers en utilisant des pointeurs
void echanger(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Fonction pour afficher les éléments d'un tableau
void afficherTableau(int *tableau, int taille) {
  for (int i = 0; i < taille; i++) {
    printf("%d ", *(tableau+i)); // pour renvoyer l'adresse : tableau + i
  }
  printf("\n");
}

int main() {
  // Déclaration et initialisation des variables
  int x = 10;
  int y = 20;

  // Affichage des valeurs avant l'échange
  printf("Avant l'échange: x = %d, y = %d\n", x, y);

  // Appel de la fonction pour échanger les valeurs
  echanger(&x, &y); // & est utilisé pour passer l'adresse des variables et non les valeurs elles-mêmes

  // Affichage des valeurs après l'échange
  printf("Après l'échange: x = %d, y = %d\n", x, y);

  // Déclaration et initialisation d'un tableau
  int tableau[] = {1, 2, 3, 4, 5};
  int taille = sizeof(tableau) / sizeof(tableau[0]);

  // Affichage des éléments du tableau
  printf("Tableau: ");
  afficherTableau(tableau, taille);

  return 0;
}

/*
Pour compiler et exécuter ce code:
1. gcc -o truc truc.c
2. ./truc (ou truc.exe sous Windows)
*/