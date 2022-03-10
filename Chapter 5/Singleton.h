#pragma once
#include <iostream>

class Singleton {
	Singleton() {
		std::cout << "Singleton()" << std::endl;
	}
public:
	static Singleton *getInstance() {
		static Singleton instance;
		return &instance;
	}
	void print(std::string str, int count) {
		for (int i = 0; i < count; i++)
			std::cout << str << std::endl;
	}
};