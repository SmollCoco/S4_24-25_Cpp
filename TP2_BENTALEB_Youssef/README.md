# README - TP 2

**Auteur : Youssef BENTALEB**  
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

-   `EXO == 1` : Affiche un message si `DEBUG` est défini.
-   `EXO == 2` : Affiche les arguments passés au programme.
-   `EXO == 3` : Utilisation d'un `namespace` pour afficher une variable.
-   `EXO == 4` : Saisie et affichage d'un entier et d'un nombre décimal.
