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
	tree.add(56);
	tree.add(45);

	cout << "Height of tree: " << tree.height() << "\n\n";

	//Expect to find paths of 3 and 24
	int pathsToTest[]{ 3, 24, 5 };

	for (int i = 0; i < 3; i++)
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

	system("pause");
	return 0;

}