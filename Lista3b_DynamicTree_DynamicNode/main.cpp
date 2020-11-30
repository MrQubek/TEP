
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//#include"DynamicNode.h"
#include"DynamicTree.h"
//#include"const.h"

void treeTest()
{
	DynamicNode* root = new DynamicNode();
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

	root->printAllBelow();

	delete root;
}

int main() {

	//treeTest();

	std::cout << NEW_LINE;

	DynamicTree* tree = new DynamicTree();
	tree->buildDefaultTestTree();
	tree->printTree();

	DynamicTree* tree2 = new DynamicTree();
	tree2->buildDefaultTestTree();

	std::cout << NEW_LINE;

	if (tree->fromTheSameTree(tree->getRoot()->getChild(0), tree->getRoot()->getChild(1))){
		std::cout << BRANCHES_IN_TREE;
	}
	else
	{
		std::cout << BRANCHES_NOT_IN_TREE;
	}

	if (tree->fromTheSameTree(tree->getRoot()->getChild(0), tree2->getRoot()->getChild(1))){
		std::cout << BRANCHES_IN_TREE;
	}
	else
	{
		std::cout << BRANCHES_NOT_IN_TREE;
	}

	std::cout << NEW_LINE;
	
	tree->moveSubtree(tree->getRoot()->getChild(1), tree->getRoot()->getChild(0));
	tree->printTree();

	delete tree;
	delete tree2;
	_CrtDumpMemoryLeaks();

	return 0;

}