#include "AbstractObserver.h"
#include "AbstractGenerator.h"
#include <chrono>
#include <thread>

void DigitObserver::update(AbstractGenerator *generator) {
	std::cout << generator->getNumber() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
