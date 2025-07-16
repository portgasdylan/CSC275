#include "WishSystem.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

//Constructor
WishSystem::WishSystem() : pullCount(0) {
	// add wish pool with characters
	// add wish pool with all 5-star characters
	wishPool5Star.push_back(Character("Diluc", "Pyro", 5, 300, 200));
	wishPool5Star.push_back(Character("Jean", "Anemo", 5, 250, 250));
	wishPool5Star.push_back(Character("Keqing", "Electro", 5, 280, 220));
	wishPool5Star.push_back(Character("Mona", "Hydro", 5, 270, 230));
	wishPool5Star.push_back(Character("Qiqi", "Cryo", 5, 260, 240));
	wishPool5Star.push_back(Character("Tartaglia", "Hydro", 5, 320, 180));
	wishPool5Star.push_back(Character("Zhongli", "Geo", 5, 350, 220));
	wishPool5Star.push_back(Character("Raiden Shogun", "Electro", 5, 340, 230));
	wishPool5Star.push_back(Character("Eula", "Cryo", 5, 370, 180));
	wishPool5Star.push_back(Character("Ayaka", "Cryo", 5, 360, 200));
	wishPool5Star.push_back(Character("Hu Tao", "Pyro", 5, 340, 250));
	wishPool5Star.push_back(Character("Ganyu", "Cryo", 5, 310, 270));
	wishPool5Star.push_back(Character("Nahida", "Dendro", 5, 280, 290));
	wishPool5Star.push_back(Character("Nilou", "Hydro", 5, 330, 240));
	wishPool5Star.push_back(Character("Wriothesley", "Cryo", 5, 400, 180));
	wishPool5Star.push_back(Character("Furina", "Hydro", 5, 350, 230));

	// add wish pool with all 4-star characters
	wishPool4Star.push_back(Character("Amber", "Pyro", 4, 200, 150));
	wishPool4Star.push_back(Character("Barbara", "Hydro", 4, 180, 170));
	wishPool4Star.push_back(Character("Fischl", "Electro", 4, 190, 160));
	wishPool4Star.push_back(Character("Kaeya", "Cryo", 4, 170, 180));
	wishPool4Star.push_back(Character("Lisa", "Electro", 4, 160, 190));
	wishPool4Star.push_back(Character("Xiangling", "Pyro", 4, 200, 170));
	wishPool4Star.push_back(Character("Sucrose", "Anemo", 4, 150, 200));
	wishPool4Star.push_back(Character("Noelle", "Geo", 4, 230, 210));
	wishPool4Star.push_back(Character("Rosaria", "Cryo", 4, 210, 190));
	wishPool4Star.push_back(Character("Yanfei", "Pyro", 4, 190, 200));
	wishPool4Star.push_back(Character("Thoma", "Pyro", 4, 200, 180));
	wishPool4Star.push_back(Character("Diona", "Cryo", 4, 180, 190));
	wishPool4Star.push_back(Character("Kuki Shinobu", "Electro", 4, 210, 180));
	wishPool4Star.push_back(Character("Kirara", "Dendro", 4, 220, 200));
	wishPool4Star.push_back(Character("Chongyun", "Cryo", 4, 240, 210));
	wishPool4Star.push_back(Character("Beidou", "Electro", 4, 250, 190));
	wishPool4Star.push_back(Character("Xingqiu", "Hydro", 4, 220, 220));
	wishPool4Star.push_back(Character("Collei", "Dendro", 4, 180, 210));
	wishPool4Star.push_back(Character("Mika", "Cryo", 4, 200, 200));

	// 3-star characters
	wishPool3Star.push_back(Character("Random Sword", "None", 3, 50, 30));
	wishPool3Star.push_back(Character("Useless Bow", "None", 3, 40, 25));
	srand(time(0)); // Seed random number generator
}

//Perform a wish
Character WishSystem::randomPull() {
	int roll = rand() % 100; // roll from 0 to 99
	if (roll < 1) { // 1% chance for 5-star
		return wishPool5Star[rand() % wishPool5Star.size()];
	}
	else if (roll < 11) { // 10% chance for 4-star
		return wishPool4Star[rand() % wishPool4Star.size()];
	}
	else { // 89% chance for 3-star
		return wishPool3Star[rand() % wishPool3Star.size()];
	}
}

// Perform a wish with a guaranteed 4-star character
Character WishSystem::guarentee4StarPull() {
	return wishPool4Star[rand() % wishPool4Star.size()];
}

//single pull
void WishSystem::singlePull() {
	pullCount++;
	Character pulled = randomPull();


	if (pullCount % 10 == 0) {
		pulled = guarentee4StarPull();
	}
	else {
		pulled = randomPull();
	}

	// Add to wish history (always log the pull)
	if (!characterExists(wishHistory, pulled)) {
		wishHistory.push_back(pulled);
	}

	// Add to obtainedCharacters if 4-star or higher (and not a duplicate)
	if (pulled.getRarity() >= 4 && !characterExists(obtainedCharacters, pulled)) {
		obtainedCharacters.push_back(pulled);
	}

	cout << "You pulled:\n";
	pulled.displayInfo();
}

//ten pull
void WishSystem::tenPull() {
	cout << "\n=========================\n";
	cout << "    Performing 10 Pulls\n";
	cout << "=========================\n";

	for (int i = 0; i < 10; i++) {
		cout << "Pull " << i + 1 << ":\n";
		singlePull();
		cout << "-------------------------\n"; // Add separation for each pull
	}

	cout << "=========================\n";
	cout << "  End of 10-Pull Results\n";
	cout << "=========================\n";
}

//Show wish history
void WishSystem::showWishHistory() const {
	if (wishHistory.empty()) {
		cout << "\nNo wish history available. Try wishing for some characters first!\n";
		return;
	}

	cout << "\n=========================================\n";
	cout << "             Wish History\n";
	cout << "=========================================\n";

	int index = 1;
	for (const auto& character : wishHistory) {
		cout << "Wish " << index++ << ":\n";
		character.displayInfo();
		cout << "-----------------------------------------\n";
	}

	cout << "=========================================\n";
	cout << "         End of Wish History\n";
	cout << "=========================================\n";
}

bool WishSystem::characterExists(const vector<Character>& characters, const Character& character) const {
	for (const auto& existingCharacter : characters) {
		if (existingCharacter.getName() == character.getName()) {
			return true; // Character already exists
		}
	}
	return false; // Character does not exist
}


void WishSystem::saveWishHistoryToFile() const {
	ofstream outFile("wish_history.txt");
	if (!outFile) {
		cerr << "Error: Unable to open file for writing.\n";
		return;
	}
	for (const auto& character : obtainedCharacters) {
		outFile << character.getName() << " "
			<< character.getElement() << " "
			<< character.getRarity() << " "
			<< character.getAttack() << " "
			<< character.getDefense() << "\n";
	}
	outFile.close();
}

void WishSystem::loadWishHistoryFromFile() {
	ifstream inFile("wish_history.txt");
	if (!inFile) {
		cerr << "No existing wish history found. Starting Fresh.\n";
		return;
	}
	string name, element;
	int rarity, attack, defense;
	while (inFile >> name >> element >> rarity >> attack >> defense) {
		obtainedCharacters.push_back(Character(name, element, rarity, attack, defense));
	}
	inFile.close();
}

//Get obtained characters
vector<Character>& WishSystem::getObtainedCharacters() {
	return obtainedCharacters;
}