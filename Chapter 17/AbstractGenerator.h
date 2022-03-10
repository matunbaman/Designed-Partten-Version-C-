#pragma once
#include <vector>
#include <random>
#include <iostream>
class AbstractObserver;

class AbstractGenerator {
	std::vector<AbstractObserver*> observers;
public:
	void addObserver(AbstractObserver *observer);
	void deleteObserver(AbstractObserver *observer); 
	void notifyObservers(); 
	virtual int getNumber() = 0;
	virtual void execute() = 0;
};

class RandomGenerator : public AbstractGenerator {
	int number;
public:
	int getNumber();
	void execute();
};

class IncrementalGenerator : public AbstractGenerator {
	int number;
	int start;
	int stop;
	int step;
public:
	IncrementalGenerator(int start, int stop, int step){
		this->start = start;
		this->stop = stop;
		this->step = step;
		this->number = start;
	}
	int getNumber(){
		return this->number;
	}
	void execute(){
		while (this->number < this->stop) {
			this->number += this->step;
			notifyObservers();
		}
	}
};