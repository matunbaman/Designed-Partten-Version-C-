#pragma once
#include <vector>
#include <string>

class Memento {
	int money;
	std::vector<std::string> fruits;
public:
	int getMoney() {
		return money;
	}
private:
	Memento(int money) : money(money) {}
	void addFruit(std::string fruit) {
		this->fruits.push_back(fruit);
	}
	std::vector<std::string> getFruits() {
		return this->fruits;
	}
};

class Gamer {
	int money;
	std::vector<std::string> fruits;
}