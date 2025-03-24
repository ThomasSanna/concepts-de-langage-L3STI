/*
    Documentation section
    @Project TD2 Exercice A.1
    @Author SANNA Thomas
    @Created 20250320
    @Program Description, Program to generate random numbers
*/

#include "util_rand.h"

/*
Initialise le générateur de nombres aléatoires en utilisant l'heure actuelle comme graine.
Input : 
    - void : aucune valeur d'entrée
Output :
    - void : aucune valeur de retour
*/
void initRand() {
    srand(time(NULL));
}

/*
Génère un nombre aléatoire compris entre 0 et RAND_MAX (valeur maximale de rand())
(généralement 32767 sur les systèmes 16 bits et 2147483647 sur les systèmes 32 bits).
Input : 
    - void : aucune valeur d'entrée
Output :
    - int : un nombre entier aléatoire compris entre 0 et RAND_MAX
*/
int randIntMax() {
    return rand();
}

/*
Génère un nombre entier aléatoire compris entre 0 et un seuil "seuil haut" donné.
Input : 
    - int SeuilHaut : le seuil supérieur
Output :
    - int : un nombre entier aléatoire compris entre 0 et SeuilHaut
*/
int randIntSeuil(int SeuilHaut) {
    return rand() % (SeuilHaut + 1);
}

/*
Génère un nombre entier aléatoire compris entre deux bornes "seuil bas" et "seuil haut" données.
Input : 
    - int SeuilBas : le seuil inférieur
    - int SeuilHaut : le seuil supérieur
Output :
    - int : un nombre entier aléatoire compris entre SeuilBas et SeuilHaut
*/
int randIntBorne(int SeuilBas, int SeuilHaut) {
    return SeuilBas + rand() % (SeuilHaut - SeuilBas + 1);
}

/*
Génère un nombre réel aléatoire compris entre 0 et 1.
Input : 
    - void : aucune valeur d'entrée
Output :
    - double : un nombre réel aléatoire compris entre 0 et 1
*/
double randDouble() {
    return (double)rand() / RAND_MAX;
}

/*
Génère un nombre réel aléatoire compris entre deux bornes "seuil bas" et "seuil haut" données.
Input : 
    - double SeuilBas : le seuil inférieur
    - double SeuilHaut : le seuil supérieur
Output :
    - double : un nombre réel aléatoire compris entre SeuilBas et SeuilHaut
*/
double randDoubleBorne(double SeuilBas, double SeuilHaut) {
    double Scale = randDouble();
    return SeuilBas + Scale * (SeuilHaut - SeuilBas);
}