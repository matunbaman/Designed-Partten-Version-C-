#include "AbstractFramework.h"

int main(void){
	auto manager = new Manager();
	auto upen = new UnderlinePen('~');
	auto mbox = new MessageBox('*');
	auto sbox = new MessageBox('+');
	manager->reg("upen", upen);
	manager->reg("mbox", mbox);
	manager->reg("sbox", sbox);
	delete upen;
	delete mbox;
	delete sbox;
	auto p1 = manager->create("upen");
	p1->use("Hello, world.");
	auto p2 = manager->create("mbox");
	p2->use("Hello, world.");
	auto p3 = manager->create("sbox");
	p3->use("Hello, world.");

	return 0;
}