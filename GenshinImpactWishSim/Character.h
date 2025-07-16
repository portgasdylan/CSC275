#ifndef Character_H
#define Character_H

#include <string>
#include <iostream>
using namespace std;

class Character {
private:
	string name;
	string element;
	int rarity;
	int attack;
	int defense;

public:
	//Constructor
	Character(string name, string element, int rarity, int attack, int defense);

	//Getters
	string getName() const;
	string getElement() const;
	int getRarity() const;
	int getAttack() const;
	int getDefense() const;

	//Display character information
	void displayInfo() const;
};

#endif