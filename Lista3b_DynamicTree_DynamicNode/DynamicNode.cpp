#include "DynamicNode.h"

void DynamicNode::deleteAllChildren() {
	for (int i = 0; i < childrenVector.size(); i++) {
		childrenVector[i]->deleteAllChildren();
		delete childrenVector[i];
	}
}

DynamicNode::DynamicNode(int newValue = 0, DynamicNode* newParent = NULL) {
	value = newValue;
	parentPtr = newParent;
}

DynamicNode::~DynamicNode() {
	deleteAllChildren();
}

void DynamicNode::setVal(int newValue) {
	value = newValue;
}

int DynamicNode::getChildrenNumber() {
	return childrenVector.size();
}

void DynamicNode::addNewChild() {
	childrenVector.push_back(new DynamicNode());
}

DynamicNode* DynamicNode::getChildPtr(unsigned int whichOne) {
	if (whichOne > childrenVector.size() || whichOne < 0) {
		return NULL;
	}
	else {
		return childrenVector[whichOne];
	}
}

void DynamicNode::print() {
	std::cout << " " << value;
}

void DynamicNode::printAllBelow() {
	print();
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		childrenVector[i]->printAllBelow();
	}
}