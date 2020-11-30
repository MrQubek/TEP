#pragma once

#include"DynamicNode.h"

template <typename T> class DynamicTree
{
private:

	DynamicNode<T>* root;

public:
	DynamicTree<T>();

	~DynamicTree();

	DynamicNode<T>* getRoot();

	void printTree();

	bool moveSubtree(DynamicNode<T>* newParent, DynamicNode<T>* newChild);

	void buildDefaultTestTree();

	bool fromTheSameTree(DynamicNode<T>* first, DynamicNode<T>* second);
};

template <typename T>
DynamicTree<T>::DynamicTree() {
	root = new DynamicNode<T>();
}

template <typename T>
DynamicTree<T>::~DynamicTree() {
	delete root;
}

template <typename T>
DynamicNode<T>* DynamicTree<T>::getRoot() {
	return root;
}

template <typename T>
void DynamicTree<T>::printTree() {
	std::vector<DynamicNode<T>* > nodesToPrint;
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

template <typename T>
bool DynamicTree<T>::moveSubtree(DynamicNode<T>* newParent, DynamicNode<T>* newChild) {
	if (newParent == newChild) {
		return false;
	}
	else
	{
		newParent->addNewChild(newChild);
		return true;
	}

}

template <>
void DynamicTree<int>::buildDefaultTestTree() {
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

template <typename T>
bool DynamicTree<T>::fromTheSameTree(DynamicNode<T>* first, DynamicNode<T>* second) {
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
			return (fromTheSameTree(first->getParentPtr(), second));
		}
		else
		{
			return (fromTheSameTree(first, second->getParentPtr()));
		}
	}
}
