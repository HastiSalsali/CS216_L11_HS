#include "creature_except.h"

CreatureExeption::CreatureExeption(string newMessage) { message = newMessage; };
void CreatureExeption::printMsg() {
		cout << message << "\nAll values reset to original or default\n";
};
CreatureExeption::~CreatureExeption() { message = ""; };