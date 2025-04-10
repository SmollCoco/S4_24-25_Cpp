#include <iostream>
#include "Savings_Account.hpp"

Savings_Account::Savings_Account(string name, double balance, double int_rate)
    : Account{name, balance}, int_rate{int_rate} {}

bool Savings_Account::deposit(double amount) {
    if (amount > 0) {
        amount += amount * (int_rate / 100);  
        return Account::deposit(amount);     
    }
    return false;
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

ostream& operator<<(ostream& os, const Savings_Account& sav_acc) {
    os << "[Savings_Account: " << sav_acc.name << " : " << sav_acc.balance << " : " << sav_acc.int_rate << "%]";
    return os;
}
