#include "Singleton.h"
#include <thread>
#include <unistd.h>

void print_func(Singleton *s, std::string str, int count) {
	for (int i = 0; i < count; i++)
		std::cout << str << std::endl;
}

int main(void){
	Singleton *s1 = Singleton::getInstance();
	auto t1 = std::thread(print_func, s1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 100);
	auto t2 = std::thread(print_func, s1, "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", 100);
	t1.join();
	t2.join();
	while(1){
		sleep(1);
	}

	return 0;
}