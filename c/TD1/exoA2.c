#include <stdio.h>

int main() {
    float Nlv, Nf, Nm, Np;
    float moyenne = (Nlv + Nf + Nm + Np) / 4.0;

    // 1) La moyenne des quatre notes est supérieure à 10
    int condition1 = (moyenne > 10);

    // 2) Les notes de mathématiques et de français sont supérieures à la moyenne des quatre notes
    int condition2 = (Nm > moyenne) && (Nf > moyenne);

    // 3) Il y a au moins une note supérieure à 10
    int condition3 = (Nlv > 10) || (Nf > 10) || (Nm > 10) || (Np > 10);

    // 4) Toutes les notes sont supérieures à 10
    int condition4 = (Nlv > 10) && (Nf > 10) && (Nm > 10) && (Np > 10);

    // 5) La moyenne (10) est obtenue pour l'un des deux types (littéraire et scientifique)
    int condition5 = ((Nlv + Nf) / 2.0 == 10) || ((Nm + Np) / 2.0 == 10);

    // 6) La moyenne des quatre notes est supérieure ou égale à 10 et la moyenne (10) est obtenue pour au plus l'un des deux types
    int condition6 = (moyenne >= 10) && (((Nlv + Nf) / 2.0 == 10) ^ ((Nm + Np) / 2.0 == 10));

    return 0;
}