#pragma once

#include "StaticNode.h"
#include "const.h"

class StaticTree
{

private:

	StaticNode root;

public:

	StaticTree();

	~StaticTree();

	void buildDefaultTestTree();

	StaticNode* getRoot();

	void printTree();

	bool moveSubtree(StaticNode* newParent, StaticNode* newChild);

	bool from_the_same_tree(StaticNode* first, StaticNode* second);

};

