#include <iostream>
#include <vector>

template<typename T>
class Conteneur {
    private:
        int n;
        std::vector<T> arr;
        int i = 0; // Premier emplacement libre dans arr 
    public:
        Conteneur(int n_) : n(n_), arr(n) {}
        void ajouter(T x) {
            if (i == n) return;
            arr[i++] = x;
        }
        T obtenir(int i) {
            return arr[i];
        }
        ~Conteneur() {}
};

int main() {
    Conteneur<int> c1(3); // Capacité de 3
    c1.ajouter(10);
    c1.ajouter(20);
    c1.ajouter(30);
    c1.ajouter(40); // Capacité dépassée
    std::cout << c1.obtenir(0) << " " << c1.obtenir(1) << std::endl; // Affiche 10 20
    Conteneur<std::string> c2(2);
    c2.ajouter("Bonjour");
    c2.ajouter("Monde");
    std::cout << c2.obtenir(0) << " " << c2.obtenir(1) << std::endl; // Affiche Bonjour Monde
    return 0;
}
