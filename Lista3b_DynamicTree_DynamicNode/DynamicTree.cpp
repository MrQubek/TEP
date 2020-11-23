#include "DynamicTree.h"

DynamicTree::DynamicTree() {
	root = new DynamicNode();
}

DynamicTree::~DynamicTree() {
	delete root;
}

DynamicNode* DynamicTree::getRoot() {
	return root;
}

void DynamicTree::printTree() {
	std::vector<DynamicNode* > nodesToPrint;
	nodesToPrint.push_back(root);
	int nodesAtCurrentLvl = 1;
	int nodesAtNextLvl = 0;
	do {
		std::cout << nodesToPrint[0]->getValue() << SPACE << nodesToPrint[0]->getChildrenNumber() << SEPARATOR;
		nodesAtCurrentLvl--;
		for (unsigned int i = 0; i < nodesToPrint[0]->getChildrenNumber(); i++)
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

bool DynamicTree::moveSubtree(DynamicNode* newParent, DynamicNode* newChild) {
	if (newParent==newChild) {
		return false;
	}
	else
	{
		newParent->addNewChild(newChild);
		return true;
	}

}

void DynamicTree::buildDefaultTestTree() {
	root->addNewChild();
	root->addNewChild();
	root->getChild(0)->setValue(NODE_1_VAL);
	root->getChild(1)->setValue(NODE_2_VAL);
	root->getChild(0)->addNewChild();
	root->getChild(0)->addNewChild();
	root->getChild(0)->getChild(0)->setValue(NODE_11_VAL);
	root->getChild(0)->getChild(1)->setValue(NODE_12_VAL);
	root->getChild(1)->addNewChild();
	root->getChild(1)->addNewChild();
	root->getChild(1)->getChild(0)->setValue(NODE_21_VAL);
	root->getChild(1)->getChild(1)->setValue(NODE_22_VAL);
}

bool DynamicTree::from_the_same_tree(DynamicNode* first, DynamicNode* second) {
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
			return (from_the_same_tree(first->getParentPtr(), second));
		}
		else
		{
			return (from_the_same_tree(first, second->getParentPtr()));
		}
	}
}
