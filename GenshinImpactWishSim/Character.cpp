#include "Character.h"

//Constructor
Character::Character(string name, string element, int rarity, int attack, int defense)
	: name(name), element(element), rarity(rarity), attack(attack), defense(defense) {}

//Getters
string Character::getName() const { return name; }
string Character::getElement() const { return element; }
int Character::getRarity() const { return rarity; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }

// Display character information
void Character::displayInfo() const {
	cout << "Name: " << name << "\n";
	cout << "Element: " << element << "\n";
	cout << "Rarity: " << rarity << " stars\n";
	cout << "Attack: " << attack << "\n";
	cout << "Defense: " << defense << "\n";
}