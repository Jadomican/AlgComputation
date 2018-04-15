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

	BinarySearchTree<double> treeDoubles;
	treeDoubles.insert(13.5);
	treeDoubles.insert(3.7);
	treeDoubles.insert(56.3);
	treeDoubles.insert(34.7);
	treeDoubles.insert(34.3);
	treeDoubles.insert(99.9);
	treeDoubles.insert(60);

	treeInts.inOrderShow();
	cout << endl;
	treeDoubles.inOrderShow();

	system("pause");
	return 0;
}