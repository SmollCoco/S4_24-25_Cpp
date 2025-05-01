#include <iostream>
#include <stdexcept>

class NegativeQuantityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Quantité négative";
    }
};

class InsufficientStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Stock insuffisant";
    }
};

class Inventory {
    int stock;
public:
    Inventory(int initial) : stock(initial) {}
    
    int get_stock() const { return stock; }
    
    void add_items(int qty) {
        if (qty < 0) throw NegativeQuantityException();
        stock += qty;
    }
    
    void remove_items(int qty) {
        if (qty < 0) throw NegativeQuantityException();
        if (qty > stock) throw InsufficientStockException();
        stock -= qty;
    }
};

int main() {
    Inventory inv(100);
    std::cout << "Stock initial: " << inv.get_stock() << std::endl;
    
    try {
        inv.add_items(50);
        std::cout << "Après ajout de 50: " << inv.get_stock() << std::endl;
    }
    catch (const NegativeQuantityException& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        inv.remove_items(160);
        std::cout << "Après retrait de 160: " << inv.get_stock() << std::endl;
    }
    catch (const InsufficientStockException& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        inv.add_items(-10);
        std::cout << "Après ajout de -10: " << inv.get_stock() << std::endl;
    }
    catch (const NegativeQuantityException& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "Programme terminé" << std::endl;
    return 0;
}
