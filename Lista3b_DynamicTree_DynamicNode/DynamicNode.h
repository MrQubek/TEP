#pragma once
#include<vector>
#include <iostream>

class DynamicNode
{

private:
	int value;
	DynamicNode* parentPtr;
	std::vector<DynamicNode*> childrenVector;

	void deleteAllChildren();

public:

	DynamicNode(int newValue = 0, DynamicNode* newParent = NULL);

	~DynamicNode();

	void setVal(int newValue);

	int getChildrenNumber();

	void addNewChild();

	DynamicNode* getChildPtr(unsigned int whichOne);

	void print();

	void printAllBelow();

};

