#include "DynamicTree.h"

DynamicTree::DynamicTree() {
	root = new DynamicNode();
}

DynamicTree::~DynamicTree() {
	root->~DynamicNode();
	delete root;
}

DynamicNode* DynamicTree::getRoot() {
	return root;
}

void DynamicTree::printTree() {
	root->printAllBelow();
}

bool DynamicTree::moveSubtree(DynamicNode* newParent, DynamicNode* newChild) {
	newParent->addNewChild(newChild);
}