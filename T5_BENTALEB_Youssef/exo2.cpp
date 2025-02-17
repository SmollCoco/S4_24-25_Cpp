#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>  // Pour std::istringstream

// Fonction pour compter la fréquence des mots
void word_frequency(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::istringstream stream(text);
    std::string word;
    // Lire chaque mot et mettre à jour sa fréquence
    while (stream >> word) {
        // Incrémenter la fréquence du mot
        freq[word]++;
    }
    // Afficher la fréquence des mots
    std::cout << "Fréquence des mots :" << std::endl;
    for (const auto& pair : freq) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, input);
    word_frequency(input);  // Appeler la fonction pour compter la fréquence des mots
    return 0;
}
