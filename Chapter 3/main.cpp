#include "AbstractDisplay.h"


int main(void){
	AbstractDisplay *d1 = new CharDisplay('H');
	AbstractDisplay *d2 = new StringDisplay("你好，世界");
	d1->display();
	d2->display();
	delete d1;
	delete d2;
	return 0;
}