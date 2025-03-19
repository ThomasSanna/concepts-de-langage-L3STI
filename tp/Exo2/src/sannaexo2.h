#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Définition de la structure de la pile
/*
    Structure représentant un nœud de la pile
    @member nb : entier stocké dans le nœud
    @member next : pointeur vers le nœud suivant
*/
typedef struct Node {
    int nb;
    struct Node* next;
} Node;

/*
    Structure représentant la pile
    @member top : pointeur vers le nœud au sommet de la pile
*/
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