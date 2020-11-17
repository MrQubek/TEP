#pragma once

#include"DynamicNode.h"

class DynamicTree
{
private:
	
	DynamicNode * root;

public:

	DynamicTree() {
		root = new DynamicNode();
	}

	~DynamicTree() {
		root->~DynamicNode();
		delete root;
	}

	DynamicNode* getRoot() {
		return root;
	}

	void printTree() {
		root->printAllBelow();
	}

};

