# Notes

## Pourquoi vérifier si un langage de programmation est compilé ou interprété ?

### Sécurité

- Les langages compilés sont plus sécurisés car ils sont convertis en langage machine avant l'exécution. Cela signifie que les utilisateurs ne peuvent pas voir le code source.
- Les langages interprétés sont moins sécurisés car on peut remonter au code source en retro-ingénierie. La méthode de protection est l'**obfuscation**.

### Performances

- Les langages compilés sont généralement plus rapides que les langages interprétés car le code est converti en langage machine avant l'exécution.
- Les langages interprétés sont généralement plus lents car le code est converti en langage machine pendant exécution.

### Portabilité

- Les langages interprétés sont généralement plus portables que les langages compilés car ils peuvent être exécutés sur n'importe quelle plateforme qui a un interpréteur pour ce langage.
- Les langages compilés sont généralement moins portables car ils doivent être compilés pour chaque plateforme cible.

## <u>Criteres propres</u> d'un langage de programmaion

- Structure de controle
- Interpretation ou Compilation pour générer du code executable
- Possède procédures et fonctions, sous-programes, abstraction procédurale.
- Peut simuler une machine de Turing ou est Church compatible/Lambda Calcul
- Gérer des entrées/sorties.

## Machine de Turing et Langages de programmation impératif

- La machine de Turing est un modèle mathématique d'un ordinateur. Elle est composée d'une bande infinie divisée en cases, d'une tête de lecture/écriture et d'un programme qui définit les actions à effectuer en fonction de l'état courant de la machine.
- **Tout langage de programmation impératif peut être traduit en langage machine, c'est-à-dire en instructions exécutables par une machine de Turing.**

## Impératif/Turing, Déclaratif/Church-Lambda Calculus

- **Impératif/Turing** : Les langages de programmation impératifs sont basés sur le modèle de la machine de Turing. Ils décrivent les étapes à suivre pour atteindre un résultat.
- **Exemple** : C, Java, Python sont des langages de programmation impératifs. On décrit les étapes à suivre pour obtenir un résultat.

- **Déclaratif/Church-Lambda Calculus** : Les langages de programmation déclaratifs sont basés sur le modèle du lambda-calcul de Church. Ils décrivent le résultat à atteindre sans spécifier les étapes pour y parvenir.
- **Exemple** : Prolog, Lisp, Haskell sont des langages de programmation déclaratifs. On décrit le résultat à atteindre sans spécifier les étapes pour y parvenir.

## Structure de donées

### Linéaires

- **Definition** : Les structures de données linéaires sont des structures de données dans lesquelles les éléments sont organisés de manière séquentielle.

- **Exemples** : Tableaux, listes chaînées, piles, files.

### Non-linéaires

- **Definition** : Les structures de données non linéaires sont des structures de données dans lesquelles les éléments ne sont pas organisés de manière séquentielle.

- **Exemples** : Arbres, graphes.

## IA Connexionniste (apprentissage) et IA Symbolique (raisonnement)

- **IA Connexionniste** : L'IA connexionniste est basée sur le modèle du cerveau humain. Elle est composée de neurones artificiels qui sont connectés entre eux pour former un réseau de neurones. L'IA connexionniste est utilisée pour résoudre des problèmes complexes tels que la reconnaissance d'images, la traduction automatique, etc..
- **Exemple** : Réseaux de neurones artificiels. **Basé sur l'apprentissage supervisé.**

- **IA Symbolique** : L'IA symbolique est basée sur la logique symbolique. Elle est composée de symboles et de règles logiques qui permettent de résoudre des problèmes de manière formelle. L'IA symbolique est utilisée pour résoudre des problèmes de raisonnement, de planification, etc..
- **Exemple** : Systèmes experts. **Basé sur le raisonnement.**

## Definition Règle d'inference

- **Definition** : Une règle d'inférence est une règle logique qui permet de déduire une conclusion à partir de prémisses.
- Utilisé en programmation logique pour déduire des faits à partir de règles logiques, en utilisant l'IA Symbolique. (Regle : Tout **homme** est **mortel**. Fait : **Socrate** est un **homme**. Conclusion : **Socrate** est **mortel**.)

## Syntaxe vs Sémantique

- **Syntaxe** : La syntaxe d'un langage de programmation définit les règles pour écrire des programmes dans ce langage. Elle concerne la structure des programmes, les mots-clés, les opérateurs, etc..
- **Exemple** : En Python, l'indentation est importante pour définir les blocs de code.

- **Sémantique** : La sémantique d'un langage de programmation définit le sens des programmes écrits dans ce langage. Elle concerne le comportement des programmes, les opérations effectuées, etc..
- **Exemple** : En Python, l'opérateur "+" est utilisé pour l'addition des nombres.

- Syntaxe : comment on écrit, Sémantique : ce que ça fait.

## Typages

- **Typage statique** : On associe un type à une variable, et ce type ne peut pas changer. Ex : Java, C, C++.
- **Typage dynamique** : La valeur porte la notion de type, pas besoin de l'associer. Ex : Python, JavaScript.
- **Typage implicite** : Pas de déclaration de type obligatoire. Ex : Python, JavaScript.
- **Typage explicite** : Déclaration de type obligatoire. Ex : Java, C, C++.
- Tout langage est typé.

## Mode de gestion de parametre

- **Passage par valeur** : La valeur de la variable est copiée dans la fonction. Les modifications dans la fonction n'affectent pas la variable d'origine. ex : C, C++.
(x=5, f(x) => x=6, f(x)=6, x=5)
- **Passage par référence** : L'adresse mémoire de la variable est passée à la fonction. Les modifications dans la fonction affectent la variable d'origine. ex : C, C++.
(x=5, f(x) => x=6, f(x)=6, x=6)
- **Passage par copie** : La valeur de la variable est copiée dans la fonction. Les modifications dans la fonction n'affectent pas la variable d'origine. ex : Python.
(x=5, f(x) => x=6, f(x)=6, x=5)

## Variables

### Comment parler des variables?

- **Portée** : La portée d'une variable est la partie du programme où la variable est accessible, ou il est possible d'y faire référence
  - **Portée globale** : La portée globale d'une variable est l'ensemble du programme.
  - **Portée locale** : La portée locale d'une variable est limitée à la fonction où elle est déclarée.
  - **Portée statique** : La portée statique d'une variable est limitée à la fonction où elle est déclarée, mais sa valeur est conservée entre les appels de la fonction.
- **Durée de vie** : La durée de vie d'une variable est la période pendant laquelle la variable existe en mémoire.

### Nature d'une variable en C ?

- **Variable globale** : Une variable globale est déclarée en dehors de toute fonction. Elle est accessible de partout dans le programme.
- **Variable locale** : Une variable locale est déclarée à l'intérieur d'une fonction. Elle n'est accessible que dans la fonction où elle est déclarée.
- **Variable locale statique** : Une variable locale statique est déclarée à l'intérieur d'une fonction avec le mot-clé static. Elle conserve sa valeur entre les appels de la fonction. Sa durée de vie dépasse la durée de vie de la fonction.
  *ex : void f() { static int x = 0; x++; printf("Nombre de fois où on a utiliser la fonction : %d", x); }*

## Transparence référentielle

- **Definition** : La transparence référentielle est une propriété des fonctions qui garantit que le résultat de la fonction ne dépend que de ses arguments et qu'elle n'a pas d'effets de bord.
- **Exemple** :

```c
int i = 0;
int f(int x) {
  return x + i;
}

print(f(1) + f(1)); // 1 + 2 = 3. f(1) != f(1) => pas de transparence référentielle.
```

## Effets de bord

- **Definition** : Un effet de bord est une modification de l'état du programme qui n'est pas reflétée dans le résultat de la fonction.
- **Exemple** : f(x) = x + 1 a un effet de bord si x est modifié dans la fonction.

## Paramètres de fonction

- **Paramètre formel** : Le paramètre formel est le nom donné à un paramètre dans la déclaration de la fonction.
- **Paramètre effectif** : Le paramètre effectif est la valeur passée à un paramètre lors de l'appel de la fonction.
- **Exemple** :

```c
int f(int x) { // => x est le paramètre formel.
  return x + 1;
}
val=4;
a = f(val) // => val est le paramètre effectif.
b = f(5) // => 5 est le paramètre effectif.
```

## Expression et Commande

- **Expression** : Une expression est une combinaison de valeurs, de variables et d'opérateurs qui peut être évaluée pour produire une valeur.
- **Exemple** : 1 + 2, x * y, f(3).
- **Commande** : Une commande est une instruction qui effectue une action mais ne produit pas de valeur.
- ²**Exemple** : x = 1, print("Hello, World!").

## difference entre #define et const

- **#define** : #define est une directive du préprocesseur qui remplace le texte par un autre texte avant la compilation. Il n'y a pas de vérification de type.
- **Exemple** :

```c
#define PI 3.14159

int main() {
  double r = 5.0;
  double area = PI * r * r; // PI, avant la compilation, est remplacé par 3.14159.
  return 0;
}
```

- **const** : const est un mot-clé qui définit une constante en C. La valeur de la constante ne peut pas être modifiée.
- **Exemple** :

```c
const double PI = 3.14159;

int main() {
  double r = 5.0;
  double area = PI * r * r; // La valeur de PI ne peut pas être modifiée, et ne sera pas remplacée par le préprocesseur.
  return 0;
}
```
