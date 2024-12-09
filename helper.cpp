#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "battle.h"

using namespace std;

void FixCinStream(string errorMsg) {
  cout << errorMsg << endl;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int AskForArmySize() {
  int armySize;
  cout << "Enter the size of the armies (>0): \n";
  cin >> armySize;
  while (!cin || armySize <= 0) {
    FixCinStream(
        "Invalid input please try again.\nEnter the size of the armies "
        "(>0): \n");
    cin >> armySize;
  };
  return armySize;
};
void BattleMenuChoice(){
    Battle myBattle;
    int armySize = AskForArmySize();
    myBattle.SetArmySize(armySize);
    myBattle.StartBattle();
}