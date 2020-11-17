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
};

