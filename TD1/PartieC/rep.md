# Arrêt sur frappe de touche avec `scanf()`

Il n'est pas possible d'utiliser directement `scanf()` pour détecter une frappe de touche sans attendre la validation par la touche "Entrée". Cependant, en utilisant des fonctions comme `getchar()` ou des bibliothèques spécifiques (comme `conio.h` sous Windows ou `termios` sous Linux), il est possible de détecter une frappe de touche en temps réel.