#include "const.h"
#include "CTable.h"
#include "zad_1_2_3.h"

#include <cstdlib>
#include <iostream>

int main() {

	CTable tab0, tab1;
	tab0.resizeTab(6);
	tab1.resizeTab(4);
	tab0 = tab1;
	
	tab1.setTabElem(2, 123);
	tab0.printTab();
	tab1.printTab();
	
	int* ptr = tab0 + tab1;
	for (int i = 0; i < tab0.getTabSize() + tab1.getTabSize();i++) {
		std::cout << ptr[i] << C_SPACE;
	}
	delete[]ptr;
	return 0;
}
