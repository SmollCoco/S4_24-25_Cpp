#include <iostream>
#include <stdexcept>

class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Division par zero";
    }
};

class InvalidOperationException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Operation invalide";
    }
};

double calculate(double a, double b, char op) {
    if (op != '+' && op != '-' && op != '*' && op != '/')
        throw InvalidOperationException();
    
    if (op == '/' && b == 0)
        throw DivideByZeroException();
    
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: throw InvalidOperationException();
    }
}

int main() {
    double num1, num2;
    char op;
    
    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;
    std::cout << "Entrez le deuxième nombre: ";
    std::cin >> num2;
    std::cout << "Entrez l'opération (+,-,*,/): ";
    std::cin >> op;
    
    try {
        double res = calculate(num1, num2, op);
        std::cout << "Résultat: " << res << std::endl;
    }
    catch (const DivideByZeroException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const InvalidOperationException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Erreur inconnue" << std::endl;
    }
    
    std::cout << "Programme terminé" << std::endl;
    return 0;
}
