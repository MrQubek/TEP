#include "DynamicNode.h"

void DynamicNode::deleteAllChildren() {
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		delete childrenVector[i];
	}
}

DynamicNode::DynamicNode(int newValue, DynamicNode* newParent) {
	value = newValue;
	parentPtr = newParent;
}

DynamicNode::~DynamicNode() {
	std::cout << "Delete node with val " << value<<'\n';
	deleteAllChildren();
}

void DynamicNode::setValue(int newValue) {
	value = newValue;
}

void DynamicNode::setParent(DynamicNode* newParent) {
	if (parentPtr != NULL) {
		parentPtr->deleteChildFromVector(this);
	}
	parentPtr = newParent;

}

bool DynamicNode::deleteChildFromVector(DynamicNode* childPtr) {
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		if (childrenVector[i] == childPtr) {
			childrenVector.erase(childrenVector.begin()+i);
			return true;
		}
	}
	return false;
}


int DynamicNode::getChildrenNumber() {
	return childrenVector.size();
}

void DynamicNode::addNewChild() {
	childrenVector.push_back(new DynamicNode());
	childrenVector.back()->setParent(this);
}

void DynamicNode::addNewChild(DynamicNode* newChildPtr) {
	childrenVector.push_back(newChildPtr);
	childrenVector.back()->setParent(this);
}


DynamicNode* DynamicNode::getChildPtr(unsigned int whichOne) {
	if (whichOne > childrenVector.size() || whichOne < 0) {
		return NULL;
	}
	else {
		return childrenVector[whichOne];
	}
}

DynamicNode* DynamicNode::getParentPtr() {
	return parentPtr;
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