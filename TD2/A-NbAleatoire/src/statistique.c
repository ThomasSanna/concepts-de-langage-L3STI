/*
    Documentation section
    @Project TD2 Exercice A.3
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to test the distribution of random numbers generated by randIntSeuil
*/


#include <stdio.h>
#include <stdlib.h>
#include "util_rand.h"

/*
Fonction pour tester la distribution des valeurs générées par randIntSeuil sur un grand nombre d'essais.
Cette fonction génère un certain nombre (ici fixé à 100000) de valeurs aléatoires (fixés entre 0 et 5) et compte combien de fois chaque valeur est générée.
Elle affiche ensuite la distribution des valeurs sous forme de pourcentage.
*/
void testRandDistribution() {
  int counts[6] = {0};
  int numTrials = 100000;

  for (int i = 0; i < numTrials; i++) {
      int result = randIntSeuil(5);
      counts[result]++;
  }

  printf("Distribution des valeurs générées sur %d essais:\n", numTrials);
  for (int i = 0; i < 6; i++) {
      printf("Valeur %d: %.2f%%\n", i, (counts[i] / (double)numTrials) * 100);
  }
}

/*
Fonction principale
*/
int main() {
  initRand();
  testRandDistribution();
  return 0;
}