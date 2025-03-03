#include <iostream>
#include <fstream>
#include <string>

class Fichier {
private:
    std::fstream* flux; // Pointeur vers un flux de fichier
public:
    // Constructeur
    Fichier() : flux(nullptr) {}
    // Destructeur
    ~Fichier() {
        if (flux) {
            flux->close();  // Fermer le fichier s'il est ouvert
            delete flux;    // Libérer la mémoire
            std::cout << "Mémoire du flux libérée." << std::endl;
        }
    }
    // Sauvegarde des données dans un fichier
    void sauvegarder(const std::string& nomFichier, const std::string& donnees) {
        flux = new std::fstream(nomFichier, std::ios::out); // Ouvrir en écriture
        if (flux->is_open()) {
            *flux << donnees; // Écrire les données
            flux->close();    // Fermer immédiatement après écriture
            delete flux;      // Libérer la mémoire
            flux = nullptr;   // Éviter un pointeur suspendu
            std::cout << "Sauvegarde des données..." << std::endl;
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier pour écriture." << std::endl;
        }
    }
    // Chargement des données depuis un fichier
    void charger(const std::string& nomFichier) {
        flux = new std::fstream(nomFichier, std::ios::in); // Ouvrir en lecture
        if (flux->is_open()) {
            std::string ligne;
            std::cout << "Lecture des données..." << std::endl;
            std::cout << "Contenu du fichier :" << std::endl;
            while (std::getline(*flux, ligne)) {
                std::cout << ligne << std::endl;
            }
            flux->close();   // Fermer après lecture
            delete flux;     // Libérer la mémoire
            std::cout << "Mémoire du flux libérée." << std::endl;
            flux = nullptr;  // Éviter un pointeur suspendu
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier pour lecture." << std::endl;
        }
    }
};

int main() {
    Fichier fichier;
    fichier.sauvegarder("test.txt", "Bonjour, ceci est un test.");
    fichier.charger("test.txt");
    return 0;
}
