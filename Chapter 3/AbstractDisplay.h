#include <iostream>
class AbstractDisplay {
public:
	virtual	void open() = 0;
	virtual	void print() = 0;
	virtual	void close() = 0;
	void display() {
		open();
		for (int i = 0; i < 5; i++) {
			print();
		}
		close();
	}
};

class CharDisplay : public AbstractDisplay {
	char ch;
public:
	CharDisplay(char ch) {
		this->ch = ch;
	}
	void open() {
		std::cout << "<<";
	}
	void close() {
		std::cout << ">>" << std::endl;
	}
	void print() {
		std::cout << ch;
	}
};

class StringDisplay : public AbstractDisplay {
	std::string str;
public:
	StringDisplay(std::string str) {
		this->str = str;
	}
	void open() {
		printLine();
	}
	void close() {
		printLine();
	}
	void print() {
		std::cout << "|" << str << "|" << std::endl;
	}
	void printLine() {
		std::cout<<"+";
		for (int i = 0; i < str.length(); i++) {
			std::cout << "-";
		}
		std::cout << "+" << std::endl;
		
	}
};