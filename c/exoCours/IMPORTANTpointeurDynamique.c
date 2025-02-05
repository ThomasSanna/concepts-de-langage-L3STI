#include <stdio.h>

/*
malloc
La fonction malloc (memory allocation) alloue un bloc de mémoire de la taille spécifiée en octets et retourne un pointeur vers le début de ce bloc. La mémoire allouée n'est pas initialisée, ce qui signifie qu'elle peut contenir des valeurs indéterminées.

calloc
La fonction calloc (contiguous allocation) alloue de la mémoire pour un tableau de num éléments, chacun de taille size octets, et initialise tous les bits à zéro. Elle retourne un pointeur vers le début de la mémoire allouée.

realloc
La fonction realloc (reallocation) redimensionne un bloc de mémoire précédemment alloué par malloc ou calloc. Elle prend un pointeur vers la mémoire allouée et la nouvelle taille en octets. Si la nouvelle taille est plus grande, le contenu de la mémoire existante est préservé et la mémoire supplémentaire est non initialisée. Si la nouvelle taille est plus petite, la mémoire excédentaire est libérée.

free
La fonction free libère un bloc de mémoire précédemment alloué par malloc, calloc ou realloc. Elle prend un pointeur vers la mémoire à libérer. Après avoir libéré la mémoire, le pointeur devient invalide et ne doit plus être utilisé.
*/

int main(void){
  int *ptInt = NULL;
  *ptInt = 10; // ERREUR : Segmentation Fault.
  ptInt = (int *) malloc(sizeof(int));
  printf("1. %p\n", ptInt);
  *ptInt = 20;
  printf("2. %p\n", ptInt);
  printf("3. %d\n", *ptInt);
  free(ptInt);
  *ptInt = 9;
  printf("4. %p\n", ptInt);
  printf("5. %d\n", *ptInt);

  return 0;
}