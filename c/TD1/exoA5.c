#include <stdio.h>

#define pscanf(message, format, variable) \
    do { \
        printf(message); \
        scanf(format, variable); \
    } while(0)

int main() {
    int age;
    pscanf("Entrez votre âge : ", "%d", &age);
    printf("Votre âge est : %d\n", age);
    return 0;
}