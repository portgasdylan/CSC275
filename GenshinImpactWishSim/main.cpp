// CSC275Final.cpp : GI Simulator
// Dylan Maxwell

#include <iostream>
#include "Character.h"
#include "WishSystem.h"
#include "CombatSystem.h"
using namespace std;

void startScreen() {
    cout << "======================================================\n";
    cout << "    Welcome to the Genshin Impact (GI) Simulator\n";
    cout << "======================================================\n";
    cout << "Simulate wishing and battling with characters!\n\n";
    cout << "Instructions:\n";
    cout << "1. Use the menu to select an option.\n";
    cout << "2. Pull for characters and use them in combat.\n";
    cout << "======================================================\n\n";
}

void mainMenu() {
    cout << "Menu:\n";
    cout << "1. Wish for Characters\n";
    cout << "2. View Wish History\n";
    cout << "3. Start Combat\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    startScreen();
    WishSystem gacha;
    CombatSystem combat;

	gacha.loadWishHistoryFromFile(); //Load saved wish history 

    int choice;
    while (true) {
        try {
            mainMenu();
            cin >> choice;

            // Input validation
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw runtime_error("Invalid input. Please enter a number.");
            }

            // Process user choice
            switch (choice) {
            case 1: {
                int pullType;
				cout << "Choose pull type:\n1. Single Pull\n2. Ten Pull\n";
				cin >> pullType;
				if (pullType == 1) {
					gacha.singlePull();
				}
				else if (pullType == 2) {
					gacha.tenPull();
				}
                else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 2:
                gacha.showWishHistory();
                break;
            case 3: {
                combat.startCombat(gacha.getObtainedCharacters());
                break;
            }
            case 4:
                gacha.saveWishHistoryToFile();
                cout << "Exiting program... Wish history saved.\n";
                return 0;
            default:
                throw out_of_range("Invalid choice. Please enter a number between 1 and 4.");
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }
}