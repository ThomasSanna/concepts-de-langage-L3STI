/*
    Documentation section
    @Project TP1 Exercice 2
    @Author Sanna Thomas
    @Created 20250319
    @Program Description, Program to create a stack and manipulate it
*/



#include "sannaexo2.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

/*
    Initialise une pile vide
    @input : pointeur vers la pile
    @output : void
*/
void initStack(Stack* stack) {
    stack->top = NULL;
}


/*
    Vérifie si la pile est vide
    @input : pointeur vers la pile
    @output : true si la pile est vide, false sinon
*/
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

/*
    Empile un nouvel élément dans la pile
    @input : pointeur vers la pile, valeur entière à empiler
    @output : void
*/
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nb = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Fonction pour récupérer la valeur de l'élément au sommet de la pile
/*
    Récupère la valeur de l'élément au sommet de la pile sans le dépiler
    @input : pointeur vers la pile
    @output : valeur entière au sommet de la pile
*/
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pile est vide\n");
        exit(1);
    }
    return stack->top->nb;
}

// Fonction pour récupérer et enlever l'élément au sommet de la pile
/*
  Dépile l'élément au sommet de la pile et retourne sa valeur
  @input : pointeur vers la pile
  @output : valeur entière dépilée
*/
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pile est vide\n");
        exit(1);
    }
    // Stocke le nœud au sommet de la pile dans une variable Node temporaire
    Node* temp = stack->top;
    // poppedValue ne servira qu'à retourner la valeur du sommet qui a été dépilé
    int poppedValue = temp->nb;
    // Déplace le sommet de la pile vers le nœud suivant
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

/*
Renverse une liste d'entiers et affiche la liste renversée en utilisant une pile
@input : pointeur vers un tableau d'entiers, taille du tableau
@output : void
*/
void reverseAndPrint(int* array, int size) {
    Stack stack;
    initStack(&stack);

    // Empile tous les éléments du tableau
    for (int i = 0; i < size; i++) {
        push(&stack, array[i]);
    }

    // Dépile tous les éléments et les affiche
    printf("Liste renversée: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}