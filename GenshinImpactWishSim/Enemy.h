#ifndef Enemy_H
#define Enemy_H

#include <string>
#include <iostream>
using namespace std;

class Enemy {
protected:
	string name;
	string element;
	int health;
	int attackPower;

public:
	Enemy(string name, string element, int health, int attackPower);

	virtual void takeDamage(int damage); //reduce health by damage amount
	bool isDefeated() const; //checks if health is <= 0
	void displayInfo() const; //display enemy information

	string getName() const;
	int getAttackPower() const;

	virtual ~Enemy() = default;
};

class Slime : public Enemy {
public:
	Slime(string element);
};

#endif