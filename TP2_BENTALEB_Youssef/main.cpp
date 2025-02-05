#include <iostream>
#ifndef EXO
#define EXO 1
#endif

#if (EXO == 1)
#define PI 3.14159265
int main() {
    #ifdef DEBUG
    std::cout << "DEBUG est définie\n";
    #endif
    return 0;
}

#elif (EXO == 2)
int main(int argc, char* argv[]) {
    std::cout << "Argument 1: " << argc << std::endl;
    std::cout << "Argument 2: " << argv << std::endl;
    return 0;
}

#elif (EXO == 3)
namespace test {
    int variable = 42;
}
int main() {
    std::cout << "std::cout avec namespace: " << test::variable << std::endl;
    using namespace std;
    cout << "cout sans préfix std:: : " << test::variable << endl;
    return 0;
}

#elif (EXO == 4)    
int main() {
    std::cout << "Entrez un entier: ";
    int n;
    std::cin >> n;
    std::cout << "Entrez un nombre décimal: ";
    float x;
    std::cin >> x;
    std::cout << "Valeurs saisies: " << n << " et " << x << std::endl;
}

#else
#error "Veuillez entrer une valeur valide pour EXO (1, 2, 3, 4, 5)"

#endif
