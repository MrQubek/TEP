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

	void setParent(DynamicNode* newParent);

	bool deleteChild(DynamicNode* childPtr);

	int getChildrenNumber();

	void addNewChild();

	void addNewChild(DynamicNode* newChildPtr);

	DynamicNode* getChildPtr(unsigned int whichOne);

	DynamicNode* getParentPtr();

	void print();

	void printAllBelow();

};

