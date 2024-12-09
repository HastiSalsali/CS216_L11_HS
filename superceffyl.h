#ifndef SUPERCEFFYL_H
#define SUPERCEFFYL_H

#include "ceffyl.h"

class Superceffyl : public Ceffyl {
public:
		Superceffyl();
		Superceffyl(string, int, int);
		Superceffyl(const Creature &);
		string GetType() const override;
		int GetDamage() const override;
		~Superceffyl(){};
};

#endif