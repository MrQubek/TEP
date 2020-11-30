#include "StaticTree.h"

StaticTree::StaticTree() {}

StaticTree::~StaticTree() {}

void StaticTree::buildDefaultTestTree() {
	root.addNewChild();
	root.addNewChild();
	root.getChild(0)->setValue(NODE_1_VAL);
	root.getChild(1)->setValue(NODE_2_VAL);
	root.getChild(0)->addNewChild();
	root.getChild(0)->addNewChild();
	root.getChild(0)->getChild(0)->setValue(NODE_11_VAL);
	root.getChild(0)->getChild(1)->setValue(NODE_12_VAL);
	root.getChild(1)->addNewChild();
	root.getChild(1)->addNewChild();
	root.getChild(1)->getChild(0)->setValue(NODE_21_VAL);
	root.getChild(1)->getChild(1)->setValue(NODE_22_VAL);
}

StaticNode* StaticTree::getRoot() {
	return &root;
}

void StaticTree::printTree() {
	std::vector<StaticNode* > nodesToPrint;
	nodesToPrint.push_back(&root);
	int nodesAtCurrentLvl = 1;
	int nodesAtNextLvl = 0;
	do {
		std::cout << nodesToPrint[0]->getValue() << SPACE << nodesToPrint[0]->getChildrenNumber() << SEPARATOR;
		nodesAtCurrentLvl--;
		for (size_t i = 0; i < nodesToPrint[0]->getChildrenNumber(); i++)
		{
			nodesToPrint.push_back(nodesToPrint[0]->getChild(i));
			nodesAtNextLvl++;
		}
		nodesToPrint.erase(nodesToPrint.begin());
		if (nodesAtCurrentLvl == 0) {
			nodesAtCurrentLvl = nodesAtNextLvl;
			nodesAtNextLvl = 0;
			std::cout << NEW_LINE;
		}
	} while (!nodesToPrint.empty());
}

bool StaticTree::moveSubtree(StaticNode* newParent, StaticNode* newChild) {
	if (newParent == NULL || newChild == NULL) {
		return false;
	}
	else {
		newParent->addNewChild(*newChild);
		if (newChild->getParentPtr()!=NULL)
		{
			newChild->removeChildFromParent();
		}
		return true;
	}
}

bool StaticTree::fromTheSameTree(StaticNode* first, StaticNode* second) {
	if (first->getParentPtr() == NULL && second->getParentPtr() == NULL) {
		if (first == second) {
			return true;
		}
		else
		{
			return false;
		}
	}
	else {
		if (first->getParentPtr() != NULL) {
			return (fromTheSameTree(first->getParentPtr(), second));
		}
		else if (second->getParentPtr() != NULL)
		{
			return (fromTheSameTree(first, second->getParentPtr()));
		}
	}
}