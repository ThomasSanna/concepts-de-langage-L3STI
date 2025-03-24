#include "sannaexo2.h"
#include <stdio.h>

int main() {

    // test : initialisation de la pile
    Stack stack;
    initStack(&stack);

    // test : empiler des entiers
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // test : afficher le sommet de la pile
    printf("Sommet de la pile: %d\n", peek(&stack)); 
    // test : dépiler un entier
    printf("Dépiler: %d\n", pop(&stack));
    printf("Sommet de la pile après dépilement: %d\n", peek(&stack));

    while (!isEmpty(&stack)) { // on libère la mémoire !
        pop(&stack);
    }

    // test : renverser et afficher une liste d'entiers
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    reverseAndPrint(array, size);

    return 0;
}