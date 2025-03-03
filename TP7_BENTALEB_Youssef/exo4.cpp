#include <iostream>
#include <string>
#include <vector>

class Objet {
private:
    std::string nom;
    int quantite;
public:
    // Constructeur
    Objet(std::string n, int q) : nom(n), quantite(q) {}
    // Getters
    std::string getNom() const { return nom; }
    int getQuantite() const { return quantite; }
    // Méthode pour afficher l'objet
    void afficher() const {
        std::cout << nom << " (x" << quantite << ")";
    }
};

class Inventaire {
private:
    std::vector<Objet*> objets; // Stockage des pointeurs d'objets
public:
    // Destructeur pour libérer la mémoire
    ~Inventaire() {
        for (Objet* obj : objets) {
            delete obj; // Libérer chaque objet alloué dynamiquement
        }
        std::cout << "Mémoire de l'inventaire libérée." << std::endl;
    }
    // Ajouter un objet
    void ajouterObjet(std::string nom, int quantite) {
        Objet* nouvelObjet = new Objet(nom, quantite); // Allocation dynamique
        objets.push_back(nouvelObjet); // Ajout au vecteur
        std::cout << "Ajout de ";
        nouvelObjet->afficher();
        std::cout << std::endl;
    }
    // Afficher l'inventaire
    void afficherInventaire() const {
        std::cout << "Inventaire :" << std::endl;
        for (const Objet* obj : objets) {
            std::cout << " - ";
            obj->afficher();
            std::cout << std::endl;
        }
    }
};

int main() {
    Inventaire inventaire;
    // Ajout d'objets
    inventaire.ajouterObjet("Pomme", 3);
    inventaire.ajouterObjet("Épée", 1);
    // Affichage de l'inventaire
    inventaire.afficherInventaire();
    // Le destructeur de l'inventaire est appelé automatiquement ici
    return 0;
}
