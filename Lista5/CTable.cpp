#include "CTable.h"


void CTable::initVariables(const std::string& tabName, const int& tabSize) {
	setTabName(tabName);

	this->tab = new (std::nothrow) int[tabSize];
	if (this->tab != NULL) {
		this->tabSize = tabSize;
	}
	else {
		this->tabSize = 0;
	}
}

void CTable::copyTabValues(const CTable& otherCTable) {
	if (tab != NULL) {
		for (int i = 0; i < tabSize; i++) {
			tab[i] = otherCTable.tab[i];
		}
	}
}

void CTable::copy(const CTable& otherCTable) {
	initVariables(otherCTable.tabName, otherCTable.tabSize);
	copyTabValues(otherCTable);
}

CTable::CTable() {
	initVariables(CTABLE_DEFAULT_NAME, CTABLE_DEFAULT_SIZE);
	std::cout << CTABLE_NO_PARAM << tabName << C_NEW_LINE;
}

CTable::CTable(const std::string& tabName, const int& tabSize) {
	initVariables(tabName, tabSize);
	std::cout << CTABLE_PARAMETR << this->tabName << C_NEW_LINE;
}

CTable::CTable(const CTable& otherCTable) {
	initVariables(otherCTable.tabName + CTABLE_COPY, otherCTable.tabSize);
	copyTabValues(otherCTable);
	std::cout << CTABLE_COPING << otherCTable.tabName << C_NEW_LINE;
}

CTable::~CTable() {
	delete[]tab;
	std::cout << CTABLE_DELETING << tabName << C_NEW_LINE;
}


CTable* CTable::pcClone() {
	//CTable* ptr = new CTable(*this);
	CTable* ptr = new CTable(this->getTabName(), this->getTabSize());
	ptr->copyTabValues(*this);
	return ptr;
}

std::string CTable::toString() {
	std::string st;
	std::stringstream out;

	out.str(tabName + C_SPACE);
	for (int i = 0; i < tabSize; i++) {
		out << tab[i] << C_SPACE;
		st = out.str();
	}
	return st;
}

std::string CTable::getTabName() {
	return this->tabName;
}

void CTable::setTabName(std::string newName) {
	this->tabName = newName;
}

bool CTable::resizeTab(int newSize) {
	if (newSize > 0) {
		int* tmpTab = new (std::nothrow) int[newSize];
		if (tmpTab != NULL) {
			for (int i = 0; i < tabSize && i < newSize; i++) {
				tmpTab[i] = tab[i];
			}
			delete[] tab;
			tab = tmpTab;
			tabSize = newSize;
			return true;
		}
	}
	return false;
}

int CTable::getTabSize() {
	return tabSize;
}

int CTable::getTabElem(int index) {
	if (index < tabSize) {
		return tab[index];
	}
}

void CTable::setTabElem(int index, int newElem) {
	if (index < tabSize) {
		tab[index] = newElem;
	}
}

void CTable::printTab() {
	std::cout << tabName << C_SPACE;
	for (int i = 0; i < tabSize; i++) {
		std::cout << tab[i] << C_SPACE;
	}
	std::cout << C_NEW_LINE;
}

CTable CTable::operator = (const CTable& other) {
	delete[] tab;
	copy(other);
	return *this;
}

CTable CTable::operator+ (const CTable& other) {
	CTable* newTab = new CTable(tabName, this->tabSize + other.tabSize);
	if (newTab->getTabSize() != 0) {
		int index = 0;
		for (; index < this->tabSize; index++) {
			newTab->setTabElem(index, tab[index]);
		}
		for (; index < other.tabSize + this->tabSize; index++) {
			newTab->setTabElem(index, other.tab[index - this->tabSize]);
		}
	}
	return *newTab;
}

CTable CTable::operator * (const int value) {
	CTable* newTab = new CTable(tabName, tabSize);
	for (int i = 0; i < tabSize; i++) {
		newTab->setTabElem(i, this->getTabElem(i) * value);
	}
	return *newTab;
}

void CTable::operator *= (const int value) {
	for (int i = 0; i < tabSize; i++) {
		this->setTabElem(i, this->getTabElem(i) * value);
	}
}

void modTabSize(CTable* tab, int newSize) {
	tab->resizeTab(newSize);
}

void modTabSize(CTable tab, int newSize) {
	tab.resizeTab(newSize);
}
