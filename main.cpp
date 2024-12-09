// Hasti, Salsali
// CS120 TT- Lab #11
// Battle abstract programming
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "helper.h"
#include "battle.h"

using namespace std;
enum MenuOptions { BATTLE = 1, QUIT };

/*************************************************************/
int main() {
		srand(time(0));

		Battle myBattle;
		int choice;
		cout << "Welcome to the battle simulator!\n";
		do {
				cout << "\nMenu Options:\n"
												"1: Start a new battle\n"
												"2: Quit\n"
												"Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case BATTLE:
						BattleMenuChoice();
						break;
				case QUIT:
						cout << "Exiting program...\n";
						break;
				default:
						FixCinStream("Invalid option, please try again.\n");
				}
		} while (choice != QUIT);
		cout << "End of program";
}

/*************************************************************/
/*
Welcome to the battle simulator!

Menu Options:
1: Start a new battle
2: Quit
Enter your choice: 1
Enter the size of the armies (>0): 
5
Battle between army1 and army2 begins!

Army 1: 
Name:          Type:          Strength:      Health:        
CRT1___________Ceffyl_____________________108_____________65
CRT2___________Nuggle______________________46_____________36
CRT3___________Nuggle______________________96_____________52
CRT4___________Ceffyl______________________57_____________74
CRT5___________Supercefcyl_________________57_____________76

Army 2: 
Name:          Type:          Strength:      Health:        
CRT1___________Nuggle______________________43_____________22
CRT2___________Supercefcyl_________________40_____________65
CRT3___________Nuggle______________________76_____________51
CRT4___________Ceffyl______________________97_____________66
CRT5___________Supercefcyl_________________80_____________27


Battle between CRT1 the Ceffyl from Army 1 and CRT1 the Nuggle from Army 2 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT1 the Ceffyl     |      3|Army 1 |CRT1 the Nuggle     |     19|Army 2 |
|CRT1 the Nuggle     |      2|Army 2 |CRT1 the Ceffyl     |     63|Army 1 |
|CRT1 the Ceffyl     |     55|Army 1 |CRT1 the Nuggle     |      0|Army 2 |

CRT1 the Nuggle from army Army 2 has been defeated!


Battle between CRT2 the Nuggle from Army 1 and CRT2 the Supercefcyl from Army 2 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT2 the Nuggle     |      4|Army 1 |CRT2 the Supercefcyl|     61|Army 2 |
|CRT2 the Supercefcyl|     16|Army 2 |CRT2 the Nuggle     |     20|Army 1 |
|CRT2 the Nuggle     |     40|Army 1 |CRT2 the Supercefcyl|     21|Army 2 |
|CRT2 the Supercefcyl|     25|Army 2 |CRT2 the Nuggle     |      0|Army 1 |

CRT2 the Nuggle from army Army 1 has been defeated!


Battle between CRT3 the Nuggle from Army 2 and CRT3 the Nuggle from Army 1 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT3 the Nuggle     |     33|Army 2 |CRT3 the Nuggle     |     19|Army 1 |
|CRT3 the Nuggle     |     63|Army 1 |CRT3 the Nuggle     |      0|Army 2 |

CRT3 the Nuggle from army Army 2 has been defeated!


Battle between CRT4 the Ceffyl from Army 1 and CRT4 the Ceffyl from Army 2 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT4 the Ceffyl     |      5|Army 1 |CRT4 the Ceffyl     |     61|Army 2 |
|CRT4 the Ceffyl     |     75|Army 2 |CRT4 the Ceffyl     |      0|Army 1 |

CRT4 the Ceffyl from army Army 1 has been defeated!


Battle between CRT5 the Supercefcyl from Army 2 and CRT5 the Supercefcyl from Army 1 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT5 the Supercefcyl|    180|Army 2 |CRT5 the Supercefcyl|      0|Army 1 |

CRT5 the Supercefcyl from army Army 1 has been defeated!


Name:          Type:          Strength:      Health:        
CRT1___________Ceffyl_____________________108_____________63
CRT2___________Nuggle______________________46______________0
CRT3___________Nuggle______________________96_____________19
CRT4___________Ceffyl______________________57______________0
CRT5___________Supercefcyl_________________57______________0
	Total health: 82
Name:          Type:          Strength:      Health:        
CRT1___________Nuggle______________________43______________0
CRT2___________Supercefcyl_________________40_____________21
CRT3___________Nuggle______________________76______________0
CRT4___________Ceffyl______________________97_____________61
CRT5___________Supercefcyl_________________80_____________27
	Total health: 109
The winner is Army 2!

Menu Options:
1: Start a new battle
2: Quit
Enter your choice: hh
Invalid option, please try again.


Menu Options:
1: Start a new battle
2: Quit
Enter your choice: 4
Invalid option, please try again.


Menu Options:
1: Start a new battle
2: Quit
Enter your choice: 1
Enter the size of the armies (>0): 
2
Battle between army1 and army2 begins!

Army 1: 
Name:          Type:          Strength:      Health:        
CRT1___________Ceffyl_____________________108_____________29
CRT2___________Supercefcyl________________117_____________32

Army 2: 
Name:          Type:          Strength:      Health:        
CRT1___________Ceffyl______________________67_____________56
CRT2___________Supercefcyl_________________48_____________43


Battle between CRT1 the Ceffyl from Army 1 and CRT1 the Ceffyl from Army 2 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT1 the Ceffyl     |     94|Army 1 |CRT1 the Ceffyl     |      0|Army 2 |

CRT1 the Ceffyl from army Army 2 has been defeated!


Battle between CRT2 the Supercefcyl from Army 1 and CRT2 the Supercefcyl from Army 2 begins!

|Attacker:           |Damage:|Army:  |Defender:           |Health:|Army:  |
|CRT2 the Supercefcyl|    140|Army 1 |CRT2 the Supercefcyl|      0|Army 2 |

CRT2 the Supercefcyl from army Army 2 has been defeated!


Name:          Type:          Strength:      Health:        
CRT1___________Ceffyl_____________________108_____________29
CRT2___________Supercefcyl________________117_____________32
	Total health: 61
Name:          Type:          Strength:      Health:        
CRT1___________Ceffyl______________________67______________0
CRT2___________Supercefcyl_________________48______________0
	Total health: 0
The winner is Army 1!

Menu Options:
1: Start a new battle
2: Quit
Enter your choice: 2
Exiting program...
End of program 
*/