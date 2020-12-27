#pragma once

#include"const.h"
#include<iostream>

class parentClass
{
public:
	parentClass();
	~parentClass();

	virtual void print();

private:

};

parentClass::parentClass()
{

}

parentClass::~parentClass()
{

}

void parentClass::print() {
	std::cout << "Parent class here" << C_NEW_LINE;
}

class childClass: public parentClass
{
public:
	childClass();
	~childClass();

	void print();

private:

};

childClass::childClass()
{
}

childClass::~childClass()
{
}

inline void childClass::print()
{
	std::cout << "Child class here" << C_NEW_LINE;
}
