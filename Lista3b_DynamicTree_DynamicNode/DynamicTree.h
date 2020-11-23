#pragma once

#include"DynamicNode.h"

class DynamicTree
{
private:
	
	DynamicNode * root;

public:

	DynamicTree();

	~DynamicTree();

	DynamicNode* getRoot();

	void printTree();

	bool moveSubtree(DynamicNode* newParent, DynamicNode* newChild);

	void buildDefaultTestTree();

	bool from_the_same_tree(DynamicNode* first, DynamicNode* second);

};
