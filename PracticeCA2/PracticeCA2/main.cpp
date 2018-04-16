//X00119321 Jason Domican
//ADS1 CA2
//Templated BST - add, delete, rebalance

#include "BinarySearchTree.h"


int main()
{
	BinarySearchTree<int> treeInts;
	treeInts.insert(13);
	treeInts.insert(3);
	treeInts.insert(56);
	treeInts.insert(16);
	treeInts.insert(34);
	treeInts.insert(10);
	treeInts.insert(53);

	treeInts.inOrderShow();
	cout << endl;

	treeInts.deleteNode(16);
	treeInts.inOrderShow();
	cout << endl;

	treeInts.insert(77);
	treeInts.inOrderShow();
	cout << endl;

	treeInts.deleteNode(3);
	treeInts.inOrderShow();
	cout << endl;

	int testInTree = 77;
	if (treeInts.inTree(testInTree))
	{
		cout << testInTree << " is in the tree\n\n";
	}
	else
	{
		cout << testInTree << " is NOT in the tree\n\n";
	}

	treeInts.postOrderShow();
	cout << endl;
	treeInts.preOrderShow();

	cout << endl;
	cout << "Height: " << treeInts.height() << "\n";
	cout << "Size: " << treeInts.size () << "\n\n";

	cout << "Min value " << treeInts.minValue() << "\n";
	cout << "Max value " << treeInts.maxValue() << "\n";

	int value = treeInts.isBST();

	if (value == 1)
	{
		cout << "\nThis is a Binary Search Tree!\n";
	}
	else
	{
		cout << "\nThis is NOT a Binary Search Tree!\n";
	}

	BinarySearchTree<int> wrongTree;
	wrongTree.insertWrong(10);

	int value2 = wrongTree.isBST();

	if (value2 == 1)
	{
		cout << "\nThis is a Binary Search Tree!\n";
	}
	else
	{
		cout << "\nThis is NOT a Binary Search Tree!\n";
	}

	wrongTree.inOrderShow();

	cout << "Rebalance..:\n\n";
	cout << "Size:" << wrongTree.size() << "\n\n";

	TreeNode<int>* temp = wrongTree.getRoot();
	temp = wrongTree.buildTree();
	BinarySearchTree<int> b2;
	b2.setRoot(temp);

	b2.inOrderShow();
	system("pause");
	return 0;
}
 