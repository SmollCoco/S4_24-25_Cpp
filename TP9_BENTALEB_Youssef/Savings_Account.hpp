#pragma once
#include "Account.hpp"

class Savings_Account : public Account {
    private:
        static constexpr const char* def_name = "Unnamed";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
    protected:
        double int_rate;
    public:
        Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
        bool deposit(double amount); // Applique le taux d’intérêt sur le dépôt
        bool withdraw(double amount);  // Hérite de withdraw
        friend ostream& operator<<(ostream& os, const Savings_Account& sav_acc);  // Affiche au format: [Savings_Account : Nom : Solde : Taux]
};
