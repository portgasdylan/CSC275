#include "CombatSystem.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void CombatSystem::startCombat(vector<Character>& obtainedChars) {
    if (obtainedChars.empty()) {
        cout << "\nYou have no characters to fight with! Try wishing for some.\n";
        return;
    }

    // Player selects a character
    cout << "\n=========================================\n";
    cout << "           Choose Your Fighter\n";
    cout << "=========================================\n";

    for (size_t i = 0; i < obtainedChars.size(); ++i) {
        cout << i + 1 << ". ";
        obtainedChars[i].displayInfo();
        cout << "-----------------------------------------\n";
    }

    int choice;
    cout << "Enter the number of the character: ";
    cin >> choice;

    if (choice < 1 || choice > obtainedChars.size()) {
        cout << "Invalid choice! Returning to main menu.\n";
        return;
    }

    Character& playerChar = obtainedChars[choice - 1];

    // Generate a random slime enemy
    srand(time(0));
    string slimeElements[] = { "Pyro", "Hydro", "Anemo", "Electro", "Cryo", "Geo" };
    string element = slimeElements[rand() % 6];
    Slime enemy(element);

    // Start Combat
    cout << "\n=========================================\n";
    cout << "           Combat Begins!\n";
    cout << "=========================================\n";

    cout << "Your Fighter:\n";
    playerChar.displayInfo();
    cout << "-----------------------------------------\n";
    cout << "Enemy Appears:\n";
    enemy.displayInfo();
    cout << "=========================================\n";

    while (!enemy.isDefeated()) {
        // Player attacks
        int damage = playerChar.getAttack();
        cout << "\n>> " << playerChar.getName() << " attacks for " << damage << " damage!\n";
        enemy.takeDamage(damage);

        if (enemy.isDefeated()) {
            cout << ">> " << enemy.getName() << " is defeated!\n";
            break;
        }

        // Enemy attacks
        int enemyDamage = enemy.getAttackPower();
        cout << ">> " << enemy.getName() << " retaliates for " << enemyDamage << " damage!\n";
        cout << "-----------------------------------------\n";
    }

    cout << "\n=========================================\n";
    cout << "           Combat Ended\n";
    cout << "=========================================\n";
}
