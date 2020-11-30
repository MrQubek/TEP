
#include"DynamicTree.h"

int main() {

	DynamicTree<int> intTree;
	intTree.buildDefaultTestTree();
	intTree.printTree();

	DynamicTree<char> charTree;
	charTree.getRoot()->setValue('a');
	charTree.getRoot()->addNewChild(new DynamicNode<char>('b'));
	charTree.getRoot()->addNewChild(new DynamicNode<char>('c'));
	charTree.printTree();

	return 0;
}