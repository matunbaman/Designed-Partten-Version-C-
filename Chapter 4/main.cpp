#include "AbstractFactory.h"

int main(void){
	AbstractFactory *factory = new IDCardFactory();
	factory->create("小明");
	factory->create("小红");
	factory->create("小白");
	delete factory;
	return 0;
}
