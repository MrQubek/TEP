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
	//tu rzuca wyjatkiem dotyczacym kopca
	return 0;
}