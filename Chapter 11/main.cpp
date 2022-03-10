#include "AbstractFile.h"

int main(void){
	Directory *dir = new Directory("");
	File *file1 = new File("file1",100);
	dir->add(file1);
	dir->printList("");
	file1->toString();
	return 0;
}