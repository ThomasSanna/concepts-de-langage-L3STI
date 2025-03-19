#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Définition de la structure de la pile
typedef struct Node {
    int nb;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// Déclarations des fonctions
void initStack(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int value);
int peek(Stack* stack);
int pop(Stack* stack);
void reverseAndPrint(int* array, int size);

#endif // STACK_H