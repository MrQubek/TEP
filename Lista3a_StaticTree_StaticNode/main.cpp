
#include"StaticNode.h"
#include"StaticTree.h"
#include"const.h"

void treeTest()
{
	StaticNode root;
	root.addNewChild();
	root.addNewChild();
	root.getChild(0)->setValue(NODE_1_VAL);
	root.getChild(1)->setValue(NODE_2_VAL);
	root.getChild(0)->addNewChild();
	root.getChild(0)->addNewChild();
	root.getChild(0)->getChild(0)->setValue(NODE_11_VAL);
	root.getChild(0)->getChild(1)->setValue(NODE_12_VAL);
	root.getChild(1)->addNewChild();
	root.getChild(1)->addNewChild();
	root.getChild(1)->getChild(0)->setValue(NODE_21_VAL);
	root.getChild(1)->getChild(1)->setValue(NODE_22_VAL);

	root.printAllBelow();

	root.getChild(1)->getChild(1)->printUp();
} 

int main() {
	
	treeTest();
	
	std::cout << NEW_LINE;

	StaticTree stTree;
	stTree.buildDefaultTestTree();
	stTree.printTree();
	
	StaticTree tree;
	StaticTree tree2;
	tree.buildDefaultTestTree();
	tree2.buildDefaultTestTree();


	if (tree.fromTheSameTree(tree.getRoot()->getChild(0), tree.getRoot()->getChild(1)))
		std::cout << BRANCHES_IN_TREE;
	else
	{
		std::cout << BRANCHES_NOT_IN_TREE;
	}

	if (tree.fromTheSameTree(tree.getRoot()->getChild(0), tree2.getRoot()->getChild(1)))
		std::cout << BRANCHES_IN_TREE;
	else
	{
		std::cout << BRANCHES_NOT_IN_TREE;
	}

	std::cout << NEW_LINE;

	stTree.moveSubtree(stTree.getRoot()->getChild(1), stTree.getRoot()->getChild(0));
	stTree.printTree();

	std::cout << NEW_LINE;

	tree.moveSubtree(tree.getRoot(),tree2.getRoot());
	tree.printTree();

	return 0;
}