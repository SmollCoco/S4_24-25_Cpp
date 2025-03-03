#include <iostream>
#include <string>

class Joueur {
private:
    std::string nom;
    int score;
public:
    // Constructeur pour initialiser nom et score
    Joueur(std::string n, int s) : nom(n), score(s) {}
    // Méthode pour afficher les informations
    void afficherInfos() const {
        std::cout << "Joueur: " << nom << ", Score: " << score << std::endl;
    }
};

int main() {
    // Création des objets Joueur
    Joueur alice("Alice", 100);
    Joueur bob("Bob", 200);
    // Appel de la méthode d'affichage
    alice.afficherInfos();
    bob.afficherInfos();
    return 0;
}
