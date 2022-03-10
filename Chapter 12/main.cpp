#include "AbstractDisplay.h"

int main(void){
	auto b4 = new SideBorder(new FullBorder(new SideBorder(new FullBorder(new StringDisplay("Hello, world.")), '*')), '#');
	b4->show();
	return 0;
}