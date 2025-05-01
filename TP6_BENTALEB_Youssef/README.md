# README - TP6

**Auteur : BENTALEB Youssef**  
**Répertoire GitHub :** [S4_24-25_Cpp](https://github.com/SmollCoco/S4_24-25_Cpp)

## Description

Ce TP contient 5 exercices sur la gestion des pointeurs, l'allocation dynamique et les smart pointers en C++. Chaque exercice est compilé séparément.

## Compilation et exécution

### Compilation avec Makefile

```sh
make all  # Compile tous les exercices
```

### Exécution des exercices

-   Exercice 1 (Gestion de matrice dynamique) :
    ```sh
    ./exo1
    ```

-   Exercice 2 (Graphe orienté avec DFS) :
    ```sh
    ./exo2
    ```

-   Exercice 3 (Arbre binaire de recherche) :
    ```sh
    ./exo3
    ```

-   Exercice 4 (Simulation mémoire avec unique_ptr) :
    ```sh
    ./exo4
    ```

-   Exercice 5 (Cache LRU avec shared_ptr/weak_ptr) :
    ```sh
    ./exo5
    ```

## Exercices disponibles

### Exercice 1 : Gestion dynamique d’une matrice

-   Alloue dynamiquement une matrice \( n \times m \), l'initialise avec des valeurs croissantes et implémente sa transposée.

### Exercice 2 : Graphe orienté avec parcours DFS

-   Implémente une classe `Graph` utilisant des pointeurs dynamiques pour représenter un graphe orienté et effectue un parcours en profondeur (DFS).

### Exercice 3 : Arbre binaire de recherche (BST)

-   Crée un arbre binaire de recherche avec insertion, suppression et affichage en parcours infixe. 

### Exercice 4 : Simulation de gestion de mémoire avec unique_ptr

-   Simule l'allocation et la fusion de blocs mémoire en utilisant `unique_ptr`.

### Exercice 5 : Cache LRU avec shared_ptr et weak_ptr

-   Implémente un cache LRU avec éviction des éléments les moins utilisés, en utilisant `shared_ptr` et `weak_ptr`.
