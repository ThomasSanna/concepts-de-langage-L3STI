/*
    Documentation section
    @Project TD2 Exercice A.2
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to simulate dice rolls
*/

#include <stdio.h>
#include "util_rand.h"
#include "dice.h"

/*
Fonction pour imprimer les valeurs des dés.
Input : 
    - int *dice : tableau contenant les valeurs des dés
    - int numDice : nombre de dés
Output :
    - void : aucune valeur de retour
*/
void printDice(int *dice, int numDice) {
    for (int i = 0; i < numDice; i++) {
        printf("Dé %d : %d\n", i, dice[i]);
    }
}

/*
Fonction pour lancer les dés.
Input : 
    - int *dice : tableau contenant les valeurs des dés
    - int numDice : nombre de dés
Output :
    - void : aucune valeur de retour
*/
void rollDice(int *dice, int numDice) {
    for (int i = 0; i < numDice; i++) {
        dice[i] = randIntSeuil(6);
    }
}

/*
Fonction pour relancer les dés identiques.
Input : 
    - int *dice : tableau contenant les valeurs des dés
    - int numDice : nombre de dés
Output :
    - void : aucune valeur de retour
*/
void rerollIdenticalDice(int *dice, int numDice) {
    int rerolled = 1;
    while (rerolled) {
        rerolled = 0;
        for (int i = 0; i < numDice; i++) {
            for (int j = i + 1; j < numDice; j++) {
                if (dice[i] == dice[j]) {
                    dice[j] = randIntSeuil(6);
                    printf("Relance du dé %d car il est identique au dé %d\n", j, i);
                    printDice(dice, numDice);
                    rerolled = 1;
                }
            }
        }
    }
}

/*
Fonction pour calculer la somme des dés.
Input : 
    - int *dice : tableau contenant les valeurs des dés
    - int numDice : nombre de dés
Output :
    - int : somme des valeurs des dés
*/
int calculateSum(int *dice, int numDice) {
    int sum = 0;
    for (int i = 0; i < numDice; i++) {
        sum += dice[i];
    }
    return sum;
}