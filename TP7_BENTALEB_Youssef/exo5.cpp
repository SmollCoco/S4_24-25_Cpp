#include <iostream>
#include <string>
#include <vector>

class Etudiant {
private:
    std::string nom;
    std::vector<int> notes;
public:
    // Constructeur
    Etudiant(std::string n) : nom(n) {}
    // Ajouter une note
    void ajouterNote(int note) {
        notes.push_back(note);
    }
    // Calculer la moyenne des notes
    double calculerMoyenne() const {
        if (notes.empty()) {
            return 0.0; // Éviter la division par zéro
        }
        int somme = 0;
        for (int note : notes) {
            somme += note;
        }
        return (float)somme / notes.size();
    }
    // Afficher les informations de l'étudiant
    void afficherInfos() const {
        std::cout << "Nom: " << nom << std::endl;
        std::cout << "Notes: ";
        for (size_t i = 0; i < notes.size(); ++i) {
            std::cout << notes[i];
            if (i < notes.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        std::cout << "Moyenne: " << calculerMoyenne() << std::endl;
    }
};

int main() {
    // Création d'un étudiant
    Etudiant karim("Karim");
    // Ajout des notes
    karim.ajouterNote(15);
    karim.ajouterNote(18);
    karim.ajouterNote(12);
    // Affichage des informations
    karim.afficherInfos();
    return 0;
}
