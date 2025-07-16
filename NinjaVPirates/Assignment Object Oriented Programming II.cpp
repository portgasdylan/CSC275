// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Polymorphism
#include <iostream>
using namespace std;
// GameStructure class with a pure virtual help method
class GameStructure {
public:
    virtual void help() = 0; // Pure virtual method
};
//Base class character inherited from GameStructure
class Character : public GameStructure {
public:
    string Name; //Public propety name for the character

    //Constructor to initialize the Name and character Health
    Character(string name, int health) : Name(name) {
        setHealth(health); // Setter for health
    }

        //Method to display character's names
        void displayName() {
        cout << "Character name: " << Name << endl;
    }

    //First Talk Method (overloaded)
        void Talk() {
            cout << Name << " says: I'm ready to fight!" << endl;
            }

     //Second Talk method (overloaded) using two parameters
        void Talk(string name, string saysStuff) {
			cout << name << " says: " << saysStuff << endl;
		}

    //Public method to get health status
    int getHealth() {
        return Health;
    }

    //Public method to set health status
    void setHealth(int health) {
        if (health < 0) {
            Health = 0;
            cout << "Character has expired" << endl;
        }
        else {
            Health = health;
        }
    }

    //Virtual attack method, can be overridden by derived classes
    virtual int attack() {
		return 10; // Base attack power is 10 hp
	}
    
	//override the pure virtual method from GameStructure class
    void help() override {}

private:
    int Health; //Private property Health
};

// Derived class ninja from character
class Ninja : public Character {
public:
    //Constructor to initialize the Name and character Health
    Ninja(string name, int health) : Character(name, health) {}

    //Method to throw stars ( specific for ninjas)
    void ThrowStars() {
        cout << "I am throwing stars!" << endl;
    }

    //Override the attack method to return 25 hp
    int attack() override {
		return 25; // Ninja attack power is 25 hp
	}

    //override the help method to display something for just ninjas
    void help() override {
		cout << "Ninjas are cool, they can throw stars!" << endl;
	}
};

// Derived class pirate from character
class Pirate : public Character {
public:
    //Constructor to initialize the Name and character Health
    Pirate(string name, int health) : Character(name, health) {}

    //Method to use sword (specific for pirates)
    void UseSword() {
        cout << "I am Swooshing my Sword!" << endl;
    }

    //Override the attack method to return 25 hp
    int attack() override {
		return 25; // Pirate attack power is 25 hp
	}

    //override the help method to display something for just pirates
    void help() override {
		cout << "Pirates are cool, they can swing swords!" << endl;
	}
};

//Function to display intro
void displayIntro() {
    cout << "Welcome to my simulation!!" << endl;
    cout << "Choose the character you want wisely" << endl;
}

int main()
{
    //Display Intro
    displayIntro();

    //Create Ninja and Pirate objects
    Ninja ninja1("Shadow", 100); //Create ninja character named shadow with 100 health
    Pirate pirate1("Whitebeard", 100); //Create pirate character named whitebeard with 500 health

    //Display their names and actions
    ninja1.displayName();
    ninja1.ThrowStars();
    cout << "Health:" << ninja1.getHealth() << endl;
    cout << "Ninja attack power: " << ninja1.attack() << " hit points" << endl;
    ninja1.help(); // display help for ninjas

    pirate1.displayName();
    pirate1.UseSword();
    cout << "Health:" << pirate1.getHealth() << endl;
    cout << "Pirate attack power: " << pirate1.attack() << " hit points" << endl;
    pirate1.help(); // display help for pirates
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file