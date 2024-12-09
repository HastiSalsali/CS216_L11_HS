#include "superceffyl.h"

Superceffyl::Superceffyl() : Ceffyl(){};
Superceffyl::Superceffyl(string newName, int newStrength, int newHealth)
				: Ceffyl(newName, newStrength, newHealth){};
Superceffyl::Superceffyl(const Creature &rhs) : Ceffyl(rhs){};
string Superceffyl::GetType() const { return "Supercefcyl"; };
int Superceffyl::GetDamage() const {
		return (Ceffyl::GetDamage() + Ceffyl::GetDamage());
};