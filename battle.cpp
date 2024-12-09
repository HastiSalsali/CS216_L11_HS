#include "battle.h"

Battle::Battle() { SetArmySize(0); }
void Battle::SetArmySize(int size) {
		battleArmy[0].SetArmySize(size);
		battleArmy[1].SetArmySize(size);
};

void Battle::CreatureAttack(int creatureNum) {
		int damage, startingArmyIndex = rand() % 2;

		Army *attackArmy = &battleArmy[startingArmyIndex],
							*defenseArmy = &battleArmy[1 - startingArmyIndex], *tempArmy = nullptr;

		cout << "Battle between " << attackArmy->GetCreatureFullName(creatureNum)
							<< " from " << GetArmyName(attackArmy) << " and "
							<< defenseArmy->GetCreatureFullName(creatureNum) << " from "
							<< GetArmyName(defenseArmy)
							<< " begins!\n\n"

										"|"
							<< left << setw(BIG_COLLUMN_WIDTH) << "Attacker:"
							<< "|" << setw(SMALL_COLLUMN_WIDTH) << "Damage:"
							<< "|" << setw(SMALL_COLLUMN_WIDTH) << "Army:"
							<< "|" << setw(BIG_COLLUMN_WIDTH) << "Defender:"
							<< "|" << setw(SMALL_COLLUMN_WIDTH) << "Health:"
							<< "|" << setw(SMALL_COLLUMN_WIDTH) << "Army:"
							<< "|\n";

		while (attackArmy->IsAlive(creatureNum)) {
				damage = attackArmy->GetCreatureRandDamage(creatureNum);
				defenseArmy->TakeDamage(creatureNum, damage);
				cout << "|" << left << setw(BIG_COLLUMN_WIDTH)
									<< attackArmy->GetCreatureFullName(creatureNum) << "|" << right
									<< setw(SMALL_COLLUMN_WIDTH) << damage << "|" << left
									<< setw(SMALL_COLLUMN_WIDTH) << GetArmyName(attackArmy) << "|"
									<< setw(BIG_COLLUMN_WIDTH)
									<< defenseArmy->GetCreatureFullName(creatureNum) << "|" << right
									<< setw(SMALL_COLLUMN_WIDTH)
									<< defenseArmy->GetCreatureHealth(creatureNum) << "|" << left
									<< setw(SMALL_COLLUMN_WIDTH) << GetArmyName(defenseArmy) << "|"
									<< endl;
				tempArmy = attackArmy;
				attackArmy = defenseArmy;
				defenseArmy = tempArmy;
		}
		cout << "\n"
							<< attackArmy->GetCreatureFullName(creatureNum) << " from army "
							<< (attackArmy == &battleArmy[0] ? "Army 1" : "Army 2")
							<< " has been defeated!\n\n\n";
};
string Battle::GetArmyName(Army *pArmy) {
		return (pArmy == &battleArmy[0] ? "Army 1" : "Army 2");
}

void Battle::PrintArmy(int armyNum) const { cout << battleArmy[armyNum]; };
void Battle::PrintWinner() const {
		cout << battleArmy[0] << "Total health: " << battleArmy[0].GetTotalHealth()
							<< "\n"
							<< battleArmy[1] << "Total health: " << battleArmy[1].GetTotalHealth()
							<< "\n";

		cout << "The winner is Army "
							<< (battleArmy[0].GetTotalHealth() > battleArmy[1].GetTotalHealth()
															? "1"
															: "2")
							<< "!\n";
};

void Battle::StartBattle() {
		if (battleArmy[0].GetActiveCreatures() ==
										battleArmy[1].GetActiveCreatures() &&
						battleArmy[0].GetActiveCreatures() > 0) {
				cout << "Battle between army1 and army2 begins!\n\n"
												"Army 1: \n"
									<< battleArmy[0]
									<< "\n"
												"Army 2: \n"
									<< battleArmy[1] << "\n\n";
				for (int i = 0; i < battleArmy[0].GetActiveCreatures(); i++) {
						CreatureAttack(i);
				}
				PrintWinner();
		} else {
				cout << "Program couldn't make the armies. Please try some other time.\n\n";
				battleArmy[0].DealocateArmyPointers();
				battleArmy[1].DealocateArmyPointers();
		}
};
Battle::~Battle(){};
