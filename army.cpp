#include "army.h"

Army::Army(int size) { SetArmySize(size); };
Army::Army(const Army &rhs) {
  try {
    ppArmyMembers = new Creature *[rhs.activeCreatures] { nullptr };
    string type;
    for (int i = 0; i < rhs.activeCreatures; i++) {
      type = rhs.ppArmyMembers[i]->GetType();
      if (type == "Ceffyl") {
        ppArmyMembers[i] = new Ceffyl(*(rhs.ppArmyMembers[i]));
      } else if (type == "Superceffyl") {
        ppArmyMembers[i] = new Superceffyl(*(rhs.ppArmyMembers[i]));
      } else if (type == "Nuggle") {
        ppArmyMembers[i] = new Nuggle(*(rhs.ppArmyMembers[i]));
      }
    }
    activeCreatures = rhs.activeCreatures;
  } catch (bad_alloc) {
    cout << "Program couldn't create an army of " << rhs.activeCreatures
         << "members. Empty army created.\n";
    DealocateArmyPointers();
  } catch (...) {
    cout << "Unknown exception occured.\nEmpty army created.\n";
    DealocateArmyPointers();
  }
};

void Army::SetArmySize(int size) {
  Creature **ppOldArmyMembers = ppArmyMembers;
  if (size == 0) {
    activeCreatures = 0;
    DealocateArmyPointers();
  } else {
    try {
      int random, randHealth, randStrength;
      string newName;
      CreatureType creatureType;

      ppArmyMembers = new Creature *[size] { nullptr };
      for (int i = 0; i < size; i++) {
        random = rand() % CREATURE_TYPE_COUNT;
        randHealth = rand() % (MAX_HEALTH - MIN_HEALTH + 1) + MIN_HEALTH;
        randStrength =
            rand() % (MAX_STRENGTH - MIN_STRENGTH + 1) + MIN_STRENGTH;
        newName = ARMY_CREATURE_NAME + to_string(i + 1);
        creatureType = static_cast<CreatureType>(random);
        switch (creatureType) {
        case CEFFYL:
          ppArmyMembers[i] = new Ceffyl(newName, randStrength, randHealth);
          break;
        case SUPERCEFFYL:
          ppArmyMembers[i] = new Superceffyl(newName, randStrength, randHealth);
          break;
        case NUGGLE:
          ppArmyMembers[i] = new Nuggle(newName, randStrength, randHealth);
          break;
        }
        activeCreatures = size;
      }
    } catch (bad_alloc) {
      cout << "Program couldn't create an army of " << ppArmyMembers
           << " members.\n"
              "Army remains unchanged or empty army is created.\n";
      DealocateArmyPointers();
      ppArmyMembers = ppOldArmyMembers;
    } catch (...) {
      cout << "Unknown exception occured.\n";
      activeCreatures = 0;
      DealocateArmyPointers();
      ppArmyMembers = ppOldArmyMembers;
    }
  }
}

Army &Army::operator=(const Army &rhs) {
  if (this != &rhs) {
    Creature **ppOldArmyMembers = ppArmyMembers;
    try {
      ppArmyMembers = new Creature *[rhs.activeCreatures] { nullptr };
      for (int i = 0; i < rhs.activeCreatures; i++) {
        if (rhs.ppArmyMembers[i]->GetType() == "Ceffyl") {
          ppArmyMembers[i] = new Ceffyl(*(rhs.ppArmyMembers[i]));
        } else if (rhs.ppArmyMembers[i]->GetType() == "Superceffyl") {
          ppArmyMembers[i] = new Superceffyl(*(rhs.ppArmyMembers[i]));
        } else if (rhs.ppArmyMembers[i]->GetType() == "Nuggle") {
          ppArmyMembers[i] = new Nuggle(*(rhs.ppArmyMembers[i]));
        }
      }
      activeCreatures = rhs.activeCreatures;
    } catch (bad_alloc) {
      cout << "Program couldn't create an army of " << rhs.activeCreatures
           << "members. Army remains unchanged .\n";
      DealocateArmyPointers();
      ppArmyMembers = ppOldArmyMembers;
      throw;
    } catch (...) {
      cout << "Unknown exception occured. Army remains unchanged.\n";
      DealocateArmyPointers();
      ppArmyMembers = ppOldArmyMembers;
      throw;
    }
  }
  return *this;
};
void Army::DealocateArmyPointers() {
  if (ppArmyMembers != nullptr) {
    for (int i = 0; i < activeCreatures; i++) {
      if (ppArmyMembers[i] != nullptr) {
        delete ppArmyMembers[i];
        ppArmyMembers[i] = nullptr;
      }
    }
    delete[] ppArmyMembers;
    ppArmyMembers = nullptr;
  }
  activeCreatures = 0;
};
int Army::GetActiveCreatures() const { return activeCreatures; }
ostream &operator<<(ostream &ss, const Army &myArmy) {

  ss << left << setw(ARMY_COLLUMN_SIZE) << "Name:" << setw(ARMY_COLLUMN_SIZE)
     << "Type: " << setw(ARMY_COLLUMN_SIZE)
     << "Strength: " << setw(ARMY_COLLUMN_SIZE) << "Health: " << endl;
  for (int i = 0; i < myArmy.activeCreatures; i++) {
    ss << setfill('_') << left << setw(ARMY_COLLUMN_SIZE)
       << myArmy.ppArmyMembers[i]->GetName() << setw(ARMY_COLLUMN_SIZE)
       << myArmy.ppArmyMembers[i]->GetType() << right << setw(ARMY_COLLUMN_SIZE)
       << myArmy.ppArmyMembers[i]->GetStrength() << setw(ARMY_COLLUMN_SIZE)
       << myArmy.ppArmyMembers[i]->GetHealth() << setw(ARMY_COLLUMN_SIZE)
       << setfill(' ') << endl;
  }
  return ss;
}

string Army::GetCreatureName(int creatureNum) const {
  return ppArmyMembers[creatureNum]->GetName();
};
string Army::GetCreatureFullName(int creatureNum) const {
  return ppArmyMembers[creatureNum]->GetName() + " the " +
         ppArmyMembers[creatureNum]->GetType();
}
int Army::GetCreatureStrength(int creatureNum) const {
  return ppArmyMembers[creatureNum]->GetStrength();
};
int Army::GetCreatureHealth(int creatureNum) const {
  return ppArmyMembers[creatureNum]->GetHealth();
};
string Army::GetCreatureType(int creatureNum) const {
  return ppArmyMembers[creatureNum]->GetType();
}
int Army::GetTotalHealth() const {
  int totalHealth = 0;
  for (int i = 0; i < activeCreatures; i++) {
    totalHealth += ppArmyMembers[i]->GetHealth();
  }
  return totalHealth;
};
void Army::TakeDamage(int creatureNum, int damage) {
  ppArmyMembers[creatureNum]->TakeDamage(damage);
};
bool Army::IsAlive(int creatureNum) const {
  return (ppArmyMembers[creatureNum]->GetHealth() > 0);
};

int Army::GetCreatureRandDamage(int creatureNum) const {
  return (ppArmyMembers[creatureNum]->GetDamage());
}
Army::~Army() { DealocateArmyPointers(); };
