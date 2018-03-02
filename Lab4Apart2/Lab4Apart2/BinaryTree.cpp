//X00119321 Jason Domican - ALC Lab3B

#include "BinaryTree.h"
#include <iostream>

void BinaryTree::add(int data, TreeNode*& subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode(data, NULL, NULL);
	}
	else if (data < subTreeRoot->data)
	{
		add(data, subTreeRoot->leftPointer);
	}
	else
	{
		add(data, subTreeRoot->rightPointer);
	}
}

void BinaryTree::add(int data)
{
	add(data, root);
}


/***************************************************************************************
*    Usage: modified
*    Title: Binary Tree Height Function
*    Date: 27/02/2018
*	 Availability: https://stackoverflow.com/questions/13041948/binary-tree-height-function
***************************************************************************************/


int BinaryTree::height() const
{
	return height(root);
}

int BinaryTree::height(TreeNode* node) const
{
	if (node == NULL)
	{
		return -1;
	}

	int left = height(node->leftPointer);
	int right = height(node->rightPointer);

	if (left > right)
	{
		return 1 + left;
	}
	else
	{
		return 1 + right;
	}

}

/***************************************************************************************
*    Usage: modified
*    Title: Root to leaf path sum equal to a given number
*    Date: 02/03/2018
*	 Availability: https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
***************************************************************************************/

bool BinaryTree::hasPathSum(int sum)
{
	return hasPathSum(root, sum);
}

bool BinaryTree::hasPathSum(TreeNode* node, int sum)
{
	if (!node)
	{
		return sum == 0;
	}
	else
	{
		bool answer = 0;
		
		int subSum = sum - node->data;

		// If at a leaf and sum becomes 0, return true
		if (subSum == 0 && node->leftPointer == NULL && node->rightPointer == NULL)
		{
			return 1;
		}

		if (node->leftPointer)
		{
			answer = answer || hasPathSum(node->leftPointer, subSum);
		}
		if (node->rightPointer)
		{
			answer = answer || hasPathSum(node->rightPointer, subSum);
		}

		return answer;
	}
}


/***************************************************************************************
*    Usage: modified
*    Title: Given a binary tree, print all root-to-leaf paths
*    Date: 02/03/2018
*	 Availability: https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
***************************************************************************************/


void BinaryTree::printPaths()
{
	int path[1000];
	printPaths(root, path, 0);
}

void BinaryTree::printPaths(TreeNode* node, int path[], int pathLength)
{
	if (node == NULL)
	{
		return;
	}

	path[pathLength] = node->data;
	pathLength++;

	if (node->leftPointer == NULL && node->rightPointer == NULL)
	{
		//If both pointers are null, it's a leaf
		printPathsArray(path, pathLength);
	}
	else
	{
		//Otherwise try both subtrees
		printPaths(node->leftPointer, path, pathLength);
		printPaths(node->rightPointer, path, pathLength);
	}
}


void BinaryTree::printPathsArray(int ints[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << ints[i] << " ";
	}
	cout << "\n";
}
