//X00119321 Jason Domican - ALC Lab4A

#include <iostream>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{

	BinarySearchTree tree;

	tree.insert('a');
	tree.insert('f');
	tree.insert('w');
	tree.insert('t');
	tree.insert('b');
	tree.insert('c');
	tree.insert('z');
	tree.insert('k');

	cout << "Tree contents IN-ORDER: \n";
	tree.inOrderShow();


	cout << "\n\nEnter a value to check if it exists in the tree: ";
	char value;
	cin >> value;
	if (tree.inTree(value))
	{
		cout << "\n" << value << " is in the tree!\n";
	}
	else
	{
		cout << "\nNot found\n";
	}

	cout << "\nTree contents PRE-ORDER: \n";
	tree.preOrderShow();

	cout << "\nTree contents POST-ORDER: \n";
	tree.postOrderShow();


	system("pause");
	return 0;

}