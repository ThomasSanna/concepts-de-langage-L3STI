#include <stdio.h>
#include <stdlib.h>

int main() {
  // Ce programme échange les valeurs de deux variables entières (v10 et v20) en utilisant des pointeurs génériques (void*).
  // 1. Les variables v10 et v20 sont initialisées avec les valeurs 10 et 20 respectivement.
  // 2. Des pointeurs génériques (void*) sont utilisés pour manipuler les adresses des variables.
  // 3. Un espace mémoire est alloué dynamiquement avec malloc pour servir de tampon temporaire (ptemp).
  // 4. Les valeurs des variables sont échangées en utilisant des conversions de type (cast) pour accéder aux données via les pointeurs.
  // 5. La mémoire allouée dynamiquement est libérée avec free pour éviter les fuites mémoire.
  // 6. Enfin, les nouvelles valeurs de v10 et v20 sont affichées à l'écran.

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