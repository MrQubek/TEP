
#ifndef STATICNODE
#define STATICNODE

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

	StaticNode(const StaticNode& other);

	StaticNode* operator = (const StaticNode& other);

	void setValue(int newValue);

	int getValue();

	void setParent(StaticNode* newParent);

	int getChildrenNumber();

	void addNewChild();

	void addNewChild(StaticNode newChildren);

	bool removeChildFromParent();

	bool removeChildFromVector(StaticNode* childPtr);

	StaticNode* getChild(unsigned int whichOne);

	void print();

	void printAllBelow();

	void printUp();

	StaticNode* getParentPtr();

};

#endif // !STATICNODE
