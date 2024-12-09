#include "ceffyl.h"

Ceffyl::Ceffyl() : Creature(){};
Ceffyl::Ceffyl(string newName, int newStrength, int newHealth)
				: Creature(newName, newStrength, newHealth){};
Ceffyl::Ceffyl(const Creature &rhs) : Creature(rhs){};
string Ceffyl::GetType() const { return "Ceffyl"; }
int Ceffyl::GetDamage() const {
		int damage = Creature::GetDamage();
		if ((rand() % 100) < CHANCE_CEFFYLS_ATTACK) {
				damage += CEFFYLS_EXTRA_DAMAGE;
		}
		return damage;
};