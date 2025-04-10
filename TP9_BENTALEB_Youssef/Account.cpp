#include <iostream>
#include "Account.hpp"

Account::Account(string name, double balance)
    : name{name}, balance{balance} {
    if (balance < 0) {
        this->balance = 0.0;
        cout << "Solde entré est négatif. Solde initialisé par 0.0" << endl;
    }
}

bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Account& acc) {
    os << "[Account: " << acc.name << " : " << acc.balance << "]";
    return os;
}
