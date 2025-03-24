#ifndef UTIL_RAND_H
#define UTIL_RAND_H

#include <stdlib.h>
#include <time.h>

void initRand();
int randIntMax();
int randIntSeuil(int seuil_haut);
int randIntBorne(int seuil_bas, int seuil_haut);
double randDouble();
double randDoubleBorne(double seuil_bas, double seuil_haut);

#endif // UTIL_RAND_H