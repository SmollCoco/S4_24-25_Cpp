#include <iostream>
using namespace std;

// Fonction pour allouer dynamiquement une matrice
int** allouerMatrice(int n, int m) {
    int** matrice = new int*[n];  // Allouer un tableau de pointeurs de lignes
    for (int i = 0; i < n; i++) {
        matrice[i] = new int[m];  // Allouer chaque ligne
    }
    return matrice;
}

// Fonction pour initialiser la matrice avec des valeurs croissantes
void initialiserMatrice(int** matrice, int n, int m) {
    int a = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrice[i][j] = a++;
        }
    }
}

// Fonction pour afficher la matrice
void afficherMatrice(int** matrice, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

// Fonction pour transposer une matrice
int** transposerMatrice(int** matrice, int n, int m) {
    int** transposee = allouerMatrice(m, n); // Allouer une nouvelle matrice transposée
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposee[j][i] = matrice[i][j]; // Échanger lignes et colonnes
        }
    }
    return transposee;
}

// Fonction pour libérer la mémoire allouée
void libererMatrice(int** matrice, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrice[i];  // Libérer chaque ligne
    }
    delete[] matrice;  // Libérer le tableau de pointeurs
}

int main() {
    int n = 3, m = 3;  // Taille de la matrice
    // Étape 1 : Allouer et initialiser la matrice
    int** matrice = allouerMatrice(n, m);
    initialiserMatrice(matrice, n, m);
    // Étape 2 : Afficher la matrice initiale
    cout << "Matrice initiale :" << endl;
    afficherMatrice(matrice, n, m);
    // Étape 3 : Transposer la matrice
    int** transposee = transposerMatrice(matrice, n, m);
    // Étape 4 : Afficher la matrice transposée
    cout << "\nMatrice transposée :" << endl;
    afficherMatrice(transposee, m, n);
    // Étape 5 : Libérer la mémoire allouée
    libererMatrice(matrice, n);
    libererMatrice(transposee, m);
    return 0;
}
