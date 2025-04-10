#include <string>
using namespace std;

class Account {
    private:
        static constexpr const char* def_name = "Unnamed";
        static constexpr double def_balance = 0.0;
    protected:
        string name;
        double balance;
    public:
        Account(string name = def_name, double balance = def_balance);
        bool deposit(double amount);  // Dépose un montant s'il est positif
        bool withdraw(double amount);  // Retire un montant s'il est positif et le solde le permet
        friend ostream& operator<<(ostream& os, const Account& acc);  // Affiche au format: [Account : Nom : Solde]
};
