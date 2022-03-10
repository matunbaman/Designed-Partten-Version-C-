#pragma once
#include <iostream>

class AbstractProduct{
public:
	virtual void use() = 0;
};

class AbstractFactory{
public:
	virtual AbstractProduct *createProduct(std::string owner) = 0;
	virtual void registerProduct(AbstractProduct *product) = 0;

	AbstractProduct *create(std::string owner) {
		auto p = createProduct(owner);
		registerProduct(p);
		return p;
	}
};


class IDCard : public AbstractProduct{
	std::string owner;
public:
	IDCard(std::string& owner) : owner(owner){
		std::cout << "create "<< owner <<" IDCard" << std::endl;
	}
	void use(){
		std::cout << "use "<< owner <<" IDCard" << std::endl;
	}
	std::string getOwner(){
		return owner;
	}
};

class IDCardFactory : public AbstractFactory{
public:
	AbstractProduct *createProduct(std::string owner){
		return new IDCard(owner);
	}
	void registerProduct(AbstractProduct *product){
		std::cout << "register " << static_cast<IDCard*>(product)->getOwner() <<" IDCard" << std::endl;
//错误  std::cout << "register " << product->getOwner() <<" IDCard" << std::endl;

	}
};

