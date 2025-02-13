#include<stdio.h>
#include<stdlib.h>

void swap_int(void* p1, void* p2, int size ) {
  void* ptemp = malloc(size);

  *ptemp = *p1;
  *p1 = *p2;
  *p2 = *ptemp;

  free(ptemp);

}

int main(){

  char c1 = "i";
  char c2 = "t";
  int size = sizeof(char);
  swap_int(&c1, &c2, size);

  printf("c1 : %c, c2 : %i", c1, c2);

  int i1 = 2;
  int i2 = 3;
  int size = sizeof(int);
  swap_int(&i1, &i2, size);

  printf("i1 : %i, i2 : %i", i1, i2);

} 