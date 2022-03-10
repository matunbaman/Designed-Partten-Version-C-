#pragma once

#include "AbstractElement.h"

class AbstractVisitor {
	virtual void visit(Directory *directory) = 0;
	virtual void visit(File *file) = 0;
};

class ListVisitor : public AbstractVisitor {
	std::string currentPath;
public:
	void visit(Directory *directory) {
		std::cout << currentPath + "/" + directory->getName() + " (" + std::to_string(directory->getSize()) + ")" << std::endl;
		currentPath += "/" + directory->getName();
		for (Entry *entry : directory->getContents()) {
			entry->accept(this);
		}
		currentPath = currentPath.substr(0, currentPath.find_last_of("/"));
	}
};
