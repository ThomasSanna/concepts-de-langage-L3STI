#include <stdio.h>

int main() {
    char c1, c2, c3;
    printf("Entrez trois caractères : ");
    scanf(" %c %c %c", &c1, &c2, &c3);
    printf("Vous avez saisi : %c, %c, %c\n", c1, c2, c3);
    return 0;
}