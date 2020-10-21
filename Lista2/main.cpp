#include "const.h"
#include "CTable.h"
#include "zad_1_2_3.h"

#include <cstdlib>
#include <iostream>

int main() {

	allocTableAdd5(C_5);

	int** tab = NULL;

	std::cout << C_NEW_LINE;
	if (allocTable2Dim(tab, X_DIM, Y_DIM)) {
		std::cout << C_OK;
	}
	else {
		std::cout << C_NOPE;
	}
	std::cout << C_NEW_LINE;
	if (deallocTable2Dim(tab, X_DIM, Y_DIM)) {
		std::cout << C_OK;
	}
	else {
		std::cout << C_NOPE;
	}
	std::cout << C_NEW_LINE << C_NEW_LINE;

	CTable* tab1 = new CTable();
	std::cout << tab1->toString()<<C_NEW_LINE;

	CTable* tab2 = new CTable(*tab1);
	CTable* tab3 = tab1->pcClone();

	tab2->setTabElem(0, 0);
	tab3->setTabElem(1, 0);

	std::cout << C_NEW_LINE << tab1->toString();
	std::cout << C_NEW_LINE << tab2->toString();
	std::cout << C_NEW_LINE << tab3->toString()<<C_NEW_LINE;

	modTabSize(*tab1, 2);
	std::cout << C_NEW_LINE << tab1->toString();
	modTabSize(tab1, 2);
	std::cout << C_NEW_LINE << tab1->toString() << C_NEW_LINE;

	delete tab1;
	delete tab2;
	delete tab3;

	return 0;
}