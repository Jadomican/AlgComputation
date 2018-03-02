//X00119321 Jason Domican - ALC Lab4A

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
	tree.add(24);
	tree.add(30);

	cout << "Height of tree: " << tree.height() << "\n\n";

	//Expect to find paths of 30 and 71
	int pathsToTest[]{ 30, 71, 56, 99 };

	for (int i = 0; i < 4; i++)
	{
		if (tree.hasPathSum(pathsToTest[i]))
		{
			cout << "Has a path of " << pathsToTest[i] << "!\n";
		}
		else
		{
			cout << "No path of " << pathsToTest[i] << "!\n";
		}

	}

	cout << "\nPrinting paths\n";
	tree.printPaths();

	system("pause");
	return 0;

}