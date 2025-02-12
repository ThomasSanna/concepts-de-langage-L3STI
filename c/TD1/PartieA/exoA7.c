#include <stdio.h>

void convertir_en_romain(int nombre) {
    int valeurs[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symboles[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    for (int i = 0; i < 13; i++) {
        while (nombre >= valeurs[i]) {
            printf("%s", symboles[i]);
            nombre -= valeurs[i];
        }
    }
    printf("\n");
}

int main() {
    int nombre;
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);
    convertir_en_romain(nombre);
    return 0;
}