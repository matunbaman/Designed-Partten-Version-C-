#include "Display.h"

int main(void){
	Display *d1 = new CountDisplay(new StringDisplayImpl("Hello, world."));
	static_cast<CountDisplay *>(d1)->multiDisplay(5);
	return 0;
}