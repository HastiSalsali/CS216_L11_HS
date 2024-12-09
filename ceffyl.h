#ifndef CEFFYL_H
#define CEFFYL_H

#include <string>
#include "creature.h"

const int CEFFYLS_EXTRA_DAMAGE = 45,
	CHANCE_CEFFYLS_ATTACK = 12;

class Ceffyl : public Creature {
public:
		Ceffyl();
		Ceffyl(string, int, int);
		Ceffyl(const Creature &);
		string GetType() const override;
		int GetDamage() const override;
		virtual ~Ceffyl(){};
};

#endif