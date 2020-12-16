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

	void copyTabValues(const CTable& otherCTable);

	void copy(const CTable& otherCTable);

public:

	CTable();

	CTable(const std::string& tabName, const int& tabSize);

	CTable(const CTable& otherCTable);

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

	CTable operator = (const CTable& other);

	CTable operator + (const CTable& other);

	CTable operator * (const int value);

	void operator *= (const int value);
};

void modTabSize(CTable* tab, int newSize);

void modTabSize(CTable tab, int newSize);
