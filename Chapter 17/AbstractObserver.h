#pragma once
#include <iostream>
using namespace std;
class AbstractGenerator;
class AbstractObserver {
public:
	virtual void update(AbstractGenerator *generator) = 0;
};

class DigitObserver : public AbstractObserver {
public:
	void update(AbstractGenerator *generator); 
	
};

