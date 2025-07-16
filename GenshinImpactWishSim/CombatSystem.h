#ifndef CombatSystem_H
#define CombatSystem_H

#include "Character.h"
#include "Enemy.h"
#include <vector>

class CombatSystem {
public:
	void startCombat(vector<Character>& obtainedCharacters);
};


#endif // !CombatSystem_H
