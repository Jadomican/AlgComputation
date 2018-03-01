//X00119321 Jason Domican - ALC Lab 3B

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree<int> treeInt;

	treeInt.insert(3);
	treeInt.insert(44);
	treeInt.insert(7);
	treeInt.insert(33);
	treeInt.insert(67);
	treeInt.insert(99);
	treeInt.insert(24);
	treeInt.insert(1);

	cout << "Tree contents IN-ORDER: \n";
	treeInt.inOrderShow();

	cout << "\n\nEnter an integer to check if it exists in the tree: ";
	int value;
	cin >> value;
	if (treeInt.inTree(value))
	{
		cout << "\n" << value << " is in the tree!\n\n";
	}
	else
	{
		cout << "\nNot found\n\n";
	}


	BinarySearchTree<char> treeChar;

	treeChar.insert('r');
	treeChar.insert('g');
	treeChar.insert('s');
	treeChar.insert('h');
	treeChar.insert('k');
	treeChar.insert('y');
	treeChar.insert('n');
	treeChar.insert('f');

	cout << "Tree contents IN-ORDER: \n";
	treeChar.inOrderShow();

	cout << "\n\nEnter an character to check if it exists in the tree: ";
	char valueChar;
	cin >> valueChar;
	if (treeChar.inTree(valueChar))
	{
		cout << "\n" << valueChar << " is in the tree!\n";
	}
	else
	{
		cout << "\nNot found\n";
	}

	system("pause");
	return 0;
}