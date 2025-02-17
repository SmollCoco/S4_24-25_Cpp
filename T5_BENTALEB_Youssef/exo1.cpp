#include <iostream>
#include <string>
#include <algorithm>  // Pour std::reverse
#include <cctype>     // Pour std::tolower
#include <sstream>    // Pour std::stringstream

// Fonction pour vérifier si la chaîne est un palindrome
bool is_palindrome(const std::string& text) {
    std::string cleaned_text;    
    // On enlève les espaces et on met tout en minuscule
    for (char ch : text) {
        if (!std::isspace(ch)) {
            cleaned_text += std::tolower(ch);
        }
    }
    // Créer une copie de cleaned_text
    std::string reversed_text = cleaned_text;
    // Inverser la chaîne
    std::reverse(reversed_text.begin(), reversed_text.end());
    // Comparer la chaîne originale et inversée
    return cleaned_text == reversed_text;
}

int main() {
    std::string input;
    std::cout << "Entrez un mot : ";
    std::getline(std::cin, input);
    if (is_palindrome(input)) {
        std::cout << "\"" << input << "\" est un palindrome." << std::endl;
    } else {
        std::cout << "\"" << input << "\" n'est pas un palindrome." << std::endl;
    }
    return 0;
}
