#include "BankingApp.h"
#include <iostream>
#include <fstream>

using namespace std;

//Function to create a new bank account
void createAccount(map<string, BankAccount*>& accounts) {
	string accNumber, accHolderName;
	double initialBalance;

	cout << "Enter account number: ";
	cin >> accNumber;
	cout << "Enter account holder name: ";
	cin >> accHolderName;
	cout << "Enter initial balance: ";
	cin >> initialBalance;

	//Create a new BankAccount object and store it in the map
	accounts[accNumber] = new BankAccount(accNumber, accHolderName, initialBalance);
	cout << "Account created successfully!" << endl;
}

//Function to deposit money into an account
void depositToAccount(map<string, BankAccount*>& accounts) {
	string accNumber;
	double amount;

	cout << "Enter account number: ";
	cin >> accNumber;

	//Check if the account exists
	if (accounts.find(accNumber) != accounts.end()) {
		cout << "Enter amount to deposit: ";
		cin >> amount;
		accounts[accNumber]->deposit(amount); // Deposit the amount
		cout << "Amount deposited successfully!" << endl;
	}
	else {
		cout << "Account not found." << endl;
	}
}

//Function to withdraw money from an account
void withdrawFromAccount(map<string, BankAccount*>& accounts) {
	string accNumber;
	double amount;

	cout << "Enter account number: ";
	cin >> accNumber;

	//Check if the account exists
	if (accounts.find(accNumber) != accounts.end()) {
		cout << "Enter amount to withdraw: ";
		cin >> amount;
		accounts[accNumber]->withdraw(amount); // Deposit the amount
		cout << "Amount withdrawn successfully!" << endl;
	}
	else {
		cout << "Account not found." << endl;
	}
}

//Function to display account information
void displayAccountInfo(map<string, BankAccount*>& accounts) {
	string accNumber;

	cout << "Enter account number: ";
	cin >> accNumber;
	
	//Check if the account exists
	if (accounts.find(accNumber) != accounts.end()) {
		accounts[accNumber]->displayAccountInfo(); //Display account details
	}
	else {
		cout << "Account not found!" << endl;
	}
}

//Function to save all accounts to a file
void saveAccountsToFile(map<string, BankAccount* > & accounts) {
	ofstream outFile("accounts.txt");

	// Iterate through all accounts and save them to the file
	for (auto& pair : accounts) {
		outFile << pair.second->getAccountNumber() << " "
			<< pair.second->getAccountHolderName() << " "
			<< pair.second->getBalance() << endl;
	}
	outFile.close();
	cout << "Accounts saved to file!" << endl;
}

// Function to load all acounts from a file
void loadAccountsFromFile(map<string, BankAccount*>& accounts) {
	ifstream inFile("accounts.txt");
	string accNumber, accHolderName;
	double balance;

	//Load Accounts from file and create BankAccount objects
	while (inFile >> accNumber >> accHolderName >> balance) {
		accounts[accNumber] = new BankAccount(accNumber, accHolderName, balance);
	}
	
	inFile.close();
	cout << "Accounts loaded from file!" << endl;
}