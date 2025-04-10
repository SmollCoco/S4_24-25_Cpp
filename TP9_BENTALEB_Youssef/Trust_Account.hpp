#include "Savings_Account.hpp"

class Trust_Account : public Savings_Account {
    private:
        static constexpr const char* def_name = "Unnamed";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
        static constexpr double bonus_amount = 50.0;
        static constexpr double bonus_threshold = 5000.0;
        static constexpr int max_withdrawals = 3;
        static constexpr double max_withdrawals_percent = 0.2;
    protected:
        int num_withdrawals = 0;
    public:
        Trust_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
        bool deposit(double amount);  // Ajoute un bonus si amount < 5000
        bool withdraw(double amount);  // Limité à 3 retraits, chacun < 20% du solde
        friend ostream& operator<<(ostream& os, const Trust_Account& tr_acc);  // [Trust_Account : Nom : Solde : Taux : Retraits]
};
