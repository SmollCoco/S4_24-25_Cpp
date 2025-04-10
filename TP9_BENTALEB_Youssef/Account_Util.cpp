#include <iostream>
#include "Account_Util.hpp"

void display(const vector<Account>& accounts) {
    for (const auto& acc : accounts) {
        cout << acc << endl;
    }
}

void display(const vector<Savings_Account>& accounts) {
    for (const auto& acc : accounts) {
        cout << acc << endl;
    }
}

void display(const vector<Checking_Account>& accounts) {
    for (const auto& acc : accounts) {
        cout << acc << endl;
    }
}

void display(const vector<Trust_Account>& accounts) {
    for (const auto& acc : accounts) {
        cout << acc << endl;
    }
}

void deposit(vector<Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.deposit(amount)) {
            cout << "Deposited " << amount << " to " << acc << endl;
        } else {
            cout << "Failed to deposit " << amount << " to " << acc << endl;
        }
    }
}

void deposit(vector<Savings_Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.deposit(amount)) {
            cout << "Deposited " << amount << " to " << acc << endl;
        } else {
            cout << "Failed to deposit " << amount << " to " << acc << endl;
        }
    }
}

void deposit(vector<Checking_Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.deposit(amount)) {
            cout << "Deposited " << amount << " to " << acc << endl;
        } else {
            cout << "Failed to deposit " << amount << " to " << acc << endl;
        }
    }
}

void deposit(vector<Trust_Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.deposit(amount)) {
            cout << "Deposited " << amount << " to " << acc << endl;
        } else {
            cout << "Failed to deposit " << amount << " to " << acc << endl;
        }
    }
}

// Withdraw functions
void withdraw(vector<Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << acc << endl;
        } else {
            cout << "Failed to withdraw " << amount << " from " << acc << endl;
        }
    }
}

void withdraw(vector<Savings_Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << acc << endl;
        } else {
            cout << "Failed to withdraw " << amount << " from " << acc << endl;
        }
    }
}

void withdraw(vector<Checking_Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << acc << endl;
        } else {
            cout << "Failed to withdraw " << amount << " from " << acc << endl;
        }
    }
}

void withdraw(vector<Trust_Account>& accounts, double amount) {
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << acc << endl;
        } else {
            cout << "Failed to withdraw " << amount << " from " << acc << endl;
        }
    }
}
