#pragma once

class AbstractFactory {
public:
	AbstractFactory *getFactory(std::string factoryName) {
		if (factoryName == "TextFactory") {
			return new TextFactory();
		}
		else if (factoryName == "HtmlFactory") {
			return new HtmlFactory();
		}
		else {
			return nullptr;
		}
	}
};