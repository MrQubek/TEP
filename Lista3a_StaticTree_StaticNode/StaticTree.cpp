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
	root.printAllBelow();
}