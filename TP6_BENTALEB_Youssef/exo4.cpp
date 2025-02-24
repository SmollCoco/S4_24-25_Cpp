#include <iostream>
#include <memory>
using namespace std;

struct MemoryBlock {
    int taille;
    MemoryBlock(int t) : taille(t) {
        cout << "Bloc de mémoire alloué de " << taille << " unités." << endl;
    }
};

unique_ptr<MemoryBlock> fusionner(unique_ptr<MemoryBlock> bloc1, unique_ptr<MemoryBlock> bloc2) {
    int somme = bloc1->taille + bloc2->taille;
    cout << "Fusion des deux blocs : " << somme << " unités." << endl;
    return make_unique<MemoryBlock>(somme);
}

void libererMemoire(unique_ptr<MemoryBlock> bloc) {
    cout << "Libération de la mémoire." << endl;
}

int main() {
    auto bloc1 = make_unique<MemoryBlock>(100);
    auto bloc2 = make_unique<MemoryBlock>(200);
    auto blocFusionne = fusionner(move(bloc1), move(bloc2));
    libererMemoire(move(blocFusionne));
    return 0;
}
