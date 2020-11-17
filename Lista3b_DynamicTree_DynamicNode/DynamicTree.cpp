#include "DynamicTree.h"
#include"const.h"

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
	root->printAllBelow();
	std::cout << NEW_LINE;
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
	root->getChildPtr(0)->setValue(NODE_1_VAL);
	root->getChildPtr(1)->setValue(NODE_2_VAL);
	root->getChildPtr(0)->addNewChild();
	root->getChildPtr(0)->addNewChild();
	root->getChildPtr(0)->getChildPtr(0)->setValue(NODE_11_VAL);
	root->getChildPtr(0)->getChildPtr(1)->setValue(NODE_12_VAL);
	root->getChildPtr(1)->addNewChild();
	root->getChildPtr(1)->addNewChild();
	root->getChildPtr(1)->getChildPtr(0)->setValue(NODE_21_VAL);
	root->getChildPtr(1)->getChildPtr(1)->setValue(NODE_22_VAL);
}
