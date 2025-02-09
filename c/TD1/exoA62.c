#include <stdio.h>
#include <ncurses.h>

void chiffrer_et_afficher(char c, int cle) {
    putchar(c + cle);
}

int main() {
    char c;
    int cle;

    printf("Entrez une clé : ");
    scanf("%d", &cle);
    printf("Entrez un mot (finir avec Ctrl+D) : ");

    while ((c = getchar()) != EOF) {
        chiffrer_et_afficher(c, cle);
    }

    return 0;
}