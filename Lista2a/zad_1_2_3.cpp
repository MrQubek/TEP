#include "zad_1_2_3.h"

void allocTableAdd5(int tabSize) {
	if (tabSize > 0) {
		int* tab = new (std::nothrow)int[tabSize];
		if (tab != NULL) {
			for (int i = 0; i < tabSize; i++) {
				tab[i] = i + C_5;
			}

			for (int i = 0; i < tabSize; i++) {
				std::cout << tab[i] << C_NEW_LINE;
			}
		}
		delete[]tab;
	}
}

bool allocTable2Dim(int**& tab, int xDim, int yDim) {
	if (xDim > 0 && yDim > 0) {
		tab = new(std::nothrow) int* [xDim];
		if (tab != NULL) {
			for (int i = 0; i < xDim; i++) {
				tab[i] = new(std::nothrow) int[yDim];
				if (tab[i] == NULL) {
					for (int j = i - 1; j >= 0; j--) {
						delete[] tab[i];
					}
					delete[] tab;
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

bool deallocTable2Dim(int**& tab, int xDim, int yDim) {
	if (xDim > 0) {
		for (int i = 0; i < xDim; i++) {
			delete[] tab[i];
		}
		delete[]tab;
		tab = NULL;
		return true;
	}
	return false;
}