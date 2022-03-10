#include "AbstractSupport.h"
#include "Trouble.h"

int main(void){
	auto alice = new NoSupport("Alice");
	auto bob  = new LimitSupport("Bob", 100);
	auto charlie = new SpecialSupport("Charlie", 429);
	auto diana = new LimitSupport("Diana", 200);
	auto elmo = new OddSupport("Elmo");
	auto fred = new LimitSupport("Fred", 300);
	alice->setNext(bob)->setNext(charlie)->setNext(diana)->setNext(elmo)->setNext(fred);
	for (int i = 0; i < 500;i++)
		alice->support(new Trouble(i));
	return 0;
}