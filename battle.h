#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "creature.h"
#include "ceffyl.h"
#include "superceffyl.h"
#include "nuggle.h"
#include "army.h"
using namespace std;

const int NUM_ARMIES_IN_BATTLE = 2, SMALL_COLLUMN_WIDTH = 7,
BIG_COLLUMN_WIDTH = 20;

class Battle {
private:
		Army battleArmy[NUM_ARMIES_IN_BATTLE];

public:
		Battle();
		void SetArmySize(int);

		void StartBattle();
		void CreatureAttack(int);

		string GetArmyName(Army *);
		void PrintArmy(int) const;
		void PrintWinner() const;

		~Battle();
};

#endif