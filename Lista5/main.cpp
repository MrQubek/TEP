
#include"CTable.h"
#include"CTableMove.h"
#include"SmartPointer.h"
#include"CTab.h"
#include"testClasses.h"

int main() {

	{
		std::cout << C_NEW_LINE << C_TILDES << ZAD_1_2 << C_TILDES << C_NEW_LINE;

		int* testInt = new int(4);
		std::cout << (*testInt)++ << C_NEW_LINE;
		SmartPointer<int> sPtrInt(testInt);
		std::cout << *sPtrInt << C_NEW_LINE;

		std::string* testString = new std::string("napis");
		std::cout << *testString << C_NEW_LINE;
		SmartPointer<std::string> sPtrString(testString);
		*sPtrString += " 2";
		std::cout << *sPtrString << C_NEW_LINE;

		std::string* testStringSecond = new std::string("test string");
		SmartPointer<std::string> testStringDuplicate(testStringSecond);
		testStringDuplicate = sPtrString.duplicate();
		*testStringDuplicate += " duplicate";
		std::cout << *sPtrString << C_NEW_LINE;
		std::cout << *testStringDuplicate << C_NEW_LINE;

		//delete testInt;
		//delete testString;

		int test = 4;
		//delete& test;
	}

	{
		std::cout << C_NEW_LINE << C_TILDES << ZAD_4 << C_TILDES << C_NEW_LINE;
		CTab cTab;
		cTab = std::move(cCreateTab());
	}

	{
		std::cout << C_NEW_LINE << C_TILDES << ZAD_5 << C_SPACE << CTABLE_DEFAULT_NAME << C_TILDES << C_NEW_LINE;
		CTable tab0("tab0", 5), tab1("tab1", 5);
		tab0.resizeTab(6);
		tab1.resizeTab(4);

		std::cout << C_NEW_LINE;

		tab0 = tab1;
		tab0.setTabName("tab0");

		std::cout << C_NEW_LINE;

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

		std::cout << C_NEW_LINE;

		CTable tab2;
		tab2 = (tab0 + tab1) * 2 + tab1;
		tab2.printTab();

		std::cout << C_NEW_LINE;

		tab1 *= 2;
		tab1 *= -3;
		tab1.printTab();
	}
	{
		std::cout << C_NEW_LINE << C_TILDES << ZAD_5 << C_SPACE << CTABLE_MOVE_DEFAULT_NAME << C_TILDES << C_NEW_LINE;
		CTableMove tab00("tab0", 5), tab10("tab1", 5);
		tab00.resizeTab(6);
		tab10.resizeTab(4);

		std::cout << C_NEW_LINE;

		tab00 = tab10;
		tab00.setTabName("tab0");

		std::cout << C_NEW_LINE;

		tab10.setTabElem(0, 0);
		tab10.setTabElem(1, 1);
		tab10.setTabElem(2, 2);
		tab10.setTabElem(3, 3);
		tab10.setTabElem(4, 4);

		tab00.setTabElem(0, 5);
		tab00.setTabElem(1, 6);
		tab00.setTabElem(2, 7);
		tab00.setTabElem(3, 8);
		tab00.setTabElem(4, 9);

		tab00.printTab();
		tab10.printTab();

		std::cout << C_NEW_LINE;

		CTableMove tab20;
		tab20 = (tab00 + tab10) * 2 + tab10;
		tab20.printTab();

		std::cout << C_NEW_LINE;

		tab10 *= 2;
		tab10 *= -3;
		tab10.printTab();

		std::cout << C_NEW_LINE;
	}

	{
		std::cout << C_TILDES << C_NEW_LINE;
		
		/*parentClass parent;
		parent.print();
		childClass child;
		child.print();

		childClass * childPtr = &child;

		parentClass* parentPtr = &parent;
		parentPtr->print();
		if (parentPtr = dynamic_cast<parentClass*>(childPtr)) {
			parentPtr->print();
		}*/

		/*parentClass* parentPtr = &parent;
		childClass* childPtr;
		if (childPtr = dynamic_cast<childClass*>(parentPtr)) {
			childPtr->print();
		}*/

		SmartPointer<parentClass> parent(new parentClass());
		SmartPointer<childClass> child(new childClass());

		parent->print();
		child->print();

		parent = child.dynamicCast<parentClass>();
		parent->print();

	}

	return 0;
}
