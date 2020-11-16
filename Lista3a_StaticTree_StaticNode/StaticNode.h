#pragma once

#include <vector>
#include <iostream>


class StaticNode
{

private:
	int value;
	StaticNode* parentPtr;
	std::vector<StaticNode> childrenVector;

public:
	StaticNode(int newValue = 0, StaticNode* parentNode = NULL);

	~StaticNode();

	void setValue(int newValue);

	int getChildrenNumber();

	void addNewChildren(StaticNode newChildren);

	StaticNode* getChild(int whichOne);

	void print();

	void printAllBelow();

};

