#ifndef WishSystem_H
#define WishSystem_H

#include "Character.h"
#include <vector>
using namespace std;

class WishSystem {
private:
	vector<Character> wishPool5Star;
	vector<Character> wishPool4Star;
	vector<Character> wishPool3Star;
	vector<Character> obtainedCharacters;
	vector<Character> wishHistory;
	int pullCount;

	Character randomPull();
	Character guarentee4StarPull();

	bool characterExists(const vector<Character>& characters, const Character& character) const;

public:
	//Constructor
	WishSystem();

	//Methods
	void singlePull();
	void tenPull();
	void showWishHistory() const;
	void saveWishHistoryToFile() const;
	void loadWishHistoryFromFile();
	vector<Character>& getObtainedCharacters();
};

#endif