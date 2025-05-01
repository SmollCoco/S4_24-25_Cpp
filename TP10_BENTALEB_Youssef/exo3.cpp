#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

class PaireBase {
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const = 0;
};

template<typename T, typename U>
class Paire : public PaireBase {
    private:
        T premier;
        U second;
    public:
        Paire(T premier_, U second_) : premier(premier_), second(second_) {}
        void afficher() const override {
            if constexpr (!std::is_same_v<T, bool> && !std::is_same_v<U, bool>) {
                std::cout << '(' << premier << ", " << second << ")\n";
            } else if constexpr (std::is_same_v<T, bool>) {
                std::cout << '(' << (premier ? "vrai" : "faux") << ", " << second << ")\n";
            } else if constexpr (std::is_same_v<U, bool>) {
                std::cout << '(' << premier << ", " << (second ? "vrai" : "faux") << ")\n";
            } else {
                std::cout << '(' << (premier ? "vrai" : "faux") << ", " << (second ? "vrai" : "faux") << ")\n";
            }
        }
};

template<typename T>
class Paire<T, int> : public PaireBase {
    private:
        T premier;
        int second;
    public:
        Paire(T premier_, int second_) : premier(premier_), second(second_) {}
        void afficher() const override {
            if constexpr(std::is_same_v<T, bool>) {
                std::cout << '(' << (premier ? "vrai" : "faux") << ", " << second << "(int)" << ")\n";
            } else {
                std::cout << '(' << premier << ", " << second << "(int)" << ")\n";
            }
        }
};

int main() {
    std::vector<std::unique_ptr<PaireBase>> paires;

    // Ajout de paires hétérogènes
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));

    // Affichage des paires
    for (const auto& p : paires) {
        p->afficher();
    }

    return 0;
}
