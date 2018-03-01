//X00119321 Jason Domican - ALC Lab3B

#include "BinaryTree.h"

void BinaryTree::add(int key, TreeNode*& subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode(key, NULL, NULL);
	}
	else if (key < subTreeRoot->key_value)
	{
		add(key, subTreeRoot->leftPointer);
	}
	else
	{
		add(key, subTreeRoot->rightPointer);
	}
}

void BinaryTree::add(int key)
{
	add(key, root);
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

int BinaryTree::height(TreeNode * node) const
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


