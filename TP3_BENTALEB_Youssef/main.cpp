#include <iostream>

#ifndef EXO
#define EXO 1
#endif

#if (EXO == 1)
int main() {
    int tab[10] = {0, 1, 2, 3, 4, 5, 7, 8, 9};
    std::cout << "Taille totale du tableau : " << sizeof(tab) << " octet(s)\n";
    std::cout << "Taille d'un élément : " << sizeof(tab[0]) << " octet(s)\n";
    std::cout << "Nombre d'éléments : " << sizeof(tab) / sizeof(tab[0]) << '\n';
    return 0;
}

#elif (EXO == 2)
int main() {
    std::cout << "Estimate for carpet cleaning service\n";
    std::cout << "Number of small rooms: ";
    int small_rooms;
    std::cin >> small_rooms;
    std::cout << "Number of large rooms: ";
    int large_rooms;
    std::cin >> large_rooms;
    const int small_room_tarif = 250;  // en dh
    const int large_room_tarif = 350;  // en dh
    std::cout << "Price per small room: " << small_room_tarif << "dh\n";
    std::cout << "Price per large room: " << large_room_tarif << "dh\n";
    int cost = small_rooms * small_room_tarif + large_rooms * large_room_tarif;
    std::cout << "Cost: " << cost << "dh\n";
    const float tva = 0.06;  // en pourcentage / 100 
    float tax = cost * tva;
    std::cout << "Tax: " << tax << "dh\n";
    std::cout << "===============================\n";
    float total = cost + tax;
    std::cout << "Total estimate: " << total << "dh\n";
    const int estimate_duration = 30;  // en jours
    std::cout << "This estimate is valid for " << estimate_duration << " days\n";
    return 0;
}

#elif (EXO == 3)
constexpr int fact(int n) {
    return (n <= 1) ? 1 : (n * fact(n - 1));
}

constexpr int fact5 = fact(5);
static_assert(fact5 == 120, "Factorielle de 5 devrait être 120");

int main() {
    int n;
    std::cout << "Entrez une valeur: ";
    std::cin >> n;
    std::cout << "Factorielle de " << n << ": " << fact(n) << std::endl;
    std::cout << "Factorielle de 5 (compile-time): " << fact5 << std::endl;
    return 0;
}

#elif (EXO == 4)
int value = 100;

int main() {
    int value = 50;
    std::cout << "La variable 'value' locale: " << value << std::endl;
    std::cout << "La variable 'value' globale: " << ::value << std::endl;
    return 0;
}

#elif (EXO == 5)
const int num_months = 12;
constexpr float r = 7;
#define PI 3.14159

int main() {    
    std::cout << "Nombre de mois dans une année : " << num_months << std::endl;
    std::cout << "Rayon du cercle : " << r << std::endl;
    std::cout << "Aire du cercle : " << PI * r * r << std::endl;
    return 0;
}

#elif (EXO == 6)
#include <limits>

int safeMultiply(int a, int b) {
    if ((a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b) ||
        (a < 0 && b < 0 && a < std::numeric_limits<int>::max() / b) ||
        (a > 0 && b < 0 && b < std::numeric_limits<int>::min() / a) ||
        (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b)) {
        std::cout << "Overflow détecté" << std::endl;
        return -1;
    }
    return a * b;
}

int main() {
    int a = 30000;
    int b = 1000;
    int result = safeMultiply(a, b);
    std::cout << "Resultat de " << a << " * " << b << " = " << result << std::endl;
    a = 300000;
    b = 10000;
    result = safeMultiply(a, b);
    std::cout << "Resultat de " << a << " * " << b << " = " << result << std::endl;
    return 0;
}

#else
#error "Veuillez entrer une valeur valide pour EXO (1, 2, 3, 4, 5, 6)"

#endif
