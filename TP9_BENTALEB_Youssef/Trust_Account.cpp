#include <iostream>
#include "Trust_Account.hpp"

Trust_Account::Trust_Account(string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawals{0} {}

bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold) {
        amount += bonus_amount;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || amount > balance * max_withdrawals_percent) {
        return false;
    }
    if (Savings_Account::withdraw(amount)) {
        ++num_withdrawals; 
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Trust_Account& tr_acc) {
    os << "[Trust_Account: " << tr_acc.name << " : " << tr_acc.balance << " : " << tr_acc.int_rate << "% : " << tr_acc.num_withdrawals << "]";
    return os;
}
