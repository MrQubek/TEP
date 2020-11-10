#include "const.h"
#include "CTable.h"
#include "zad_1_2_3.h"

#include <cstdlib>
#include <iostream>

int main() {

	CTable tab0("tab0",5), tab1("tab1", 5);
	tab0.resizeTab(6);
	tab1.resizeTab(4);
	
	tab0 = tab1;
	tab0.setTabName("tab0");

	tab1.setTabElem(0, 0);
	tab1.setTabElem(1, 1);
	tab1.setTabElem(2, 2);
	tab1.setTabElem(3, 3);
	tab1.setTabElem(4, 4);

	tab0.setTabElem(0, 5);
	tab0.setTabElem(1, 6);
	tab0.setTabElem(2, 7);
	tab0.setTabElem(3, 8);
	tab0.setTabElem(4, 9);

	tab0.printTab();
	tab1.printTab();
	
	CTable tab2;
	tab2 = (tab0 + tab1) * 2 + tab1;

	tab2.printTab();

	tab1 *= 2;
	tab1 *= -3;
	tab1.printTab();

	return 0;
}
