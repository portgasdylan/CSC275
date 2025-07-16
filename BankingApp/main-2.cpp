#include <iostream>
#include <map>
#include "BankAccount.h"
#include "BankingApp.h"

using namespace std;

int main() {

	cout << "Welcome to the Banking App!" << endl; //Greet User

	map<string, BankAccount*> accounts; // Map to store bank accounts
	loadAccountsFromFile(accounts); // Load existing accounts from file

	int choice;

	do {
		cout << "1. Create Account" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "4. Display Account Info" << endl;
		cout << "5. Save & Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		
		switch (choice) {
		case 1: createAccount(accounts); break;
		case 2: depositToAccount(accounts); break;
		case 3: withdrawFromAccount(accounts);  break;
		case 4: displayAccountInfo(accounts); break;
		case 5: saveAccountsToFile(accounts); break;
		default: cout << "Invalid Choice." << endl;
		}
	} while (choice != 5);

	// Clean up dynamically allocated memory
	for (auto& pair : accounts) {
		delete pair.second;
	}

	return 0;
}