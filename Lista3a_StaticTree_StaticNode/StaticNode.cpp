#include "StaticNode.h"

StaticNode::StaticNode(int newValue, StaticNode* parentNode) {
	value = newValue;
	parentPtr = parentNode;
}

StaticNode::~StaticNode() {
	//std::cout << "Delete node with val " << value<<'\n';
}

StaticNode::StaticNode(const StaticNode& other) {
	value = other.value;
	parentPtr = other.parentPtr;
	childrenVector = other.childrenVector;
}

StaticNode* StaticNode::operator = (const StaticNode& other) {
	value = other.value;
	parentPtr = other.parentPtr;
	childrenVector = other.childrenVector;
	return this;
}

void StaticNode::setValue(int newValue) {
	value = newValue;
}

int StaticNode::getValue() {
	return value;
}


void StaticNode::setParent(StaticNode* newParent) {
	parentPtr = newParent;
}


int StaticNode::getChildrenNumber() {
	return childrenVector.size();
}

void StaticNode::addNewChild() {
	childrenVector.push_back(StaticNode());
	childrenVector.back().setParent(this);
}

void StaticNode::addNewChild(StaticNode newChildren) {
	childrenVector.push_back(newChildren);
	childrenVector.back().setParent(this);

}

bool StaticNode::removeChildFromParent() {
	if (parentPtr != NULL) {
		return parentPtr->removeChildFromVector(this);
	}
	else
	{
		return false;
	}
}

bool StaticNode::removeChildFromVector(StaticNode* childPtr) {
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		if (&childrenVector[i] == childPtr) {
			childrenVector.erase(childrenVector.begin() + i);
			return true;
		}
	}
	return false;
}

StaticNode* StaticNode::getChild(unsigned int whichOne) {
	if (whichOne > childrenVector.size() || whichOne < 0) {
		return NULL;
	}
	else {
		return &childrenVector[whichOne];
	}
}

void StaticNode::print() {
	std::cout << " " << value;
}

void StaticNode::printAllBelow() {
	print();
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		childrenVector[i].printAllBelow();
	}
}

void StaticNode::printUp() {
	print();
	if (parentPtr != NULL) {
		parentPtr->printUp();
	}
}

StaticNode* StaticNode::getParentPtr() {
	return parentPtr;
}

