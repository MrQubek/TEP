
#include"DynamicNode.h"
#include"DynamicTree.h"
#include"const.h"

void treeTest()
{
	DynamicNode * root = new DynamicNode();
	root->addNewChild();
	root->addNewChild();
	root->getChildPtr(0)->setValue(NODE_1_VAL);
	root->getChildPtr(1)->setValue(NODE_2_VAL);
	root->getChildPtr(0)->addNewChild();
	root->getChildPtr(0)->addNewChild();
	root->getChildPtr(0)->getChildPtr(0)->setValue(NODE_11_VAL);
	root->getChildPtr(0)->getChildPtr(1)->setValue(NODE_12_VAL);
	root->getChildPtr(1)->addNewChild();
	root->getChildPtr(1)->addNewChild();
	root->getChildPtr(1)->getChildPtr(0)->setValue(NODE_21_VAL);
	root->getChildPtr(1)->getChildPtr(1)->setValue(NODE_22_VAL);

	root->printAllBelow();

	delete root;
}

int main() {
	
	treeTest();

	std::cout << NEW_LINE;

	DynamicTree tree;
	tree.buildDefaultTestTree();
	tree.printTree();

	std::cout << NEW_LINE;

	tree.moveSubtree(tree.getRoot()->getChildPtr(1), tree.getRoot()->getChildPtr(0));
	tree.printTree();

	return 0;

}