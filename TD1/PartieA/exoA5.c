#include <stdio.h>

#define pscanf(message, format, variable) \
    do { \
        printf(message); \
        scanf(format, variable); \
    } while(0) // On fait un do while(0) pour pouvoir utiliser le point-virgule à la fin de la macro

int main() {
    int age;
    pscanf("Entrez votre âge : ", "%d", &age);
    printf("Votre âge est : %d\n", age);
    return 0;
}
