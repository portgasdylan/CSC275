#ifndef BankingApp_h
#define BankingApp_h

#include <map> // Includes the map library, which provides the map container.
#include <string>
#include "BankAccount.h"

//Functions for banking app operations

//Function to create a new bank account
void createAccount(map<string, BankAccount*>& accounts);

//Function to deposit money into an account
void depositToAccount(map<string, BankAccount*>& accounts);

//Function to withdraw money from an account
void withdrawFromAccount(map<string, BankAccount*>& accounts);

//Function to display account information
void displayAccountInfo(map<string, BankAccount*>& accounts);

//Function to save all accounts to a file
void saveAccountsToFile(map<string, BankAccount*>& accounts);

//Function to load all accounts from a file
void loadAccountsFromFile(map<string, BankAccount*>& accounts);

#endif // !BankingApp_h
