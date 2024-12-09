#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include "creature_except.h"

using namespace std;

const int MIN_STRENGTH = 40, MAX_STRENGTH = 120, MIN_HEALTH = 20,
	MAX_HEALTH = 80, MIN_NAME_CHARS = 3,
CREATURE_TYPE_COUNT = 3;
const string DEFAULT_CREATURE_NAME = "N/A";
enum CreatureType { CEFFYL = 0, SUPERCEFFYL, NUGGLE };

class Creature {
protected:
		string name = DEFAULT_CREATURE_NAME;
		int strength = MIN_STRENGTH;
		int health = MIN_HEALTH;

public:
		Creature();
		Creature(string, int, int);
		Creature(const Creature &);

		void SetCreature(string newName, int newStrength, int newHealth);
		Creature &operator=(const Creature &);
		void SetName(string);
		void SetStrength(int);
		void SetHealth(int);

		void TakeDamage(int);

		string GetName() const;
		int GetStrength() const;
		int GetHealth() const;
		virtual int GetDamage() const;
		virtual string GetType() const = 0;
		string to_string() const;

		friend ostream &operator<<(ostream &, const Creature &);

		virtual ~Creature();
};

#endif