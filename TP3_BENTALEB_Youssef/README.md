# README - TP 3

**Auteur : Youssef BENTALEB**  
**Répertoire GitHub :** [S4_24-25_Cpp](https://github.com/SmollCoco/S4_24-25_Cpp)

## Description

Ce programme exécute les exercices du TP3 en fonction de la valeur de la macro `EXO`. Par défaut, l'exercice 1 est compilé.

## Compilation et exécution

### Compilation

Compilation par défaut (`EXO=1`) :

```sh
g++ -o main main.cpp
```

Compilation pour un exercice spécifique (exemple pour `EXO=3`) :

```sh
g++ -o main main.cpp -DEXO=3
```

### Exécution

```sh
./main
```

## Exercices disponibles

-   **`EXO == 1`** : Analyse la mémoire d'un tableau (taille totale, taille d'un élément, nombre d'éléments).
-   **`EXO == 2`** : Calcule une estimation de coût pour un service de nettoyage de tapis (incluant taxe et validité).
-   **`EXO == 3`** : Calcule la factorielle d'un nombre à la compilation avec `constexpr` et vérifie via `static_assert`.
-   **`EXO == 4`** : Illustre le "shadowing" de variables (affiche une variable locale et une variable globale de même nom).
-   **`EXO == 5`** : Utilise des constantes (`const`, `constexpr`, `#define`) pour calculer l'aire d'un cercle.
-   **`EXO == 6`** : Détecte les overflows lors de la multiplication de deux entiers avec `std::numeric_limits`.

---

**Note :** Pour chaque exercice, recompilez le programme avec la macro `EXO` correspondante avant l'exécution.
