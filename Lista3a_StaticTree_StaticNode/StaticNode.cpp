#include "StaticNode.h"

StaticNode::StaticNode(int newValue, StaticNode* parentNode) {
	value = newValue;
	childrenVector = std::vector<StaticNode>();
	parentPtr = parentNode;
}

StaticNode::~StaticNode() {

}

void StaticNode::setValue(int newValue) {
	value = newValue;
}

void StaticNode::setParent(StaticNode* newParent) {
	parentPtr = newParent;
}


int StaticNode::getChildrenNumber() {
	return childrenVector.size();
}

void StaticNode::addNewChild() {
	StaticNode tmp;
	tmp.setParent(this);
	childrenVector.push_back(tmp);
}

void StaticNode::addNewChild(StaticNode newChildren) {
	newChildren.setParent(this);
	childrenVector.push_back(newChildren);
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
