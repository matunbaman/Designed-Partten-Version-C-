#pragma once
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

class Printable {
public:
	virtual void setPrinterName(std::string name) = 0;
	virtual std::string getPrinterName() = 0;
	virtual void print(std::string str) = 0;
};

class Printer : public Printable {
	std::string name;
	void heavyJob(std::string name){
		std::cout << "Printer " << name << " is printing a job" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << ".";
			std::flush(std::cout);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		std::cout << "Done" << std::endl;
	}

public:
	Printer(std::string name): name(name) {
		this->heavyJob(name);
	}
	std::string getPrinterName() {
		return this->name;
	}
	void setPrinterName(std::string name) {
		this->name = name;
	}
	void print(std::string str) {
		std::cout << "Printer " << this->name << " prints " << str << std::endl;
	}
};

class PrinterProxy : public Printable {
	std::string name;
	Printer *real;
public:
	PrinterProxy(std::string name): name(name), real(nullptr) {}
	void setPrinterName(std::string name) {
		if(this->real != nullptr) {
			this->real->setPrinterName(name);
		}
		this->name = name;
	}
	std::string getPrinterName() {
		return this->name;
	}
	void print(std::string str) {
		if(this->real == nullptr) {
			this->real = new Printer(this->name);
		}
		this->real->print(str);
	}
};
