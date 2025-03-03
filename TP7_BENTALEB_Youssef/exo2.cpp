#include <iostream>
#include <string>

class Joueur {
private:
    std::string nom;
    int score;
public:
    // Constructeur
    Joueur(std::string n, int s) : nom(n), score(s) {}
    // Getters pour accéder aux attributs privés
    std::string getNom() const { return nom; }
    int getScore() const { return score; }
};

int main() {
    // Création d'un objet statique
    Joueur alice("Alice", 100);
    std::cout << "Nom: " << alice.getNom() << std::endl;
    std::cout << "Score: " << alice.getScore() << std::endl;
    // Création d'un objet dynamique
    Joueur* dynamique = new Joueur("Bob", 200);
    // Accès aux membres avec l'opérateur `->` (non affiché)
    dynamique->getNom();
    // Libération de la mémoire et message
    delete dynamique;
    std::cout << "Objet dynamique supprimé" << std::endl;
    return 0;
}
