#pragma once
#include <string>
#include <iostream>

class AbstractBuilder {
public:
	virtual void makeTitle(std::string title) = 0;
	virtual void makeString(std::string str) = 0;
	virtual void makeItems(std::string items[], int) = 0;
	virtual void close() = 0;
};


class TextBuilder : public AbstractBuilder {
	std::string buffer;
public:
	void makeTitle(std::string title) {
		buffer.append("========================\n");
		buffer.append("『" + title + "』\n");
		buffer.append("\n");
	}
	void makeString(std::string str) {
		buffer.append("■" + str + "\n");
		buffer.append("\n");
	}
	void makeItems(std::string items[], int len) {
		for (int i = 0; i < len; i++) {
			buffer.append(" ・" + items[i] + "\n");
		}
	}
	void close() {
		buffer.append("========================\n");
	}
	std::string getResult() {
		return buffer;
	}
};

class Director {
	AbstractBuilder *builder;
public:
	Director(AbstractBuilder *builder) : builder(builder) {
	}
	void construct(){
		builder->makeTitle("Greeting");
		builder->makeString("朝から昼にかけて");
		builder->makeItems(new std::string[2]{"おはようございます", "こんにちは" }, 2);
		builder->close();
	}
};