#include "StaticNode.h"

StaticNode::StaticNode(int newValue = 0, StaticNode* parentNode = NULL) {
	value = newValue;
	childrenVector = std::vector<StaticNode>();
	parentPtr = parentNode;
}

StaticNode::~StaticNode() {

}

void StaticNode::setValue(int newValue) {
	value = newValue;
}

int StaticNode::getChildrenNumber() {
	return childrenVector.size();
}

void StaticNode::addNewChildren(StaticNode newChildren) {
	childrenVector.push_back(newChildren);
}

StaticNode* StaticNode::getChild(int whichOne) {
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
	for (int i = 0; i < childrenVector.size(); i++) {
		childrenVector[i].printAllBelow();
	}
}