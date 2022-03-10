#include "AbstractObserver.h"
#include "AbstractGenerator.h"
#include <iostream>

int main(void){
	auto generator = new IncrementalGenerator(5,100,2);
	auto observer = new DigitObserver();
	generator->addObserver(observer);
	generator->execute();
	return 0;
}