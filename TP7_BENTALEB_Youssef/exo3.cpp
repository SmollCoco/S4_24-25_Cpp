#include <iostream>
#include <string>

class Joueur {
private:
    std::string nom;
    int score;
public:
    // Constructeur
    Joueur(std::string n, int s) : nom(n), score(s) {
        std::cout << "Constructeur appelé" << std::endl;
    }
    // Destructeur
    ~Joueur() {
        std::cout << "Destructeur appelé" << std::endl;
    }
    // Méthode pour afficher les informations
    void afficherInfos() const {
        std::cout << "Joueur: " << nom << ", Score: " << score << std::endl;
    }
};

int main() {
    // Création d'un objet Joueur
    Joueur alice("Alice", 100);
    // Affichage des informations
    alice.afficherInfos();
    // Le destructeur est appelé automatiquement à la fin du scope
    return 0;
}
