#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class AbstractProduct {
public:
	virtual void use(std::string ) = 0;
	virtual AbstractProduct *clone() = 0;
};

class Manager {
public:
	void reg(string name, AbstractProduct *product) {
		showcase[name] = product->clone();
	}
	AbstractProduct *create(std::string name) {
		return showcase[name]->clone();
	}
private:
	std::map <std::string, AbstractProduct*> showcase;
};

class MessageBox : public AbstractProduct {
	char decochar;
public:
	MessageBox(char decochar) : decochar(decochar) {}
	void use(std::string s){
		int length = s.length();
		for (int i = 0; i < length + 4; i++) {
			std::cout << decochar;
		}
		std::cout << std::endl;
		std::cout << decochar << " " << s << " " << decochar << std::endl;
		for (int i = 0; i < length + 4; i++) {
			std::cout << decochar;
		}
		std::cout << std::endl;
	}
	AbstractProduct *clone() {
		return new MessageBox(decochar);
	}
};

class UnderlinePen : public AbstractProduct {
	char ulchar;
public:
	UnderlinePen(int ulchar) : ulchar(ulchar) {}
	void use(std::string s) {
		std::cout << "\"" << s << "\"" << std::endl;
		int length = s.length();
		std::cout << " ";
		for (int i = 0; i < length; i++) {
			std::cout << ulchar;
		}
		std::cout << std::endl;
	}
	AbstractProduct *clone() {
		return new UnderlinePen(ulchar);
	}
};
