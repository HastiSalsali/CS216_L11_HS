#ifndef ARMY_H
#define ARMY_H

#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "creature.h"
#include "ceffyl.h"
#include "superceffyl.h"
#include "nuggle.h"
using namespace std;

const int 
ARMY_COLLUMN_SIZE = 15;
const string ARMY_CREATURE_NAME = "CRT";
class Army {
private:
		Creature **ppArmyMembers = nullptr;
		int activeCreatures;

public:
		explicit Army(int = 0);
		Army(const Army &);

		Army &operator=(const Army &);
		void SetArmySize(int);

		void DealocateArmyPointers();
		void TakeDamage(int creatureNum, int damage);

		int GetActiveCreatures() const;
		string GetCreatureName(int) const;
		string GetCreatureFullName(int) const; //name+type
		int GetCreatureStrength(int) const;
		int GetCreatureHealth(int) const;
		string GetCreatureType(int) const;
		int GetCreatureRandDamage(int) const;
		int GetTotalHealth() const;
		bool IsAlive(int) const;

		friend ostream &operator<<(ostream &, const Army &);

		~Army();
};
#endif