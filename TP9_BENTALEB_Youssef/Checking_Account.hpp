#include "Savings_Account.hpp"

class Checking_Account : public Account {
    private:
        static constexpr const char* def_name = "Unnamed";
        static constexpr double def_balance = 0.0;
        static constexpr double per_check_fee = 1.50;
    public:
        Checking_Account(string name = def_name, double balance = def_balance);
        bool withdraw(double amount);  // Applique les frais lors du retrait
        bool deposit(double amount);  // Hérite de deposit
        friend ostream& operator<<(ostream& os, const Checking_Account& check_acc);  // Affiche au format: [Checking_Account : Nom : Solde]
};
