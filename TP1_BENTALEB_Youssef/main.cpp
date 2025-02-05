#include <iostream>
#ifndef EXO
#define EXO 1
#endif

#if (EXO == 1)
int main() {
    // Affiche des messages de bienvenue
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Bienvenue en C++!" << std::endl;
    return 0;
}

#elif (EXO == 2)
int main() {
    // Demande à l'utilisateur d'entrer un nombre et l'affiche
    std::cout << "Entrez un nombre: ";
    int x;
    std::cin >> x;
    std::cout << "Vous avez entré: " << x << std::endl;
    return 0;
}

#elif (EXO == 3)
int main() {
    // Demande à l'utilisateur d'entrer deux nombres et affiche les opérations arithmétiques de base
    std::cout << "Entrez deux nombres: ";
    int x, y;
    std::cin >> x >> y;
    std::cout << "Somme: " << x + y << std::endl;
    std::cout << "Différence: " << x - y << std::endl;
    std::cout << "Produit: " << x * y << std::endl;
    std::cout << "Quotient: " << x / y << std::endl;
    return 0;
}
    
#elif (EXO == 4)
int main() {
    // Code corrigé
    int nombre;
    std::cin >> nombre;
    std::cout << "Vous avez entré: " << nombre << std::endl;
    return 0;
}

#elif (EXO == 5)
int main() {
    // Demande à l'utilisateur d'entrer une température en Celsius et la convertit en Fahrenheit
    std::cout << "Entrez une température en Celsius: ";
    int c;
    std::cin >> c;
    std::cout << "En Fahrenheit: " << (c * 9.0 / 5 + 32) << "°F" << std::endl;
    return 0;
}

#else
#error "Veuillez entrer une valeur valide pour EXO (1, 2, 3, 4, 5)"

#endif
