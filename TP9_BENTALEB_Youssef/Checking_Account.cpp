#include <iostream>
#include "Checking_Account.hpp"

Checking_Account::Checking_Account(string name, double balance)
    : Account{name, balance} {}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;  
    return Account::withdraw(amount); 
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);  
}

ostream& operator<<(ostream& os, const Checking_Account& check_acc) {
    os << "[Checking_Account: " << check_acc.name << " : " << check_acc.balance << "]";
    return os;
}
