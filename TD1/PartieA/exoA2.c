#include <stdio.h>

int main() {
    float Nlv, Nf, Nm, Np;

    // Demander à l'utilisateur de saisir les notes
    printf("Entrez la note de littérature : ");
    scanf("%f", &Nlv);
    printf("Entrez la note de français : ");
    scanf("%f", &Nf);
    printf("Entrez la note de mathématiques : ");
    scanf("%f", &Nm);
    printf("Entrez la note de physique : ");
    scanf("%f", &Np);

    float moyenne = (Nlv + Nf + Nm + Np) / 4.0;

    // Vérifier les conditions et afficher les résultats
    printf("Condition 1 (moyenne > 10) : %s\n", (moyenne > 10) ? "Vrai" : "Faux");
    printf("Condition 2 (math et français > moyenne) : %s\n", (Nm > moyenne && Nf > moyenne) ? "Vrai" : "Faux");
    printf("Condition 3 (au moins une note > 10) : %s\n", (Nlv > 10 || Nf > 10 || Nm > 10 || Np > 10) ? "Vrai" : "Faux");
    printf("Condition 4 (toutes les notes > 10) : %s\n", (Nlv > 10 && Nf > 10 && Nm > 10 && Np > 10) ? "Vrai" : "Faux");
    printf("Condition 5 (moyenne littéraire ou scientifique == 10) : %s\n",
           ((Nlv + Nf) / 2.0 == 10 || (Nm + Np) / 2.0 == 10) ? "Vrai" : "Faux");
    printf("Condition 6 (moyenne >= 10 et au plus un type == 10) : %s\n",
           (moyenne >= 10 && (((Nlv + Nf) / 2.0 == 10) ^ ((Nm + Np) / 2.0 == 10))) ? "Vrai" : "Faux");

    return 0;
}