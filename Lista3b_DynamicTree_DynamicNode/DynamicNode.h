#pragma once
#include<vector>
#include <iostream>
#include"const.h"

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

	void setValue(int newValue);

	int getValue();

	void setParent(DynamicNode* newParent);

	bool removeFromParent();

	bool removeChildFromVector(DynamicNode* childPtr);

	int getChildrenNumber();

	void addNewChild();

	void addNewChild(DynamicNode* newChildPtr);

	DynamicNode* getChild(unsigned int whichOne);

	DynamicNode* getParentPtr();

	void print();

	void printAllBelow();



};

