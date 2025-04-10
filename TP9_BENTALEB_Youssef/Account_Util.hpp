#include <vector>
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"

void display(const vector<Account>& accounts);
void display(const vector<Savings_Account>& accounts);
void display(const vector<Checking_Account>& accounts);
void display(const vector<Trust_Account>& accounts);

void deposit(vector<Account>& accounts, double amount);
void deposit(vector<Savings_Account>& accounts, double amount);
void deposit(vector<Checking_Account>& accounts, double amount);
void deposit(vector<Trust_Account>& accounts, double amount);

void withdraw(vector<Account>& accounts, double amount);
void withdraw(vector<Savings_Account>& accounts, double amount);
void withdraw(vector<Checking_Account>& accounts, double amount);
void withdraw(vector<Trust_Account>& accounts, double amount);
