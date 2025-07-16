#ifndef BankAccount_h
#define BankAccount_h

#include <string>

using namespace std;

//Class to represent the Bank Account
class BankAccount {
    //Create a private version ( can only be accessed from within the class )
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    //Create a public version ( can be accessed outside the class )
public:
    // Constructor to initialize a BankAccount object
    BankAccount(string accNumber, string accHolderName, double initialBalance);

    //Getters for account properties
    string getAccountNumber();
    string getAccountHolderName();
    double getBalance();

    //Functions to deposit and withdraw money
    void deposit(double amount);
    void withdraw(double amount);

    //Function to display account info
    void displayAccountInfo();

};
#endif // !1

