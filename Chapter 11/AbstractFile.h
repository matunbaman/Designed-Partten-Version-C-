#pragma once
#include <string>
#include <iostream>
#include <vector>

class Entry {
public:
	virtual std::string getName() = 0;
	virtual int getSize() = 0;
	virtual Entry* add(Entry*){
		return nullptr;
	}
	void printList() {
		printList("");
	}
	std::string toString() {
		return this->getName() + " (" + std::to_string(this->getSize()) + ")";
	}
	virtual void printList(std::string prefix) = 0; 
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
	void printList(std::string prefix) {
		std::cout << prefix + "/" + this->getName() + " (" + std::to_string(this->getSize()) + ")" << std::endl;
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
	Entry* add(Entry* entry) {
		contents.push_back(entry);
		return entry;
	}
	void printList(std::string prefix) {
		std::cout << prefix + "/" + this->getName() + " (" + std::to_string(this->getSize()) + ")" << std::endl;
		for (Entry* entry : contents) {
			entry->printList(prefix + "/" + this->getName());
		}
	}
};
