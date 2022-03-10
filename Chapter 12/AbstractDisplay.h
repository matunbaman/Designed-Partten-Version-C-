#pragma once
#include <iostream>
#include <string>

class Display {
public:
	virtual int getColumns() = 0;
	virtual int getRows() = 0;
	virtual std::string getRowText(int row) = 0;
	void show() {
		for (int i = 0; i < getRows(); i++) {
			std::cout << getRowText(i) << std::endl;
		}
	}
};

class StringDisplay : public Display {
	std::string m_string;
public:
	StringDisplay(std::string string) : m_string(string) {}
	int getColumns() {
		return m_string.length();
	}
	int getRows() {
		return 1;
	}
	std::string getRowText(int row) {
		if (row == 0) {
			return m_string;
		}
		else {
			return "";
		}
	}
};
class Border : public Display {
protected:
	Display *m_display;
	Border(Display *display) : m_display(display) {}
};

class SideBorder : public Border {
	char m_borderChar;
public:
	SideBorder(Display *display, char borderChar) : Border(display), m_borderChar(borderChar) {}
	int getColumns() {
		return 1 + m_display->getColumns() + 1;
	}
	int getRows() {
		return m_display->getRows();
	}
	std::string getRowText(int row) {
		return std::string(1, m_borderChar) + m_display->getRowText(row) + std::string(1, m_borderChar);
	}
};

class FullBorder : public Border {
public:
	FullBorder(Display *display) : Border(display) {}
	int getColumns() {
		return 1 + m_display->getColumns() + 1;
	}
	int getRows() {
		return 1 + m_display->getRows() + 1;
	}
	std::string getRowText(int row) {
		if (row == 0 || row == getRows() - 1) {
			return std::string(getColumns(), '-');
		}
		else {
			return std::string(1, '|') + m_display->getRowText(row - 1) + std::string(1, '|');
		}
	}
private:
	std::string makeLine(char ch, int count) {
		std::string str;
		for (int i = 0; i < count; i++) {
			str += ch;
		}
		return str;
	}
};