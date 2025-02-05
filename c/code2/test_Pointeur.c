#include <stddef.h>

int main(void) {
  int val = 4;
  int val2 = 6;
  int *ptrVal = NULL; // bonnes pratiquss : Mettre null avant l'assignation d'un pointeur à une variable. A null, ptrVal = 0000000000000000.
  printf("%p\n",ptrVal);
  int *ptrVal2 = &val2;
  ptrVal = &val; 
  *ptrVal = *ptrVal2;
  printf("%i\n", val); // val deviens val2
  return 0;
}