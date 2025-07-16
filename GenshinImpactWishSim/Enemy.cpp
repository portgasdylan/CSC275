#include "Enemy.h"

//Constructor
Enemy::Enemy(string name, string element, int health, int attackPower)
	: name(name), element(element), health(health), attackPower(attackPower) {}

//function for taking damage
void Enemy::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

//check if defeated
bool Enemy::isDefeated() const {
	return health <= 0;
}

//display enemy information
void Enemy::displayInfo() const {
	cout << "Name: " << name << "\n";
	cout << "Element: " << element << "\n";
	cout << "Health: " << health << "\n";
	cout << "Attack Power: " << attackPower << "\n";
}

//getter for name
string Enemy::getName() const {
	return name;
}

//getter for attack power
int Enemy::getAttackPower() const {
	return attackPower;
}

// Slime Constructor
Slime::Slime(string element)
	: Enemy(element + " Slime", element, 100, 20) {
}