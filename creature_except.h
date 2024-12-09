#ifndef CREATURE_EXCEPT_H
#define CREATURE_EXCEPT_H

#include <string>
#include <iostream>
using namespace std;

class CreatureExeption {
private:
		string message;

public:
		explicit CreatureExeption(string = "Unknown error occured");
		void printMsg();
		~CreatureExeption();
};

#endif