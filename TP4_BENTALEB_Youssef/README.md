# README - TP 4

**Auteur : Joseph**  
**Répertoire GitHub :** [S4_24-25_Cpp](https://github.com/SmollCoco/S4_24-25_Cpp)

## Description

Ce programme exécute différents exercices selon la valeur définie de `EXO`.

## Compilation et exécution

### Compilation

```sh
g++ -o main main.cpp
```

### Exécution

Par défaut (`EXO=1`) :

```sh
./main
```

Pour exécuter un autre exercice (`EXO=3`, par exemple) :

```sh
g++ -o main main.cpp -DEXO=3
./main
```

## Exercices disponibles

-   `EXO == 1` : Affiche les éléments d'un tableau et leur somme.
-   `EXO == 2` : Affiche une matrice et la somme de sa diagonale.
-   `EXO == 3` : Inverse un tableau.
-   `EXO == 4` : Double les éléments d'un vecteur.
-   `EXO == 5` : Manipule une liste avec des insertions.
-   `EXO == 6` : Manipule un ensemble sans doublons.
-   `EXO == 7` : Affiche les paires clé-valeur d'une map.
-   `EXO == 8` : Compte les occurrences de mots dans une map non ordonnée.
-   `EXO == 9` : Trie un vecteur.
-   `EXO == 10` : Trouve la plus longue séquence consécutive dans un ensemble.
-   `EXO == 11` : Implémente un cache LRU (Least Recently Used).
