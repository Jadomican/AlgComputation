//X00119321 Jason Domican - ALC Lab4B

#include <iostream>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree tree;

	tree.insert(14);
	tree.insert(8);
	tree.insert(27);
	tree.insert(21);
	tree.insert(1);
	tree.insert(6);
	tree.insert(9);
	tree.insert(19);

	cout << "Tree contents IN-ORDER: \n";
	tree.inOrderShow();

	//Print out the min and max values in the binary search tree
	cout << "\n\nMin value in tree: " << tree.minValue() << "\n";
	cout << "\nMax value in tree: " << tree.maxValue() << "\n";

	//Expect this to evaluate to 1 (TRUE)
	int value = tree.isBST();

	if (value == 1)
	{
		cout << "\nThis is a Binary Search Tree!\n";
	}
	else
	{
		cout << "\nThis is NOT a Binary Search Tree!\n";
	}

	system("pause");
	return 0;

}