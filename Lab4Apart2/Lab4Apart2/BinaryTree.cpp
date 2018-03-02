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
*    Title: Given a binary tree and a sum, determine if the tree has a root-to-leaf...
*    Date: 02/03/2018
*	 Availability: https://stackoverflow.com/questions/28946030/given-a-binary-tree-and-a-sum-determine-if-the-tree-has-a-root-to-leaf-path-suc
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
	return hasPathSum(node->leftPointer, sum - node->data) || hasPathSum(node->rightPointer, sum - node->data);
}


