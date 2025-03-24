### Réponse

Une liste chainée semble être le meilleur choix pour implémenter une pile.

Contrairement à un tableau statique par exemple, la liste chainée permet d'ajouter et retirer des éléments sans se soucier de la taille de la liste.
La liste chainée est beaucoup plus efficace et rapide pour ajouter et retirer des éléments que le tableau statique. (Complexité O(1) pour la liste chainée contre O(n) pour le tableau statique)
La liste chainée est donc le meilleur choix pour implémenter une pile.
Une liste doublement chainée est inutile ici car on n'a pas besoin de parcourir la liste dans les deux sens, seulement du sommet vers le bas.
De même pour une liste circulaire. On n'a pas besoin de lier le sommet de la liste au bas de la liste.