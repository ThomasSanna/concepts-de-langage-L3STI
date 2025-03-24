#include <stdio.h>
#include <stdlib.h>

int main() {

  int v10 = 10;
  int v20 = 20;

  void* p10 = NULL;
  void* p20 = NULL;
  void* ptemp = NULL;

  p10 = &v10;
  p20 = &v20;
  ptemp = malloc(sizeof(int));

  *(int*)ptemp = *(int*)p10;
  *(int*)p10 = *(int*)p20;
  *(int*)p20 = *(int*)ptemp;

  free(ptemp);

  printf("v10 : %i, v20 : %i", v10, v20);
}