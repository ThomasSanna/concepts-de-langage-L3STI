#include<stdio.h>
#include<stdlib.h>

void swap_int(int* p1, int* p2) {

  int vTemp = *p1;
  *p1 = *p2;
  *p2 = vTemp;

}

int main(){

  int v10 = 10;
  int v20 = 20;

  swap_int(&v10, &v20);

  printf("v10 : %i, v20 : %i", v10, v20);

  return 0;
} 