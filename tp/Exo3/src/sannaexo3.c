#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // Pour INT_MAX

/*
J'ai choisi d'utiliser un tableau dynamique pour stocker les horaires de train, car cela permet de gérer facilement un nombre variable d'horaires sans avoir à définir une taille fixe à l'avance.
On préfère un tableau dynamique qu'une liste chainée car la liste chainée est plus complexe à gérer et nécessite plus de mémoire pour stocker les pointeurs.
On peut facilement redimensionner le tableau dynamique si nécessaire, ce qui est plus simple que de gérer la mémoire pour une liste chainée.
un tableau dynamique permet un accès direct aux éléments, ce qui est plus rapide que de parcourir une liste chainée.
*/

/*
Structures de données utilisées :
- Horaire : pour stocker les informations d'un horaire de train (ville de départ, ville d'arrivée, heure de départ, heure d'arrivée, distance).
- ListeHoraires : pour stocker un tableau dynamique d'horaires de train, ainsi que la taille actuelle et la capacité du tableau.
Fonctions principales :
- initialiserListe : pour initialiser la liste d'horaires avec une capacité initiale.
- ajouterHoraire : pour ajouter un horaire à la liste, en redimensionnant le tableau si nécessaire.
- afficherHoraires : pour afficher tous les horaires de la liste.
*/

/*
Structure d'horaire :
- Ville de départ (string)
- Ville d'arrivée (string)
- Heure de départ (string au format HHMM)
- Heure d'arrivée (string au format HHMM)
- Distance (int)
*/
typedef struct {
    char ville_depart[50];  // Ville de départ
    char ville_arrivee[50]; // Ville d'arrivée
    char heure_depart[6];   // Heure de départ au format HHMM
    char heure_arrivee[6];  // Heure d'arrivée au format HHMM
    int distance;           // Distance entre les deux villes en kilomètres
} Horaire;

/*
Structure de liste d'horaires :
- Tableau dynamique d'horaires
- Taille actuelle du tableau
- Capacité actuelle du tableau
*/
typedef struct {
    Horaire *horaires; // Tableau dynamique d'horaires
    int taille;        // Nombre d'horaires dans la liste
    int capacite;      // Capacité actuelle du tableau
} ListeHoraires;

/*
Initialise la liste d'horaires avec une capacité initiale.
@param liste : pointeur vers la liste d'horaires à initialiser
@param capacite_initiale : capacité initiale du tableau d'horaires
*/
void initialiserListe(ListeHoraires *liste, int capacite_initiale) {
    liste->horaires = (Horaire *)malloc(capacite_initiale * sizeof(Horaire));
    liste->taille = 0;
    liste->capacite = capacite_initiale;
}

/*
Ajoute un horaire à la liste d'horaires.
@param liste : pointeur vers la liste d'horaires
@param horaire : horaire à ajouter à la liste
*/
void ajouterHoraire(ListeHoraires *liste, Horaire horaire) {
    if (liste->taille == liste->capacite) {
        // Augmenter la capacité du tableau si nécessaire
        // Il est préférable de doubler (par exemple) plutôt que d'augmenter de 1
        // pour éviter de réallouer trop souvent la mémoire, et, en conséquence, recopier les données dans le tableau
        liste->capacite *= 2;
        liste->horaires = (Horaire *)realloc(liste->horaires, liste->capacite * sizeof(Horaire));
    }
    liste->horaires[liste->taille++] = horaire;
}

/*
Affiche tous les horaires de la liste.
@param liste : pointeur vers la liste d'horaires
*/
void afficherHoraires(ListeHoraires *liste) {
    for (int i = 0; i < liste->taille; i++) {
        printf("De %s à %s, départ à %s, arrivée à %s, distance: %d km\n",
               liste->horaires[i].ville_depart,
               liste->horaires[i].ville_arrivee,
               liste->horaires[i].heure_depart,
               liste->horaires[i].heure_arrivee,
               liste->horaires[i].distance);
    }
}

/*
Question 2.
Demande à l'utilisateur d'entrer des horaires de train.
@param liste : pointeur vers la liste d'horaires
*/
void demanderHoraires(ListeHoraires *liste) {
    int n;
    printf("Combien d'horaires voulez-vous entrer ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char villeArrivee[50];
        char villeDepart[50];
        char heureDepart[6];
        char heureArrivee[6];
        int distance;
        printf("Horaire %d:\n", i + 1);
        printf("Ville de départ (stop pour quitter): ");
        scanf("%s", villeDepart);
        if (strcmp(villeDepart, "stop") == 0) {
            break;
        }
        printf("Ville d'arrivée: ");
        scanf("%s", villeArrivee);
        printf("Heure de départ (XXhXX): ");
        scanf("%s", heureDepart);
        printf("Heure d'arrivée (XXhXX): ");
        scanf("%s", heureArrivee);
        printf("Distance (km): ");
        scanf("%d", &distance);

        /*
        Vérification des entrées :
        - La ville de départ et d'arrivée ne peuvent pas être identiques.
        - Le nom de la ville ne peut pas dépasser 50 caractères.
        - La distance doit être positive.
        - L'heure doit être au format XXhXX (5 caractères).
        */
        if (strcmp(villeDepart, villeArrivee) == 0) {
            printf("Erreur: La ville de départ et d'arrivée ne peuvent pas être identiques.\n");
            i--;
            continue;
        }
        if (strlen(villeDepart) > 50 || strlen(villeArrivee) > 50) {
            printf("Erreur: Le nom de la ville ne peut pas dépasser 50 caractères.\n");
            i--;
            continue;
        }
        if (distance <= 0) {
            printf("Erreur: La distance doit être positive.\n");
            i--;
            continue;
        }
        if (strlen(heureDepart) != 5 || strlen(heureArrivee) != 5) {
            printf("Erreur: L'heure doit être au format XXhXX.\n");
            i--;
            continue;
        }

        // Ajout de l'horaire à la liste
        Horaire horaire;
        strcpy(horaire.ville_depart, villeDepart);
        strcpy(horaire.ville_arrivee, villeArrivee);
        strcpy(horaire.heure_depart, heureDepart);
        strcpy(horaire.heure_arrivee, heureArrivee);
        horaire.distance = distance;


        ajouterHoraire(liste, horaire);

        printf("Horaire ajouté avec succès !\n");
    }
}

/*
Question 3.
Affiche les horaires tous les trains au départ d'une ville donnée.
@param liste : pointeur vers la liste d'horaires
@param ville : ville de départ
*/
void afficherHorairesUsingVilleDepart(ListeHoraires *liste, char *ville) {
    printf("Horaires au départ de %s:\n", ville);
    for(int i=0; i<liste->taille; i++){
        if(strcmp(liste->horaires[i].ville_depart, ville) == 0){
            printf("De %s à %s, départ à %s, arrivée à %s, distance: %d km\n",
                liste->horaires[i].ville_depart,
                liste->horaires[i].ville_arrivee,
                liste->horaires[i].heure_depart,
                liste->horaires[i].heure_arrivee,
                liste->horaires[i].distance);
        }
    }
}

/*
Question 4.
Determine le trajet avec la vitesse moyenne la plus élevée.
@param liste : pointeur vers la liste d'horaires
*/
void afficherTrajetPlusRapide(ListeHoraires *liste) {
    if (liste->taille == 0) {
        printf("Aucun horaire disponible.\n");
        return;
    }

    int maxVitesse = 0;
    Horaire meilleurHoraire;

    for(int i=0; i<liste->taille; i++){

        // Conversion des heures de départ et d'arrivée en entiers
        int heureDepart = (liste->horaires[i].heure_depart[0] - '0') * 10 + (liste->horaires[i].heure_depart[1] - '0');
        int minuteDepart = (liste->horaires[i].heure_depart[3] - '0') * 10 + (liste->horaires[i].heure_depart[4] - '0');
        int heureArrivee = (liste->horaires[i].heure_arrivee[0] - '0') * 10 + (liste->horaires[i].heure_arrivee[1] - '0');
        int minuteArrivee = (liste->horaires[i].heure_arrivee[3] - '0') * 10 + (liste->horaires[i].heure_arrivee[4] - '0');

        /* 
            Autre convertion possibles :
            Avec atoi() :
            On met dans un char le premier caractère de l'heure, puis on met dans un autre char le second caractère de l'heure, et on les convertit en int avec atoi().
        */
        // char heureDepartStr[3] = {liste->horaires[i].heure_depart[0], liste->horaires[i].heure_depart[1], '\0'};
        // char minuteDepartStr[3] = {liste->horaires[i].heure_depart[3], liste->horaires[i].heure_depart[4], '\0'};
        // int heureDepart = atoi(heureDepartStr);
        // int minuteDepart = atoi(minuteDepartStr);

        // char heureArriveeStr[3] = {liste->horaires[i].heure_arrivee[0], liste->horaires[i].heure_arrivee[1], '\0'};
        // char minuteArriveeStr[3] = {liste->horaires[i].heure_arrivee[3], liste->horaires[i].heure_arrivee[4], '\0'};
        // int heureArrivee = atoi(heureArriveeStr);
        // int minuteArrivee = atoi(minuteArriveeStr);

        /*
            Autre convertion possibles :
            Avec sscanf() :
                "%2d%*1c%2d" :
                - %2d : lit 2 chiffres et les stocke dans une variable entière (heure)
                - %*1c : lit 1 caractère (le 'h') mais ne le stocke pas (* signifie "ignorer")
                - %2d : lit 2 chiffres et les stocke dans une autre variable entière (minute)
        */
        // int heureDepart, minuteDepart, heureArrivee, minuteArrivee;
        // sscanf(liste->horaires[i].heure_depart, "%2d%*1c%2d", &heureDepart, &minuteDepart);
        // sscanf(liste->horaires[i].heure_arrivee, "%2d%*1c%2d", &heureArrivee, &minuteArrivee);


        // Calcul du temps total en minutes (heure d'arrivée - heure de départ)
        int tempsTotal = (heureArrivee * 60 + minuteArrivee) - (heureDepart * 60 + minuteDepart);
        // Calcul de la vitesse
        // Vitesse = distance / temps :)
        int vitesse = (liste->horaires[i].distance / tempsTotal) * 60; // Vitesse en km/h

        if(vitesse > maxVitesse){
            maxVitesse = vitesse;
            meilleurHoraire = liste->horaires[i];
        }
    }


    printf("Le trajet le plus rapide est de %s à %s, départ à %s, arrivée à %s, distance: %d km, vitesse: %d km/h\n",
           meilleurHoraire.ville_depart,
           meilleurHoraire.ville_arrivee,
           meilleurHoraire.heure_depart,
           meilleurHoraire.heure_arrivee,
           meilleurHoraire.distance,
           maxVitesse);
}

/*
Question 5.
Trie les horaires par ordre croissant de l'heure de départ.
Algorithme de tri à bulles.
@param liste : pointeur vers la liste d'horaires
*/
void trierHoraires(ListeHoraires *liste) {
    for (int i = 0; i < liste->taille - 1; i++) {
        for (int j = 0; j < liste->taille - i - 1; j++) {
            // Comparaison des heures de départ
            if (strcmp(liste->horaires[j].heure_depart, liste->horaires[j + 1].heure_depart) > 0) {
                // Échange des horaires
                Horaire temp = liste->horaires[j];
                liste->horaires[j] = liste->horaires[j + 1];
                liste->horaires[j + 1] = temp;
            }
        }
    }
}

/*
Détermine le moyen le plus rapide pour aller d'une ville à une autre avec au plus une correspondance.
@param liste : pointeur vers la liste d'horaires
@param vd : ville de départ
@param va : ville d'arrivée
*/
void trouverMoyenLePlusRapide(ListeHoraires *liste, char *vd, char *va) {
    Horaire direct;
    Horaire correspondance1;
    Horaire correspondance2;
    int directFound = 0;
    int correspondanceFound = 0;
    int minTemps = INT_MAX;

    for (int i = 0; i < liste->taille; i++) {

        if (strcmp(liste->horaires[i].ville_depart, vd) == 0 && strcmp(liste->horaires[i].ville_arrivee, va) == 0) {
            int heureDepart = (liste->horaires[i].heure_depart[0] - '0') * 10 + (liste->horaires[i].heure_depart[1] - '0');
            int minuteDepart = (liste->horaires[i].heure_depart[3] - '0') * 10 + (liste->horaires[i].heure_depart[4] - '0');
            int heureArrivee = (liste->horaires[i].heure_arrivee[0] - '0') * 10 + (liste->horaires[i].heure_arrivee[1] - '0');
            int minuteArrivee = (liste->horaires[i].heure_arrivee[3] - '0') * 10 + (liste->horaires[i].heure_arrivee[4] - '0');
            int tempsTotal = (heureArrivee * 60 + minuteArrivee) - (heureDepart * 60 + minuteDepart);

            if (tempsTotal < minTemps) {
                minTemps = tempsTotal;
                direct = liste->horaires[i];
                directFound = 1;
                correspondanceFound = 0;
            }
        }

        if (strcmp(liste->horaires[i].ville_depart, vd) == 0) {
            for (int j = 0; j < liste->taille; j++) {
                if (strcmp(liste->horaires[j].ville_depart, liste->horaires[i].ville_arrivee) == 0 && strcmp(liste->horaires[j].ville_arrivee, va) == 0) {
                    int heureArrivee1 = (liste->horaires[i].heure_arrivee[0] - '0') * 10 + (liste->horaires[i].heure_arrivee[1] - '0');
                    int minuteArrivee1 = (liste->horaires[i].heure_arrivee[3] - '0') * 10 + (liste->horaires[i].heure_arrivee[4] - '0');
                    int heureDepart2 = (liste->horaires[j].heure_depart[0] - '0') * 10 + (liste->horaires[j].heure_depart[1] - '0');
                    int minuteDepart2 = (liste->horaires[j].heure_depart[3] - '0') * 10 + (liste->horaires[j].heure_depart[4] - '0');
                    int tempsCorrespondance = (heureDepart2 * 60 + minuteDepart2) - (heureArrivee1 * 60 + minuteArrivee1);

                    if (tempsCorrespondance >= 5 && tempsCorrespondance <= 120) {
                        int heureDepart1 = (liste->horaires[i].heure_depart[0] - '0') * 10 + (liste->horaires[i].heure_depart[1] - '0');
                        int minuteDepart1 = (liste->horaires[i].heure_depart[3] - '0') * 10 + (liste->horaires[i].heure_depart[4] - '0');
                        int heureArrivee2 = (liste->horaires[j].heure_arrivee[0] - '0') * 10 + (liste->horaires[j].heure_arrivee[1] - '0');
                        int minuteArrivee2 = (liste->horaires[j].heure_arrivee[3] - '0') * 10 + (liste->horaires[j].heure_arrivee[4] - '0');
                        int tempsTotal = (heureArrivee2 * 60 + minuteArrivee2) - (heureDepart1 * 60 + minuteDepart1);

                        if (tempsTotal < minTemps) {
                            minTemps = tempsTotal;
                            correspondance1 = liste->horaires[i];
                            correspondance2 = liste->horaires[j];
                            correspondanceFound = 1;
                            directFound = 0;
                        }
                    }
                }
            }
        }
    }

    if (directFound) {
        printf("Le moyen le plus rapide est un trajet direct de %s à %s, départ à %s, arrivée à %s, temps total: %d minutes\n",
               direct.ville_depart, direct.ville_arrivee, direct.heure_depart, direct.heure_arrivee, minTemps);
    } else if (correspondanceFound) {
        printf("Le moyen le plus rapide est un trajet avec correspondance:\n");
        printf("1. De %s à %s, départ à %s, arrivée à %s\n", correspondance1.ville_depart, correspondance1.ville_arrivee, correspondance1.heure_depart, correspondance1.heure_arrivee);
        printf("2. De %s à %s, départ à %s, arrivée à %s\n", correspondance2.ville_depart, correspondance2.ville_arrivee, correspondance2.heure_depart, correspondance2.heure_arrivee);
        printf("Temps total: %d minutes\n", minTemps);
    } else {
        printf("Aucun trajet disponible de %s à %s\n", vd, va);
    }
}


/*
Fonction principale
*/
int main() {
    ListeHoraires liste;
    initialiserListe(&liste, 5);

    Horaire h1 = {"Lille", "Paris", "08h00", "08h59", 237};
    Horaire h2 = {"Lille", "Lyon", "07h00", "10h00", 709};
    Horaire h3 = {"Paris", "Marseille", "12h00", "18h00", 900};
    Horaire h4 = {"Lyon", "Marseille", "10h07", "15h01", 450};
    Horaire h5 = {"Lille", "Calais", "15h19", "18h34", 110};
    Horaire h6 = {"Lyon", "Marseille", "11h50", "17h00", 450};

    // Question 2.
    printf("\nQuestion 2 :\n");
    demanderHoraires(&liste);

    ajouterHoraire(&liste, h1);
    ajouterHoraire(&liste, h2);
    ajouterHoraire(&liste, h3);
    ajouterHoraire(&liste, h4);
    ajouterHoraire(&liste, h5);
    ajouterHoraire(&liste, h6);

    afficherHoraires(&liste);

    // Question 3.
    printf("\nQuestion 3 :\n");
    afficherHorairesUsingVilleDepart(&liste, "Lille");

    // Question 4.
    printf("\nQuestion 4 :\n");
    afficherTrajetPlusRapide(&liste);

    // Question 5.
    printf("\nQuestion 5 :\n");
    trierHoraires(&liste);
    printf("Horaires triés par ordre croissant de l'heure de départ:\n");
    afficherHoraires(&liste);

    // Question 6.
    printf("\nQuestion 6 :\n");
    trouverMoyenLePlusRapide(&liste, "Lille", "Marseille");

    // Libérer la mémoire allouée
    free(liste.horaires);

    return 0;
}