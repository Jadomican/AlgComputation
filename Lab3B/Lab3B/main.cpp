//X00119321 Jason Domican - ALC Lab3B

#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	
	BinaryTree tree;

	tree.add(3);
	tree.add(14);
	tree.add(7);
	tree.add(6);
	tree.add(56);
	tree.add(45);

	cout << "Height of tree: " << tree.height() << endl;

	system("pause");
	return 0;

}