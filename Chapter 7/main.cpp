#include "AbstractBuilder.h"

int main(void){
	auto builder = new TextBuilder();
	auto director = new Director(builder);
	director->construct();
	auto result = builder->getResult();
	std::cout << result << std::endl;
	return 0;
}