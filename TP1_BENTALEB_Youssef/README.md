# README - TP 1

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

- `EXO == 1` : Affiche un message.
- `EXO == 2` : Demande un nombre et l'affiche.
- `EXO == 3` : Effectue des opérations mathématiques.
- `EXO == 4` : Affiche un nombre saisi.
- `EXO == 5` : Convertit une température de Celsius en Fahrenheit.
