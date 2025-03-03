#include <iostream>

class SharedPtr {
private:
    int* ptr;           // Pointeur vers l'objet partagé
    int* refCount;      // Pointeur vers le compteur de références
    // Fonction interne pour la suppression
    void deleteObject() {
        if (refCount && *refCount == 0 && ptr) {
            delete ptr;
            delete refCount;
            std::cout << "Objet supprimé" << std::endl;
        }
    }
public:
    // Constructeur
    SharedPtr(int* p) : ptr(p), refCount(new int(1)) {
        std::cout << "Création d'un SharedPtr vers " << *ptr << std::endl;
        std::cout << "Nombre de références : " << *refCount << std::endl;
    }
    // Constructeur de copie
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        ++(*refCount);
        std::cout << "Création d'une copie" << std::endl;
        std::cout << "Nombre de références : " << *refCount << std::endl;
    }
    // Opérateur d'affectation (pour une gestion correcte des références)
    SharedPtr& operator=(const SharedPtr& other) {
         if (this != &other) {
            if (ptr) {
                --(*refCount);
                if (*refCount == 0) {
                    deleteObject();
                }
            }
            ptr = other.ptr;
            refCount = other.refCount;
            ++(*refCount);
            std::cout << "Affectation" << std::endl;
            std::cout << "Nombre de références : " << *refCount << std::endl;
         }
         return *this;
    }
    // Destructeur
    ~SharedPtr() {
        --(*refCount);
        std::cout << "Destruction d'un SharedPtr" << std::endl;
        std::cout << "Nombre de références : " << (refCount ? *refCount : 0) << std::endl;
        deleteObject();
    }
    // Méthode pour accéder à la valeur pointée
    int get() const {
         if(ptr != nullptr){
            return *ptr;
        } else {
            return 0;
        }
    }
};

int main() {
    int* value = new int(10);
    SharedPtr sp1(value);
    SharedPtr sp2(sp1);
    SharedPtr sp3(new int(20));
    sp3 = sp1;
    return 0;
}
