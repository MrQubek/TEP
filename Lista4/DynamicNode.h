#pragma once

#include<vector>
#include <iostream>
#include"const.h"

template <typename T> class DynamicNode {

private:
	T value;
	DynamicNode* parentPtr;
	std::vector<DynamicNode<T>*> childrenVector;

	void deleteAllChildren();

public:

	DynamicNode<T>();

	DynamicNode<T>(T newValue, DynamicNode* newParent = NULL);

	~DynamicNode();

	void setValue(T newValue);

	T getValue();


	void setParent(DynamicNode* newParent);

	bool removeFromParent();

	bool removeChildFromVector(DynamicNode* childPtr);


	int getChildrenNumber();

	void addNewChild();

	void addNewChild(DynamicNode* newChildPtr);


	DynamicNode* getChild(unsigned int whichOne);

	DynamicNode* getParentPtr();


	void print();

	void printAllBelow();

};

template <typename T>
void DynamicNode<T>::deleteAllChildren() {
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		delete childrenVector[i];
	}
}

template <typename T>
DynamicNode<T>::DynamicNode() {
	parentPtr = NULL;
}

template <typename T>
DynamicNode<T>::DynamicNode(T newValue, DynamicNode<T>* newParent) {
	value = newValue;
	parentPtr = newParent;
}

template <typename T>
DynamicNode<T>::~DynamicNode() {
	deleteAllChildren();
}

template <typename T>
void DynamicNode<T>::setValue(T newValue) {
	value = newValue;
}

template <typename T>
T DynamicNode<T>::getValue() {
	return value;
}

template <typename T>
void DynamicNode<T>::setParent(DynamicNode* newParent) {
	parentPtr = newParent;
}

template <typename T>
bool DynamicNode<T>::removeFromParent() {
	if (parentPtr != NULL) {
		return parentPtr->removeChildFromVector(this);
	}
	else {
		return false;
	}
}

template <typename T>
bool DynamicNode<T>::removeChildFromVector(DynamicNode* childPtr) {
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		if (childrenVector[i] == childPtr) {
			childrenVector.erase(childrenVector.begin() + i);
			return true;
		}
	}
	return false;
}

template <typename T>
int DynamicNode<T>::getChildrenNumber() {
	return childrenVector.size();
}

template <typename T>
void DynamicNode<T>::addNewChild() {
	childrenVector.push_back(new DynamicNode());
	childrenVector.back()->setParent(this);
}

template <typename T>
void DynamicNode<T>::addNewChild(DynamicNode* newChildPtr) {
	childrenVector.push_back(newChildPtr);
	childrenVector.back()->removeFromParent();
	childrenVector.back()->setParent(this);
}

template <typename T>
DynamicNode<T>* DynamicNode<T>::getChild(unsigned int whichOne) {
	if (whichOne > childrenVector.size() || whichOne < 0) {
		return NULL;
	}
	else {
		return childrenVector[whichOne];
	}
}

template <typename T>
DynamicNode<T>* DynamicNode<T>::getParentPtr() {
	return parentPtr;
}

template <typename T>
void DynamicNode<T>::print() {
	std::cout << " " << value;
}

template <typename T>
void DynamicNode<T>::printAllBelow() {
	print();
	for (unsigned int i = 0; i < childrenVector.size(); i++) {
		childrenVector[i]->printAllBelow();
	}
}
