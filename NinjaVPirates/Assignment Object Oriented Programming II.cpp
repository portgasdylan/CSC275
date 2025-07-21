// ConsoleApp.cpp : Demonstrates OOP principles in a simple fight simulation.

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <random>
using namespace std;

// --- Abstraction: GameStructure interface ---
class GameStructure {
public:
    virtual void help() const = 0;
    virtual ~GameStructure() = default;
};

// --- Abstraction & Polymorphism: Weapon interface ---
class Weapon {
public:
    virtual int damage() const = 0;
    virtual string name() const = 0;
    virtual ~Weapon() = default;
};

// Concrete Weapons
class Star : public Weapon {
public:
    int damage() const override { return 25; }
    string name() const override { return "Throwing Star"; }
};
class Sword : public Weapon {
public:
    int damage() const override { return 20; }
    string name() const override { return "Sword Slash"; }
};
class Fireball : public Weapon {
public:
    int damage() const override { return 30; }
    string name() const override { return "Fireball"; }
};

// --- Base Character class, encapsulates name & health ---
class Character : public GameStructure {
public:
    Character(string name, int health, unique_ptr<Weapon> w)
        : name_(move(name)), health_(health), weapon_(move(w)) {
    }

    const string& getName() const { return name_; }
    int getHealth() const { return health_; }
    void applyDamage(int d) {
        health_ = max(0, health_ - d);
        if (health_ == 0)
            cout << name_ << " has fallen!\n";
    }

    virtual int attack() const {
        cout << name_ << " attacks with "
            << weapon_->name()
            << " for " << weapon_->damage() << " dmg.\n";
        return weapon_->damage();
    }

    void help() const override {
        cout << name_ << " has no special hints.\n";
    }

    virtual ~Character() = default;

protected:
    const unique_ptr<Weapon> weapon_;

private:
    string name_;
    int health_;
};

// --- Derived classes with their own help messages ---
class Ninja : public Character {
public:
    Ninja(string name, int health)
        : Character(move(name), health, make_unique<Star>()) {
    }

    void help() const override {
        cout << "Ninja tip: Stay in the shadows and strike first!\n";
    }
};

class Pirate : public Character {
public:
    Pirate(string name, int health)
        : Character(move(name), health, make_unique<Sword>()) {
    }

    void help() const override {
        cout << "Pirate tip: Keep your blade sharp and your wits sharper!\n";
    }
};

class Wizard : public Character {
public:
    Wizard(string name, int health)
        : Character(move(name), health, make_unique<Fireball>()) {
    }

    void help() const override {
        cout << "Wizard tip: Mana is precious—choose spells wisely!\n";
    }
};

// --- Utility: one round of battle between two characters ---
void battleRound(Character& a, Character& b) {
    int dmg = a.attack();
    b.applyDamage(dmg);
    if (b.getHealth() > 0) {
        dmg = b.attack();
        a.applyDamage(dmg);
    }
}

// --- Intro display ---
void displayIntro() {
    cout << "=== Welcome to the OOP Battle Simulator ===\n\n";
}

int main() {
    displayIntro();

    // Create our fighters
    vector<unique_ptr<Character>> fighters;
    fighters.emplace_back(make_unique<Ninja>("Shadow", 100));
    fighters.emplace_back(make_unique<Pirate>("Blackbeard", 120));
    fighters.emplace_back(make_unique<Wizard>("Merlin", 80));

    // Show each character’s help tip
    for (const auto& c : fighters) {
        cout << "[" << c->getName() << "] ";
        c->help();
    }
    cout << "\n";

    // Pick two distinct fighters by index
    int n = static_cast<int>(fighters.size());
    mt19937 gen{ random_device{}() };
    uniform_int_distribution<int> dist(0, n - 1);

    int i1 = dist(gen);
    int i2 = dist(gen);
    while (i2 == i1) {
        i2 = dist(gen);
    }

    Character& f1 = *fighters[i1];
    Character& f2 = *fighters[i2];

    cout << "Battle: " << f1.getName() << " vs. " << f2.getName() << "\n\n";

    // Fight until one falls
    while (f1.getHealth() > 0 && f2.getHealth() > 0) {
        battleRound(f1, f2);
        cout << f1.getName() << " HP: " << f1.getHealth()
            << " | " << f2.getName() << " HP: " << f2.getHealth()
            << "\n\n";
    }

    cout << "=== Simulation Ended ===\n";
    return 0;
}
