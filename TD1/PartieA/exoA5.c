#include <stdio.h>

#define pscanf(message, format, variable) \
    do { \
        printf(message); \
        scanf(format, variable); \
    } while(0) // On fait un do while(0) pour pouvoir utiliser le point-virgule à la fin de la macro
//NB : Les antislash indiquent que la definition de la macro continue sur plusieurs lignes, sinon on aurait du tout mettre sur une ligne

int main() {
    int age;
    pscanf("Entrez votre âge : ", "%d", &age);
    printf("Votre âge est : %d\n", age);
    return 0;
}
