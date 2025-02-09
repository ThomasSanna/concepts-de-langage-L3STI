#include <stdio.h>

void convertir_en_romain(int nombre) {
    while (nombre >= 1000) { printf("M"); nombre -= 1000; }
    while (nombre >= 900) { printf("CM"); nombre -= 900; }
    while (nombre >= 500) { printf("D"); nombre -= 500; }
    while (nombre >= 400) { printf("CD"); nombre -= 400; }
    while (nombre >= 100) { printf("C"); nombre -= 100; }
    while (nombre >= 90) { printf("XC"); nombre -= 90; }
    while (nombre >= 50) { printf("L"); nombre -= 50; }
    while (nombre >= 40) { printf("XL"); nombre -= 40; }
    while (nombre >= 10) { printf("X"); nombre -= 10; }
    while (nombre >= 9) { printf("IX"); nombre -= 9; }
    while (nombre >= 5) { printf("V"); nombre -= 5; }
    while (nombre >= 4) { printf("IV"); nombre -= 4; }
    while (nombre >= 1) { printf("I"); nombre -= 1; }
    printf("\n");
}

int main() {
    int nombre;
    printf("Entrez un nombre entier : ");
    scanf("%d", &nombre);
    convertir_en_romain(nombre);
    return 0;
}