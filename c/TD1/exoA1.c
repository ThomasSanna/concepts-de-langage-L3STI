#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isInt(const char *str) {
  if (*str == '-' || *str == '+') str++;
  if (!*str) return 0;
  while (*str) {
    if (!isdigit(*str)) return 0;
    str++;
  }
  return 1;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Mauvais usage : au moins deux paramètres attendus:\n./exoA1.exe param1 param2\n");
    return 1;
  }

  int sum = 0;
  for (int i = 1; i < argc; i++) {
    if (!isInt(argv[i])) {
      printf("Erreur : %s n'est pas un entier valide\n", argv[i]);
      return 1;
    }
    sum += atoi(argv[i]);
    printf("%s\n", argv[i]);
  }
  printf("Somme : %i\n", sum);

  return 0;
}