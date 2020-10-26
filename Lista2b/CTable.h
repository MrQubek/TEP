#pragma once

#include "const.h"

#include <string>
#include <iostream>
#include <sstream>

class CTable
{
private:
	std::string tabName;
	int* tab;
	int tabSize;

	void initVariables(const std::string& tabName, const int& tabSize);

	void copyTabValues(const CTable& oldCTable);

public:

	CTable();

	CTable(const std::string& tabName, const int& tabSize);

	CTable(const CTable& oldCTable);

	~CTable();

	CTable* pcClone();

	std::string toString();

	std::string getTabName();

	void setTabName(std::string newName);

	bool resizeTab(int newSize);

	int getTabSize();

	int getTabElem(int index);

	void setTabElem(int index, int newElem);

	void printTab();

	int* operator+ (const CTable & other);

	int operator = (const CTable& other);
};

void modTabSize(CTable* tab, int newSize);

void modTabSize(CTable tab, int newSize);
