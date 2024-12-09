#include "nuggle.h"

Nuggle::Nuggle() : Creature(){};
Nuggle::Nuggle(string newName, int newStrength, int newHealth)
    : Creature(newName, newStrength, newHealth){};
Nuggle::Nuggle(const Creature &rhs) : Creature(rhs){};
string Nuggle::GetType() const { return "Nuggle"; }
int Nuggle::GetDamage() const {
  int damage = Creature::GetDamage();
  if ((rand() % CHANCE_NUGGLE_ATTACK) == 0) {
    damage += damage;
  }
  return damage;
}