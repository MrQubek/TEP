
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

	void setValue(int newValue);

	void setParent(StaticNode* newParent);

	int getChildrenNumber();

	void addNewChild();
	
	void addNewChild(StaticNode newChildren);

	StaticNode* getChild(unsigned int whichOne);

	void print();

	void printAllBelow();

	void printUp();

};

#endif // !STATICNODE
