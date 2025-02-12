#include <stdio.h>

void chiffrer(char *mot, int cle) {
    for (int i = 0; mot[i] != '\0'; i++) {
        mot[i] = mot[i] + cle;
    }
}

void dechiffrer(char *mot, int cle) {
    for (int i = 0; mot[i] != '\0'; i++) {
        mot[i] = mot[i] - cle;
    }
}

int main() {
    char mot[100];
    int cle;

    printf("Entrez un mot : ");
    scanf("%s", mot);
    printf("Entrez une clé : ");
    scanf("%d", &cle);

    chiffrer(mot, cle);
    printf("Mot chiffré : %s\n", mot);

    dechiffrer(mot, cle);
    printf("Mot déchiffré : %s\n", mot);

    return 0;
}