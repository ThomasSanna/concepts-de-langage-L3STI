/*
    Documentation section
    @Project TD2 Exercice A.1-2
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to simulate dice rolls
*/


#include <stdio.h>
#include "util_rand.h"
#include "dice.h"

int main() {
    int numDice;
    int dice[MAX_DICE];
    int seuil, sum;

    initRand();

    printf("Avec combien de dés voulez-vous jouer ?\n");
    printf("Tapez 1, 2, 3, ou 4 ? ");
    scanf("%d", &numDice);

    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Nombre de dés invalide.\n");
        return 1;
    }

    printf("Vous avez choisi %d dé(s)\n", numDice);

    rollDice(dice, numDice);
    printDice(dice, numDice);

    rerollIdenticalDice(dice, numDice);

    sum = calculateSum(dice, numDice);
    seuil = (numDice * 6 * 2) / 3;

    printf("La somme des %d dés lancés est de %d, le seuil était de %d\n", numDice, sum, seuil);

    if (sum >= seuil) {
        printf("Vous avez gagné avec %d points en plus du seuil.\n", sum - seuil);
    } else {
        printf("Score inférieur de %d au seuil.\n", seuil - sum);
        printf("Vous avez perdu :(\n");
    }

    return 0;
}