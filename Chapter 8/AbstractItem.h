#pragma once
#include <string>
#include <vector>
#include <iostream>

class AbstractItem {
protected:
	std::string caption;
public:
	AbstractItem(std::string caption) : caption(caption) {}
	virtual void makeHTML() = 0;
};

class AbstractLink: public AbstractItem {
protected:
	std::string url;
public:
	AbstractLink(std::string caption, std::string url) : AbstractItem(caption), url(url) {}
};

class AbstractTray: public AbstractItem {
protected:
	std::vector<AbstractItem*> tray;
public:
	AbstractTray(std::string caption) : AbstractItem(caption) {}
	void add(AbstractItem *item) {
		tray.push_back(item);
	}
};

class Abstract Page {
protected:
	std::string title;
	std::string author;
	std::vector<AbstractItem*> content;
	Page(std::string title, std::string author) : title(title), author(author) {}
	void add(AbstractItem *item) {
		content.push_back(item);
	}
	virtual std::string makeHTML() = 0;
	void output() {
		std::cout << this->makeHTML() << std::endl;
	}
};
