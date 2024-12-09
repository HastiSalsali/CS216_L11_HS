#include "creature.h"


Creature::Creature() { SetCreature(DEFAULT_CREATURE_NAME, MIN_STRENGTH, MIN_HEALTH); }
Creature::Creature(string newName, int newStrength, int newHealth) {
		SetCreature(newName, newStrength, newHealth);
};
Creature::Creature(const Creature &rhs) {
		SetCreature(rhs.name, rhs.strength, rhs.health);
}

void Creature::SetCreature(string newName, int newStrength, int newHealth) {
		try {
				if (newName.length() < MIN_NAME_CHARS) {
						throw CreatureExeption("Name must be at least " +
																													std::to_string(MIN_NAME_CHARS) +
																													" characters long.");
				}
				if (newStrength <= 0) {
						throw CreatureExeption("Strength has to be greater than 0");
				}
				if (newHealth <= 0) {
						throw CreatureExeption("Health has to be greater than 0.");
				}
				name = newName;
				strength = newStrength;
				health = newHealth;
		} catch (CreatureExeption &e) {
				e.printMsg();
		} catch (...) {
				cout << "Unknown exception occured."
									<< "\n";
		}
}
Creature &Creature::operator=(const Creature &other) {
		if (this != &other) {
				SetCreature(other.name, other.strength, other.health);
		}
		return *this;
};
void Creature::SetName(string newName) {
		SetCreature(newName, strength, health);
};
void Creature::SetStrength(int newStrength) {
		SetCreature(name, newStrength, health);
};
void Creature::SetHealth(int newHealth) {
		SetCreature(name, strength, newHealth);
};

void Creature::TakeDamage(int damage) {
		health -= damage >= health ? health : damage;
};

string Creature::GetName() const { return name; };
int Creature::GetStrength() const { return strength; };
int Creature::GetHealth() const { return health; };
int Creature::GetDamage() const { return ((rand() % strength) + 1); };
string Creature::to_string() const {
		return (name + " " + std::to_string(strength) + " " + std::to_string(health));
};
Creature::~Creature() { SetCreature(DEFAULT_CREATURE_NAME, MIN_STRENGTH, MIN_HEALTH); };

ostream &operator<<(ostream &s, const Creature &rhs) {
		s << rhs.to_string();
		return s;
};