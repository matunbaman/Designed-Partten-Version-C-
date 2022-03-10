#pragma once
#include "AbstractVisitor.h"
#include <string>

class AbstractElement {
public:
	virtual void accept(AbstractVisitor *visitor) = 0;
};


class Entry : public AbstractElement {
public:
	virtual std::string getName() = 0;
	virtual std::string getSize() = 0;
	virtual Entry* add(Entry* entry){
		return nullptr;
	}
	std::string toString() {
		return this->getName() + " (" + this->getSize() + ")";
	}
};

class File : public Entry {
	std::string name;
	int size;
public:
	File(std::string name, int size) : name(name), size(size) {}
	std::string getName() {
		return name;
	}
	int getSize() {
		return size;
	}
	void accept(AbstractVisitor *visitor) {
		visitor->visit(this);
	}
};

class Directory : public Entry {
	std::string name;
	std::vector<Entry*> contents;
public:
	Directory(std::string name) : name(name) {}
	std::string getName() {
		return name;
	}
	int getSize() {
		int totalSize = 0;
		for (Entry* entry : contents) {
			totalSize += entry->getSize();
		}
		return totalSize;
	}
	void accept(AbstractVisitor *visitor) {
		visitor->visit(this);
	}
	void add(Entry* entry) {
		contents.push_back(entry);
	}
	std::vector &getContents() {
		return contents;
	}
};




