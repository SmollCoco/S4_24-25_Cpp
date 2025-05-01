# README - TP7

**Auteur : BENTALEB Youssef**  
**Répertoire GitHub :** [S4_24-25_Cpp](https://github.com/SmollCoco/S4_24-25_Cpp)

## Description

Ce TP contient 7 exercices sur la programmation orientée objet en C++ avec les pointeurs. Chaque exercice est compilé séparément et explore des concepts essentiels tels que la gestion dynamique d'objets, les modificateurs d'accès, les constructeurs/destructeurs, et les pointeurs intelligents.

## Compilation et exécution

### Compilation avec Makefile

```sh
make  # Compile tous les exercices
```

### Exécution des exercices

-   Exercice 1 (Classe et objets) :

    ```sh
    ./exo1
    ```

-   Exercice 2 (Gestion d'objets avec pointeurs) :

    ```sh
    ./exo2
    ```

-   Exercice 3 (Constructeurs et destructeurs) :

    ```sh
    ./exo3
    ```

-   Exercice 4 (Gestion d'inventaire avec pointeurs dynamiques) :

    ```sh
    ./exo4
    ```

-   Exercice 5 (Système de notes) :

    ```sh
    ./exo5
    ```

-   Exercice 6 (Manipulation de fichiers avec pointeurs) :

    ```sh
    ./exo6
    ```

-   Exercice 7 (Implémentation de shared_ptr) :
    ```sh
    ./exo7
    ```

## Exercices disponibles

### Exercice 1 : Définition d'une classe et création d'objets

-   Implémente une classe `Joueur` avec les attributs `nom` et `score`.
-   Ajoute des méthodes pour afficher les informations du joueur.
-   Crée plusieurs objets et les affiche.

### Exercice 2 : Gestion d'objets avec pointeurs

-   Utilise les modificateurs `public` et `private` pour restreindre l'accès aux données.
-   Montre l'usage des opérateurs `.` et `->` pour accéder aux membres d'une classe.
-   Alloue dynamiquement un objet avec `new` et le libère avec `delete`.

### Exercice 3 : Constructeurs et destructeurs

-   Implémente un constructeur pour initialiser les attributs d'un objet.
-   Définit un destructeur affichant un message lors de la destruction de l'objet.

### Exercice 4 : Gestion d'un inventaire avec pointeurs dynamiques

-   Crée une classe `Objet` avec un nom et une quantité.
-   Implémente une classe `Inventaire` utilisant des pointeurs dynamiques.
-   Ajoute et retire des objets dynamiquement.
-   Libère la mémoire allouée.

### Exercice 5 : Gestion d'un système de notes

-   Implémente une classe `Étudiant` avec un nom et une liste de notes.
-   Ajoute une méthode pour calculer la moyenne des notes.

### Exercice 6 : Manipulation de fichiers avec pointeurs

-   Développe une classe `Fichier` permettant de lire et écrire dans un fichier texte.
-   Utilise un pointeur vers un flux de fichier (`fstream`) pour gérer les données.
-   Implémente des méthodes de sauvegarde et de chargement.

### Exercice 7 : Implémentation de shared_ptr (sans smart pointer)

-   Crée une classe `SharedPtr` gérant un pointeur avec un compteur de références.
-   Met en place l'incrémentation et la décrémentation du compteur lors de la copie et de la destruction.
-   Assure la suppression automatique de l'objet lorsque le compteur atteint zéro.
