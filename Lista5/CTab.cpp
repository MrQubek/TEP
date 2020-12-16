#include "CTab.h"

CTab::CTab(const CTab& cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}

CTab::CTab(CTab&& cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	cOther.i_size = 0;
	std::cout << "MOVE ";
}


CTab::~CTab()
{
	if (pi_tab != NULL)
		delete[] pi_tab;
	std::cout << "Destr ";
}

CTab CTab::operator=(const CTab& cOther)
{
	if (pi_tab != NULL)
		delete[] pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}

CTab CTab::operator=(CTab&& cOther) {
	if (this != &cOther) {
		if (pi_tab != NULL)
			delete[] pi_tab;
		pi_tab = cOther.pi_tab;
		i_size = cOther.i_size;
		cOther.pi_tab = NULL;
		std::cout << "op= MOVE ";
	}
	return(*this);
}

bool CTab::bSetSize(int iNewSize) {
	if (iNewSize != NULL) {
		delete[] pi_tab;
		pi_tab = NULL;
	}
	pi_tab = new(std::nothrow) int[iNewSize];
	if (pi_tab == NULL) {
		i_size = 0;
		return false;
	}
	else
	{
		i_size = iNewSize;
		return true;
	}

}

void CTab::v_copy(const CTab& cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}

CTab cCreateTab()
{
	CTab c_result;
	c_result.bSetSize(5);
	return(c_result);
}