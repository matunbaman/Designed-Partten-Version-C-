#include "Printable.h"

int main(void){
	Printable *p1 = new PrinterProxy("Alice");
	for (int i = 0; i < 4; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "*";
		std::flush(std::cout);
	}
	std::cout << std::endl;
	p1->setPrinterName("Bob");
	p1->print("Hello World");
	return 0;
}