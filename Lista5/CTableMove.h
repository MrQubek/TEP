#pragma once

#include "const.h"

#include <string>
#include <iostream>
#include <sstream>

class CTableMove
{
private:
	std::string tabName;
	int* tab;
	int tabSize;

	void initVariables(const std::string& tabName, const int& tabSize);

	void copyTabValues(const CTableMove& otherCTable);

	void copy(const CTableMove& otherCTable);

public:

	CTableMove();

	CTableMove(const std::string& tabName, const int& tabSize);

	CTableMove(const CTableMove& otherCTable);

	~CTableMove();

	CTableMove* pcClone();

	std::string toString();

	std::string getTabName();

	void setTabName(std::string newName);

	bool resizeTab(int newSize);

	int getTabSize();

	int getTabElem(int index);

	void setTabElem(int index, int newElem);

	void printTab();

	CTableMove operator = (const CTableMove& other);

	CTableMove operator + (const CTableMove& other);

	CTableMove operator * (const int value);

	void operator *= (const int value);
};

void modTabSize(CTableMove* tab, int newSize);

void modTabSize(CTableMove tab, int newSize);
