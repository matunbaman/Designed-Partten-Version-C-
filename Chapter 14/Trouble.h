#pragma once
#include <string>

class Trouble {
	int number;
public:	
	Trouble(int number) : number(number) {}
	int getNumber() {
		return number;
	}
	std::string toString() {
		return "Trouble " + std::to_string(number);
	}
};
