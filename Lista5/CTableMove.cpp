#include "CTableMove.h"


void CTableMove::initVariables(const std::string& tabName, const int& tabSize) {
	setTabName(tabName);

	this->tab = new (std::nothrow) int[tabSize];
	if (this->tab != NULL) {
		this->tabSize = tabSize;
	}
	else {
		this->tabSize = 0;
	}
}

void CTableMove::copyTabValues(const CTableMove& otherCTable) {
	if (tab != NULL) {
		for (int i = 0; i < tabSize; i++) {
			tab[i] = otherCTable.tab[i];
		}
	}
}

void CTableMove::copy(const CTableMove& otherCTable) {
	initVariables(otherCTable.tabName, otherCTable.tabSize);
	copyTabValues(otherCTable);
}

CTableMove::CTableMove() {
	initVariables(CTABLE_DEFAULT_NAME, CTABLE_DEFAULT_SIZE);
	std::cout << CTABLE_NO_PARAM << tabName << C_NEW_LINE;
}

CTableMove::CTableMove(const std::string& tabName, const int& tabSize) {
	initVariables(tabName, tabSize);
	std::cout << CTABLE_PARAMETR << this->tabName << C_NEW_LINE;
}

CTableMove::CTableMove(const CTableMove& otherCTable) {
	initVariables(otherCTable.tabName + CTABLE_COPY, otherCTable.tabSize);
	copyTabValues(otherCTable);
	std::cout << CTABLE_COPING << otherCTable.tabName << C_NEW_LINE;
}

CTableMove::~CTableMove() {
	delete[]tab;
	std::cout << CTABLE_DELETING << tabName << C_NEW_LINE;
}


CTableMove* CTableMove::pcClone() {
	CTableMove* ptr = new CTableMove(this->getTabName(), this->getTabSize());
	ptr->copyTabValues(*this);
	return ptr;
}

std::string CTableMove::toString() {
	std::string st;
	std::stringstream out;

	out.str(tabName + C_SPACE);
	for (int i = 0; i < tabSize; i++) {
		out << tab[i] << C_SPACE;
		st = out.str();
	}
	return st;
}

std::string CTableMove::getTabName() {
	return this->tabName;
}

void CTableMove::setTabName(std::string newName) {
	this->tabName = newName;
}

bool CTableMove::resizeTab(int newSize) {
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

int CTableMove::getTabSize() {
	return tabSize;
}

int CTableMove::getTabElem(int index) {
	if (index < tabSize) {
		return tab[index];
	}
}

void CTableMove::setTabElem(int index, int newElem) {
	if (index < tabSize) {
		tab[index] = newElem;
	}
}

void CTableMove::printTab() {
	std::cout << tabName << C_SPACE;
	for (int i = 0; i < tabSize; i++) {
		std::cout << tab[i] << C_SPACE;
	}
	std::cout << C_NEW_LINE;
}

CTableMove CTableMove::operator = (const CTableMove& other) {
	delete[] tab;
	copy(other);
	return *this;
}

CTableMove CTableMove::operator+ (const CTableMove& other) {
	CTableMove* newTab = new CTableMove(tabName, this->tabSize + other.tabSize);
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

CTableMove CTableMove::operator * (const int value) {
	CTableMove* newTab = new CTableMove(tabName, tabSize);
	for (int i = 0; i < tabSize; i++) {
		newTab->setTabElem(i, this->getTabElem(i) * value);
	}
	return *newTab;
}

void CTableMove::operator *= (const int value) {
	for (int i = 0; i < tabSize; i++) {
		this->setTabElem(i, this->getTabElem(i) * value);
	}
}

void modTabSize(CTableMove* tab, int newSize) {
	tab->resizeTab(newSize);
}

void modTabSize(CTableMove tab, int newSize) {
	tab.resizeTab(newSize);
}
