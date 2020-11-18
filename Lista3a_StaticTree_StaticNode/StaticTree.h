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

	bool moveSubtree(StaticNode* newParent, StaticNode* newChild) {
		if (newParent == newChild || newChild == NULL) {
			return false;
		}
		else
		{
			newParent->addNewChild(StaticNode(newChild->getValue(), newParent));
			while (newChild->getChildrenNumber() > 0)
			{
				moveSubtree((newParent->getChild(newParent->getChildrenNumber() - 1)), newChild->getChild(0));
			}
			newChild->removeChildFromParent();
			return true;
		}
	}
};

