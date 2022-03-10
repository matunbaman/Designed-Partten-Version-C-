#include "AbstractGenerator.h"
#include "AbstractObserver.h"



void AbstractGenerator::addObserver(AbstractObserver *observer)
{
	this->observers.push_back(observer);
}

void AbstractGenerator::deleteObserver(AbstractObserver *observer) {
	for (auto it = observers.begin(); it != observers.end(); it++) {
		if (*it == observer) {
			observers.erase(it);
			break;
		}
	}
}

void AbstractGenerator::notifyObservers() {
	for (AbstractObserver *observer : observers) {
		observer->update(this);
	}
}
int RandomGenerator::getNumber() {
	return this->number;
}

void RandomGenerator::execute()
{
	for (int i = 0; i < 50; i++)
	{
		number = i;
		notifyObservers();
	}
}