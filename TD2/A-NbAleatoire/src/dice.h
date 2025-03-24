#ifndef DES_H
#define DES_H

#define MAX_DICE 4

void printDice(int *dice, int numDice);
void rollDice(int *dice, int numDice);
void rerollIdenticalDice(int *dice, int numDice);
int calculateSum(int *dice, int numDice);

#endif // DES_H