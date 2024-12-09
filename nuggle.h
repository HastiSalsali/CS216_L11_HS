#ifndef NUGGLE_H
#define NUGGLE_H

#include <string>
#include "creature.h"

const int CHANCE_NUGGLE_ATTACK = 10;

class Nuggle : public Creature {
public:
		Nuggle();
		Nuggle(string, int, int);
		Nuggle(const Creature &);
		string GetType() const override;
		int GetDamage() const override;
		~Nuggle(){};
};
#endif