#pragma once

#include "Trouble.h"
#include <iostream>

class Support {
	std::string name;
	Support *next;
public:
	Support(std::string name) : name(name) {}
	Support* setNext(Support *next) {
		this->next = next;
		return next;
	}
	void support(Trouble *trouble) {
		if (resolve(trouble)) {
			this->done(trouble);
		}
		else if (next != nullptr) {
			next->support(trouble);
		}else {
			this->fail(trouble);
		}
	}
	std::string toString() {
		return "[" + name + "]";
	}
protected:
	virtual bool resolve(Trouble *trouble) = 0;
	void done(Trouble *trouble) {
		std::cout << this->toString() << " resolved " << trouble->toString() << std::endl;
	}
	void fail(Trouble *trouble) {
		std::cout << this->toString() << " failed to resolve " << trouble->toString() << std::endl;
	}
};

class NoSupport : public Support {
public:
	NoSupport(std::string name) : Support(name) {}
protected:
	bool resolve(Trouble *trouble) {
		return false;
	}
};

class LimitSupport : public Support {
	int limit;
public:
	LimitSupport(std::string name, int limit) : Support(name), limit(limit) {}
protected:
	bool resolve(Trouble *trouble) {
		if (trouble->getNumber() < limit) {
			return true;
		}
		else {
			return false;
		}
	}
};

class OddSupport : public Support {
public:
	OddSupport(std::string name) : Support(name) {}
protected:
	bool resolve(Trouble *trouble) {
		if (trouble->getNumber() % 2 == 1) {
			return true;
		}
		else {
			return false;
		}
	}
};

class SpecialSupport : public Support {
	int number;
public:
	SpecialSupport(std::string name, int number) : Support(name), number(number) {}
protected:
	bool resolve(Trouble *trouble) {
		if (trouble->getNumber() == number) {
			return true;
		}
		else {
			return false;
		}
	}
};

