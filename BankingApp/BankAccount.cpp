#include "BankAccount.h"
#include <iostream>

using namespace std;

// Implement Constructor Into app
BankAccount::BankAccount(string accNumber, string accHolderName, double initialBalance) {
    accountNumber = accNumber;
    accountHolderName = accHolderName;
    balance = initialBalance;
}

//Getter for account number
string BankAccount::getAccountNumber() {
    return accountNumber;
}

//Getter for account holder name
string BankAccount::getAccountHolderName() {
    return accountHolderName;
}

//Getter for account balance
double BankAccount::getBalance() {
    return balance;
}

//Function to deposit money into the account
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    else {
        cout << "Invalid Deposit Amount!" << endl;
    }
}

//Function to withdraw money from the account
void BankAccount::withdraw(double amount) {
    if (amount < 0 && amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Insufficient funds or Invalid Amount!" << endl;
    }
}

//Function to display account information
void BankAccount::displayAccountInfo() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Balance: " << balance << endl;
}