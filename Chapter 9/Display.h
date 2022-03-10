#pragma once
#include <iostream>
#include <string>
class DispalyImpl {
public:
	virtual void rawOpen() = 0;
	virtual void rawPrint() = 0;
	virtual void rawClose() = 0;
};

class StringDisplayImpl : public DispalyImpl {
	std::string m_string;
	int width;
	void printLine() {
		std::cout << "+";
		for (int i = 0; i < width; i++) {
			std::cout << "-";
		}
		std::cout << "+\n";
	}
public:
	StringDisplayImpl(std::string string) : m_string(string), width(string.length()) {
	}
	void rawOpen() {
		this->printLine();
	}
	void rawPrint() {
		std::cout << "|" << m_string << "|\n";
	}
	void rawClose() {
		this->printLine();
	}
};


class Display {
	DispalyImpl *impl;
public:
	Display(DispalyImpl *impl) : impl(impl) {}
	void open() {
		impl->rawOpen();
	}
	void close() {
		impl->rawClose();
	}
	void print() {
		impl->rawPrint();
	}
	void display() {
		open();
		print();
		close();
	}
};

class CountDisplay : public Display {
public:
	CountDisplay(DispalyImpl *impl) : Display(impl) {}
	void multiDisplay(int times) {
		this->open();
		for (int i = 0; i < times; i++) {
			this->print();
		}
		this->close();
	}
};

