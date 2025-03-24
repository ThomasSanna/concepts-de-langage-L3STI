/*
    Documentation section
    @Project TD2 Exercice B.1
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to demonstrate stack overflow
*/


#include <stdio.h>

void recursiveFunction() {
  // La fonction s'appelle elle-même sans condition d'arrêt, ce qui provoque un stackoverflow.
  recursiveFunction();
}

int main() {
  recursiveFunction();
  return 0;
}